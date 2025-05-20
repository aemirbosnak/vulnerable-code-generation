//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of periodic table elements
typedef struct {
    char symbol[3];
    char name[20];
    int atomic_number;
} element;

// Define a function to check answers and update score
int check_answer(char *user_answer, char *correct_answer, int *score) {
    if (strcmp(user_answer, correct_answer) == 0) {
        *score += 1;
        printf("\nCorrect! Your score is now %d\n\n", *score);
        return 1;
    } else {
        printf("\nSorry, that is incorrect. Your score is still %d\n\n", *score);
        return 0;
    }
}

int main() {
    // Initialize the periodic table array
    element periodic_table[] = {
        {"H", "Hydrogen", 1},
        {"He", "Helium", 2},
        {"Li", "Lithium", 3},
        {"Be", "Beryllium", 4},
        {"B", "Boron", 5},
        {"C", "Carbon", 6},
        {"N", "Nitrogen", 7},
        {"O", "Oxygen", 8},
        {"F", "Fluorine", 9},
        {"Ne", "Neon", 10},
        {"Na", "Sodium", 11},
        {"Mg", "Magnesium", 12},
        {"Al", "Aluminum", 13},
        {"Si", "Silicon", 14},
        {"P", "Phosphorus", 15},
        {"S", "Sulfur", 16},
        {"Cl", "Chlorine", 17},
        {"Ar", "Argon", 18},
        {"K", "Potassium", 19},
        {"Ca", "Calcium", 20},
    };

    // Define variables for user input and score
    char user_input[3];
    int score = 0;

    // Welcome the user and prompt for input
    printf("Welcome to the C Periodic Table Quiz!\n");
    printf("Type the element symbol for each question and hit enter.\n");

    // Loop through each element in the periodic table
    for (int i = 0; i < 20; i++) {
        printf("\n%d. What is the symbol for %s? ", i+1, periodic_table[i].name);
        scanf("%s", user_input);

        // Check the user's answer using the check_answer function
        check_answer(user_input, periodic_table[i].symbol, &score);
    }

    // Give the user their final score and end the program
    printf("\nCongratulations, you finished the quiz with a score of %d/20!\n\n", score);

    return 0;
}