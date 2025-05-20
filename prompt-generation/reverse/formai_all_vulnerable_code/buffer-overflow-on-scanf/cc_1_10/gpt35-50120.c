//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for each element
typedef struct {
    char symbol[3];
    char name[20];
    int atomic_number;
    double atomic_weight;
} Element;

// Define function for displaying element details
void display_element(Element e) {
    printf("Symbol: %s\t Name: %s\t Atomic Number: %d\t Atomic Weight: %.4f\n", 
           e.symbol, e.name, e.atomic_number, e.atomic_weight);
}

int main() {
    // Define the array of elements
    Element elements[7] = {
        { "He", "Helium", 2, 4.0026 },    // Helium
        { "Li", "Lithium", 3, 6.941 },    // Lithium
        { "Be", "Beryllium", 4, 9.0122 }, // Beryllium
        { "C", "Carbon", 6, 12.011 },     // Carbon
        { "N", "Nitrogen", 7, 14.007 },   // Nitrogen
        { "O", "Oxygen", 8, 15.999 },     // Oxygen
        { "Ne", "Neon", 10, 20.180 }      // Neon
    };

    // Welcome message and instructions
    printf("Welcome to the C Periodic Table Quiz!\n");
    printf("Please enter the correct atomic number for each element:\n");

    // Shuffle the elements
    for (int i = 0; i < 7; i++) {
        int r = rand() % (7 - i) + i;
        Element temp = elements[i];
        elements[i] = elements[r];
        elements[r] = temp;
    }

    // Ask for atomic numbers for each element
    int score = 0;
    for (int i = 0; i < 7; i++) {
        printf("\n%s\t", elements[i].name);
        int guess;
        scanf("%d", &guess);
        if (guess == elements[i].atomic_number) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %d.\n", elements[i].atomic_number);
        }
    }

    // Display the final score
    printf("\nYou scored %d out of 7.\n", score);

    // Display the element details (just for fun!)
    printf("\nHere are the element details:\n");
    for (int i = 0; i < 7; i++) {
        printf("%d. ", i+1);
        display_element(elements[i]);
    }

    return 0;
}