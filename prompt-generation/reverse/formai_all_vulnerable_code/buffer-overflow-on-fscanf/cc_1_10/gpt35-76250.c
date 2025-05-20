//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define constants
#define NUM_ELEMENTS 118
#define MAX_NAME_LENGTH 20
#define MAX_SYMBOL_LENGTH 3

// Define struct for element
typedef struct element {
    int atomic_number;
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
} Element;

// Define function to read periodic table from file
void read_periodic_table(Element *periodic_table) {
    // Open the file
    FILE *file = fopen("periodic_table.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    // Read in the elements
    int i = 0;
    while (fscanf(file, "%d %s %s", &periodic_table[i].atomic_number, periodic_table[i].name, periodic_table[i].symbol) != EOF) {
        i++;
    }

    // Close the file
    fclose(file);
}

// Define function to print the periodic table
void print_periodic_table(Element *periodic_table) {
    printf("------------------------------\n");
    printf("| Atomic Number |  Name   | Symbol |\n");
    printf("------------------------------\n");
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        printf("|       %d       | %-7s |   %-2s   |\n", periodic_table[i].atomic_number, periodic_table[i].name, periodic_table[i].symbol);
    }
    printf("------------------------------\n");
}

// Define function to get user input for atomic number
int get_atomic_number() {
    int atomic_number;
    printf("Enter the atomic number of the element you want to quiz: ");
    scanf("%d", &atomic_number);
    return atomic_number;
}

// Define function to generate random atomic number
int generate_random_atomic_number() {
    srand(time(NULL));
    return rand() % NUM_ELEMENTS + 1;
}

// Define function to check if user input is correct
int check_answer(Element *periodic_table, int atomic_number) {
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        if (periodic_table[i].atomic_number == atomic_number) {
            printf("The element is %s (%s)\n", periodic_table[i].name, periodic_table[i].symbol);
            return 1;
        }
    }
    printf("That is not a valid atomic number\n");
    return 0;
}

// Define function for the quiz
void quiz(Element *periodic_table) {
    int score = 0;
    int rounds = 0;
    int choice = -1;

    while (choice != 0) {
        printf("\nChoose an option:\n");
        printf("1. Quiz on a specific element\n");
        printf("2. Random quiz\n");
        printf("0. Quit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int atomic_number = get_atomic_number();
            if (check_answer(periodic_table, atomic_number)) {
                score++;
            }
            rounds++;
        } else if (choice == 2) {
            int atomic_number = generate_random_atomic_number();
            printf("What is the element with atomic number %d? ", atomic_number);
            if (check_answer(periodic_table, atomic_number)) {
                score++;
            }
            rounds++;
        } else if (choice == 0) {
            printf("Thanks for playing! Final score: %d/%d\n", score, rounds);
        } else {
            printf("Invalid choice\n");
        }
    }
}

// Main function
int main() {
    // Allocate memory for periodic table
    Element *periodic_table = malloc(NUM_ELEMENTS * sizeof(Element));

    // Read the periodic table from the file
    read_periodic_table(periodic_table);

    // Print the periodic table
    print_periodic_table(periodic_table);

    // Start the quiz
    quiz(periodic_table);

    // Free the memory allocated for the periodic table
    free(periodic_table);

    return 0;
}