//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ELEMENTS 118

typedef struct {
    char symbol[3];
    char name[20];
    int atomicNumber;
    double atomicWeight;
} Element;

Element elements[MAX_ELEMENTS] = {
    {"H", "Hydrogen", 1, 1.008},
    {"He", "Helium", 2, 4.0026},
    {"Li", "Lithium", 3, 6.94},
    {"Be", "Beryllium", 4, 9.0122},
    {"B", "Boron", 5, 10.81},
    {"C", "Carbon", 6, 12.011},
    {"N", "Nitrogen", 7, 14.007},
    {"O", "Oxygen", 8, 15.999},
    {"F", "Fluorine", 9, 18.998},
    {"Ne", "Neon", 10, 20.180},
    // Add more elements as needed
};

void displayElement(Element e) {
    printf("Atomic Number: %d\n", e.atomicNumber);
    printf("Element: %s (%s)\n", e.name, e.symbol);
    printf("Atomic Weight: %.3f\n\n", e.atomicWeight);
}

void askQuestion(Element e) {
    char answer[3];
    printf("What is the symbol for %s? ", e.name);
    scanf("%s", answer);
    
    if (strcasecmp(answer, e.symbol) == 0) {
        printf("Correct!\n\n");
    } else {
        printf("Incorrect! The correct answer is: %s\n\n", e.symbol);
    }
}

int main() {
    srand(time(NULL));
    int score = 0;
    int totalQuestions = 5;
    
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be asked %d random questions about elements.\n", totalQuestions);
    printf("Let's start!\n\n");

    for (int i = 0; i < totalQuestions; i++) {
        int randomIndex = rand() % MAX_ELEMENTS;
        Element randomElement = elements[randomIndex];
        
        printf("Question %d:\n", i + 1);
        askQuestion(randomElement);
    }

    printf("Thanks for playing the Periodic Table Quiz!\n");
    return 0;
}