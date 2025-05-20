//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for max element name and symbol lengths
#define MAX_NAME_LENGTH 20
#define MAX_SYMBOL_LENGTH 3

// Define a struct to represent an element in the periodic table
typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    int atomic_number;
    float atomic_weight;
} Element;

// Define a function to print the table header
void printHeader(void) {
    printf("%-3s %-20s %-3s %s\n", "No", "Name", "Sym", "Weight");
}

// Define a function to print an element's information
void printElement(Element *elem) {
    printf("%-3d %-20s %-3s %.3f\n", elem->atomic_number, elem->name, elem->symbol, elem->atomic_weight);
}

// Define a function to initialize an element with its information
void initElement(Element *elem, char name[], char symbol[], int atomic_number, float atomic_weight) {
    strcpy(elem->name, name);
    strcpy(elem->symbol, symbol);
    elem->atomic_number = atomic_number;
    elem->atomic_weight = atomic_weight;
}

int main() {
    // Define an array of elements in the periodic table
    Element table[118];

    // Initialize each element in the table
    initElement(&table[0], "Hydrogen", "H", 1, 1.008);
    initElement(&table[1], "Helium", "He", 2, 4.003);
    initElement(&table[2], "Lithium", "Li", 3, 6.941);
    initElement(&table[3], "Beryllium", "Be", 4, 9.012);
    initElement(&table[4], "Boron", "B", 5, 10.81);

    // ... add the rest of the elements ...

    initElement(&table[117], "Tennessine", "Ts", 117, 294.21);

    // Prompt the user to answer questions about the periodic table
    while (1) {
        int choice;
        printf("\nChoose the number corresponding to the correct answer:\n");
        printf("1. What is the symbol for element number 8?\n");
        printf("   1. O\n");
        printf("   2. H\n");
        printf("   3. He\n");
        printf("   4. C\n");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Correct!\n");
            break;
        } else {
            printf("Incorrect. Please try again.\n");
        }
    }

    // Ask the user to guess the weight of element number 16 within 0.1 units
    float guess;
    while (1) {
        printf("\nGuess the atomic weight of element number 16 within 0.1 units:\n");
        scanf("%f", &guess);
        if (guess > (table[15].atomic_weight - 0.1) && guess < (table[15].atomic_weight + 0.1)) {
            printf("Correct!\n");
            break;
        } else {
            printf("Incorrect. Please try again.\n");
        }
    }

    // Print out the periodic table
    printf("\n");
    printHeader();
    for (int i = 0; i < 118; i++) {
        printElement(&table[i]);
    }

    return 0;
}