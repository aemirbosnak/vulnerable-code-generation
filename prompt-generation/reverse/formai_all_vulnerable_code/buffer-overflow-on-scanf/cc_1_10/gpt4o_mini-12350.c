//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 10

// Struct for an element's question
typedef struct {
    char name[20];      // Name of the element
    char symbol[3];    // Symbol of the element
    int atomicNumber;   // Atomic number of the element
} Element;

Element elements[] = {
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

// Function to display instructions
void displayInstructions() {
    printf("=== Welcome to the Post-Apocalyptic Periodic Table Quiz ===\n");
    printf("In this desolate wasteland, only the wise shall survive.\n");
    printf("Answer the following questions about the elements.\n");
    printf("You have %d questions.\n\n", MAX_QUESTIONS);
    printf("Type the correct element's symbol and press Enter.\n\n");
}

// Function to generate a random question
void generateQuestion(Element *element) {
    int index = rand() % (sizeof(elements) / sizeof(elements[0]));
    *element = elements[index];
}

// Function to collect user answer and provide feedback
int askQuestion(Element element) {
    char userAnswer[3];
    printf("Question: What is the symbol for %s? ", element.name);
    scanf("%s", userAnswer);
    return strcmp(userAnswer, element.symbol) == 0;
}

// Function to run the quiz
void runQuiz() {
    srand(time(NULL));
    Element element;
    int score = 0;

    for (int i = 0; i < MAX_QUESTIONS; i++) {
        generateQuestion(&element);
        if (askQuestion(element)) {
            printf("Correct!\n\n");
            score++;
        } else {
            printf("Incorrect! The correct answer was: %s\n\n", element.symbol);
        }
    }

    printf("Quiz over! Your score: %d/%d\n", score, MAX_QUESTIONS);
    if (score == MAX_QUESTIONS) {
        printf("You possess elemental knowledge worthy of the old world!\n");
    } else if (score >= MAX_QUESTIONS / 2) {
        printf("You are well on your way to mastering the elements!\n");
    } else {
        printf("The elements elude your grasp... Study harder!\n");
    }
}

// Main function
int main() {
    displayInstructions();
    runQuiz();
    return 0;
}