//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENTS 118
#define MAX_ELEMENT_NAME_LENGTH 100
#define MAX_ELEMENT_SYMBOL_LENGTH 3
#define MAX_ELEMENT_ATOMIC_NUMBER_LENGTH 3
#define MAX_ELEMENT_ATOMIC_WEIGHT_LENGTH 6
#define MAX_ELEMENT_DESCRIPTION_LENGTH 1000

typedef struct {
    char name[MAX_ELEMENT_NAME_LENGTH];
    char symbol[MAX_ELEMENT_SYMBOL_LENGTH];
    char atomic_number[MAX_ELEMENT_ATOMIC_NUMBER_LENGTH];
    char atomic_weight[MAX_ELEMENT_ATOMIC_WEIGHT_LENGTH];
    char description[MAX_ELEMENT_DESCRIPTION_LENGTH];
} Element;

Element elements[MAX_ELEMENTS];

void load_elements() {
    FILE *file = fopen("elements.txt", "r");
    if (file == NULL) {
        printf("Error reading elements file\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s %s %s %s\n", elements[count].name, elements[count].symbol, elements[count].atomic_number, elements[count].atomic_weight, elements[count].description)!= EOF) {
        count++;
    }

    fclose(file);
}

int main() {
    srand(time(NULL));

    load_elements();

    int score = 0;
    int question_count = 0;

    while (question_count < 10) {
        int index = rand() % MAX_ELEMENTS;
        Element element = elements[index];

        printf("Question %d: %s\n", ++question_count, element.name);

        char answer[MAX_ELEMENT_NAME_LENGTH];
        scanf("%s", answer);

        if (strcmp(answer, element.name) == 0) {
            score++;
        }
    }

    printf("You scored %d out of 10\n", score);

    return 0;
}