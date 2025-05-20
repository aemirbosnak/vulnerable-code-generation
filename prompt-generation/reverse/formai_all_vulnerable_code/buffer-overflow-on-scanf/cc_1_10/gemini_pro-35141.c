//GEMINI-pro DATASET v1.0 Category: Periodic Table Quiz ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Structure to store element data
typedef struct {
    int atomicNumber;
    char *name;
    char *symbol;
    double atomicWeight;
} Element;

// Array of elements
Element elements[] = {
    {1, "Hydrogen", "H", 1.008},
    {2, "Helium", "He", 4.0026},
    {3, "Lithium", "Li", 6.941},
    {4, "Beryllium", "Be", 9.0122},
    {5, "Boron", "B", 10.811},
    {6, "Carbon", "C", 12.011},
    {7, "Nitrogen", "N", 14.007},
    {8, "Oxygen", "O", 16.000},
    {9, "Fluorine", "F", 19.000},
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

// Number of elements
int numElements = sizeof(elements) / sizeof(Element);

// Function to print the periodic table
void printPeriodicTable() {
    // Print the header
    printf("  Atomic Atomic  \n");
    printf("Number  Weight  Symbol  Name\n");
    printf("------- -------- -------- --------\n");

    // Loop through the elements
    for (int i = 0; i < numElements; i++) {
        // Print the element data
        printf("%-7d %-8.3f %-7s %-7s\n", elements[i].atomicNumber, elements[i].atomicWeight, elements[i].symbol, elements[i].name);
    }
}

// Function to quiz the user on the periodic table
void quizPeriodicTable() {
    // Get a random element
    int randomIndex = rand() % numElements;
    Element randomElement = elements[randomIndex];

    // Ask the user a question about the element
    printf("What is the atomic number of %s?\n", randomElement.name);

    // Get the user's answer
    int answer;
    scanf("%d", &answer);

    // Check if the answer is correct
    if (answer == randomElement.atomicNumber) {
        printf("Correct!\n");
    } else {
        printf("Incorrect. The correct answer is %d.\n", randomElement.atomicNumber);
    }
}

// Main function
int main() {
    // Print the periodic table
    printPeriodicTable();

    // Quiz the user on the periodic table
    quizPeriodicTable();

    return 0;
}