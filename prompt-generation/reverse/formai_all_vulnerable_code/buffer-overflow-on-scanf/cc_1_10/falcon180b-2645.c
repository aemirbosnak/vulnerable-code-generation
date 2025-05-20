//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of elements in the periodic table
#define ELEMENT_COUNT 118

// Define the structure for an element
typedef struct {
    char name[3];
    int atomicNumber;
    char symbol;
} Element;

// Function to generate a random element
Element generateRandomElement() {
    Element element;
    element.atomicNumber = rand() % ELEMENT_COUNT + 1; // Generate a random atomic number between 1 and 118
    switch (element.atomicNumber) {
        case 1:
            strcpy(element.name, "H");
            strcpy(element.symbol, "H");
            break;
        case 2:
            strcpy(element.name, "He");
            strcpy(element.symbol, "He");
            break;
        case 6:
            strcpy(element.name, "C");
            strcpy(element.symbol, "C");
            break;
        case 7:
            strcpy(element.name, "N");
            strcpy(element.symbol, "N");
            break;
        case 8:
            strcpy(element.name, "O");
            strcpy(element.symbol, "O");
            break;
        default:
            sprintf(element.name, "Element %d", element.atomicNumber);
            sprintf(element.symbol, "%c", 'A' + (element.atomicNumber - 1));
            break;
    }
    return element;
}

// Function to print an element
void printElement(Element element) {
    printf("Name: %s\n", element.name);
    printf("Atomic Number: %d\n", element.atomicNumber);
    printf("Symbol: %c\n\n", element.symbol);
}

// Function to ask a question about an element
int askQuestion(Element element) {
    int correctAnswer = 0;
    int userAnswer = 0;

    printf("What is the atomic number of %s? ", element.name);
    scanf("%d", &userAnswer);

    if (userAnswer == element.atomicNumber) {
        correctAnswer = 1;
    }

    return correctAnswer;
}

// Function to run the quiz
void runQuiz() {
    srand(time(NULL)); // Seed the random number generator with the current time

    int score = 0;
    int totalQuestions = 10;

    for (int i = 0; i < totalQuestions; i++) {
        Element element = generateRandomElement();
        printElement(element);

        if (askQuestion(element)) {
            score++;
        }
    }

    printf("Your final score is: %d out of %d\n", score, totalQuestions);
}

int main() {
    runQuiz();
    return 0;
}