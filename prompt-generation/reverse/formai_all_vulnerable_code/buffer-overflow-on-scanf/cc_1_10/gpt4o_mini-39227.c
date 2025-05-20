//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ELEMENTS 10
#define MAX_STRING_LENGTH 30

typedef struct {
    char name[MAX_STRING_LENGTH];
    char symbol[MAX_STRING_LENGTH];
    int atomicNumber;
} Element;

Element periodicTable[MAX_ELEMENTS] = {
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

void printInstructions() {
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be asked about the elements of the periodic table.\n");
    printf("Answer the questions by typing the corresponding symbol for the element.\n");
    printf("Let's see how many you can get right!\n");
}

int askQuestion(int index) {
    char answer[MAX_STRING_LENGTH];
    printf("What is the symbol for %s? ", periodicTable[index].name);
    scanf("%s", answer);

    if (strcmp(answer, periodicTable[index].symbol) == 0) {
        printf("Correct!\n");
        return 1;
    } else {
        printf("Incorrect! The correct answer is %s.\n", periodicTable[index].symbol);
        return 0;
    }
}

int main() {
    int score = 0;
    int index, numQuestions = 5;
    int randomIndices[MAX_ELEMENTS];
    srand(time(NULL));

    printInstructions();

    // Generate random indices for questions
    for (int i = 0; i < numQuestions; i++) {
        int randomIndex;
        int unique;

        do {
            unique = 1;
            randomIndex = rand() % MAX_ELEMENTS;

            // Check for uniqueness
            for (int j = 0; j < i; j++) {
                if (randomIndices[j] == randomIndex) {
                    unique = 0;
                    break;
                }
            }
        } while (!unique);

        randomIndices[i] = randomIndex;
    }

    // Ask questions
    for (int i = 0; i < numQuestions; i++) {
        score += askQuestion(randomIndices[i]);
    }

    // Display final score
    printf("You scored %d out of %d!\n", score, numQuestions);

    printf("Thank you for playing the Periodic Table Quiz!\n");
    
    return 0;
}