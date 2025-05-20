//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 118
#define NAME_LENGTH 30

typedef struct {
    int atomic_number;
    char name[NAME_LENGTH];
    char symbol[3];
    float atomic_weight;
    char category[20];
} Element;

Element periodic_table[MAX_ELEMENTS] = {
    // Format: {Atomic Number, "Name", "Symbol", Atomic Weight, "Category"}
    {1, "Hydrogen", "H", 1.008, "Nonmetal"},
    {2, "Helium", "He", 4.0026, "Noble Gas"},
    {3, "Lithium", "Li", 6.94, "Alkali Metal"},
    {4, "Beryllium", "Be", 9.0122, "Alkaline Earth Metal"},
    {5, "Boron", "B", 10.81, "Metalloid"},
    // Initialize the rest of the elements here...
    {6, "Carbon", "C", 12.011, "Nonmetal"},
    {7, "Nitrogen", "N", 14.007, "Nonmetal"},
    {8, "Oxygen", "O", 15.999, "Nonmetal"},
    {9, "Fluorine", "F", 18.998, "Nonmetal"},
    {10, "Neon", "Ne", 20.180, "Noble Gas"},
    {11, "Sodium", "Na", 22.990, "Alkali Metal"},
    {12, "Magnesium", "Mg", 24.305, "Alkaline Earth Metal"},
    {13, "Aluminum", "Al", 26.982, "Post-transition Metal"},
    {14, "Silicon", "Si", 28.085, "Metalloid"},
    {15, "Phosphorus", "P", 30.974, "Nonmetal"},
    {16, "Sulfur", "S", 32.06, "Nonmetal"},
    {17, "Chlorine", "Cl", 35.45, "Nonmetal"},
    {18, "Argon", "Ar", 39.948, "Noble Gas"},
    {19, "Potassium", "K", 39.098, "Alkali Metal"},
    {20, "Calcium", "Ca", 40.078, "Alkaline Earth Metal"},
    // ... upto 118
};

void displayElement(int index) {
    if (index < 0 || index >= MAX_ELEMENTS) {
        printf("Invalid element index.\n");
        return;
    }
    Element e = periodic_table[index];
    printf("Element Details:\n");
    printf("Atomic Number: %d\n", e.atomic_number);
    printf("Name: %s\n", e.name);
    printf("Symbol: %s\n", e.symbol);
    printf("Atomic Weight: %.3f\n", e.atomic_weight);
    printf("Category: %s\n", e.category);
}

void startQuiz() {
    char user_answer[NAME_LENGTH];
    int score = 0;

    printf("Welcome to the Periodic Table Quiz! Answer the following questions:\n\n");
    
    for (int i = 0; i < 5; i++) { // Five questions
        int element_index = rand() % MAX_ELEMENTS;
        Element e = periodic_table[element_index];
        
        printf("Question %d: What is the symbol of %s? ", i + 1, e.name);
        scanf("%s", user_answer);
        
        if (strcmp(user_answer, e.symbol) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Wrong! The correct answer is %s.\n", e.symbol);
        }
    }

    printf("\nYour final score: %d/5\n", score);
}

int main() {
    srand(time(NULL)); // Seed for random number generation

    printf("Periodic Table Quiz Program\n");
    printf("===========================\n");
    printf("1. Display an element\n");
    printf("2. Start the quiz\n");
    printf("3. Exit\n");

    int choice;
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                int index;
                printf("Enter atomic number (1-118): ");
                scanf("%d", &index);
                displayElement(index - 1); // Adjust for 0-based index
                break;
            }
            case 2:
                startQuiz();
                break;
            case 3:
                printf("Thank you for participating!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
        printf("\n");
    }

    return 0;
}