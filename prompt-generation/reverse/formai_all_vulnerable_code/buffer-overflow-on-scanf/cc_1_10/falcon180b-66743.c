//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void game_init(void);
void game_loop(void);
void game_end(void);

// Global variables
int player_pos;
int player_score;
int game_state;

int main(void) {
    game_init();
    game_loop();
    game_end();

    return 0;
}

// Initialize the game
void game_init(void) {
    printf("Welcome to the Happy Game!\n");
    printf("You are a happy little cloud, floating through the sky.\n");
    printf("Your goal is to collect as many happy stars as you can.\n");
    printf("Press any key to begin...\n");

    // Initialize variables
    player_pos = 0;
    player_score = 0;
    game_state = 1;

    // Clear the screen
    system("clear");
}

// Main game loop
void game_loop(void) {
    char input;

    // Print the current game state
    printf("\n");
    printf("Score: %d\n", player_score);
    printf("Position: %d\n", player_pos);

    // Get player input
    printf("Press 'w' to move up,'s' to move down, 'a' to move left, or 'd' to move right.\n");
    scanf(" %c", &input);

    // Update player position based on input
    switch (input) {
        case 'w':
            player_pos--;
            break;
        case's':
            player_pos++;
            break;
        case 'a':
            player_pos--;
            break;
        case 'd':
            player_pos++;
            break;
        default:
            printf("Invalid input.\n");
    }

    // Check for collision with star
    if (player_pos == 5 || player_pos == 10 || player_pos == 15 || player_pos == 20) {
        printf("You collected a happy star! Your score is now %d.\n", player_score + 1);
        player_score++;
    } else {
        printf("You missed the star.\n");
    }

    // Check for game over
    if (player_pos < 0 || player_pos > 20) {
        printf("Game over! Your final score is %d.\n", player_score);
        game_state = 0;
    }
}

// End the game
void game_end(void) {
    printf("\nThanks for playing the Happy Game!\n");
}