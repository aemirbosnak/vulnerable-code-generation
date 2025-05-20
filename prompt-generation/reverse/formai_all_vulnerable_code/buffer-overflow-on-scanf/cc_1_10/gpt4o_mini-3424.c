//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 10
#define MAX_NAME_LENGTH 20
#define MAX_QUIZ_QUESTIONS 5

typedef struct {
    char name[MAX_NAME_LENGTH];
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

void display_welcome() {
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("Test your knowledge of the elements!\n");
    printf("You will answer a series of questions based on the periodic table.\n\n");
}

void ask_question(int index) {
    char userAnswer[3];
    
    printf("What is the symbol of %s? ", periodicTable[index].name);
    scanf("%s", userAnswer);
    
    if (strcmp(userAnswer, periodicTable[index].symbol) == 0) {
        printf("Correct!\n\n");
    } else {
        printf("Incorrect! The correct answer is %s.\n\n", periodicTable[index].symbol);
    }
}

void conduct_quiz() {
    printf("Let's begin the quiz!\n\n");
    
    for (int i = 0; i < MAX_QUIZ_QUESTIONS; i++) {
        ask_question(i);
    }

    printf("Quiz finished! Thank you for participating.\n");
}

int main() {
    display_welcome();
    conduct_quiz();
    return 0;
}