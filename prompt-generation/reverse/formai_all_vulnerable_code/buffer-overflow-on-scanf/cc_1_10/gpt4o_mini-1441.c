//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ELEMENT_COUNT 10

struct Element {
    char name[20];
    char symbol[3];
    int atomicNumber;
};

struct Element elements[ELEMENT_COUNT] = {
    {"Hydrogen", "H", 1},
    {"Helium", "He", 2},
    {"Lithium", "Li", 3},
    {"Beryllium", "Be", 4},
    {"Boron", "B", 5},
    {"Carbon", "C", 6},
    {"Nitrogen", "N", 7},
    {"Oxygen", "O", 8},
    {"Fluorine", "F", 9},
    {"Neon", "Ne", 10}
};

void printWelcomeMessage() {
    printf("*********************************************************\n");
    printf("           Welcome to the Periodic Table Quiz!           \n");
    printf("*********************************************************\n");
    printf("Test your knowledge of the first 10 elements of the Periodic Table!\n");
    printf("You will be asked to match the atomic symbols with their respective element names.\n");
    printf("Let’s get started!\n\n");
}

void shuffleElements() {
    srand(time(NULL));
    for (int i = ELEMENT_COUNT - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        struct Element temp = elements[i];
        elements[i] = elements[j];
        elements[j] = temp;
    }
}

void askQuestions() {
    int correctAnswers = 0;
    char answer[3];

    for (int i = 0; i < ELEMENT_COUNT; i++) {
        printf("What is the symbol for %s? ", elements[i].name);
        scanf("%s", answer);

        if (strcmp(answer, elements[i].symbol) == 0) {
            printf("Correct!\n");
            correctAnswers++;
        } else {
            printf("Oops! The correct answer is %s.\n", elements[i].symbol);
        }
        printf("\n");
    }

    printf("You got %d out of %d correct.\n", correctAnswers, ELEMENT_COUNT);
}

void showThanks() {
    printf("*********************************************************\n");
    printf("         Thank you for playing the Periodic Table Quiz!  \n");
    printf("       We hope you learned something new today. Bye!     \n");
    printf("*********************************************************\n");
}

int main() {
    printWelcomeMessage();
    shuffleElements();
    askQuestions();
    showThanks();
    return 0;
}