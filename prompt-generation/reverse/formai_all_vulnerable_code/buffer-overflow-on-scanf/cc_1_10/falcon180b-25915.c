//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numQuestions;
    int correctAnswers = 0;
    char choice;
    int score = 0;
    int i;
    int randomIndex;
    struct {
        char *element;
        char *symbol;
        int atomicNumber;
    } elements[] = {
        {"Hydrogen", "H", 1},
        {"Helium", "He", 2},
        {"Lithium", "Li", 3},
        {"Beryllium", "Be", 4},
        {"Boron", "B", 5},
        {"Carbon", "C", 6},
        {"Nitrogen", "N", 7},
        {"Oxygen", "O", 8},
        {"Fluorine", "F", 9},
        {"Neon", "Ne", 10},
        {"Sodium", "Na", 11},
        {"Magnesium", "Mg", 12},
        {"Aluminum", "Al", 13},
        {"Silicon", "Si", 14},
        {"Phosphorus", "P", 15},
        {"Sulfur", "S", 16},
        {"Chlorine", "Cl", 17},
        {"Argon", "Ar", 18},
        {"Potassium", "K", 19},
        {"Calcium", "Ca", 20},
        {"Iron", "Fe", 26},
        {"Copper", "Cu", 29},
        {"Zinc", "Zn", 30},
        {"Nickel", "Ni", 28},
        {"Gold", "Au", 79},
        {"Platinum", "Pt", 78},
        {"Silver", "Ag", 47}
    };

    srand(time(NULL));
    numQuestions = rand() % 20 + 5; // Random number of questions between 5 and 20

    for (i = 0; i < numQuestions; i++) {
        randomIndex = rand() % 26; // Random element from the array
        printf("Question %d: What is the symbol for the element with atomic number %d?\n", i+1, elements[randomIndex].atomicNumber);
        printf("A. %s\n", elements[randomIndex].symbol);
        printf("B. %s\n", elements[(randomIndex+1)%26].symbol);
        printf("C. %s\n", elements[(randomIndex+2)%26].symbol);
        printf("D. %s\n", elements[(randomIndex+3)%26].symbol);

        scanf(" %c", &choice);

        if (choice == elements[randomIndex].symbol[0]) {
            correctAnswers++;
        }
    }

    score = (int) ((float) correctAnswers / numQuestions * 100);

    printf("\nYou got %d out of %d questions correct (%.2f%% score).\n", correctAnswers, numQuestions, score);

    return 0;
}