//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX_ELEMENTS 118
#define MAX_NAME_LENGTH 50
#define MAX_SYMBOL_LENGTH 3

typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    int atomic_number;
    int group;
    float atomic_weight;
} Element;

Element elements[MAX_ELEMENTS];

void read_elements(FILE *file) {
    int count = 0;
    while (fscanf(file, "%s %s %d %d %f", &elements[count].name, &elements[count].symbol, &elements[count].atomic_number, &elements[count].group, &elements[count].atomic_weight) == 5) {
        count++;
    }
}

int main() {
    FILE *file;
    file = fopen("elements.txt", "r");

    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    read_elements(file);

    int choice;
    do {
        printf("Periodic Table Quiz\n");
        printf("1. Start Quiz\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int score = 0;
            int total_questions = 10;

            for (int i = 0; i < total_questions; i++) {
                int random_index = rand() % MAX_ELEMENTS;
                printf("Question %d: What is the symbol of the element with atomic number %d?\n", i + 1, elements[random_index].atomic_number);
                char answer[MAX_SYMBOL_LENGTH];
                scanf("%s", answer);

                if (strcmp(answer, elements[random_index].symbol) == 0) {
                    score++;
                }
            }

            printf("You scored %d out of %d.\n", score, total_questions);
        }
    } while (choice!= 2);

    return 0;
}