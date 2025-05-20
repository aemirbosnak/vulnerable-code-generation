//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ELEMENTS 10

// Structure to hold information about an element
typedef struct {
    char name[20];
    char symbol[3];
    int atomicNumber;
} Element;

// Function to initialize the periodic table with a few elements
void initializePeriodicTable(Element *elements) {
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

// Function to display the periodic table
void displayPeriodicTable(Element *elements) {
    printf("Periodic Table of Elements (First 10 Elements):\n");
    printf("--------------------------------------------------\n");
    printf("No. | Symbol |        Name         \n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < ELEMENTS; i++) {
        printf("%-3d | %-6s | %-20s \n", 
               elements[i].atomicNumber,
               elements[i].symbol,
               elements[i].name);
    }
    printf("--------------------------------------------------\n");
}

// Function to ask quiz questions
void askQuiz(Element *elements) {
    int score = 0;
    int totalQuestions = 5;
    srand(time(0));
    
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be asked %d random questions about the first 10 elements.\n", totalQuestions);
    
    for (int i = 0; i < totalQuestions; i++) {
        int randomIndex = rand() % ELEMENTS;
        Element currentElement = elements[randomIndex];

        printf("\nQuestion %d: What is the symbol of %s? ", 
               i + 1, currentElement.name);
        char userAnswer[3];
        scanf("%s", userAnswer);

        // Check if the answer is correct
        if (strcmp(userAnswer, currentElement.symbol) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect! The correct answer is %s.\n", currentElement.symbol);
        }
    }

    printf("\nYour total score: %d out of %d\n", score, totalQuestions);
}

// Main Function
int main() {
    Element elements[ELEMENTS];

    // Initialize the periodic table
    initializePeriodicTable(elements);

    // Display periodic table
    displayPeriodicTable(elements);

    // Start the quiz
    askQuiz(elements);

    return 0;
}