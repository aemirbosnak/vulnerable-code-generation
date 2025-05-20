//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_ELEMENTS 118   // total number of elements

// struct for an element
typedef struct {
    char symbol[3];
    char name[20];
    int atomic_number;
    float atomic_weight;
    char state[10];
} Element;

// print the details of an element
void print_element(Element e) {
    printf("Symbol: %s\n", e.symbol);
    printf("Name: %s\n", e.name);
    printf("Atomic Number: %d\n", e.atomic_number);
    printf("Atomic Weight: %.4f\n", e.atomic_weight);
    printf("State: %s\n", e.state);
}

// find element by atomic number
Element find_element_by_number(Element elements[], int atomic_number) {
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        if (elements[i].atomic_number == atomic_number) {
            return elements[i];
        }
    }
    Element null_element;
    strcpy(null_element.symbol, "N/A");
    strcpy(null_element.name, "N/A");
    null_element.atomic_number = 0;
    null_element.atomic_weight = 0;
    strcpy(null_element.state, "N/A");
    return null_element;
}

int main() {
    // initialize elements
    Element periodic_table[NUM_ELEMENTS] = {
        {"H", "Hydrogen", 1, 1.008, "Gas"},
        {"He", "Helium", 2, 4.003, "Gas"},
        {"Li", "Lithium", 3, 6.941, "Solid"},
        {"Be", "Beryllium", 4, 9.012, "Solid"},
        {"B", "Boron", 5, 10.81, "Solid"},
        {"C", "Carbon", 6, 12.01, "Solid"},
        {"N", "Nitrogen", 7, 14.01, "Gas"},
        {"O", "Oxygen", 8, 16.00, "Gas"},
        {"F", "Fluorine", 9, 19.00, "Gas"},
        {"Ne", "Neon", 10, 20.18, "Gas"},
        // rest of the elements...
    };

    // welcome message and instructions
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("Enter an atomic number (1-118) to see details of an element or enter 0 to exit.\n");

    // game loop
    int atomic_number;
    do {
        // get user input
        printf("\nEnter atomic number: ");
        scanf("%d", &atomic_number);

        if (atomic_number == 0) {
            // exit game if user enters 0
            printf("Exiting game...");
            break;
        } else if (atomic_number < 1 || atomic_number > NUM_ELEMENTS) {
            // ignore invalid inputs
            printf("Invalid atomic number. Please enter a number between 1-118.\n");
            continue;
        }
        
        // find element by atomic number
        Element e = find_element_by_number(periodic_table, atomic_number);
        if (strcmp(e.symbol, "N/A") == 0) {
            // error message for non-existent elements
            printf("Element with atomic number %d does not exist.\n", atomic_number);
            continue;
        }

        // print out element details
        printf("\n----------\n");
        printf("Details of element with atomic number %d:\n", atomic_number);
        print_element(e);
        printf("----------\n");

    } while (1);

    return 0;
}