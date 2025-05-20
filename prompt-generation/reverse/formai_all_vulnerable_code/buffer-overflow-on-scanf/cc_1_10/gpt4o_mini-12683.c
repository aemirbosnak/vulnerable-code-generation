//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 10

typedef struct {
    char name[30];
    char symbol[3];
} Element;

Element elements[MAX_ELEMENTS] = {
    {"Hydrogen", "H"},
    {"Helium", "He"},
    {"Lithium", "Li"},
    {"Beryllium", "Be"},
    {"Boron", "B"},
    {"Carbon", "C"},
    {"Nitrogen", "N"},
    {"Oxygen", "O"},
    {"Fluorine", "F"},
    {"Neon", "Ne"}
};

int askQuestion(int index) {
    char answer[3];
    printf("What is the chemical symbol for %s? ", elements[index].name);
    scanf("%s", answer);
    
    if (strcmp(answer, elements[index].symbol) == 0) {
        printf("Correct!\n\n");
        return 1;
    } else {
        printf("Incorrect! The correct answer is %s.\n\n", elements[index].symbol);
        return 0;
    }
}

void printScore(int score) {
    printf("You scored %d out of %d.\n", score, MAX_ELEMENTS);
    if (score == MAX_ELEMENTS) {
        printf("Excellent! You're a chemistry whiz!\n");
    } else if (score >= MAX_ELEMENTS / 2) {
        printf("Good job! Keep studying!\n");
    } else {
        printf("Don't give up! Try again!\n");
    }
}

int main() {
    int score = 0;
    srand(time(NULL));
    
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be asked to provide the chemical symbol for 10 elements.\n");
    printf("Let's get started!\n\n");

    for (int i = 0; i < MAX_ELEMENTS; i++) {
        int randomIndex = rand() % MAX_ELEMENTS;
        score += askQuestion(randomIndex);
    }

    printScore(score);
    return 0;
}