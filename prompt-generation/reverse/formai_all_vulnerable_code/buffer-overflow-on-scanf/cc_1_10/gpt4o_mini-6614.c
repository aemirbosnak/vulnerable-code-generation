//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ELEMENTS 10
#define MAX_QUE 5
#define BUFFER_SIZE 100

typedef struct {
    char name[BUFFER_SIZE];
    char symbol[BUFFER_SIZE];
    int atomicNumber;
} Element;

Element elements[MAX_ELEMENTS] = {
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

void clearScreen() {
    // Clear the screen for a fresh appearance
    printf("\033[H\033[J");
}

void displayWelcome() {
    clearScreen();
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("Test your knowledge about elements.\n\n");
    printf("Press 'Enter' to start the quiz...\n");
    getchar(); // Wait for user to press Enter
}

void shuffleElements(int* order) {
    for(int i = 0; i < MAX_ELEMENTS; i++) {
        order[i] = i;
    }
    for(int i = 0; i < MAX_ELEMENTS; i++) {
        int j = rand() % MAX_ELEMENTS;
        int temp = order[i];
        order[i] = order[j];
        order[j] = temp;
    }
}

void askQuestion(int index) {
    printf("What is the atomic symbol of %s? ", elements[index].name);
}

void getAnswer(int index, char* answer) {
    printf("Your answer: ");
    scanf("%s", answer);
}

void evaluateAnswer(int index, const char* answer) {
    if (strcasecmp(answer, elements[index].symbol) == 0) {
        printf("Correct!\n\n");
    } else {
        printf("Wrong! The correct answer is %s.\n\n", elements[index].symbol);
    }
}

void startQuiz() {
    int order[MAX_ELEMENTS];
    char answer[BUFFER_SIZE];
    int score = 0;

    printf("Starting the quiz...\n\n");
    shuffleElements(order);

    for (int i = 0; i < MAX_QUE; i++) {
        askQuestion(order[i]);
        getAnswer(order[i], answer);
        evaluateAnswer(order[i], answer);
    
        // Scoring
        if (strcasecmp(answer, elements[order[i]].symbol) == 0) {
            score++;
        }
    }
    printf("Your total score: %d out of %d\n", score, MAX_QUE);
}

void displayGoodbye() {
    printf("Thank you for participating in the Periodic Table Quiz!\n");
    printf("Goodbye!\n");
}

int main() {
    srand(time(0)); // Seed for randomness
    displayWelcome();
    startQuiz();
    displayGoodbye();

    return 0;
}