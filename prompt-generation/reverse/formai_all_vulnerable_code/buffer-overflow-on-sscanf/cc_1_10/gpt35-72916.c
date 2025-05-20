//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold information about each element
typedef struct {
    char name[20];
    char symbol[3];
    int atomicNumber;
    float atomicWeight;
} Element;

// Define an array to hold all of the elements
Element elements[118];

// Define a function to load the data from a file into the elements array
void loadElements() {
    FILE *file = fopen("periodic_table.txt", "r");
    if (file) {
        // Read the data from the file and load it into the elements array
        char line[50];
        int i = 0;
        while (fgets(line, sizeof(line), file)) {
            sscanf(line, "%s %s %d %f", elements[i].name, elements[i].symbol, &elements[i].atomicNumber, &elements[i].atomicWeight);
            i++;
        }
        fclose(file);
    } else {
        printf("Error opening file\n");
        exit(1);
    }
}

// Define a function to display the menu and get the user's choice
int getMenuChoice() {
    int choice;
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("Please choose one of the following options:\n");
    printf("1. Search for an element by name\n");
    printf("2. Search for an element by symbol\n");
    printf("3. Guess the symbol from the name\n");
    printf("4. Guess the name from the symbol\n");
    printf("5. Exit\n");
    printf("Your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Define a function to search for an element by name
void searchByName() {
    char name[20];
    printf("Please enter the name of the element: ");
    scanf("%s", name);
    for (int i = 0; i < 118; i++) {
        if (strcmp(name, elements[i].name) == 0) {
            printf("%s is element %d and has a symbol of %s with an atomic weight of %.2f\n", name, elements[i].atomicNumber, elements[i].symbol, elements[i].atomicWeight);
            return;
        }
    }
    printf("%s not found\n", name);
}

// Define a function to search for an element by symbol
void searchBySymbol() {
    char symbol[3];
    printf("Please enter the symbol of the element: ");
    scanf("%s", symbol);
    for (int i = 0; i < 118; i++) {
        if (strcmp(symbol, elements[i].symbol) == 0) {
            printf("%s with an atomic weight of %.2f is element %d\n", symbol, elements[i].atomicWeight, elements[i].atomicNumber);
            return;
        }
    }
    printf("%s not found\n", symbol);
}

// Define a function to check if the user's guess is correct
int checkGuess(char answer[], char guess[]) {
    int result = strcmp(answer, guess);
    if (result == 0) {
        printf("Correct!\n");
        return 1;
    } else {
        printf("Incorrect. The correct answer is %s.\n", answer);
        return 0;
    }
}

// Define a function to guess the symbol from the name
void guessSymbol() {
    char name[20], guess[3];
    printf("Please enter the name of the element: ");
    scanf("%s", name);
    for (int i = 0; i < 118; i++) {
        if (strcmp(name, elements[i].name) == 0) {
            printf("What is the symbol for %s? ", name);
            scanf("%s", guess);
            checkGuess(elements[i].symbol, guess);
            return;
        }
    }
    printf("%s not found\n", name);
}

// Define a function to guess the name from the symbol
void guessName() {
    char symbol[3], guess[20];
    printf("Please enter the symbol of the element: ");
    scanf("%s", symbol);
    for (int i = 0; i < 118; i++) {
        if (strcmp(symbol, elements[i].symbol) == 0) {
            printf("What is the name of %s? ", symbol);
            scanf("%s", guess);
            checkGuess(elements[i].name, guess);
            return;
        }
    }
    printf("%s not found\n", symbol);
}

// Define the main function to control the flow of the program
int main() {
    loadElements();
    int choice;
    do {
        choice = getMenuChoice();
        switch (choice) {
            case 1:
                searchByName();
                break;
            case 2:
                searchBySymbol();
                break;
            case 3:
                guessSymbol();
                break;
            case 4:
                guessName();
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 5);
    return 0;
}