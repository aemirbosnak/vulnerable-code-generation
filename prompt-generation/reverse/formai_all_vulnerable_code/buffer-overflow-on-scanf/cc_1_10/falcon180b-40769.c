//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENTS 118
#define MAX_ATTEMPTS 10

struct element {
    char symbol[3];
    char name;
    int atomic_number;
    char category[20];
};

void generate_quiz(struct element elements[], int num_elements) {
    int i, j;
    char answer[20];

    srand(time(NULL));
    for (i = 0; i < num_elements; i++) {
        elements[i].atomic_number = rand() % 118 + 1; // generate random atomic number between 1 and 118
        sprintf(answer, "%d", elements[i].atomic_number);
        elements[i].category[0] = '\0'; // initialize category string to empty
    }

    for (i = 0; i < num_elements; i++) {
        printf("Question %d: What is the atomic number of %s?\n", i+1, elements[i].symbol);
        scanf("%s", answer);
        if (strcmp(answer, elements[i].symbol) == 0) {
            printf("Correct!\n");
        } else {
            printf("Incorrect, the correct answer is %s.\n", elements[i].symbol);
        }
    }
}

int main() {
    struct element elements[MAX_ELEMENTS];
    int num_elements, attempts, correct_answers;

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("How many elements would you like to be quizzed on? (1-%d)\n", MAX_ELEMENTS);
    scanf("%d", &num_elements);

    num_elements = (num_elements > MAX_ELEMENTS)? MAX_ELEMENTS : num_elements;
    num_elements = (num_elements < 1)? 1 : num_elements;

    generate_quiz(elements, num_elements);

    attempts = 0;
    correct_answers = 0;

    while (attempts < MAX_ATTEMPTS && correct_answers < num_elements) {
        generate_quiz(elements, num_elements);
        attempts++;
        correct_answers = 0;

        for (int i = 0; i < num_elements; i++) {
            if (strcmp(elements[i].symbol, elements[i].name) == 0) {
                correct_answers++;
            }
        }

        if (correct_answers == num_elements) {
            printf("Congratulations! You got all %d questions correct!\n", num_elements);
        } else {
            printf("You got %d out of %d questions correct.\n", correct_answers, num_elements);
        }
    }

    return 0;
}