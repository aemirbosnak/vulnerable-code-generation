//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ELEMENTS 118
#define MAX_NAME_LENGTH 20
#define MAX_SYMBOL_LENGTH 3
#define MAX_ATOMIC_NUMBER_LENGTH 3
#define MAX_ATOMIC_WEIGHT_LENGTH 6

typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    int atomic_number;
    char atomic_weight[MAX_ATOMIC_WEIGHT_LENGTH];
} Element;

Element elements[MAX_ELEMENTS];

void load_elements() {
    // Load the periodic table data from a file
}

int main() {
    load_elements();

    int num_questions;
    printf("Enter the number of questions: ");
    scanf("%d", &num_questions);

    int score = 0;
    for (int i = 0; i < num_questions; i++) {
        int index = rand() % MAX_ELEMENTS;
        Element *element = &elements[index];

        char question[100];
        sprintf(question, "What is the name of element %s? ", element->symbol);

        char answer[MAX_NAME_LENGTH];
        scanf("%s", answer);

        if (strcmp(answer, element->name) == 0) {
            score++;
        }
    }

    printf("Your score is %d out of %d\n", score, num_questions);

    return 0;
}