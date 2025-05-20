//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for each element in the periodic table
struct element {
    char symbol[3];
    char name[20];
    int atomic_number;
};

// Declare an array of elements
struct element periodic_table[118];

// Fill the array with data for each element
void initialize_periodic_table() {
    strcpy(periodic_table[0].symbol, "H");
    strcpy(periodic_table[0].name, "Hydrogen");
    periodic_table[0].atomic_number = 1;
    // Fill in the rest of the elements here...
}

// Ask the user a periodic table question and check if the answer is correct
int ask_question(int atomic_number) {
    char guess[20];
    printf("What is the symbol for element #%d?\n", atomic_number);
    scanf("%s", guess);
    if (strcmp(guess, periodic_table[atomic_number-1].symbol) == 0) {
        printf("Correct! The symbol for element #%d is %s\n", atomic_number, guess);
        return 1;
    } else {
        printf("Incorrect. The symbol for element #%d is %s\n", atomic_number, periodic_table[atomic_number-1].symbol);
        return 0;
    }
}

int main() {
    // Call the function to initialize the periodic table array
    initialize_periodic_table();

    // Ask the user 5 random periodic table questions
    int i, score = 0;
    for (i = 0; i < 5; i++) {
        int atomic_number = rand() % 118 + 1;
        score += ask_question(atomic_number);
    }

    // Print the final score
    printf("You got %d out of 5 questions correct!\n", score);

    return 0;
}