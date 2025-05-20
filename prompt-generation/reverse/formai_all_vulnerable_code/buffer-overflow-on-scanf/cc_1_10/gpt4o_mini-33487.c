//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: high level of detail
#include <stdio.h>
#include <string.h>

#define MAX_ELEMENTS 118

typedef struct {
    char name[20];
    char symbol[3];
    int atomicNumber;
    float atomicWeight;
} Element;

Element periodicTable[MAX_ELEMENTS] = {
    {"Hydrogen", "H", 1, 1.008},
    {"Helium", "He", 2, 4.0026},
    {"Lithium", "Li", 3, 6.94},
    {"Beryllium", "Be", 4, 9.0122},
    {"Boron", "B", 5, 10.81},
    {"Carbon", "C", 6, 12.011},
    {"Nitrogen", "N", 7, 14.007},
    {"Oxygen", "O", 8, 15.999},
    {"Fluorine", "F", 9, 18.998},
    {"Neon", "Ne", 10, 20.180},
    {"Sodium", "Na", 11, 22.990},
    {"Magnesium", "Mg", 12, 24.305},
    {"Aluminum", "Al", 13, 26.982},
    {"Silicon", "Si", 14, 28.085},
    {"Phosphorus", "P", 15, 30.974},
    {"Sulfur", "S", 16, 32.06},
    {"Chlorine", "Cl", 17, 35.045},
    {"Argon", "Ar", 18, 39.948},
    {"Potassium", "K", 19, 39.098},
    {"Calcium", "Ca", 20, 40.078},
    // ... (Fill in the rest of the periodic table up to element 118)
    {"Oganesson", "Og", 118, 294},
};

void displayElement(Element e) {
    printf("Element: %s\n", e.name);
    printf("Symbol: %s\n", e.symbol);
    printf("Atomic Number: %d\n", e.atomicNumber);
    printf("Atomic Weight: %.3f\n", e.atomicWeight);
    printf("-------------------------\n");
}

void quizElement(int atomicNum) {
    if (atomicNum < 1 || atomicNum > MAX_ELEMENTS) {
        printf("Invalid atomic number!\n");
        return;
    }
    
    Element e = periodicTable[atomicNum - 1];
    char answer[3];
    
    printf("What is the symbol for the element with atomic number %d? ", e.atomicNumber);
    scanf("%s", answer);
    
    if (strcmp(answer, e.symbol) == 0) {
        printf("Correct! The symbol for %s is %s.\n", e.name, e.symbol);
    } else {
        printf("Incorrect! The correct symbol is %s.\n", e.symbol);
    }
}

void quizRandom() {
    int atomicNum = (rand() % MAX_ELEMENTS) + 1; // Generate a random number between 1 and 118
    quizElement(atomicNum);
}

void displayMenu() {
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("1. Quiz a specific element by atomic number\n");
    printf("2. Quiz a random element\n");
    printf("3. Exit\n");
}

int main() {
    int choice, atomicNum;
    
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter atomic number (1-118): ");
                scanf("%d", &atomicNum);
                quizElement(atomicNum);
                break;
            case 2:
                quizRandom();
                break;
            case 3:
                printf("Thank you for playing!\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }
    return 0;
}