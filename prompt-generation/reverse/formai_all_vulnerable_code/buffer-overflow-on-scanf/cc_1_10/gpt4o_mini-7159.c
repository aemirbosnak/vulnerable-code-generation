//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of elements in the periodic table
#define MAX_ELEMENTS 118
#define MAX_NAME_LENGTH 20

// Structure to store element information
typedef struct {
    int atomicNumber;
    char name[MAX_NAME_LENGTH];
    char symbol[3];
    float atomicWeight;
} Element;

// Initialize the periodic table with elements
Element periodicTable[MAX_ELEMENTS] = {
    {1, "Hydrogen", "H", 1.008},
    {2, "Helium", "He", 4.0026},
    {3, "Lithium", "Li", 6.94},
    {4, "Beryllium", "Be", 9.0122},
    {5, "Boron", "B", 10.81},
    {6, "Carbon", "C", 12.011},
    {7, "Nitrogen", "N", 14.007},
    {8, "Oxygen", "O", 15.999},
    {9, "Fluorine", "F", 18.998},
    {10, "Neon", "Ne", 20.180},
    // Further elements would be initialized here
    {11, "Sodium", "Na", 22.990},
    {12, "Magnesium", "Mg", 24.305},
    {13, "Aluminum", "Al", 26.982},
    {14, "Silicon", "Si", 28.085},
    {15, "Phosphorus", "P", 30.974},
    {16, "Sulfur", "S", 32.06},
    {17, "Chlorine", "Cl", 35.45},
    {18, "Argon", "Ar", 39.948},
    {19, "Potassium", "K", 39.098},
    {20, "Calcium", "Ca", 40.078},
    // etc.
};

// Function to display the quiz
void displayQuiz() {
    system("clear"); // Clear the console for better visibility
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("Answer the following questions correctly.\n\n");
}

// Function to run the quiz
void runQuiz() {
    int score = 0;
    char answer[3];

    for (int i = 0; i < 10; i++) { // Quiz with 10 questions
        printf("Question %d: What is the symbol for %s? ", i+1, periodicTable[i].name);
        scanf("%s", answer);
        if (strcmp(answer, periodicTable[i].symbol) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect! The correct symbol is %s.\n", periodicTable[i].symbol);
        }
        printf("\n");
    }
    
    printf("Your total score is %d out of 10.\n", score);
}

// Function to display instructions
void displayInstructions() {
    printf("Instructions:\n");
    printf("1. You will be asked questions based on the symbols of the first 10 elements of the periodic table.\n");
    printf("2. Type your answer and press Enter.\n");
    printf("3. The quiz will notify you if you are correct or incorrect.\n");
    printf("4. Good luck!\n\n");
}

// Main function
int main() {
    int choice;

    displayInstructions();
    displayQuiz();
    runQuiz();

    return 0;
}