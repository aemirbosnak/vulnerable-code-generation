//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ELEMENT_COUNT 10

typedef struct {
    char name[30];
    char symbol[3];
    int atomicNumber;
} Element;

// In a world of flickering stars and swirling thoughts, behold the elements
Element elements[ELEMENT_COUNT] = {
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

void printIntroduction() {
    printf("Welcome to the Cosmic Periodic Table Quiz!\n");
    printf("In this dreamlike landscape, you shall explore the wonders of the elements.\n");
    printf("Answer the questions wisely, for the universe awaits your brilliance!\n\n");
}

void printElement(Element element) {
    printf("Element [%d]: %s (Symbol: %s)\n", element.atomicNumber, element.name, element.symbol);
}

int askQuestion(Element element) {
    char answer[3];
    printf("What is the symbol for the element with atomic number %d? ", element.atomicNumber);
    scanf("%s", answer);
    
    if (strcmp(answer, element.symbol) == 0) {
        printf("Correct! The cosmos grants you knowledge.\n\n");
        return 1;
    } else {
        printf("Alas, the stars have misled you. The correct symbol is %s.\n\n", element.symbol);
        return 0;
    }
}

void shuffleElements() {
    srand(time(NULL));
    for (int i = ELEMENT_COUNT - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Element temp = elements[i];
        elements[i] = elements[j];
        elements[j] = temp;
    }
}

int main() {
    printIntroduction();
    
    shuffleElements(); // Shuffle the elements like a surrealist dream
    int score = 0;
    
    for (int i = 0; i < ELEMENT_COUNT; i++) {
        printElement(elements[i]);
        score += askQuestion(elements[i]);
    }
    
    printf("You journeyed through the periodic cosmos and scored: %d out of %d!\n", score, ELEMENT_COUNT);
    printf("Reflect upon your score, for it is but a fragment of the universe.\n");
    printf("May the knowledge of the elements swirl around you like a comforting nebula!\n");
    
    return 0;
}