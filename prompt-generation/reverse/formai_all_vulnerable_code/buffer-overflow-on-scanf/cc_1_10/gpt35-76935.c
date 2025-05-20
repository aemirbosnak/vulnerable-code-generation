//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: real-life
#include <stdio.h>
#include <string.h>

// struct to hold element information
struct element {
    int atomic_number;
    char symbol[3];
    char name[25];
    float atomic_mass;
};

// function to display quiz instructions
void instructions() {
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be given the symbol or name of an element and must enter the corresponding atomic number.\n");
    printf("Enter '0' to exit the quiz.\n");
    printf("Good luck!\n\n");
}

// function to check if input is valid
int is_input_valid(char *input) {
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] < '0' || input[i] > '9') {
            return 0;
        }
    }
    return 1;
}

int main() {
    instructions();

    // create array of elements to quiz on
    struct element elements[15] = {
        {1, "H", "Hydrogen", 1.008},
        {2, "He", "Helium", 4.003},
        {3, "Li", "Lithium", 6.941},
        {4, "Be", "Beryllium", 9.012},
        {5, "B", "Boron", 10.81},
        {6, "C", "Carbon", 12.01},
        {7, "N", "Nitrogen", 14.01},
        {8, "O", "Oxygen", 16.00},
        {9, "F", "Fluorine", 19.00},
        {10, "Ne", "Neon", 20.18},
        {11, "Na", "Sodium", 22.99},
        {12, "Mg", "Magnesium", 24.31},
        {13, "Al", "Aluminum", 26.98},
        {14, "Si", "Silicon", 28.09},
        {15, "P", "Phosphorus", 30.97}
    };

    // variable to hold user input
    char input[10];

    // loop through quiz questions
    for (int i = 0; i < 10; i++) {
        int index = i % 15; // get index of current element
        struct element current_element = elements[index];

        // ask question
        printf("Question %d: What is the atomic number of %s? ", i+1, current_element.symbol);

        // get input from user
        scanf(" %s", input);

        // check if user wants to exit
        if (strcmp(input, "0") == 0) {
            printf("Thanks for playing!\n");
            return 0;
        }

        // check if input is valid
        if (!is_input_valid(input)) {
            printf("Invalid input. Please enter a number.\n");
            i--; // ask question again
            continue;
        }

        // convert input to int and check if it is correct
        int answer = atoi(input);
        if (answer == current_element.atomic_number) {
            printf("Correct!\n\n");
        } else {
            printf("Incorrect. The correct answer is %d.\n\n", current_element.atomic_number);
        }
    }

    // done with quiz
    printf("Congratulations! You've completed the quiz.\n");
    printf("Thanks for playing!\n");
    return 0;
}