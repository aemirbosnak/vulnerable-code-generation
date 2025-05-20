//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

#define MAX_ELEMENTS 10

typedef struct {
    char name[20];
    char symbol[3];
    int atomicNumber;
} Element;

void initializeElements(Element elements[]) {
    // Initialize the periodic table elements for the quiz
    strcpy(elements[0].name, "Hydrogen");
    strcpy(elements[0].symbol, "H");
    elements[0].atomicNumber = 1;

    strcpy(elements[1].name, "Helium");
    strcpy(elements[1].symbol, "He");
    elements[1].atomicNumber = 2;

    strcpy(elements[2].name, "Lithium");
    strcpy(elements[2].symbol, "Li");
    elements[2].atomicNumber = 3;

    strcpy(elements[3].name, "Beryllium");
    strcpy(elements[3].symbol, "Be");
    elements[3].atomicNumber = 4;

    strcpy(elements[4].name, "Boron");
    strcpy(elements[4].symbol, "B");
    elements[4].atomicNumber = 5;

    strcpy(elements[5].name, "Carbon");
    strcpy(elements[5].symbol, "C");
    elements[5].atomicNumber = 6;

    strcpy(elements[6].name, "Nitrogen");
    strcpy(elements[6].symbol, "N");
    elements[6].atomicNumber = 7;

    strcpy(elements[7].name, "Oxygen");
    strcpy(elements[7].symbol, "O");
    elements[7].atomicNumber = 8;

    strcpy(elements[8].name, "Fluorine");
    strcpy(elements[8].symbol, "F");
    elements[8].atomicNumber = 9;

    strcpy(elements[9].name, "Neon");
    strcpy(elements[9].symbol, "Ne");
    elements[9].atomicNumber = 10;
}

void askQuestion(int index, Element element) {
    printf("%d. What is the symbol of %s? ", index+1, element.name);
}

void askAtomicNumberQuestion(int index, Element element) {
    printf("%d. What is the atomic number of %s? ", index+1, element.name);
}

int main() {
    Element elements[MAX_ELEMENTS];
    initializeElements(elements);

    int score = 0;
    char answer[3];
    
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be asked questions about the first 10 elements.\n\n");

    // Quiz for symbols
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        askQuestion(i, elements[i]);
        scanf("%s", answer);
        
        if (strcmp(answer, elements[i].symbol) == 0) {
            printf("Correct!\n\n");
            score++;
        } else {
            printf("Incorrect! The correct symbol is: %s\n\n", elements[i].symbol);
        }
    }

    printf("Your score for symbols: %d out of %d\n", score, MAX_ELEMENTS);

    score = 0; // Reset score for atomic number questions
    printf("\nNow let's test your knowledge of atomic numbers!\n\n");

    // Quiz for atomic numbers
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        askAtomicNumberQuestion(i, elements[i]);
        int userAnswer;
        scanf("%d", &userAnswer);

        if (userAnswer == elements[i].atomicNumber) {
            printf("Correct!\n\n");
            score++;
        } else {
            printf("Incorrect! The correct atomic number is: %d\n\n", elements[i].atomicNumber);
        }
    }

    printf("Your score for atomic numbers: %d out of %d\n", score, MAX_ELEMENTS);
    printf("Thank you for participating in the quiz!\n");

    return 0;
}