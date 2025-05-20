//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTS 118 // Maximum number of elements in the periodic table

// Struct to hold element information
typedef struct {
    char* name;
    char* symbol;
    int atomicNumber;
    char* category;
} Element;

// Function prototypes
void loadElements(Element elements[]);
void displayMenu();
void displayElementInfo(Element element);
void quiz(Element elements[]);

int main() {
    Element elements[MAX_ELEMENTS];
    loadElements(elements);

    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayElementInfo(elements[0]);
                break;
            case 2:
                quiz(elements);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 3);

    return 0;
}

// Load element information from a text file
void loadElements(Element elements[]) {
    FILE* file = fopen("elements.txt", "r");
    if (file == NULL) {
        printf("Error loading elements.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s %d %s\n", elements[count].name, elements[count].symbol, &elements[count].atomicNumber, elements[count].category) == 4) {
        count++;
    }

    fclose(file);
}

// Display menu options
void displayMenu() {
    printf("\n");
    printf("1. Display element information\n");
    printf("2. Take a quiz\n");
    printf("3. Exit\n");
    printf("\n");
}

// Display information about an element
void displayElementInfo(Element element) {
    printf("Name: %s\n", element.name);
    printf("Symbol: %s\n", element.symbol);
    printf("Atomic number: %d\n", element.atomicNumber);
    printf("Category: %s\n", element.category);
    printf("\n");
}

// Quiz the user on element information
void quiz(Element elements[]) {
    int score = 0;
    int numQuestions = 10;

    for (int i = 0; i < numQuestions; i++) {
        int index = rand() % MAX_ELEMENTS;
        displayElementInfo(elements[index]);
        printf("What is the atomic number of %s? ", elements[index].name);
        scanf("%d", &score);

        if (score == elements[index].atomicNumber) {
            printf("Correct!\n");
        } else {
            printf("Incorrect. The correct answer is %d.\n", elements[index].atomicNumber);
        }
    }

    printf("\nYour final score is %d out of %d.\n", score, numQuestions);
}