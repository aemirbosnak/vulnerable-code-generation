//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the number of elements in the periodic table
#define NUM_ELEMENTS 118

// Define the maximum length of an element symbol
#define MAX_SYMBOL_LENGTH 3

// Define the maximum length of an element name
#define MAX_NAME_LENGTH 20

// Define the maximum length of an element description
#define MAX_DESCRIPTION_LENGTH 100

// Define a struct to represent an element in the periodic table
typedef struct Element {
    char symbol[MAX_SYMBOL_LENGTH + 1]; // +1 for null terminator
    char name[MAX_NAME_LENGTH + 1]; // +1 for null terminator
    float atomic_mass;
    int atomic_number;
    char description[MAX_DESCRIPTION_LENGTH + 1]; // +1 for null terminator
} Element;

// Define an array to hold all the elements in the periodic table
Element elements[NUM_ELEMENTS];

// Define a function to load the periodic table from a text file
void load_periodic_table() {
    FILE* file = fopen("periodic_table.txt", "r");
    if (file == NULL) {
        printf("Could not open periodic_table.txt.\n");
        exit(1);
    }
    char line[256];
    int count = 0;
    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%s %s %f %d %[^\n]", elements[count].symbol, elements[count].name, &elements[count].atomic_mass, &elements[count].atomic_number, elements[count].description);
        count++;
    }
    fclose(file);
}

// Define a function to print the periodic table
void print_periodic_table() {
    printf("-------------------------------------------------------------------------\n");
    printf("| Symbol |            Name            | Atomic Mass | Atomic Number | Description |\n");
    printf("-------------------------------------------------------------------------\n");
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        printf("| %6s | %24s | %11.4f | %13d | %11s |\n", elements[i].symbol, elements[i].name, elements[i].atomic_mass, elements[i].atomic_number, elements[i].description);
    }
    printf("-------------------------------------------------------------------------\n");
}

// Define a function to prompt the user for an element symbol and return the corresponding element
Element get_element() {
    char symbol[MAX_SYMBOL_LENGTH + 1];
    printf("Enter an element symbol: ");
    scanf("%s", symbol);
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        if (strcmp(symbol, elements[i].symbol) == 0) {
            return elements[i];
        }
    }
    printf("Element not found.\n");
    exit(1);
}

// Define a function to quiz the user on the periodic table
void quiz() {
    char answer[MAX_SYMBOL_LENGTH + 1];
    int correct_count = 0;
    int incorrect_count = 0;
    for (int i = 0; i < 10; i++) {
        int index = rand() % NUM_ELEMENTS;
        printf("What is the symbol for %s? ", elements[index].name);
        scanf("%s", answer);
        if (strcmp(answer, elements[index].symbol) == 0) {
            printf("Correct!\n");
            correct_count++;
        } else {
            printf("Incorrect. The correct answer is %s.\n", elements[index].symbol);
            incorrect_count++;
        }
    }
    printf("You got %d correct and %d incorrect.\n", correct_count, incorrect_count);
}

int main() {
    load_periodic_table();
    printf("Welcome to the Happy Periodic Table Quiz!\n");
    while (1) {
        printf("1. Print periodic table.\n");
        printf("2. Quiz me!\n");
        printf("3. Quit.\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                print_periodic_table();
                break;
            case 2:
                quiz();
                break;
            case 3:
                printf("Thanks for playing! Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}