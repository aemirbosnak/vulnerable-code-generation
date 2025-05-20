//Falcon2-11B DATASET v1.0 Category: Periodic Table Quiz ; Style: visionary
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void quiz(int atomicNumber, char* symbol);

int main() {
    int atomicNumber;
    char symbol[20];

    printf("Welcome to the C Periodic Table Quiz!\n");
    printf("Enter the atomic number of the element you think matches the given atomic number: ");
    scanf("%d", &atomicNumber);
    printf("Enter the symbol of the element: ");
    scanf("%s", symbol);

    quiz(atomicNumber, symbol);

    return 0;
}

void quiz(int atomicNumber, char* symbol) {
    bool correctAnswer = false;
    int correctElement = 0;

    if (strcmp(symbol, "H") == 0) {
        correctElement = 1;
    }
    else if (strcmp(symbol, "He") == 0) {
        correctElement = 2;
    }
    else if (strcmp(symbol, "Li") == 0) {
        correctElement = 3;
    }
    else if (strcmp(symbol, "Be") == 0) {
        correctElement = 4;
    }
    else if (strcmp(symbol, "B") == 0) {
        correctElement = 5;
    }
    else if (strcmp(symbol, "C") == 0) {
        correctElement = 6;
    }
    else if (strcmp(symbol, "N") == 0) {
        correctElement = 7;
    }
    else if (strcmp(symbol, "O") == 0) {
        correctElement = 8;
    }
    else if (strcmp(symbol, "F") == 0) {
        correctElement = 9;
    }
    else if (strcmp(symbol, "Ne") == 0) {
        correctElement = 10;
    }
    else if (strcmp(symbol, "Na") == 0) {
        correctElement = 11;
    }
    else if (strcmp(symbol, "Mg") == 0) {
        correctElement = 12;
    }
    else if (strcmp(symbol, "Al") == 0) {
        correctElement = 13;
    }
    else if (strcmp(symbol, "Si") == 0) {
        correctElement = 14;
    }
    else if (strcmp(symbol, "P") == 0) {
        correctElement = 15;
    }
    else if (strcmp(symbol, "S") == 0) {
        correctElement = 16;
    }
    else if (strcmp(symbol, "Cl") == 0) {
        correctElement = 17;
    }
    else if (strcmp(symbol, "Ar") == 0) {
        correctElement = 18;
    }
    else {
        printf("Invalid symbol!\n");
        correctAnswer = false;
    }

    if (correctElement == atomicNumber) {
        printf("Correct!\n");
        correctAnswer = true;
    }

    if (correctAnswer) {
        printf("You guessed it!\n");
    }
    else {
        printf("Incorrect!\n");
    }

    int userAnswer = 0;
    char userSymbol[20];
    printf("Do you want to play again? (y/n): ");
    scanf(" %c", &userAnswer);

    if (userAnswer == 'y') {
        quiz(atomicNumber, symbol);
    }
    else {
        printf("Thanks for playing!\n");
    }
}