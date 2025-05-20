//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ELEMENTS 118
#define MAX_ATTEMPTS 3
#define TIMEOUT 10

struct element {
    char symbol[3];
    char name;
    int atomic_number;
    int group;
    int period;
    char category[20];
};

void load_elements(struct element *elements) {
    FILE *fp = fopen("elements.txt", "r");
    
    if (fp == NULL) {
        printf("Error loading elements.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(fp, "%s %c %d %d %d %[^\n]", elements[count].symbol, &elements[count].name, &elements[count].atomic_number, &elements[count].group, &elements[count].period, elements[count].category) == 6) {
        count++;
    }

    fclose(fp);
}

void print_element(struct element element) {
    printf("Symbol: %s\n", element.symbol);
    printf("Name: %c\n", element.name);
    printf("Atomic Number: %d\n", element.atomic_number);
    printf("Group: %d\n", element.group);
    printf("Period: %d\n", element.period);
    printf("Category: %s\n\n", element.category);
}

int main() {
    struct element elements[NUM_ELEMENTS];
    
    load_elements(elements);

    int num_questions = rand() % 5 + 1;
    int score = 0;

    for (int i = 0; i < num_questions; i++) {
        int index = rand() % NUM_ELEMENTS;
        struct element question = elements[index];
        char buffer[20];

        printf("Question %d:\n", i+1);
        printf("Symbol: %s\n", question.symbol);

        fflush(stdout);
        fgets(buffer, 20, stdin);

        if (strcmp(buffer, question.symbol) == 0) {
            score++;
        }
    }

    printf("Your score is %d out of %d.\n", score, num_questions);

    return 0;
}