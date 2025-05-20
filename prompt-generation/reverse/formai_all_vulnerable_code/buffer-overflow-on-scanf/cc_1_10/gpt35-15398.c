//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: configurable
#include <stdio.h>
#include <stdbool.h>

#define NUM_ELEMENTS 118
#define MAX_NAME_LENGTH 15

// Struct to represent an element in the periodic table
typedef struct Element {
    int atomicNumber;
    char symbol[3];
    char name[MAX_NAME_LENGTH];
    double atomicMass;
} Element;

// Array to store all elements in the periodic table
Element elements[NUM_ELEMENTS];

// Function to print a welcome message and instructions for the quiz
void printWelcome() {
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be given the symbol or name of an element, and you must choose the correct atomic number and atomic mass.\n");
    printf("You will have a total of 10 questions.\n");
    printf("Good luck!\n\n");
}

// Function to initialize all elements in the periodic table
void initializeElements() {
    // Element 1
    Element hydrogen = { 1, "H", "Hydrogen", 1.008 };
    elements[0] = hydrogen;
    // Element 2
    Element helium = { 2, "He", "Helium", 4.003 };
    elements[1] = helium;
    // ...
    // Initialize all elements in the periodic table
}

// Function to generate a random index for an element in the periodic table
int generateRandomIndex() {
    return rand() % NUM_ELEMENTS;
}

// Function to print a question asking for the atomic number of an element
// Returns true if the user answers correctly, false otherwise
bool askAtomicNumber() {
    int index = generateRandomIndex();
    Element element = elements[index];

    printf("What is the atomic number of %s (%s)?\n", element.name, element.symbol);
    int answer;
    scanf("%d", &answer);

    if (answer == element.atomicNumber) {
        printf("Correct!\n\n");
        return true;
    } else {
        printf("Incorrect. The correct answer was %d.\n\n", element.atomicNumber);
        return false;
    }
}

// Function to print a question asking for the atomic mass of an element
// Returns true if the user answers correctly, false otherwise
bool askAtomicMass() {
    int index = generateRandomIndex();
    Element element = elements[index];

    printf("What is the atomic mass of %s (%s)?\n", element.name, element.symbol);
    double answer;
    scanf("%lf", &answer);

    if (answer == element.atomicMass) {
        printf("Correct!\n\n");
        return true;
    } else {
        printf("Incorrect. The correct answer was %.3f.\n\n", element.atomicMass);
        return false;
    }
}

// Main quiz function
void quiz() {
    int score = 0;

    // Ask 10 questions: 5 atomic number, 5 atomic mass
    for (int i = 0; i < 5; i++) {
        if (askAtomicNumber()) {
            score++;
        }
        if (askAtomicMass()) {
            score++;
        }
    }

    // Print final score
    printf("Quiz complete! Your score is %d out of 10.\n", score);
}

int main() {
    srand(time(NULL)); // Seed random number generator
    printWelcome();
    initializeElements();
    quiz();
    return 0;
}