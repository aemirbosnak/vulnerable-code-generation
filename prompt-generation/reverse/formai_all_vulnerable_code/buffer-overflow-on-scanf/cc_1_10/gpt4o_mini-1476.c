//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 118

typedef struct {
    char name[30];
    char symbol[3];
    int atomicNumber;
    float atomicWeight;
} Element;

Element periodicTable[MAX_ELEMENTS];

// Function to initialize the periodic table
void initializePeriodicTable() {
    // Filling the periodic table with some elements as a demonstration
    strcpy(periodicTable[0].name, "Hydrogen");
    strcpy(periodicTable[0].symbol, "H");
    periodicTable[0].atomicNumber = 1;
    periodicTable[0].atomicWeight = 1.008;

    strcpy(periodicTable[1].name, "Helium");
    strcpy(periodicTable[1].symbol, "He");
    periodicTable[1].atomicNumber = 2;
    periodicTable[1].atomicWeight = 4.0026;

    // ... You can fill it out till MAX_ELEMENTS or leave it for demonstration
    // Adding a few more elements for fun
    strcpy(periodicTable[6].name, "Carbon");
    strcpy(periodicTable[6].symbol, "C");
    periodicTable[6].atomicNumber = 6;
    periodicTable[6].atomicWeight = 12.011;

    strcpy(periodicTable[7].name, "Nitrogen");
    strcpy(periodicTable[7].symbol, "N");
    periodicTable[7].atomicNumber = 7;
    periodicTable[7].atomicWeight = 14.007;

    strcpy(periodicTable[8].name, "Oxygen");
    strcpy(periodicTable[8].symbol, "O");
    periodicTable[8].atomicNumber = 8;
    periodicTable[8].atomicWeight = 15.999;

    // More can be added accordingly
}

// Function to print the element details
void printElementDetails(Element element) {
    printf("Name: %s\n", element.name);
    printf("Symbol: %s\n", element.symbol);
    printf("Atomic Number: %d\n", element.atomicNumber);
    printf("Atomic Weight: %.3f\n", element.atomicWeight);
}

// Function to conduct the quiz
void conductQuiz() {
    int correctAnswers = 0, totalQuestions = 5;
    char userAnswer[3];
    
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("Try to answer the following questions.\n\n");

    // Sample questions based on elements
    for (int i = 0; i < totalQuestions; ++i) {
        if (i == 0) {
            printf("Question 1: What is the symbol of Oxygen?\n");
            printf("Your answer: ");
            scanf("%s", userAnswer);
            if (strcmp(userAnswer, periodicTable[8].symbol) == 0) {
                printf("Correct!\n");
                correctAnswers++;
            } else {
                printf("Wrong! The correct answer is %s.\n", periodicTable[8].symbol);
            }
        } else if (i == 1) {
            printf("Question 2: What is the atomic number of Hydrogen?\n");
            printf("Your answer: ");
            scanf("%d", &userAnswer[0]);
            if (userAnswer[0] == periodicTable[0].atomicNumber) {
                printf("Correct!\n");
                correctAnswers++;
            } else {
                printf("Wrong! The correct answer is %d.\n", periodicTable[0].atomicNumber);
            }
        } else if (i == 2) {
            printf("Question 3: What is the atomic weight of Carbon?\n");
            printf("Your answer: ");
            scanf("%s", userAnswer);
            if (atof(userAnswer) == periodicTable[6].atomicWeight) {
                printf("Correct!\n");
                correctAnswers++;
            } else {
                printf("Wrong! The correct answer is %.3f.\n", periodicTable[6].atomicWeight);
            }
        }
        // Add more questions...
    }

    printf("\nYou answered %d out of %d correctly!\n", correctAnswers, totalQuestions);
}

// Main function
int main() {
    // Initialize periodic table
    initializePeriodicTable();
    
    // Give a warm welcome
    printf("Welcome to the Periodic Table Explorer!\n");
    printf("Dive into the realm of elements and test your knowledge!\n\n");

    // Conduct the quiz
    conductQuiz();

    printf("Thank you for playing the quiz! Until next time, stay curious!\n");
    
    return 0;
}