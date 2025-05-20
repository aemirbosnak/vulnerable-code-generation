//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ELEMENTS 10
#define MAX_QUESTIONS 5
#define NAME_SIZE 20
#define SYMBOL_SIZE 5

typedef struct {
    char name[NAME_SIZE];
    char symbol[SYMBOL_SIZE];
    int atomicNumber;
} Element;

Element elements[MAX_ELEMENTS] = {
    {"Hydrogen", "H", 1},
    {"Helium", "He", 2},
    {"Lithium", "Li", 3},
    {"Beryllium", "Be", 4},
    {"Carbon", "C", 6},
    {"Nitrogen", "N", 7},
    {"Oxygen", "O", 8},
    {"Fluorine", "F", 9},
    {"Neon", "Ne", 10},
    {"Sodium", "Na", 11},
};

void printQuizInstructions() {
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be asked a series of questions about elements.\n");
    printf("Answer with the correct element name or symbol.\n");
    printf("Type 'exit' to quit the quiz at any time.\n\n");
}

void askQuestion(int index) {
    char answer[NAME_SIZE];
    printf("What is the symbol for %s? ", elements[index].name);
    scanf("%s", answer);
    
    if (strcmp(answer, elements[index].symbol) == 0) {
        printf("Correct!\n\n");
    } else if (strcmp(answer, "exit") == 0) {
        printf("Exiting the quiz. Hope you had fun!\n");
        exit(0);
    } else {
        printf("Wrong! The correct answer is: %s\n\n", elements[index].symbol);
    }
}

int main() {
    srand(time(NULL));
    int score = 0;
    int questionsAsked = 0;
    char choice;

    printQuizInstructions();

    while (questionsAsked < MAX_QUESTIONS) {
        int randomIndex = rand() % MAX_ELEMENTS;
        askQuestion(randomIndex);
        questionsAsked++;
    }

    printf("You completed the quiz! You've answered %d questions.\n", questionsAsked);
    return 0;
}