//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: imaginative
#include <stdio.h>
#include <string.h>

#define MAX_ELEMENTS 10

typedef struct {
    char name[20];
    char symbol[3];
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

void welcomeMessage() {
    printf("=== Welcome to the Elemental Quest! ===\n");
    printf("Test your knowledge of the periodic table!\n");
    printf("You will answer questions about various elements!\n");
    printf("==================================================================\n");
}

void displayElement(Element elem) {
    printf("Element: %s, Symbol: %s, Atomic Number: %d\n", elem.name, elem.symbol, elem.atomicNumber);
}

int askQuestion(Element elem) {
    printf("\nWhat is the symbol of %s? ", elem.name);
    
    char answer[3];
    scanf("%s", answer);
    
    if (strcmp(answer, elem.symbol) == 0) {
        printf("Correct!\n");
        return 1; // Correct answer
    } else {
        printf("Wrong! The correct symbol is %s.\n", elem.symbol);
        return 0; // Incorrect answer
    }
}

void elementalQuest() {
    int score = 0;
    int totalQuestions = MAX_ELEMENTS;

    for (int i = 0; i < totalQuestions; i++) {
        score += askQuestion(periodicTable[i]);
    }

    printf("\n=== Quest Complete! ===\n");
    printf("Your total score: %d out of %d\n", score, totalQuestions);
    
    if (score == totalQuestions) {
        printf("Congratulations! You are an Elemental Master!\n");
    } else if (score >= totalQuestions / 2) {
        printf("Great job! You are on your way to mastering the elements!\n");
    } else {
        printf("Keep learning, young chemist! The elements await!\n");
    }
}

int main() {
    welcomeMessage();
    elementalQuest();
    return 0;
}