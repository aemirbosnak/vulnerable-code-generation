//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Define constant values */
#define ROOMS 5
#define MAX_GHOSTS 3

/* Function prototypes */
void print_instructions();
int play_game();

int main()
{
    char choice;
    srand(time(NULL)); // Set random seed
    
    do {
        print_instructions(); // Display instructions
        int score = play_game(); // Play game and get score
        
        // Display score and ask to play again
        printf("\nYour score was %d out of %d.\n", score, ROOMS);
        printf("Would you like to play again? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y');
    
    printf("Thanks for playing Haunted House Simulator!\n");
    return 0;
}

/* Display game instructions */
void print_instructions()
{
    printf("Welcome to Haunted House Simulator!\n");
    printf("You are trapped in a haunted house with %d rooms.\n", ROOMS);
    printf("There are ghosts hiding in %d of the rooms.\n", MAX_GHOSTS);
    printf("Your goal is to navigate the house and avoid the ghosts.\n");
    printf("Use the arrow keys to move around.\n");
    printf("Press any key to continue...");
    getchar(); // Wait for user input
}

/* Play the game and return the score */
int play_game()
{
    int position = 1; // Start in room 1
    int ghosts[MAX_GHOSTS]; // Initialize array to store ghost positions
    int i, j, score = 0;
    
    // Randomly place ghosts in rooms
    for (i = 0; i < MAX_GHOSTS; i++) {
        ghosts[i] = rand() % ROOMS + 1; // Range: 1-5
        // Check for duplicate positions
        for (j = 0; j < i; j++) {
            if (ghosts[i] == ghosts[j]) {
                i--; // Decrement to try again
                break;
            }
        }
    }
    
    printf("You are in room %d.\n", position);
    
    // Loop until user reaches end of house
    while (position < ROOMS) {
        int move = 0; // Initialize move value
        
        // Get user input
        printf("Enter a direction (1 = left, 2 = right): ");
        scanf("%d", &move);
        
        // Move left
        if (move == 1) {
            if (position == 1) {
                printf("You can't go that way.\n");
            } else {
                position--;
                printf("You are in room %d.\n", position);
            }
        
        // Move right
        } else if (move == 2) {
            position++;
            printf("You are in room %d.\n", position);
        }
        
        // Verify if there is a ghost in the room
        for (i = 0; i < MAX_GHOSTS; i++) {
            if (position == ghosts[i]) {
                printf("A ghost jumps out and scares you!\n");
                score++; // Increment score
            }
        }
    }
    
    printf("Congratulations! You have escaped the haunted house!\n");
    return score;
}