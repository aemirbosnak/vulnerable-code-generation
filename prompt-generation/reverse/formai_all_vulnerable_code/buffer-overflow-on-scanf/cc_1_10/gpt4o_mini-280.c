//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ELEMENTS 10
#define MAX_NAME_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[3];
    int atomicNumber;
} Element;

// Function prototypes
void initializeElements(Element elements[]);
void displayTitle();
void displayElement(int score);
int getRandomElementIndex(int limit);

int main() {
    Element elements[MAX_ELEMENTS];
    int score = 0;
    int attempts = 5;

    initializeElements(elements);
    displayTitle();

    while (attempts > 0) {
        int index = getRandomElementIndex(MAX_ELEMENTS);
        displayElement(elements[index].atomicNumber);

        char answer[MAX_NAME_LEN];
        printf("Your answer (name): ");
        scanf("%s", answer);

        if (strcasecmp(answer, elements[index].name) == 0) {
            printf("Correct!\n");
            score++;
            attempts--;
        } else {
            printf("Incorrect! The correct answer is %s.\n", elements[index].name);
            attempts--;
        }

        printf("Your current score: %d\n\n", score);
        printf("Attempts left: %d\n", attempts);
    }

    printf("\nYour final score: %d out of 5\n", score);
    return 0;
}

// Initialize elements
void initializeElements(Element elements[]) {
    strcpy(elements[0].name, "Hydrogen"); strcpy(elements[0].symbol, "H"); elements[0].atomicNumber = 1;
    strcpy(elements[1].name, "Helium"); strcpy(elements[1].symbol, "He"); elements[1].atomicNumber = 2;
    strcpy(elements[2].name, "Lithium"); strcpy(elements[2].symbol, "Li"); elements[2].atomicNumber = 3;
    strcpy(elements[3].name, "Beryllium"); strcpy(elements[3].symbol, "Be"); elements[3].atomicNumber = 4;
    strcpy(elements[4].name, "Boron"); strcpy(elements[4].symbol, "B"); elements[4].atomicNumber = 5;
    strcpy(elements[5].name, "Carbon"); strcpy(elements[5].symbol, "C"); elements[5].atomicNumber = 6;
    strcpy(elements[6].name, "Nitrogen"); strcpy(elements[6].symbol, "N"); elements[6].atomicNumber = 7;
    strcpy(elements[7].name, "Oxygen"); strcpy(elements[7].symbol, "O"); elements[7].atomicNumber = 8;
    strcpy(elements[8].name, "Fluorine"); strcpy(elements[8].symbol, "F"); elements[8].atomicNumber = 9;
    strcpy(elements[9].name, "Neon"); strcpy(elements[9].symbol, "Ne"); elements[9].atomicNumber = 10;
}

// Display title
void displayTitle() {
    printf("====================================\n");
    printf("     Welcome to the Periodic Table  \n");
    printf("          Quiz Game!                \n");
    printf("====================================\n");
}

// Display element details
void displayElement(int atomicNumber) {
    printf("What is the name of the element with atomic number %d?\n", atomicNumber);
}

// Get a random index
int getRandomElementIndex(int limit) {
    srand(time(NULL)); // Seed the random number generator
    return rand() % limit;
}