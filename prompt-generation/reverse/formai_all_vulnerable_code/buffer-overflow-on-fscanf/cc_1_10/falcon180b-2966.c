//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ELEMENTS 118
#define MAX_NAME_LENGTH 32
#define MAX_SYMBOL_LENGTH 3
#define MAX_ATOMIC_NUMBER_LENGTH 4

typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    int atomic_number;
} Element;

Element elements[NUM_ELEMENTS];

void populate_elements() {
    FILE *file = fopen("elements.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open elements file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s %d\n", elements[count].name, elements[count].symbol, &elements[count].atomic_number) == 3) {
        count++;
    }

    fclose(file);
}

void generate_quiz() {
    srand(time(NULL));
    int num_questions = rand() % 10 + 5;

    printf("Periodic Table Quiz\n");
    printf("------------------\n");
    printf("You will be asked %d questions.\n\n", num_questions);

    int correct_answers = 0;
    for (int i = 0; i < num_questions; i++) {
        int index = rand() % NUM_ELEMENTS;
        Element question_element = elements[index];

        printf("Question %d:\n", i + 1);
        printf("Name: ");
        char input_name[MAX_NAME_LENGTH];
        scanf("%s", input_name);

        printf("Symbol: ");
        char input_symbol[MAX_SYMBOL_LENGTH];
        scanf("%s", input_symbol);

        printf("Atomic Number: ");
        char input_atomic_number[MAX_ATOMIC_NUMBER_LENGTH];
        scanf("%s", input_atomic_number);

        if (strcmp(input_name, question_element.name) == 0 &&
            strcmp(input_symbol, question_element.symbol) == 0 &&
            atoi(input_atomic_number) == question_element.atomic_number) {
            printf("Correct!\n");
            correct_answers++;
        } else {
            printf("Incorrect. The correct answers are:\n");
            printf("Name: %s\n", question_element.name);
            printf("Symbol: %s\n", question_element.symbol);
            printf("Atomic Number: %d\n", question_element.atomic_number);
        }
    }

    printf("\nYou got %d out of %d questions correct.\n", correct_answers, num_questions);
}

int main() {
    populate_elements();
    generate_quiz();

    return 0;
}