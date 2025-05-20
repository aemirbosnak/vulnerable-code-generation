//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TOTAL_ELEMENTS 118 // Total number of elements in the periodic table

struct element {
    char symbol[3]; // Chemical symbol of element
    char name[20]; // Name of element
    int atomic_number; // Atomic number of element
    float atomic_mass; // Atomic mass of element
} elements[TOTAL_ELEMENTS];

// Load elements data from file
void load_elements() {
    FILE *fptr = fopen("elements.txt", "r");
    if (fptr == NULL) {
        printf("Error opening elements file\n");
        exit(1);
    }
    for (int i=0; i<TOTAL_ELEMENTS; i++) {
        fscanf(fptr, "%s %s %d %f", elements[i].symbol, elements[i].name, &elements[i].atomic_number, &elements[i].atomic_mass);
    }
    fclose(fptr);
}

// Display menu and get user's choice
int get_choice() {
    int choice;
    printf("\n\nPERIODIC TABLE QUIZ\n\n");
    printf("1. Guess element name\n");
    printf("2. Guess element symbol\n");
    printf("3. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Get random element from the periodic table
struct element get_random_element() {
    int index = rand() % TOTAL_ELEMENTS;
    return elements[index];
}

// Display element and prompt user for answer
bool prompt_user(struct element e, bool by_name) {
    char answer[20];
    if (by_name) {
        printf("\nWhat is the symbol for %s? ", e.name);
        scanf("%s", answer);
        return strcmp(answer, e.symbol) == 0;
    } else {
        printf("\nWhat is the name for %s? ", e.symbol);
        scanf("%s", answer);
        return strcmp(answer, e.name) == 0;
    }
}

int main() {
    srand(time(NULL)); // Initialize random seed
    load_elements(); // Load elements data from file
    int choice;
    do {
        choice = get_choice(); // Display menu and get user's choice
        switch (choice) {
            case 1:
            case 2: {
                struct element e = get_random_element(); // Get random element from the periodic table
                bool correct = prompt_user(e, choice==1); // Prompt user for answer
                printf("%s\n", correct ? "Correct!" : "Incorrect!");
                break;
            }
            case 3: {
                printf("\nGoodbye!\n");
                break;
            }
            default: {
                printf("\nInvalid choice, please try again.\n");
                break;
            }
        }
    } while (choice != 3);
    return 0; //Exit program
}