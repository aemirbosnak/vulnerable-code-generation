//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_ELEMENTS 10

typedef struct {
    char name[20];
    char symbol[3];
    int atomic_number;
} Element;

// Sample elements for the quiz
Element elements[NUM_ELEMENTS] = {
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

void clearBuffer() {
    while (getchar() != '\n'); // Clear input buffer
}

void askQuestion(Element el, int questionType) {
    char userInput[30];

    switch (questionType) {
    case 0: // Question about name
        printf("What is the atomic symbol of %s? ", el.name);
        scanf("%s", userInput);
        break;
    case 1: // Question about symbol
        printf("What is the atomic number of element %s? ", el.symbol);
        scanf("%d", (int*)&userInput);
        break;
    case 2: // Question about atomic number
        printf("What is the name of the element with atomic number %d? ", el.atomic_number);
        scanf("%s", userInput);
        break;
    }

    // Check the answer
    if ((questionType == 0 && strcmp(userInput, el.symbol) == 0) ||
        (questionType == 1 && atoi(userInput) == el.atomic_number) ||
        (questionType == 2 && strcmp(userInput, el.name) == 0)) {
        printf("Correct!\n");
    } else {
        printf("Wrong! The correct answer is: ");
        if (questionType == 0)
            printf("%s\n", el.symbol);
        else if (questionType == 1)
            printf("%d\n", el.atomic_number);
        else
            printf("%s\n", el.name);
    }
}

int main() {
    srand(time(NULL)); // Seed for random number generation
    int score = 0;
    int rounds = 5;
    
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will answer %d questions.\n", rounds);
    printf("Get ready!\n\n");

    for (int i = 0; i < rounds; i++) {
        int randomIndex = rand() % NUM_ELEMENTS;
        int questionType = rand() % 3; // Randomly select question type
        
        askQuestion(elements[randomIndex], questionType);
        printf("-----------------------------\n");
    }

    printf("\nThank you for playing! Your total score is: %d out of %d\n", score, rounds);
    return 0;
}