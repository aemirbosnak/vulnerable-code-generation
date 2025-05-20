//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENTS 118
#define MAX_QUESTIONS 10

typedef struct {
    char symbol[3];
    char name;
    int atomic_number;
    int atomic_weight;
} Element;

Element elements[MAX_ELEMENTS] = {
    {"H", 'H', 1, 1.008},
    {"He", 'He', 2, 4.003},
    {"Li", 'Li', 3, 6.941},
    {"Be", 'Be', 4, 9.012},
    {"B", 'B', 5, 10.81},
    {"C", 'C', 6, 12.01},
    {"N", 'N', 7, 14.01},
    {"O", 'O', 8, 15.99},
    {"F", 'F', 9, 18.99},
    {"Ne", 'Ne', 10, 20.18}
};

int main() {
    srand(time(NULL));

    int num_questions;
    printf("How many questions do you want to answer? (1-10): ");
    scanf("%d", &num_questions);

    int correct_answers = 0;
    int total_questions = 0;

    for (int i = 0; i < num_questions; i++) {
        int index = rand() % MAX_ELEMENTS;
        Element *element = &elements[index];

        char symbol[4];
        strcpy(symbol, element->symbol);
        symbol[3] = '\0';

        int atomic_number = element->atomic_number;
        int atomic_weight = element->atomic_weight;

        printf("Question %d:\n", i+1);
        printf("Symbol: %s\n", symbol);
        printf("Atomic number: %d\n", atomic_number);
        printf("Atomic weight: %d\n", atomic_weight);

        int choice;
        printf("Enter your answer (A-%s): ", symbol);
        scanf("%d", &choice);

        if (choice == atomic_number) {
            correct_answers++;
        }

        total_questions++;
    }

    printf("\nYou got %d out of %d correct.\n", correct_answers, total_questions);

    return 0;
}