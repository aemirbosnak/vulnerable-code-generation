//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: grateful
#include <stdio.h>
#include <string.h>

#define MAX_ELEMENTS 118

typedef struct {
    char symbol[3];
    char name[20];
    int atomicNumber;
    float atomicWeight;
} Element;

void initializeTable(Element elements[]) {
    // An abbreviated Periodic Table for demonstration
    strcpy(elements[0].symbol, "H");
    strcpy(elements[0].name, "Hydrogen");
    elements[0].atomicNumber = 1;
    elements[0].atomicWeight = 1.008;

    strcpy(elements[1].symbol, "He");
    strcpy(elements[1].name, "Helium");
    elements[1].atomicNumber = 2;
    elements[1].atomicWeight = 4.0026;

    strcpy(elements[2].symbol, "Li");
    strcpy(elements[2].name, "Lithium");
    elements[2].atomicNumber = 3;
    elements[2].atomicWeight = 6.94;

    strcpy(elements[3].symbol, "Be");
    strcpy(elements[3].name, "Beryllium");
    elements[3].atomicNumber = 4;
    elements[3].atomicWeight = 9.0122;

    strcpy(elements[4].symbol, "B");
    strcpy(elements[4].name, "Boron");
    elements[4].atomicNumber = 5;
    elements[4].atomicWeight = 10.81;
    
    // Additional elements can be initialized similarly...
}

void displayElement(const Element *elem) {
    printf("Element Name: %s\n", elem->name);
    printf("Symbol: %s\n", elem->symbol);
    printf("Atomic Number: %d\n", elem->atomicNumber);
    printf("Atomic Weight: %.4f\n", elem->atomicWeight);
}

int main() {
    Element elements[MAX_ELEMENTS];
    initializeTable(elements);

    int choice = 0;

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("=====================================\n");
    printf("1. Display Information of an Element\n");
    printf("2. Exit\n");
    printf("Please enter your choice: ");

    while (1) {
        scanf("%d", &choice);
        
        if (choice == 2) {
            printf("Thank you for using the Periodic Table Quiz. Goodbye!\n");
            break;
        } else if (choice == 1) {
            int atomicNumber;
            printf("Enter the atomic number (1-5 for this demo): ");
            scanf("%d", &atomicNumber);

            if (atomicNumber < 1 || atomicNumber > 5) {
                printf("Invalid atomic number! Please try again.\n");
            } else {
                displayElement(&elements[atomicNumber - 1]);
            }
        } else {
            printf("Invalid choice! Please select 1 to display an element or 2 to exit.\n");
        }

        printf("\nChoose again (1: Display Element, 2: Exit): ");
    }

    return 0;
}