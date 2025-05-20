//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 118
#define MAX_NAME_LENGTH 20
#define MAX_SYMBOL_LENGTH 3

typedef struct {
    int atomicNumber;
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    float atomicWeight;
} Element;

Element periodicTable[MAX_ELEMENTS];

void initializePeriodicTable() {
    // Sample initialization for the first 5 elements
    periodicTable[0] = (Element){1, "Hydrogen", "H", 1.008};
    periodicTable[1] = (Element){2, "Helium", "He", 4.0026};
    periodicTable[2] = (Element){3, "Lithium", "Li", 6.94};
    periodicTable[3] = (Element){4, "Beryllium", "Be", 9.0122};
    periodicTable[4] = (Element){5, "Boron", "B", 10.81};
    // Further elements can be added here...
}

void displayElement(Element element) {
    printf("Atomic Number: %d\n", element.atomicNumber);
    printf("Element Name: %s\n", element.name);
    printf("Symbol: %s\n", element.symbol);
    printf("Atomic Weight: %.4f\n", element.atomicWeight);
}

void quizUser() {
    int score = 0;
    for (int i = 0; i < 5; i++) {  // Quiz on the first 5 elements
        char answer[MAX_SYMBOL_LENGTH];
        
        printf("Question %d: What is the symbol for %s? ", i + 1, periodicTable[i].name);
        scanf("%s", answer);
        
        if (strcasecmp(answer, periodicTable[i].symbol) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect! The correct answer is %s.\n", periodicTable[i].symbol);
        }
    }
    printf("Your score: %d out of 5\n", score);
}

void displayAllElements() {
    printf("Periodic Table:\n");
    for (int i = 0; i < 5; i++) { // Display first 5 elements for brevity
        printf("%d: %s (%s) - Atomic Weight: %.4f\n", 
                periodicTable[i].atomicNumber, 
                periodicTable[i].name, 
                periodicTable[i].symbol, 
                periodicTable[i].atomicWeight);
    }
}

int main() {
    int choice;
    
    initializePeriodicTable();
    
    while (1) {
        printf("\nPeriodic Table Quiz\n");
        printf("1. Start Quiz\n");
        printf("2. Display All Elements\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                quizUser();
                break;
            case 2:
                displayAllElements();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}