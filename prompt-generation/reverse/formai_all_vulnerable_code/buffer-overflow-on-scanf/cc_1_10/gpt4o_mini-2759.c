//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold element information
typedef struct Element {
    int atomicNumber;
    char symbol[3];
    char name[30];
    float atomicWeight;
} Element;

// Function to initialize the Periodic Table
void initializeTable(Element *table) {
    // Sample elements
    table[0] = (Element){1, "H", "Hydrogen", 1.008};
    table[1] = (Element){2, "He", "Helium", 4.0026};
    table[2] = (Element){3, "Li", "Lithium", 6.94};
    table[3] = (Element){4, "Be", "Beryllium", 9.0122};
    table[4] = (Element){5, "B", "Boron", 10.81};
    table[5] = (Element){6, "C", "Carbon", 12.011};
    table[6] = (Element){7, "N", "Nitrogen", 14.007};
    table[7] = (Element){8, "O", "Oxygen", 15.999};
    table[8] = (Element){9, "F", "Fluorine", 18.998};
    table[9] = (Element){10, "Ne", "Neon", 20.180};
    // Add more elements as necessary
}

// Function to display the periodic table
void displayTable(Element *table, int size) {
    printf("%-10s %-10s %-30s %-10s\n", "Atomic No", "Symbol", "Element Name", "Atomic Weight");
    printf("--------------------------------------------------------------------------\n");
    for (int i = 0; i < size; i++) {
        printf("%-10d %-10s %-30s %-10.4f\n", table[i].atomicNumber, table[i].symbol, table[i].name, table[i].atomicWeight);
    }
}

// Function to get an element by atomic number
Element* getElementByAtomicNumber(Element *table, int size, int atomicNumber) {
    for (int i = 0; i < size; i++) {
        if (table[i].atomicNumber == atomicNumber) {
            return &table[i];
        }
    }
    return NULL;
}

// Function to get an element by symbol
Element* getElementBySymbol(Element *table, int size, const char *symbol) {
    for (int i = 0; i < size; i++) {
        if (strcmp(table[i].symbol, symbol) == 0) {
            return &table[i];
        }
    }
    return NULL;
}

// Main Quiz Function
void quiz(Element *table, int size) {
    int score = 0, totalQuestions = 5, answer;
    char guess[3]; // For user input

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("Answer the following questions:\n");

    // Question 1:
    printf("Q1: What is the atomic number of Carbon? ");
    scanf("%d", &answer);
    if (answer == 6) {
        printf("Correct!\n");
        score++;
    } else {
        printf("Wrong! The correct answer is 6.\n");
    }

    // Question 2:
    printf("Q2: What is the symbol for Helium? ");
    scanf("%s", guess);
    if (strcmp(guess, "He") == 0) {
        printf("Correct!\n");
        score++;
    } else {
        printf("Wrong! The correct answer is He.\n");
    }

    // Question 3:
    printf("Q3: What is the atomic weight of Oxygen? ");
    scanf("%f", &answer);
    if (answer == 16.00) { // close enough for demonstration
        printf("Correct!\n");
        score++;
    } else {
        printf("Wrong! The correct answer is 15.999.\n");
    }

    // Question 4:
    printf("Q4: What is the atomic number for Nitrogen? ");
    scanf("%d", &answer);
    if (answer == 7) {
        printf("Correct!\n");
        score++;
    } else {
        printf("Wrong! The correct answer is 7.\n");
    }

    // Question 5:
    printf("Q5: What element has the symbol 'Li'? ");
    scanf("%s", guess);
    if (strcmp(guess, "Li") == 0) {
        printf("Correct!\n");
        score++;
    } else {
        printf("Wrong! The correct answer is Li (Lithium).\n");
    }

    printf("Your total score: %d/%d\n", score, totalQuestions);
}

int main() {
    const int size = 10; // Number of elements
    Element periodicTable[size];
    initializeTable(periodicTable);

    int choice;

    while (1) {
        printf("\nPeriodic Table Menu:\n");
        printf("1. Display Periodic Table\n");
        printf("2. Quiz Yourself\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayTable(periodicTable, size);
                break;
            case 2:
                quiz(periodicTable, size);
                break;
            case 3:
                printf("Thank you for visiting the Periodic Table!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}