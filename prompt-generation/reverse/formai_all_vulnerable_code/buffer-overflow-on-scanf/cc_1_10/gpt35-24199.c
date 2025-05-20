//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 118

typedef struct {
    char symbol[3];
    char name[20];
    int atomic_number;
    float atomic_mass;
} Element;

Element periodic_table[MAX_ELEMENTS];

void init_periodic_table(void);
int get_answer(char *answer);
void print_question(int question_number);

int main(void) {
    char answer[20];
    int score = 0;
    int question_number;

    init_periodic_table();

    printf("\nWelcome to the C Periodic Table Quiz!\n\n");

    for (question_number = 1; question_number <= MAX_ELEMENTS; question_number++) {
        print_question(question_number);
        get_answer(answer);
        if (strcmp(answer, periodic_table[question_number - 1].symbol) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %s.\n", periodic_table[question_number - 1].symbol);
        }
        printf("Current Score: %d/%d\n\n", score, question_number);
    }

    printf("\nYou have completed the quiz. Final Score: %d/%d\n", score, MAX_ELEMENTS);

    return 0;
}

void init_periodic_table(void) {
    strcpy(periodic_table[0].symbol, "H");
    strcpy(periodic_table[0].name, "Hydrogen");
    periodic_table[0].atomic_number = 1;
    periodic_table[0].atomic_mass = 1.008;

    strcpy(periodic_table[1].symbol, "He");
    strcpy(periodic_table[1].name, "Helium");
    periodic_table[1].atomic_number = 2;
    periodic_table[1].atomic_mass = 4.003;

    // add more elements here...

    strcpy(periodic_table[MAX_ELEMENTS - 1].symbol, "Og");
    strcpy(periodic_table[MAX_ELEMENTS - 1].name, "Oganesson");
    periodic_table[MAX_ELEMENTS - 1].atomic_number = 118;
    periodic_table[MAX_ELEMENTS - 1].atomic_mass = 294.214;
}

int get_answer(char *answer) {
    printf("Enter your answer: ");
    return scanf("%s", answer);
}

void print_question(int question_number) {
    printf("Question %d\n", question_number);
    printf("----------\n");
    printf("What is the symbol for %s?\n", periodic_table[question_number - 1].name);
}