//GEMINI-pro DATASET v1.0 Category: Periodic Table Quiz ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

// Structure to store element data
typedef struct {
    int atomic_number;
    char *symbol;
    char *name;
    double atomic_weight;
} element;

// Array of elements
element elements[] = {
    {1, "H", "Hydrogen", 1.008},
    {2, "He", "Helium", 4.0026},
    {3, "Li", "Lithium", 6.941},
    {4, "Be", "Beryllium", 9.0122},
    {5, "B", "Boron", 10.811},
    {6, "C", "Carbon", 12.011},
    {7, "N", "Nitrogen", 14.007},
    {8, "O", "Oxygen", 15.999},
    {9, "F", "Fluorine", 18.998},
    {10, "Ne", "Neon", 20.180},
    // ... continue for all elements
};

// Function to print a table of elements
void print_table(element *elements, int num_elements) {
    // Print header
    printf("%-2s %-3s %-10s %-5s\n", "No.", "Sym", "Name", "Weight");

    // Print each element
    for (int i = 0; i < num_elements; i++) {
        printf("%-2d %-3s %-10s %-5.3f\n",
               elements[i].atomic_number,
               elements[i].symbol,
               elements[i].name,
               elements[i].atomic_weight);
    }
}

// Function to quiz the user on the elements
void quiz(element *elements, int num_elements) {
    // Randomly select an element
    int index = rand() % num_elements;
    element element = elements[index];

    // Ask the user to guess the element
    char guess[100];
    printf("Guess the element with atomic number %d: ", element.atomic_number);
    scanf("%s", guess);

    // Check if the guess is correct
    if (strcmp(guess, element.symbol) == 0) {
        printf("Correct!\n");
    } else {
        printf("Incorrect. The correct answer is %s.\n", element.symbol);
    }
}

int main() {
    // Print the table of elements
    print_table(elements, sizeof(elements) / sizeof(element));

    // Quiz the user on the elements
    quiz(elements, sizeof(elements) / sizeof(element));

    return 0;
}