//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 118
#define MAX_NAME_LENGTH 30

typedef struct {
    int atomic_number;
    char name[MAX_NAME_LENGTH];
    char symbol[3];
    float atomic_weight;
    char category[MAX_NAME_LENGTH];
} Element;

Element periodic_table[MAX_ELEMENTS] = {
    {1, "Hydrogen", "H", 1.008, "Non-metal"},
    {2, "Helium", "He", 4.0026, "Noble gas"},
    {3, "Lithium", "Li", 6.94, "Alkali metal"},
    {4, "Beryllium", "Be", 9.0122, "Alkaline earth metal"},
    {5, "Boron", "B", 10.81, "Metalloid"},
    {6, "Carbon", "C", 12.011, "Non-metal"},
    {7, "Nitrogen", "N", 14.007, "Non-metal"},
    {8, "Oxygen", "O", 15.999, "Non-metal"},
    {9, "Fluorine", "F", 18.998, "Non-metal"},
    {10, "Neon", "Ne", 20.180, "Noble gas"},
    // More elements should be added for a complete quiz
};

void display_element(Element elem) {
    printf("Atomic Number: %d\n", elem.atomic_number);
    printf("Name: %s\n", elem.name);
    printf("Symbol: %s\n", elem.symbol);
    printf("Atomic Weight: %.3f\n", elem.atomic_weight);
    printf("Category: %s\n\n", elem.category);
}

void take_quiz() {
    int score = 0;
    int total_questions = 5;
    char answer[3];

    printf("Welcome to the Periodic Table Quiz!\n\n");

    for (int q = 0; q < total_questions; q++) {
        int index = rand() % MAX_ELEMENTS; // Randomly select an element
        
        printf("Question %d: What is the symbol of element with Atomic Number %d?\n", q + 1, periodic_table[index].atomic_number);
        printf("Your answer: ");
        fgets(answer, sizeof(answer), stdin);
        answer[strcspn(answer, "\n")] = 0; // Remove the newline character

        if (strcasecmp(answer, periodic_table[index].symbol) == 0) {
            printf("Correct!\n\n");
            score++;
        } else {
            printf("Wrong! The correct answer is %s.\n\n", periodic_table[index].symbol);
        }
    }

    printf("Your final score is %d out of %d.\n", score, total_questions);
}

void display_menu() {
    printf("Periodic Table Quiz Menu:\n");
    printf("1. Take Quiz\n");
    printf("2. See Elements\n");
    printf("3. Exit\n");
}

int main() {
    int choice;

    srand(time(NULL)); // Seed random number generator

    while (1) {
        display_menu();
        printf("Select an option: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character left by scanf

        switch (choice) {
            case 1:
                take_quiz();
                break;
            case 2:
                printf("Displaying all elements:\n");
                for (int i = 0; i < MAX_ELEMENTS; i++) {
                    display_element(periodic_table[i]);
                }
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}