//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of an element's name
#define MAX_NAME_LEN 3

// Define the number of elements in the periodic table
#define NUM_ELEMENTS 118

// Define the maximum number of attempts allowed for each question
#define MAX_ATTEMPTS 3

// Define a struct to store information about an element
typedef struct Element {
    char symbol[MAX_NAME_LEN+1];
    char name[20];
    int atomic_number;
    int atomic_weight;
} Element;

// Define an array to store information about all elements in the periodic table
Element elements[NUM_ELEMENTS] = {
    {"H", "Hydrogen", 1, 1},
    {"He", "Helium", 2, 4},
    {"Li", "Lithium", 3, 7},
    // More elements here...
    {"Fr", "Francium", 87, 223},
    {"Ra", "Radium", 88, 226},
    {"Ac", "Actinium", 89, 227},
    // More elements here...
    {"Og", "Oganesson", 118, 294}
};

// Function to clear the input buffer
void clear_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Function to choose a random element from the periodic table
int choose_random_element() {
    return rand() % NUM_ELEMENTS;
}

// Function to display the rules of the game
void display_rules() {
    printf("Welcome to the Periodic Table quiz!\n");
    printf("You will be given the symbol of an element,");
    printf("and you must correctly enter the name of the element.\n");
    printf("You have %d attempts for each question.\n", MAX_ATTEMPTS);
}

// Function to get the user's answer to a question
void get_user_answer(char *answer) {
    printf("Enter the name of the element: ");
    fgets(answer, 20, stdin);
    answer[strcspn(answer, "\n")] = 0; // Remove the newline character
}

// Function to check if the user's answer is correct
int check_answer(int element_index, char *user_answer) {
    return strcmp(user_answer, elements[element_index].name) == 0;
}

// Function to play the game
void play_game() {
    int element_index, attempts_left, correct;
    char user_answer[20];

    // Choose a random element and initialize the number of attempts left
    element_index = choose_random_element();
    attempts_left = MAX_ATTEMPTS;

    // Loop until the user correctly identifies the element or runs out of attempts
    do {
        // Display the symbol of the element
        printf("Symbol: %s\n", elements[element_index].symbol);

        // Get the user's answer
        get_user_answer(user_answer);

        // Check if the answer is correct
        correct = check_answer(element_index, user_answer);
        if (correct) {
            printf("Correct!\n");
        } else {
            attempts_left--;
            if (attempts_left == 0) {
                printf("Sorry, you are out of attempts.\n");
                printf("The correct answer is %s.\n", elements[element_index].name);
            } else {
                printf("Incorrect. You have %d attempts left.\n", attempts_left);
            }
        }
    } while (!correct && attempts_left > 0);
}

// Main function to run the program
int main() {
    int play_again = 1;

    // Seed the random number generator
    srand(time(NULL));

    // Display the rules of the game
    display_rules();

    // Loop until the user decides to quit
    while (play_again) {
        // Play the game
        play_game();

        // Ask the user if they want to play again
        printf("Do you want to play again? (1=yes, 0=no) ");
        scanf("%d", &play_again);
        clear_buffer(); // Clear the input buffer
    }

    printf("Thank you for playing the Periodic Table quiz!\n");

    return 0;
}