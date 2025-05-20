//GEMINI-pro DATASET v1.0 Category: Periodic Table Quiz ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

// Surprised? Here's a Periodic Table Quiz in C!

// Data structures for the elements
typedef struct {
    int atomic_number;
    char *name;
    char *symbol;
    double atomic_weight;
} Element;

// Array of elements
Element elements[] = {
    { 1, "Hydrogen", "H", 1.008 },
    { 2, "Helium", "He", 4.0026 },
    { 3, "Lithium", "Li", 6.941 },
    { 4, "Beryllium", "Be", 9.0122 },
    { 5, "Boron", "B", 10.811 },
    { 6, "Carbon", "C", 12.011 },
    { 7, "Nitrogen", "N", 14.007 },
    { 8, "Oxygen", "O", 15.999 },
    { 9, "Fluorine", "F", 18.998 },
    { 10, "Neon", "Ne", 20.180 },
    // ... and so on
};

// Number of elements in the array
#define NUM_ELEMENTS sizeof(elements) / sizeof(Element)

// Main function
int main() {
    // Welcome message
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("Let's see how much you know about the building blocks of our universe.\n\n");

    // Loop through the elements and ask questions
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        Element element = elements[i];

        // Ask the user for the element's name
        printf("What is the name of element with atomic number %d? ", element.atomic_number);
        char name[100];
        scanf("%s", name);

        // Check if the user's answer is correct
        if (strcmp(name, element.name) == 0) {
            // Correct answer
            printf("Correct! The name of element %d is %s.\n", element.atomic_number, element.name);
        } else {
            // Incorrect answer
            printf("Oops! The name of element %d is %s, not %s.\n", element.atomic_number, element.name, name);
        }

        // Ask the user for the element's symbol
        printf("What is the symbol of element with atomic number %d? ", element.atomic_number);
        char symbol[100];
        scanf("%s", symbol);

        // Check if the user's answer is correct
        if (strcmp(symbol, element.symbol) == 0) {
            // Correct answer
            printf("Correct! The symbol of element %d is %s.\n", element.atomic_number, element.symbol);
        } else {
            // Incorrect answer
            printf("Oops! The symbol of element %d is %s, not %s.\n", element.atomic_number, element.symbol, symbol);
        }

        // Ask the user for the element's atomic weight
        printf("What is the atomic weight of element with atomic number %d? ", element.atomic_number);
        double atomic_weight;
        scanf("%lf", &atomic_weight);

        // Check if the user's answer is correct
        if (fabs(atomic_weight - element.atomic_weight) < 0.001) {
            // Correct answer
            printf("Correct! The atomic weight of element %d is %.3f.\n\n", element.atomic_number, element.atomic_weight);
        } else {
            // Incorrect answer
            printf("Oops! The atomic weight of element %d is %.3f, not %.3f.\n\n", element.atomic_number, element.atomic_weight, atomic_weight);
        }
    }

    // Goodbye message
    printf("Thanks for playing the Periodic Table Quiz!\n");
    printf("I hope you learned something new about the elements.\n");

    return 0;
}