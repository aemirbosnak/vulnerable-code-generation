//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ELEMENTS 118
#define MAX_NAME_LENGTH 50
#define MAX_SYMBOL_LENGTH 3

typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    int atomic_number;
    int group;
    int period;
    char category[MAX_NAME_LENGTH];
} element;

element elements[MAX_ELEMENTS];

int compare_names(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int compare_symbols(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int compare_atomic_numbers(const void *a, const void *b) {
    return (*(int *)a) - (*(int *)b);
}

void load_elements() {
    FILE *file = fopen("elements.txt", "r");
    if (file == NULL) {
        printf("Error: could not open elements.txt\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s %d %d %d %s\n", elements[count].name, elements[count].symbol, &elements[count].atomic_number, &elements[count].group, &elements[count].period, elements[count].category) == 6) {
        count++;
    }

    fclose(file);
}

void sort_elements() {
    qsort(elements, MAX_ELEMENTS, sizeof(element), compare_names);
}

int main() {
    load_elements();
    sort_elements();

    int score = 0;
    int questions = 0;

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("How many questions would you like to answer? ");
    scanf("%d", &questions);

    for (int i = 0; i < questions; i++) {
        int index = rand() % MAX_ELEMENTS;
        printf("Question %d: What is the name of element %s? ", i + 1, elements[index].symbol);
        char answer[MAX_NAME_LENGTH];
        scanf("%s", answer);

        if (strcmp(answer, elements[index].name) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %s.\n", elements[index].name);
        }
    }

    printf("You scored %d out of %d questions correct.\n", score, questions);

    return 0;
}