//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>

#define MAX_ELEMENTS 10
#define MAX_NAME_LENGTH 20

typedef struct {
    char symbol[MAX_NAME_LENGTH];
    char name[MAX_NAME_LENGTH];
    int atomic_number;
} Element;

void initialize_elements(Element elements[]) {
    strcpy(elements[0].symbol, "H");
    strcpy(elements[0].name, "Hydrogen");
    elements[0].atomic_number = 1;

    strcpy(elements[1].symbol, "He");
    strcpy(elements[1].name, "Helium");
    elements[1].atomic_number = 2;

    strcpy(elements[2].symbol, "Li");
    strcpy(elements[2].name, "Lithium");
    elements[2].atomic_number = 3;

    strcpy(elements[3].symbol, "Be");
    strcpy(elements[3].name, "Beryllium");
    elements[3].atomic_number = 4;

    strcpy(elements[4].symbol, "B");
    strcpy(elements[4].name, "Boron");
    elements[4].atomic_number = 5;

    strcpy(elements[5].symbol, "C");
    strcpy(elements[5].name, "Carbon");
    elements[5].atomic_number = 6;

    strcpy(elements[6].symbol, "N");
    strcpy(elements[6].name, "Nitrogen");
    elements[6].atomic_number = 7;

    strcpy(elements[7].symbol, "O");
    strcpy(elements[7].name, "Oxygen");
    elements[7].atomic_number = 8;

    strcpy(elements[8].symbol, "F");
    strcpy(elements[8].name, "Fluorine");
    elements[8].atomic_number = 9;

    strcpy(elements[9].symbol, "Ne");
    strcpy(elements[9].name, "Neon");
    elements[9].atomic_number = 10;
}

void display_quiz(Element elements[], int index) {
    printf("What is the element with the symbol '%s'?\n", elements[index].symbol);
}

int main() {
    Element elements[MAX_ELEMENTS];
    initialize_elements(elements);
    
    int score = 0;
    int answer;
    char user_answer[MAX_NAME_LENGTH];

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be asked questions about the first 10 elements.\n\n");

    for (int i = 0; i < MAX_ELEMENTS; i++) {
        display_quiz(elements, i);
        printf("Your answer: ");
        scanf("%s", user_answer);
        
        // Check answer
        if (strcmp(user_answer, elements[i].name) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect! The correct answer is %s.\n", elements[i].name);
        }
        printf("\n");
    }

    printf("Quiz over! Your final score is: %d out of %d\n", score, MAX_ELEMENTS);
    return 0;
}