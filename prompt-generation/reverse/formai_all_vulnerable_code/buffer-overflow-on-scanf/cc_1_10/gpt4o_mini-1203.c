//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>

#define MAX_ELEMENTS 10
#define MAX_NAME_LENGTH 20

typedef struct {
    char symbol[3];
    char name[MAX_NAME_LENGTH];
    int atomicNumber;
} Element;

Element elements[MAX_ELEMENTS] = {
    {"H", "Hydrogen", 1},
    {"He", "Helium", 2},
    {"Li", "Lithium", 3},
    {"Be", "Beryllium", 4},
    {"B", "Boron", 5},
    {"C", "Carbon", 6},
    {"N", "Nitrogen", 7},
    {"O", "Oxygen", 8},
    {"F", "Fluorine", 9},
    {"Ne", "Neon", 10}
};

void printInstructions() {
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be asked to identify the atomic number of a given element symbol.\n");
    printf("Type your answer and press Enter. Type 'exit' to quit the quiz.\n\n");
}

int getElementIndex(char *symbol) {
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        if (strcmp(elements[i].symbol, symbol) == 0) {
            return i;
        }
    }
    return -1; // Not found
}

void startQuiz() {
    char input[100];
    while (1) {
        printf("Enter an element symbol (like H, He) or 'exit' to quit: ");
        scanf("%s", input);
        
        if (strcmp(input, "exit") == 0) {
            break;
        }

        int idx = getElementIndex(input);
        if (idx >= 0) {
            int userAnswer;
            printf("What is the atomic number of %s? ", elements[idx].name);
            scanf("%d", &userAnswer);
            
            if (userAnswer == elements[idx].atomicNumber) {
                printf("Correct! %s has atomic number %d.\n\n", elements[idx].name, elements[idx].atomicNumber);
            } else {
                printf("Incorrect! The correct atomic number is %d.\n\n", elements[idx].atomicNumber);
            }
        } else {
            printf("Element not found! Please try again.\n\n");
        }
    }
}

int main() {
    printInstructions();
    startQuiz();
    printf("Thanks for playing the Periodic Table Quiz!\n");
    return 0;
}