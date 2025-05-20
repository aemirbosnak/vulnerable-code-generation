//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 118
#define MAX_NAME_LENGTH 20

typedef struct {
    int atomicNumber;
    char name[MAX_NAME_LENGTH];
    char symbol[3];
    float atomicWeight;
} Element;

Element periodicTable[MAX_ELEMENTS];

void initializePeriodicTable() {
    // Initialize some elements (for brevity, not all elements are included)
    periodicTable[0] = (Element){1, "Hydrogen", "H", 1.008};
    periodicTable[1] = (Element){2, "Helium", "He", 4.002602};
    periodicTable[2] = (Element){3, "Lithium", "Li", 6.94};
    periodicTable[3] = (Element){4, "Beryllium", "Be", 9.0122};
    periodicTable[4] = (Element){5, "Boron", "B", 10.81};
    periodicTable[5] = (Element){6, "Carbon", "C", 12.011};
    periodicTable[6] = (Element){7, "Nitrogen", "N", 14.007};
    periodicTable[7] = (Element){8, "Oxygen", "O", 15.999};
    periodicTable[8] = (Element){9, "Fluorine", "F", 18.998};
    periodicTable[9] = (Element){10, "Neon", "Ne", 20.180};
    // Add more elements as needed...
}

void printElement(Element element) {
    printf("Atomic Number: %d\n", element.atomicNumber);
    printf("Name: %s\n", element.name);
    printf("Symbol: %s\n", element.symbol);
    printf("Atomic Weight: %.3f\n", element.atomicWeight);
    printf("---------------------------\n");
}

void quizUser() {
    int score = 0;
    char answer[3];
    int questionCount = 5;

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("Answer the following questions:\n\n");

    srand(time(NULL));

    for (int i = 0; i < questionCount; i++) {
        int randIndex = rand() % MAX_ELEMENTS;
        Element elem = periodicTable[randIndex];

        printf("What is the symbol for %s?\n", elem.name);
        printf("Your answer: ");
        scanf("%s", answer);

        if (strcmp(answer, elem.symbol) == 0) {
            printf("Correct!\n\n");
            score++;
        } else {
            printf("Wrong! The correct answer is %s.\n\n", elem.symbol);
        }
    }

    printf("You got %d out of %d questions correct!\n", score, questionCount);
}

void displayMenu() {
    printf("Periodic Table Quiz Program\n");
    printf("1. Start Quiz\n");
    printf("2. Exit\n");
    printf("Choose an option: ");
}

int main() {
    initializePeriodicTable();

    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                quizUser();
                break;
            case 2:
                printf("Thank you for participating!\n");
                break;
            default:
                printf("Invalid choice. Please enter 1 or 2.\n");
        }

    } while (choice != 2);

    return 0;
}