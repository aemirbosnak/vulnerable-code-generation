//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ELEMENT_COUNT 118

typedef struct {
    char name[20];
    char symbol[3];
    int atomicNumber;
    char category[30];
} Element;

Element periodicTable[ELEMENT_COUNT] = {
    {"Hydrogen", "H", 1, "Non-metal"},
    {"Helium", "He", 2, "Noble gas"},
    {"Lithium", "Li", 3, "Alkali metal"},
    {"Beryllium", "Be", 4, "Alkaline earth metal"},
    // Skipping some elements for brevity...
    {"Boron", "B", 5, "Metalloid"},
    {"Carbon", "C", 6, "Non-metal"},
    {"Nitrogen", "N", 7, "Non-metal"},
    {"Oxygen", "O", 8, "Non-metal"},
    {"Fluorine", "F", 9, "Non-metal"},
    {"Neon", "Ne", 10, "Noble gas"},
    // Continue filling in all elements ...
    {"Aluminum", "Al", 13, "Post-transition metal"},
    {"Silicon", "Si", 14, "Metalloid"},
    // ...
    {"Uranium", "U", 92, "Actinide"},
    {"Plutonium", "Pu", 94, "Actinide"},
    // Adding a few more ...
    {"Oganesson", "Og", 118, "Noble gas"},
};

void displayWelcome(){
    printf("***************************************\n");
    printf("* Welcome to the Periodic Table Quiz! *\n");
    printf("***************************************\n\n");
    printf("Test your knowledge about the elements!\n\n");
}

void displayElements() {
    printf("Here are the elements available:\n");
    for (int i = 0; i < ELEMENT_COUNT; i++) {
        if (strlen(periodicTable[i].name) > 0) {
            printf("%d: %s (%s)\n", periodicTable[i].atomicNumber, periodicTable[i].name, periodicTable[i].symbol);
        }
    }
    printf("\n");
}

int getQuizQuestion() {
    return rand() % ELEMENT_COUNT; // Randomly select an element
}

void askQuestion(int index) {
    char userAnswer[20];
    printf("What is the symbol for the element %s? (Atomic Number: %d)\n", periodicTable[index].name, periodicTable[index].atomicNumber);
    printf("Your answer: ");
    scanf("%s", userAnswer);
    
    // Check the answer
    if (strcasecmp(userAnswer, periodicTable[index].symbol) == 0) {
        printf("Correct! 🎉\n\n");
    } else {
        printf("Incorrect! The correct answer is %s.\n\n", periodicTable[index].symbol);
    }
}

int main() {
    int quizCount = 5; // Number of questions to ask
    int score = 0;

    // Seed random number generator
    srand((unsigned int)time(NULL));

    displayWelcome();
    
    for (int i = 0; i < quizCount; i++) {
        int elementIndex = getQuizQuestion();
        askQuestion(elementIndex);
    }

    printf("Thank you for playing the Periodic Table Quiz!\n");
    return 0;
}