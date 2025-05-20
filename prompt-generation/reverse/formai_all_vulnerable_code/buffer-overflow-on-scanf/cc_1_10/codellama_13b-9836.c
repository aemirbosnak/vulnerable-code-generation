//Code Llama-13B DATASET v1.0 Category: Game ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Global variables
int player_score = 0;
int computer_score = 0;

// Function to generate a random number
int generate_random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to get player input
void get_player_input() {
    char choice;
    printf("Enter your choice: ");
    scanf("%c", &choice);
    if (choice == 'r') {
        player_score++;
    } else if (choice == 'p') {
        computer_score++;
    } else {
        printf("Invalid input. Try again.\n");
    }
}

// Function to display the scores
void display_scores() {
    printf("Player score: %d\n", player_score);
    printf("Computer score: %d\n", computer_score);
}

// Main function
int main() {
    srand(time(NULL));
    while (1) {
        // Generate a random number
        int random_number = generate_random_number(1, 3);
        // Print the number
        printf("Random number: %d\n", random_number);
        // Get player input
        get_player_input();
        // Display the scores
        display_scores();
        // Check if the player has won
        if (player_score == 5) {
            printf("You won! Congratulations!\n");
            break;
        }
    }
    return 0;
}