//GEMINI-pro DATASET v1.0 Category: Periodic Table Quiz ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int atomic_number;
    char *name;
    char *symbol;
    double atomic_mass;
} element;

int main() {
    // Create an array of elements.
    element elements[] = {
        {1, "Hydrogen", "H", 1.00794},
        {2, "Helium", "He", 4.002602},
        {3, "Lithium", "Li", 6.941},
        {4, "Beryllium", "Be", 9.012182},
        {5, "Boron", "B", 10.811},
        {6, "Carbon", "C", 12.011},
        {7, "Nitrogen", "N", 14.007},
        {8, "Oxygen", "O", 15.999},
        {9, "Fluorine", "F", 18.998},
        {10, "Neon", "Ne", 20.180},
        {11, "Sodium", "Na", 22.990},
        {12, "Magnesium", "Mg", 24.305},
        {13, "Aluminum", "Al", 26.982},
        {14, "Silicon", "Si", 28.085},
        {15, "Phosphorus", "P", 30.974},
        {16, "Sulfur", "S", 32.066},
        {17, "Chlorine", "Cl", 35.453},
        {18, "Argon", "Ar", 39.948},
        {19, "Potassium", "K", 39.098},
        {20, "Calcium", "Ca", 40.078},
    };

    // Get the number of elements.
    int num_elements = sizeof(elements) / sizeof(elements[0]);

    // Create a quiz.
    int score = 0;
    for (int i = 0; i < num_elements; i++) {
        // Get the element's name.
        char *name = elements[i].name;

        // Get the element's symbol.
        char *symbol = elements[i].symbol;

        // Get the element's atomic number.
        int atomic_number = elements[i].atomic_number;

        // Ask the user to guess the element's name.
        printf("What is the name of element %d (%s)? ", atomic_number, symbol);
        char guess[100];
        scanf("%s", guess);

        // Check if the user's guess is correct.
        if (strcmp(guess, name) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %s.\n", name);
        }
    }

    // Print the user's score.
    printf("Your score is %d out of %d.\n", score, num_elements);

    return 0;
}