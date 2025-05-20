//GEMINI-pro DATASET v1.0 Category: Periodic Table Quiz ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int atomic_number;
    double atomic_mass;
} element;

int main() {
    // Create an array of elements
    element elements[] = {
        { "Hydrogen", 1, 1.00794 },
        { "Helium", 2, 4.002602 },
        { "Lithium", 3, 6.941 },
        { "Beryllium", 4, 9.012182 },
        { "Boron", 5, 10.811 },
        { "Carbon", 6, 12.011 },
        { "Nitrogen", 7, 14.007 },
        { "Oxygen", 8, 15.999 },
        { "Fluorine", 9, 18.998 },
        { "Neon", 10, 20.1797 }
    };

    // Get the number of elements in the array
    int num_elements = sizeof(elements) / sizeof(elements[0]);

    // Create a quiz
    int score = 0;
    for (int i = 0; i < num_elements; i++) {
        // Get the element's name
        char *name = elements[i].name;

        // Get the element's atomic number
        int atomic_number = elements[i].atomic_number;

        // Get the element's atomic mass
        double atomic_mass = elements[i].atomic_mass;

        // Ask the user a question about the element
        printf("What is the name of element %d with atomic mass %.3f?\n", atomic_number, atomic_mass);

        // Get the user's answer
        char answer[100];
        scanf("%s", answer);

        // Check if the user's answer is correct
        if (strcmp(answer, name) == 0) {
            // The user's answer is correct
            printf("Correct!\n");
            score++;
        } else {
            // The user's answer is incorrect
            printf("Incorrect. The correct answer is %s.\n", name);
        }
    }

    // Print the user's score
    printf("Your score is %d out of %d.\n", score, num_elements);

    return 0;
}