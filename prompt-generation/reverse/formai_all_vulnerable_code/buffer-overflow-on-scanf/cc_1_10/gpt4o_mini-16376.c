//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ELEMENTS 118
#define BUFFER_SIZE 256

typedef struct {
    char symbol[3];
    char name[30];
    int atomic_number;
    float atomic_weight;
} Element;

Element periodic_table[MAX_ELEMENTS] = {
    {"H", "Hydrogen", 1, 1.008},
    {"He", "Helium", 2, 4.002},
    {"Li", "Lithium", 3, 6.94},
    {"Be", "Beryllium", 4, 9.0122},
    {"B", "Boron", 5, 10.81},
    {"C", "Carbon", 6, 12.011},
    {"N", "Nitrogen", 7, 14.007},
    {"O", "Oxygen", 8, 15.999},
    {"F", "Fluorine", 9, 18.998},
    {"Ne", "Neon", 10, 20.180},
    {"Na", "Sodium", 11, 22.990},
    {"Mg", "Magnesium", 12, 24.305},
    {"Al", "Aluminum", 13, 26.982},
    {"Si", "Silicon", 14, 28.085},
    {"P", "Phosphorus", 15, 30.974},
    {"S", "Sulfur", 16, 32.06},
    {"Cl", "Chlorine", 17, 35.45},
    {"Ar", "Argon", 18, 39.948},
    {"K", "Potassium", 19, 39.098},
    {"Ca", "Calcium", 20, 40.078},
    // Additional elements can be added here for a complete periodic table
};

void show_menu() {
    printf("\n--- Periodic Table Quiz ---\n");
    printf("1. Start Quiz\n");
    printf("2. Exit\n");
    printf("--------------------------\n");
}

void ask_question() {
    int random_index = rand() % MAX_ELEMENTS;
    Element element = periodic_table[random_index];

    printf("\nWhat is the name of the element with the symbol '%s'? (Atomic Number: %d)\n", element.symbol, element.atomic_number);
    char user_answer[30];
    printf("Your answer: ");
    fgets(user_answer, sizeof(user_answer), stdin);
    user_answer[strcspn(user_answer, "\n")] = 0; // Remove trailing newline

    if (strcasecmp(user_answer, element.name) == 0) {
        printf("Correct! The atomic weight of %s is %.3f.\n", element.name, element.atomic_weight);
    } else {
        printf("Wrong! The correct answer is %s.\n", element.name);
    }
}

int main() {
    srand(time(NULL));
    int choice;

    while (1) {
        show_menu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        while(getchar() != '\n'); // clear the buffer

        if (choice == 1) {
            printf("Starting the quiz...\n");
            for (int i = 0; i < 5; ++i) { // Let's ask 5 questions
                ask_question();
            }
        } else if (choice == 2) {
            printf("Exiting the quiz. Goodbye!\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}