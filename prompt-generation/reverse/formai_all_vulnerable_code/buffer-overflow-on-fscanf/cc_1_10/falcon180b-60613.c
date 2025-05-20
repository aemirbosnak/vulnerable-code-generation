//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_ELEMENTS 118

struct element {
    char symbol[3];
    char name[20];
    int atomic_number;
    double atomic_weight;
};

void read_elements(struct element *elements) {
    FILE *file = fopen("elements.txt", "r");

    if (file == NULL) {
        printf("Error: Could not open elements file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s %d %lf", elements[count].symbol, elements[count].name, &elements[count].atomic_number, &elements[count].atomic_weight)!= EOF) {
        count++;
    }

    fclose(file);
}

int main() {
    struct element elements[MAX_ELEMENTS];
    read_elements(elements);

    int score = 0;
    int total_questions = 0;

    printf("Welcome to the Periodic Table Quiz!\n");

    while (1) {
        printf("\nEnter a number to start the quiz, or type 'quit' to exit: ");
        char input[10];
        fgets(input, 10, stdin);

        if (strcmp(input, "quit") == 0) {
            break;
        }

        int index = atoi(input) - 1;
        if (index < 0 || index >= MAX_ELEMENTS) {
            printf("Invalid element number.\n");
            continue;
        }

        struct element *current_element = &elements[index];

        total_questions++;
        printf("\nQuestion %d: What is the symbol for %s?\n", total_questions, current_element->name);
        char answer[4];
        fgets(answer, 4, stdin);

        if (strcmp(answer, current_element->symbol) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %s.\n", current_element->symbol);
        }
    }

    printf("\nYou scored %d out of %d questions correct.\n", score, total_questions);

    return 0;
}