//Code Llama-13B DATASET v1.0 Category: Periodic Table Quiz ; Style: puzzling
// Periodic Table Quiz
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ELEMENTS 118 // number of elements in the periodic table
#define MAX_ATOMS 5 // number of atoms to guess

// structure to store information about an element
struct element {
    char name[30]; // element name
    int atomic_number; // atomic number
    char symbol[5]; // element symbol
};

// function to generate a random element
struct element generate_element() {
    struct element e;
    int atomic_number = rand() % MAX_ELEMENTS + 1;
    sprintf(e.name, "Element %d", atomic_number);
    e.atomic_number = atomic_number;
    sprintf(e.symbol, "%d", atomic_number);
    return e;
}

// function to check if an element is correct
int check_element(struct element e, int atomic_number) {
    if (e.atomic_number == atomic_number) {
        return 1;
    }
    return 0;
}

int main() {
    // initialize random seed
    srand(time(NULL));

    // generate elements to guess
    struct element elements[MAX_ATOMS];
    for (int i = 0; i < MAX_ATOMS; i++) {
        elements[i] = generate_element();
    }

    // prompt user to guess elements
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("Guess the atomic number of an element by entering its name or symbol.\n");
    for (int i = 0; i < MAX_ATOMS; i++) {
        printf("Element %d: ", i + 1);
        char input[30];
        scanf("%s", input);
        int atomic_number = atoi(input);
        if (atomic_number == 0) {
            // input is not a number, try to match the input with the element name or symbol
            for (int j = 0; j < MAX_ELEMENTS; j++) {
                if (strcmp(input, elements[j].name) == 0 || strcmp(input, elements[j].symbol) == 0) {
                    atomic_number = elements[j].atomic_number;
                    break;
                }
            }
        }
        if (check_element(elements[i], atomic_number)) {
            printf("Correct! The atomic number of %s is %d.\n", elements[i].name, elements[i].atomic_number);
        } else {
            printf("Incorrect. The atomic number of %s is %d.\n", elements[i].name, elements[i].atomic_number);
        }
    }
    printf("Thank you for playing the Periodic Table Quiz!\n");
    return 0;
}