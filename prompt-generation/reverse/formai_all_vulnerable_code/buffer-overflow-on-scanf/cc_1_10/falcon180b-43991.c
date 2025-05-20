//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENTS 118 // Total number of elements in the periodic table
#define MAX_QUESTIONS 10 // Maximum number of questions to ask
#define MAX_ATTEMPTS 3 // Maximum number of attempts for each question
#define CORRECT_ANSWER_VALUE 1 // Value assigned to correct answers
#define INCORRECT_ANSWER_VALUE 0 // Value assigned to incorrect answers

struct {
    char name[30]; // Element name
    int atomicNumber; // Atomic number
    char symbol[3]; // Element symbol
} elements[MAX_ELEMENTS] = {
    {"Hydrogen", 1, "H"},
    {"Helium", 2, "He"},
    {"Lithium", 3, "Li"},
    {"Beryllium", 4, "Be"},
    {"Boron", 5, "B"},
    {"Carbon", 6, "C"},
    {"Nitrogen", 7, "N"},
    {"Oxygen", 8, "O"},
    {"Fluorine", 9, "F"},
    {"Neon", 10, "Ne"}
};

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time
    int numQuestions = rand() % MAX_QUESTIONS + 1; // Generate a random number of questions between 1 and MAX_QUESTIONS
    int totalScore = 0; // Initialize the total score to zero
    int questionIndex; // Index variable for the current question
    
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be asked %d questions about the elements in the periodic table.\n", numQuestions);
    printf("Each correct answer is worth 1 point.\n");
    printf("Good luck!\n\n");
    
    for (questionIndex = 0; questionIndex < numQuestions; questionIndex++) {
        int elementIndex = rand() % MAX_ELEMENTS; // Generate a random element index
        printf("Question %d: What is the atomic number of %s?\n", questionIndex+1, elements[elementIndex].name);
        int userAnswer;
        int attempts = 0;
        
        while (attempts < MAX_ATTEMPTS) {
            printf("Enter your answer: ");
            scanf("%d", &userAnswer);
            
            if (userAnswer == elements[elementIndex].atomicNumber) {
                printf("Correct!\n");
                totalScore++;
                break;
            } else {
                printf("Incorrect. Try again.\n");
                attempts++;
            }
        }
        
        if (attempts == MAX_ATTEMPTS) {
            printf("Time's up! The correct answer is %d.\n", elements[elementIndex].atomicNumber);
        }
    }
    
    printf("\nYour final score is %d out of %d.\n", totalScore, numQuestions);
    
    return 0;
}