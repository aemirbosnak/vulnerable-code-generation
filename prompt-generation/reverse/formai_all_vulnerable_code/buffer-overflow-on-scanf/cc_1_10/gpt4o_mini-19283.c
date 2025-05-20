//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TOTAL_ELEMENTS 10

typedef struct {
    char name[30];
    char symbol[3];
    int atomicNumber;
} Element;

Element elements[TOTAL_ELEMENTS] = {
    {"Hydrogen", "H", 1},
    {"Helium", "He", 2},
    {"Lithium", "Li", 3},
    {"Beryllium", "Be", 4},
    {"Boron", "B", 5},
    {"Carbon", "C", 6},
    {"Nitrogen", "N", 7},
    {"Oxygen", "O", 8},
    {"Fluorine", "F", 9},
    {"Neon", "Ne", 10}
};

void displayMenu() {
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("Choose an option below:\n");
    printf("1. Start Quiz\n");
    printf("2. Exit\n");
}

void quiz() {
    int score = 0;
    char answer[3];

    printf("Let's get started! Answer the following questions:\n");

    for (int i = 0; i < TOTAL_ELEMENTS; i++) {
        int randomIndex = rand() % TOTAL_ELEMENTS;
        printf("What is the symbol for %s? ", elements[randomIndex].name);
        scanf("%s", answer);

        if (strcasecmp(answer, elements[randomIndex].symbol) == 0) {
            printf("Correct! 🎉\n");
            score++;
        } else {
            printf("Oops! The correct answer is %s.\n", elements[randomIndex].symbol);
        }
    }

    printf("Quiz finished! Your score: %d out of %d\n", score, TOTAL_ELEMENTS);
}

int main() {
    srand(time(NULL));
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                quiz();
                break;
            case 2:
                printf("Thanks for playing! Goodbye! 👋\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}