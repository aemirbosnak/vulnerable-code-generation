//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 10
#define MAX_ELEMENTS 10
#define MAX_NAME_LENGTH 20
#define MAX_SYMBOL_LENGTH 3

typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
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

void shuffleQuestions(Element elements[], int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Element temp = elements[i];
        elements[i] = elements[j];
        elements[j] = temp;
    }
}

void printQuestion(const Element *element) {
    printf("What is the symbol of %s? ", element->name);
}

int checkAnswer(const char *input, const char *correctAnswer) {
    return strcmp(input, correctAnswer) == 0;
}

void startQuiz() {
    srand(time(NULL));
    shuffleQuestions(periodicTable, MAX_ELEMENTS);
    
    int score = 0;
    char answer[MAX_SYMBOL_LENGTH];
    
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be asked %d questions.\n", MAX_QUESTIONS);
    
    for (int i = 0; i < MAX_QUESTIONS && i < MAX_ELEMENTS; i++) {
        printQuestion(&periodicTable[i]);
        scanf("%s", answer);

        if (checkAnswer(answer, periodicTable[i].symbol)) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Wrong! The correct answer is %s.\n", periodicTable[i].symbol);
        }
    }
    
    printf("Quiz completed! Your score: %d out of %d.\n", score, MAX_QUESTIONS);
}

void displayMenu() {
    printf("Periodic Table Quiz Menu:\n");
    printf("1. Start Quiz\n");
    printf("2. Exit\n");
}

int main() {
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                startQuiz();
                break;
            case 2:
                printf("Thank you for playing! Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    } while (choice != 2);

    return 0;
}