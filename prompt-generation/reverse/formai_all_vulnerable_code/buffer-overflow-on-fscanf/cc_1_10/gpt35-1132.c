//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ELEMENTS 118 // Total number of elements in the periodic table

// Struct that defines an element
typedef struct Element {
    char name[15];
    char symbol[3];
    int atomicNumber;
} Element;

// Function that reads the elements from a file and stores them in an array of elements
void readElements(Element elements[]) {
    FILE *file;
    file = fopen("elements.txt", "r");
    
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    
    int i = 0;
    while (!feof(file)) {
        fscanf(file, "%s %s %d", elements[i].name, elements[i].symbol, &elements[i].atomicNumber);
        i++;
    }
    
    fclose(file);
}

// Function that shuffles the array of elements using the Fisher-Yates shuffle algorithm
void shuffleElements(Element elements[]) {
    srand(time(NULL)); // Seed for random number generator
    
    for (int i = ELEMENTS - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        
        Element temp = elements[i];
        elements[i] = elements[j];
        elements[j] = temp;
    }
}

// Function that prints a welcome message and instructions for the quiz
void welcome() {
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be given the symbols for %d randomly chosen elements from the periodic table.\n", ELEMENTS);
    printf("You must enter the corresponding atomic number for each element.\n");
    printf("Good luck!\n\n");
}

int main() {
    Element elements[ELEMENTS];
    readElements(elements); // Read elements from file
    shuffleElements(elements); // Shuffle elements randomly
    
    int score = 0;
    
    welcome();
    
    for (int i = 0; i < ELEMENTS; i++) {
        printf("%d. What is the atomic number for %s? ", i+1, elements[i].symbol);
        
        int answer;
        scanf("%d", &answer);
        
        if (answer == elements[i].atomicNumber) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The atomic number for %s is %d.\n", elements[i].symbol, elements[i].atomicNumber);
        }
    }
    
    printf("\nCongratulations, you finished the quiz!\n");
    printf("You scored %d out of %d.\n", score, ELEMENTS);
    
    return 0;
}