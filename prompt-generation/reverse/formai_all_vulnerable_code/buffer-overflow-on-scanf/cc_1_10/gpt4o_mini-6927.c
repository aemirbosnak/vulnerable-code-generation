//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 118
#define MAX_NAME_LENGTH 20

typedef struct {
    int atomic_number;
    char element_name[MAX_NAME_LENGTH];
    char symbol[3];
    double atomic_weight;
} Element;

Element periodic_table[MAX_ELEMENTS] = {
    {1, "Hydrogen", "H", 1.008},
    {2, "Helium", "He", 4.002602},
    {3, "Lithium", "Li", 6.94},
    {4, "Beryllium", "Be", 9.0122},
    {5, "Boron", "B", 10.81},
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
    {16, "Sulfur", "S", 32.06},
    {17, "Chlorine", "Cl", 35.45},
    {18, "Argon", "Ar", 39.948},
    {19, "Potassium", "K", 39.098},
    {20, "Calcium", "Ca", 40.078},
    // ... Add remaining elements 
    {118, "Oganesson", "Og", 294.0}  // Placeholder example for element 118
};

void display_quiz_menu() {
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("1. Start Quiz\n");
    printf("2. Exit\n");
}

void display_element_info(int atomic_number) {
    if (atomic_number < 1 || atomic_number > MAX_ELEMENTS) {
        printf("Invalid atomic number.\n");
        return;
    }
    Element elem = periodic_table[atomic_number - 1];
    printf("\nElement Information:\n");
    printf("Atomic Number: %d\n", elem.atomic_number);
    printf("Name: %s\n", elem.element_name);
    printf("Symbol: %s\n", elem.symbol);
    printf("Atomic Weight: %.3f\n", elem.atomic_weight);
}

int get_random_element() {
    return (rand() % MAX_ELEMENTS) + 1;  // Returns a random atomic number between 1 and 118
}

void start_quiz() {
    int score = 0, num_questions = 5;
    char user_answer[3];
    
    for (int i = 0; i < num_questions; i++) {
        int atomic_number = get_random_element();
        Element elem = periodic_table[atomic_number - 1];

        printf("\nQuestion %d: What is the symbol for %s? ", i + 1, elem.element_name);
        scanf("%s", user_answer);

        if (strcasecmp(user_answer, elem.symbol) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect! The correct answer is %s\n", elem.symbol);
        }
    }
    
    printf("\nYour total score: %d out of %d\n", score, num_questions);
}

int main() {
    int choice;

    srand(time(NULL)); // Seed for random number generation

    do {
        display_quiz_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                start_quiz();
                break;
            case 2:
                printf("Thank you for playing!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 2);

    return 0;
}