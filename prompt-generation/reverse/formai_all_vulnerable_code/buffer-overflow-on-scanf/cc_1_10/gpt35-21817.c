//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Welcome screen
void welcome_screen() {
    printf("\n  Welcome to the Maze of Adventure!\n");
    printf("------------------------------------\n");
    printf("  Can you find your way to the end?\n\n");
}

// Print choices
void print_choices() {
    printf("\nChoose your next move:\n");
    printf("1. Go left\n");
    printf("2. Go right\n");
    printf("3. Go straight\n");
    printf("4. Quit\n");
}

// Handle user input
int get_choice() {
    int choice;
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Random direction generator
int random_direction() {
    srand(time(0));
    return (rand() % 3) + 1;
}

// Handle game over
void game_over() {
    printf("\nUh oh! You've lost your way in the maze.\n");
    printf("Game over.\n");
}

// Handle winning condition
void win_game() {
    printf("\nCongratulations! You've made it out of the maze.\n");
    printf("You win!\n");
}

// Maze of Adventure
int main() {
    int direction;
    welcome_screen();

    // Start the game
    while(1) {
        // Print choices
        print_choices();

        // Get user input
        int choice = get_choice();
        if (choice == 4) {
            printf("\nGoodbye!\n");
            break;
        }

        // Generate random direction
        direction = random_direction();

        // Prompt user based on direction
        if (direction == 1) {
            printf("\nYou encounter a wall to your left.\n");
        } else if (direction == 2) {
            printf("\nYou encounter a wall to your right.\n");
        } else {
            printf("\nYou continue down the hallway.\n");
        }

        // Handle winning condition
        if (direction == 3 && choice == 3) {
            win_game();
            break;
        }

        // Handle losing condition
        if (direction != 3 && choice == direction) {
            game_over();
            break;
        }
    }

    return 0;
}