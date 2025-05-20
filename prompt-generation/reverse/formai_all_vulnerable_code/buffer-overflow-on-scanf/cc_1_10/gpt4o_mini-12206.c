//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ELEMENTS_COUNT 118
#define MAX_NAME_LENGTH 20
#define MAX_SYMBOL_LENGTH 3

typedef struct {
    int atomicNumber;
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    float atomicWeight;
} Element;

Element periodicTable[ELEMENTS_COUNT] = {
    {1, "Hydrogen", "H", 1.008},
    {2, "Helium", "He", 4.002602},
    {3, "Lithium", "Li", 6.94},
    {4, "Beryllium", "Be", 9.0122},
    {5, "Boron", "B", 10.81},
    {6, "Carbon", "C", 12.011},
    {7, "Nitrogen", "N", 14.007},
    {8, "Oxygen", "O", 15.999},
    {9, "Fluorine", "F", 18.998},
    {10, "Neon", "Ne", 20.180},
    // ... all other elements ...
    {118, "Oganesson", "Og", 294}
};

void printQuestion(int number);
int getAnswer(int atomicNumber);
float calculateAverageWeight();

int main() {
    int score = 0;
    int numberOfQuestions = 10;

    printf("Welcome to the Periodic Table Quiz!\n\n");

    for (int i = 0; i < numberOfQuestions; i++) {
        int atomicNumber = rand() % ELEMENTS_COUNT + 1; // Random atomic number
        printQuestion(atomicNumber);
        int answer = getAnswer(atomicNumber);

        if (answer == atomicNumber) {
            score++;
            printf("Correct!\n\n");
        } else {
            printf("Wrong! The correct answer was %d (%s)\n\n", atomicNumber, periodicTable[atomicNumber - 1].name);
        }
    }

    printf("Quiz finished! Your score: %d/%d\n", score, numberOfQuestions);
    printf("Average Atomic Weight of All Elements: %.2f\n", calculateAverageWeight());

    return 0;
}

void printQuestion(int number) {
    printf("What is the atomic number of %s? ", periodicTable[number - 1].name);
}

int getAnswer(int atomicNumber) {
    int userAnswer;
    printf("Your answer: ");
    scanf("%d", &userAnswer);
    return userAnswer;
}

float calculateAverageWeight() {
    float totalWeight = 0;

    for (int i = 0; i < ELEMENTS_COUNT; i++) {
        totalWeight += periodicTable[i].atomicWeight;
    }

    return totalWeight / ELEMENTS_COUNT;
}