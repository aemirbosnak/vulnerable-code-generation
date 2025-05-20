//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: intelligent
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

// Function prototypes
void initializePeriodicTable();
void displayQuizMenu();
void takeQuiz();
void printElement(Element element);
void displayElementInfo(int atomicNumber);

int main() {
    initializePeriodicTable();
    
    int choice;
    do {
        displayQuizMenu();
        printf("Enter your choice (0 to exit): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                takeQuiz();
                break;
            case 0:
                printf("Thank you for participating!\n");
                break;
            default:
                printf("Invalid selection. Please try again.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}

void initializePeriodicTable() {
    periodicTable[0] = (Element){1, "Hydrogen", "H", 1.008};
    periodicTable[1] = (Element){2, "Helium", "He", 4.0026};
    periodicTable[2] = (Element){3, "Lithium", "Li", 6.94};
    // ... Populate rest of the elements (for brevity, only a few are shown)
    periodicTable[3] = (Element){4, "Beryllium", "Be", 9.0122};
    periodicTable[4] = (Element){5, "Boron", "B", 10.81};
    periodicTable[5] = (Element){6, "Carbon", "C", 12.011};
    periodicTable[6] = (Element){7, "Nitrogen", "N", 14.007};
    periodicTable[7] = (Element){8, "Oxygen", "O", 15.999};
    periodicTable[8] = (Element){9, "Fluorine", "F", 18.998};
    periodicTable[9] = (Element){10, "Neon", "Ne", 20.180};
    // Continue until atomic number 118, adding all elements...
}

void displayQuizMenu() {
    printf("\n---------- Periodic Table Quiz ----------\n");
    printf("1. Take the Quiz\n");
    printf("0. Exit\n");
}

void takeQuiz() {
    int score = 0;
    char answer[MAX_SYMBOL_LENGTH];

    for (int i = 0; i < 10; i++) { // 10 quiz questions
        int randomIndex = rand() % MAX_ELEMENTS;
        Element element = periodicTable[randomIndex];
        
        printf("What is the symbol for %s? ", element.name);
        scanf("%s", answer);

        if (strncmp(answer, element.symbol, MAX_SYMBOL_LENGTH) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Wrong! The correct answer is %s.\n", element.symbol);
        }
    }

    printf("Your score: %d/10\n", score);
}

void printElement(Element element) {
    printf("Element: %s\n", element.name);
    printf("Symbol: %s\n", element.symbol);
    printf("Atomic Number: %d\n", element.atomicNumber);
    printf("Atomic Weight: %.3f\n", element.atomicWeight);
}

void displayElementInfo(int atomicNumber) {
    if (atomicNumber < 1 || atomicNumber > MAX_ELEMENTS) {
        printf("Invalid atomic number!\n");
        return;
    }
    Element element = periodicTable[atomicNumber - 1];
    printElement(element);
}