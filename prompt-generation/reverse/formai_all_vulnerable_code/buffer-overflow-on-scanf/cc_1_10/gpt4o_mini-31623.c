//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 118

// Structure to hold information about each element
typedef struct {
    char name[30];
    char symbol[3];
    int atomicNumber;
    float atomicWeight;
} Element;

// Function declarations
void initializeElements(Element elements[]);
void displayQuizIntro();
void displayElementInfo(const Element *element);
int getUserSelection();
int checkAnswer(int userAnswer, int correctAnswer);
void conductQuiz(Element elements[]);

int main() {
    Element elements[MAX_ELEMENTS];
    initializeElements(elements);  // Initializes the periodic table elements
    displayQuizIntro();            // Displays the HTML styled introduction
    conductQuiz(elements);         // Starts the quiz
    return 0;
}

void initializeElements(Element elements[]) {
    // Sample initialization for a few elements for demonstration purposes
    strcpy(elements[0].name, "Hydrogen");
    strcpy(elements[0].symbol, "H");
    elements[0].atomicNumber = 1;
    elements[0].atomicWeight = 1.008;

    strcpy(elements[1].name, "Helium");
    strcpy(elements[1].symbol, "He");
    elements[1].atomicNumber = 2;
    elements[1].atomicWeight = 4.0026;

    strcpy(elements[2].name, "Lithium");
    strcpy(elements[2].symbol, "Li");
    elements[2].atomicNumber = 3;
    elements[2].atomicWeight = 6.94;

    // ... Continue initializing other elements as needed
}

void displayQuizIntro() {
    printf("\n====================================\n");
    printf("|      Futuristic Element Quiz     |\n");
    printf("====================================\n");
    printf("Welcome, noble scholar of the future!\n");
    printf("Prepare to test your elemental knowledge and unlock the mysteries of the cosmos.\n");
    printf("Enter the atomic number of each element as prompted.\n");
    printf("====================================\n");
}

void displayElementInfo(const Element *element) {
    printf("\nElement: %s\n", element->name);
    printf("Symbol: %s\n", element->symbol);
    printf("Atomic Number: %d\n", element->atomicNumber);
    printf("Atomic Weight: %.4f\n", element->atomicWeight);
}

int getUserSelection() {
    int selection;
    printf("Choose an element (1 - %d): ", MAX_ELEMENTS);
    scanf("%d", &selection);
    return selection - 1;  // Adjusting for 0-indexing
}

int checkAnswer(int userAnswer, int correctAnswer) {
    return userAnswer == correctAnswer;
}

void conductQuiz(Element elements[]) {
    int score = 0;
    int totalQuestions = 3; // Set total questions for the quiz
    for (int i = 0; i < totalQuestions; i++) {
        int elementIndex = rand() % 3; // Randomly select from initialized elements
        displayElementInfo(&elements[elementIndex]);
        int userAnswer = getUserSelection();

        if (checkAnswer(userAnswer, elementIndex)) {
            printf("Correct! Well done, elemental wizard!\n");
            score++;
        } else {
            printf("Oops! The answer was %d: %s (%s)\n", 
                elements[elementIndex].atomicNumber, 
                elements[elementIndex].name, 
                elements[elementIndex].symbol);
        }
    }
    
    printf("\nYour final score: %d out of %d\n", score, totalQuestions);
    if (score == totalQuestions) {
        printf("Congratulations! You've mastered the elements of the universe!\n");
    } else {
        printf("Keep studying! The elements hold many secrets.\n");
    }
}