//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: creative
#include <stdio.h>
#include <string.h>

#define MAX_ELEMENTS 10

typedef struct {
    char name[20];
    char symbol[3];
    int atomicNumber;
} Element;

void displayWelcomeMessage();
void displayElementDetails(Element elements[], int count);
void askQuizQuestions(Element elements[], int count);
void displayThankYouMessage();

int main() {
    Element elements[MAX_ELEMENTS] = {
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

    displayWelcomeMessage();
    
    char choice;
    do {
        printf("\nChoose an option:\n");
        printf("1. Display Periodic Table Elements\n");
        printf("2. Take the Element Quiz\n");
        printf("3. Exit\n");
        printf("Your choice: ");
        scanf(" %c", &choice);
        
        switch (choice) {
            case '1':
                displayElementDetails(elements, MAX_ELEMENTS);
                break;
            case '2':
                askQuizQuestions(elements, MAX_ELEMENTS);
                break;
            case '3':
                displayThankYouMessage();
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != '3');
    
    return 0;
}

void displayWelcomeMessage() {
    printf("************************************\n");
    printf("* Welcome to the Periodic Table Quiz *\n");
    printf("************************************\n");
}

void displayElementDetails(Element elements[], int count) {
    printf("\n********* Periodic Table Elements *********\n");
    for (int i = 0; i < count; i++) {
        printf("Element: %-10s | Symbol: %-2s | Atomic Number: %d\n",
               elements[i].name, elements[i].symbol, elements[i].atomicNumber);
    }
    printf("*******************************************\n");
}

void askQuizQuestions(Element elements[], int count) {
    int score = 0;
    char answer[3];

    printf("\n******** Quiz Time! ********\n");
    for (int i = 0; i < count; i++) {
        printf("What is the symbol of %s? ", elements[i].name);
        scanf("%s", answer);
        if (strcasecmp(answer, elements[i].symbol) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect! The correct symbol is %s.\n", elements[i].symbol);
        }
    }
    
    printf("\nYour total score: %d out of %d\n", score, count);
}

void displayThankYouMessage() {
    printf("\nThank you for playing! Goodbye!\n");
}