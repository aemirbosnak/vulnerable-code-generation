//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char symbol[3];
    char name[50];
    int atomicNumber;
    float atomicWeight;
} Element;

Element periodicTable[] = {
    {"H", "Hydrogen", 1, 1.008},
    {"He", "Helium", 2, 4.0026},
    {"Li", "Lithium", 3, 6.94},
    {"Be", "Beryllium", 4, 9.0122},
    {"B", "Boron", 5, 10.81},
    {"C", "Carbon", 6, 12.011},
    {"N", "Nitrogen", 7, 14.007},
    {"O", "Oxygen", 8, 15.999},
    {"F", "Fluorine", 9, 18.998},
    {"Ne", "Neon", 10, 20.18},
    {"Na", "Sodium", 11, 22.989},
    {"Mg", "Magnesium", 12, 24.305},
    {"Al", "Aluminum", 13, 26.982},
    {"Si", "Silicon", 14, 28.085},
    {"P", "Phosphorus", 15, 30.974},
    {"S", "Sulfur", 16, 32.06},
    {"Cl", "Chlorine", 17, 35.45},
    {"Ar", "Argon", 18, 39.948},
    {"K", "Potassium", 19, 39.098},
    {"Ca", "Calcium", 20, 40.078},
    // Add more elements as needed
};

#define TOTAL_ELEMENTS (sizeof(periodicTable) / sizeof(periodicTable[0]))

void displayInstructions() {
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be asked questions about elements in the periodic table.\n");
    printf("Answer the questions by entering the correct option number.\n");
    printf("Let's see how well you know your elements!\n");
}

void quiz() {
    int score = 0;
    char answer;

    for (int i = 0; i < TOTAL_ELEMENTS; i++) {
        printf("\nQuestion %d: What is the atomic number of %s (%s)?\n", 
                i + 1, periodicTable[i].name, periodicTable[i].symbol);
        printf("A) %d\n", periodicTable[i].atomicNumber);
        printf("B) %d\n", periodicTable[i].atomicNumber + 1);
        printf("C) %d\n", periodicTable[i].atomicNumber - 1);
        printf("D) %d\n", periodicTable[i].atomicNumber + 2);
        
        printf("Your answer: ");
        scanf(" %c", &answer); // Space before %c ignores any whitespace before input

        if (answer == 'A' || answer == 'a') {
            score++;
            printf("Correct!\n");
        } else {
            printf("Wrong! The correct answer is A) %d.\n", periodicTable[i].atomicNumber);
        }
    }

    printf("\nQuiz finished! Your score: %d out of %d\n", score, TOTAL_ELEMENTS);
}

int main() {
    displayInstructions();
    quiz();
    return 0;
}