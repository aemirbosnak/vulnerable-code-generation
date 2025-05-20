//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 118

typedef struct {
    int atomicNumber;
    char symbol[3];
    char name[30];
    float atomicWeight;
} Element;

Element periodicTable[MAX_ELEMENTS];

void initializePeriodicTable() {
    // Sample data for the first 10 elements
    periodicTable[0] = (Element){1, "H", "Hydrogen", 1.008};
    periodicTable[1] = (Element){2, "He", "Helium", 4.0026};
    periodicTable[2] = (Element){3, "Li", "Lithium", 6.94};
    periodicTable[3] = (Element){4, "Be", "Beryllium", 9.0122};
    periodicTable[4] = (Element){5, "B", "Boron", 10.81};
    periodicTable[5] = (Element){6, "C", "Carbon", 12.011};
    periodicTable[6] = (Element){7, "N", "Nitrogen", 14.007};
    periodicTable[7] = (Element){8, "O", "Oxygen", 15.999};
    periodicTable[8] = (Element){9, "F", "Fluorine", 18.998};
    periodicTable[9] = (Element){10, "Ne", "Neon", 20.180};

    // Additional elements can be added similarly
    // ... (you can add more elements for a complete table)
}

void printElement(Element el) {
    printf("Atomic Number: %d\n", el.atomicNumber);
    printf("Symbol: %s\n", el.symbol);
    printf("Name: %s\n", el.name);
    printf("Atomic Weight: %.4f\n", el.atomicWeight);
}

void showPeriodicTable() {
    printf("Periodic Table of Elements:\n");
    for (int i = 0; i < 10; ++i) { // Change this limit for more elements
        printf("%d: %s (%s) - %.4f\n", periodicTable[i].atomicNumber, periodicTable[i].name, periodicTable[i].symbol, periodicTable[i].atomicWeight);
    }
}

void quizUser() {
    int score = 0;
    char answer[3];
    int questionNumber;

    for (int i = 0; i < 5; ++i) { // Asking 5 questions
        questionNumber = rand() % 10; // Randomly select an element from the first 10
        printf("Question %d: What is the symbol for %s? ", i + 1, periodicTable[questionNumber].name);
        scanf("%s", answer);
        
        if (strcmp(answer, periodicTable[questionNumber].symbol) == 0) {
            printf("Correct!\n\n");
            score++;
        } else {
            printf("Incorrect! The correct answer is %s.\n\n", periodicTable[questionNumber].symbol);
        }
    }

    printf("Your final score is: %d out of 5.\n", score);
}

int main() {
    srand(time(NULL)); // Seed for random number generation
    initializePeriodicTable();

    int choice;
    do {
        printf("Welcome to the Periodic Table Quiz!\n");
        printf("1. Show Periodic Table\n");
        printf("2. Start Quiz\n");
        printf("3. Exit\n");
        printf("Please choose an option: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                showPeriodicTable();
                break;
            case 2:
                quizUser();
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}