//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the number of elements in the periodic table
#define ELEMENTS_COUNT 10

// Structure to hold element data
typedef struct {
    char name[20];
    char symbol[3];
    int atomicNumber;
    float atomicWeight;
} Element;

// Function declarations
void initializeElements(Element elements[]);
void displayElements(const Element elements[]);
int quizUser(const Element elements[]);
void clearInputBuffer();

int main() {
    Element elements[ELEMENTS_COUNT];
    initializeElements(elements);
    
    int score = quizUser(elements);
    
    printf("\nYour total score: %d out of %d\n", score, ELEMENTS_COUNT);
    return 0;
}

// Initialize elements with some data
void initializeElements(Element elements[]) {
    strcpy(elements[0].name, "Hydrogen");
    strcpy(elements[0].symbol, "H");
    elements[0].atomicNumber = 1;
    elements[0].atomicWeight = 1.008;

    strcpy(elements[1].name, "Helium");
    strcpy(elements[1].symbol, "He");
    elements[1].atomicNumber = 2;
    elements[1].atomicWeight = 4.0026;

    strcpy(elements[2].name, "Lithium");
    strcpy(elements[2].symbol, "Li");
    elements[2].atomicNumber = 3;
    elements[2].atomicWeight = 6.94;

    strcpy(elements[3].name, "Beryllium");
    strcpy(elements[3].symbol, "Be");
    elements[3].atomicNumber = 4;
    elements[3].atomicWeight = 9.0122;

    strcpy(elements[4].name, "Boron");
    strcpy(elements[4].symbol, "B");
    elements[4].atomicNumber = 5;
    elements[4].atomicWeight = 10.81;

    strcpy(elements[5].name, "Carbon");
    strcpy(elements[5].symbol, "C");
    elements[5].atomicNumber = 6;
    elements[5].atomicWeight = 12.011;

    strcpy(elements[6].name, "Nitrogen");
    strcpy(elements[6].symbol, "N");
    elements[6].atomicNumber = 7;
    elements[6].atomicWeight = 14.007;

    strcpy(elements[7].name, "Oxygen");
    strcpy(elements[7].symbol, "O");
    elements[7].atomicNumber = 8;
    elements[7].atomicWeight = 15.999;

    strcpy(elements[8].name, "Fluorine");
    strcpy(elements[8].symbol, "F");
    elements[8].atomicNumber = 9;
    elements[8].atomicWeight = 18.998;

    strcpy(elements[9].name, "Neon");
    strcpy(elements[9].symbol, "Ne");
    elements[9].atomicNumber = 10;
    elements[9].atomicWeight = 20.180;
}

// Function to display the elements
void displayElements(const Element elements[]) {
    printf("Periodic Table Elements:\n");
    for (int i = 0; i < ELEMENTS_COUNT; i++) {
        printf("%d: %s (%s) - Atomic Weight: %.3f\n", 
               elements[i].atomicNumber, 
               elements[i].name, 
               elements[i].symbol, 
               elements[i].atomicWeight);
    }
}

// Function to quiz the user
int quizUser(const Element elements[]) {
    int correctAnswers = 0;
    char answer[3];

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("Answer the following questions:\n\n");

    for (int i = 0; i < ELEMENTS_COUNT; i++) {
        printf("What is the symbol of %s? ", elements[i].name);
        scanf("%s", answer);
        clearInputBuffer();

        if (strcmp(answer, elements[i].symbol) == 0) {
            printf("Correct!\n");
            correctAnswers++;
        } else {
            printf("Wrong! The correct answer is %s.\n", elements[i].symbol);
        }
    }

    return correctAnswers;
}

// Helper function to clear input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}