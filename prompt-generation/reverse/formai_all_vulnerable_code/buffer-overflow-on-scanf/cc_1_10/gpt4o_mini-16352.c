//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold element information
typedef struct {
    char symbol[3];
    char name[20];
    int atomic_number;
    float atomic_weight;
} Element;

// Function to initialize the elements of the periodic table
void initializePeriodicTable(Element elements[]) {
    strcpy(elements[0].symbol, "H");
    strcpy(elements[0].name, "Hydrogen");
    elements[0].atomic_number = 1;
    elements[0].atomic_weight = 1.008;

    strcpy(elements[1].symbol, "He");
    strcpy(elements[1].name, "Helium");
    elements[1].atomic_number = 2;
    elements[1].atomic_weight = 4.0026;

    strcpy(elements[2].symbol, "Li");
    strcpy(elements[2].name, "Lithium");
    elements[2].atomic_number = 3;
    elements[2].atomic_weight = 6.94;

    strcpy(elements[3].symbol, "Be");
    strcpy(elements[3].name, "Beryllium");
    elements[3].atomic_number = 4;
    elements[3].atomic_weight = 9.0122;

    strcpy(elements[4].symbol, "B");
    strcpy(elements[4].name, "Boron");
    elements[4].atomic_number = 5;
    elements[4].atomic_weight = 10.81;

    // Add more elements as needed for the quiz...
}

// Function to ask the quiz question
void askQuestion(Element elements[], int count) {
    int randomIndex = rand() % count;
    Element selectedElement = elements[randomIndex];
    
    printf("What is the atomic number of %s (symbol: %s)? ", selectedElement.name, selectedElement.symbol);

    int inputNumber;
    scanf("%d", &inputNumber);

    if (inputNumber == selectedElement.atomic_number) {
        printf("Correct! 🎉 The atomic number of %s is indeed %d.\n", selectedElement.name, selectedElement.atomic_number);
    } else {
        printf("Incorrect! 😢 The correct atomic number of %s is %d.\n", selectedElement.name, selectedElement.atomic_number);
    }
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create an array of elements
    Element elements[5];
    initializePeriodicTable(elements);

    char playAgain;
    do {
        askQuestion(elements, 5);
        printf("Would you like to try another question? (y/n): ");
        scanf(" %c", &playAgain);  // Notice the space before %c to consume any newline character from previous input
    } while (playAgain == 'y' || playAgain == 'Y');

    printf("Thanks for playing the Periodic Table Quiz! Goodbye! 👋\n");
    return 0;
}