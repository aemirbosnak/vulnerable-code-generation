//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ELEMENTS 10
#define MAX_NAME_LENGTH 20
#define MAX_SYMBOL_LENGTH 3

typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
} Element;

Element elements[MAX_ELEMENTS] = {
    {"Hydrogen", "H"},
    {"Helium", "He"},
    {"Lithium", "Li"},
    {"Beryllium", "Be"},
    {"Carbon", "C"},
    {"Nitrogen", "N"},
    {"Oxygen", "O"},
    {"Fluorine", "F"},
    {"Neon", "Ne"},
    {"Sodium", "Na"}
};

void shuffleElements(int n) {
    srand(time(NULL));
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Element temp = elements[i];
        elements[i] = elements[j];
        elements[j] = temp;
    }
}

int quizUser(int questionIndex) {
    int answerCorrect = 0;
    char userAnswer[MAX_SYMBOL_LENGTH];

    printf("What is the symbol for %s? ", elements[questionIndex].name);
    scanf("%s", userAnswer);

    if (strcmp(userAnswer, elements[questionIndex].symbol) == 0) {
        printf("Correct! You must be a chemist or a wizard!\n");
        answerCorrect = 1;
    } else {
        printf("Oops! The correct answer is: %s\n", elements[questionIndex].symbol);
        printf("Don't worry, you'll get it next time! Maybe with a little potion!\n");
    }

    return answerCorrect;
}

void displayScore(int score, int totalQuestions) {
    printf("\nYour score: %d out of %d\n", score, totalQuestions);
    if (score == totalQuestions) {
        printf("You're a periodic table genius! Have you been studying alchemy?\n");
    } else if (score > totalQuestions / 2) {
        printf("Good job! But you can do better, keep at it!\n");
    } else {
        printf("Looks like you need a little more practice. Time to hit the books!\n");
    }
}

int main() {
    int totalQuestions = MAX_ELEMENTS;
    int score = 0;

    printf("Welcome to the Mind-Bending Periodic Table Quiz!\n");
    printf("Beware, knowledge of the elements can lead to extraordinary things!\n");
    printf("Let's see if you can match these elements with their symbols...\n\n");

    shuffleElements(MAX_ELEMENTS);

    for (int i = 0; i < totalQuestions; i++) {
        score += quizUser(i);
    }

    displayScore(score, totalQuestions);
    printf("Thank you for playing! Remember: every atom in your body was born in a star!\n");

    return 0;
}