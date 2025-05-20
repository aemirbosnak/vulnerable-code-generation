//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5 // Number of rows in the game board
#define COLS 25 // Number of columns in the game board

/* Function to draw the game board with the player's spaceship */
void draw_board(int player_row, int player_col, char board[][COLS+1]) {
    system("cls"); // Clear the console window
    for(int i=0; i<ROWS; i++) {
        printf("%s\n", board[i]);
    }
    for(int i=0; i<player_row; i++) {
        printf("\n"); // Add empty rows above player spaceship
    }
    for(int i=0; i<player_col; i++) {
        printf(" "); // Add empty spaces to the left of player spaceship
    }
    printf("V\n"); // Draw the player's spaceship
}

/* Function to move the player's spaceship left */
void move_left(int *player_col) {
    if(*player_col > 0) {
        (*player_col)--;
    }
}

/* Function to move the player's spaceship right */
void move_right(int *player_col) {
    if(*player_col < COLS-1) {
        (*player_col)++;
    }
}

/* Function to update the position of the enemy invaders */
void update_invaders(int *invad_row, int *invad_col, int *invad_dir, int *invad_speed) {
    if(*invad_dir == 1) {
        (*invad_col)++;
    } else {
        (*invad_col)--;
    }
    if(*invad_col <= 0 || *invad_col >= COLS-1) {
        *invad_dir *= -1; // Change direction of movement
        (*invad_row)++;
        (*invad_speed)++; // Increase speed of movement
    }
}

int main() {
    char board[ROWS][COLS+1]; // Game board
    int player_row = ROWS-1, player_col = COLS/2; // Starting position of player spaceship
    int invad_row = 0, invad_col = COLS/2, invad_dir = 1, invad_speed = 1; // Starting position and movement of enemy invaders
    int score = 0; // Player's score
    char c; // Variable to store user input

    // Initialize game board with empty spaces
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            board[i][j] = ' ';
        }
        board[i][COLS] = '\0'; // Add null terminator to end of each row
    }

    // Draw initial game board
    draw_board(player_row, player_col, board);

    // Game loop
    while(1) {
        // Update position of enemy invaders
        update_invaders(&invad_row, &invad_col, &invad_dir, &invad_speed);

        // Check if player has collided with enemy invaders
        if(player_row == invad_row && player_col == invad_col) {
            printf("Game over! Final score: %d\n", score);
            break;
        }

        // Draw updated game board
        draw_board(player_row, player_col, board);

        // Print current score on console
        printf("Score: %d\n", score);

        // Get user input
        printf("Press 'a' to move left, 'd' to move right, 'q' to quit: ");
        scanf(" %c", &c);

        // Process user input
        switch(c) {
            case 'a':
                move_left(&player_col);
                break;
            case 'd':
                move_right(&player_col);
                break;
            case 'q':
                printf("Game over! Final score: %d\n", score);
                exit(0);
            default:
                break;
        }

        // Increase score by 1 for each successful move
        score++;

        // Slow down enemy invaders based on current speed setting
        int delay = 1000000 / invad_speed;
        usleep(delay);
    }

    return 0;
}