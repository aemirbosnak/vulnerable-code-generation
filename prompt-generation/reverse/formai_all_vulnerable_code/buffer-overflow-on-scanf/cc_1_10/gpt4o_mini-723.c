//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: energetic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Structure to hold element information
typedef struct {
    char name[30];
    char symbol[3];
} Element;

// Function to generate random unique index
int uniqueRandomIndex(int max, int *used, int count) {
    int randIndex;
    int unique = 0;

    while (unique == 0) {
        randIndex = rand() % max;
        unique = 1;
        for (int i = 0; i < count; i++) {
            if (used[i] == randIndex) {
                unique = 0;
                break;
            }
        }
    }
    return randIndex;
}

// Function to ask quiz questions
void askQuiz(Element elements[], int numElements) {
    int score = 0;
    int used[10] = { -1 };  // keep track of used indices
    int count = 0;

    printf("\nWelcome to the Periodic Table Quiz! Let's see how much you know!\n\n");

    // Loop to ask 10 questions
    while (count < 10) {
        int index = uniqueRandomIndex(numElements, used, count);
        used[count] = index;  // save the used index
        count++;

        printf("What is the symbol for the element %s? ", elements[index].name);
        char answer[3];
        scanf("%s", answer);

        // Check answer
        if (strcmp(answer, elements[index].symbol) == 0) {
            printf("Correct! 🎉\n\n");
            score++;
        } else {
            printf("Oops! The correct answer is %s.\n\n", elements[index].symbol);
        }
    }

    // Display the final score
    printf("Quiz completed! Your score is %d out of 10.\n", score);
}

int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Array of elements to quiz on
    Element elements[] = {
        {"Hydrogen", "H"},
        {"Helium", "He"},
        {"Lithium", "Li"},
        {"Beryllium", "Be"},
        {"Boron", "B"},
        {"Carbon", "C"},
        {"Nitrogen", "N"},
        {"Oxygen", "O"},
        {"Fluorine", "F"},
        {"Neon", "Ne"},
        {"Sodium", "Na"},
        {"Magnesium", "Mg"},
        {"Aluminum", "Al"},
        {"Silicon", "Si"},
        {"Phosphorus", "P"},
        {"Sulfur", "S"},
        {"Chlorine", "Cl"},
        {"Argon", "Ar"},
        {"Potassium", "K"},
        {"Calcium", "Ca"},
        {"Scandium", "Sc"},
        {"Titanium", "Ti"},
        {"Vanadium", "V"},
        {"Chromium", "Cr"},
        {"Manganese", "Mn"},
        {"Iron", "Fe"},
        {"Cobalt", "Co"},
        {"Nickel", "Ni"},
        {"Copper", "Cu"},
        {"Zinc", "Zn"},
        {"Gallium", "Ga"},
        {"Germanium", "Ge"},
        {"Arsenic", "As"},
        {"Selenium", "Se"},
        {"Bromine", "Br"},
        {"Krypton", "Kr"},
        // Add more elements as needed for the quiz
    };

    int numElements = sizeof(elements) / sizeof(elements[0]);

    askQuiz(elements, numElements);

    return 0;
}