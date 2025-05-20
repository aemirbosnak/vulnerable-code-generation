//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENTS 10
#define NAME_LENGTH 20
#define SYMBOL_LENGTH 5

typedef struct {
    char name[NAME_LENGTH];
    char symbol[SYMBOL_LENGTH];
    int atomic_number;
} Element;

void initialize_elements(Element elements[]) {
    // Sample elements
    strcpy(elements[0].name, "Hydrogen");
    strcpy(elements[0].symbol, "H");
    elements[0].atomic_number = 1;
    
    strcpy(elements[1].name, "Helium");
    strcpy(elements[1].symbol, "He");
    elements[1].atomic_number = 2;

    strcpy(elements[2].name, "Lithium");
    strcpy(elements[2].symbol, "Li");
    elements[2].atomic_number = 3;

    strcpy(elements[3].name, "Beryllium");
    strcpy(elements[3].symbol, "Be");
    elements[3].atomic_number = 4;

    strcpy(elements[4].name, "Boron");
    strcpy(elements[4].symbol, "B");
    elements[4].atomic_number = 5;

    strcpy(elements[5].name, "Carbon");
    strcpy(elements[5].symbol, "C");
    elements[5].atomic_number = 6;

    strcpy(elements[6].name, "Nitrogen");
    strcpy(elements[6].symbol, "N");
    elements[6].atomic_number = 7;

    strcpy(elements[7].name, "Oxygen");
    strcpy(elements[7].symbol, "O");
    elements[7].atomic_number = 8;

    strcpy(elements[8].name, "Fluorine");
    strcpy(elements[8].symbol, "F");
    elements[8].atomic_number = 9;

    strcpy(elements[9].name, "Neon");
    strcpy(elements[9].symbol, "Ne");
    elements[9].atomic_number = 10;
}

void display_welcome_message() {
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("Test your knowledge of the elements!\n");
    printf("You will be given different types of questions.\n");
    printf("Let’s see how many you can answer correctly!\n\n");
}

void quiz_user(Element elements[], int num_questions) {
    int score = 0;
    srand(time(NULL));

    for (int i = 0; i < num_questions; i++) {
        int question_type = rand() % 3; // 0: Name, 1: Symbol, 2: Atomic Number
        int idx = rand() % MAX_ELEMENTS; // Randomly select an element
        Element elem = elements[idx];

        char answer[NAME_LENGTH];
        switch (question_type) {
            case 0: // Ask for the name
                printf("What is the name of the element with atomic number %d? ", elem.atomic_number);
                scanf("%s", answer);
                if (strcmp(answer, elem.name) == 0) {
                    printf("Correct!\n\n");
                    score++;
                } else {
                    printf("Wrong! The correct answer is %s.\n\n", elem.name);
                }
                break;

            case 1: // Ask for the symbol
                printf("What is the symbol for the element %s? ", elem.name);
                scanf("%s", answer);
                if (strcmp(answer, elem.symbol) == 0) {
                    printf("Correct!\n\n");
                    score++;
                } else {
                    printf("Wrong! The correct answer is %s.\n\n", elem.symbol);
                }
                break;

            case 2: // Ask for the atomic number
                printf("What is the atomic number of %s? ", elem.name);
                int atomic_answer;
                scanf("%d", &atomic_answer);
                if (atomic_answer == elem.atomic_number) {
                    printf("Correct!\n\n");
                    score++;
                } else {
                    printf("Wrong! The correct atomic number is %d.\n\n", elem.atomic_number);
                }
                break;
        }
    }

    printf("Your final score is: %d out of %d\n", score, num_questions);
}

int main() {
    Element elements[MAX_ELEMENTS];
    initialize_elements(elements);
    display_welcome_message();

    int num_questions = 5; // Number of questions to ask
    quiz_user(elements, num_questions);

    printf("Thank you for playing the Periodic Table Quiz!\n");
    return 0;
}