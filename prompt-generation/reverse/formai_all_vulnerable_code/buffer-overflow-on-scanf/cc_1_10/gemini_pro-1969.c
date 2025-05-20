//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Global variables
int table[6][6]; // The table
int player_x, player_y; // Player's coordinates
int score; // Player's score

// Function prototypes
void initialize_table();
void print_table();
void move_player(char direction);
int check_win();

int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Initialize the table
    initialize_table();

    // Print the table
    print_table();

    // Get the player's move
    char direction;
    while (1) {
        printf("Enter your move (w, a, s, d): ");
        scanf(" %c", &direction);

        // Move the player
        move_player(direction);

        // Print the table
        print_table();

        // Check if the player has won
        int win = check_win();
        if (win) {
            printf("You win!\n");
            break;
        }
    }

    return 0;
}

void initialize_table() {
    // Clear the table
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            table[i][j] = 0;
        }
    }

    // Place the player in the center of the table
    player_x = 3;
    player_y = 3;

    // Generate a random number for the score
    score = rand() % 100;
}

void print_table() {
    // Print the top border
    printf("╔═══╤═══╤═══╤═══╤═══╤═══╗\n");

    // Print the table
    for (int i = 0; i < 6; i++) {
        printf("║");
        for (int j = 0; j < 6; j++) {
            if (i == player_x && j == player_y) {
                printf(" P ");
            } else if (table[i][j] == 1) {
                printf(" X ");
            } else {
                printf("   ");
            }
            printf("│");
        }
        printf("\n");

        // Print the bottom border
        if (i < 5) {
            printf("╟───┼───┼───┼───┼───┼───╢\n");
        }
    }
    printf("╚═══╧═══╧═══╧═══╧═══╧═══╝\n");
}

void move_player(char direction) {
    switch (direction) {
        case 'w':
            if (player_x > 0) {
                player_x--;
            }
            break;
        case 'a':
            if (player_y > 0) {
                player_y--;
            }
            break;
        case 's':
            if (player_x < 5) {
                player_x++;
            }
            break;
        case 'd':
            if (player_y < 5) {
                player_y++;
            }
            break;
    }
}

int check_win() {
    // Check if the player is on the edge of the table
    if (player_x == 0 || player_x == 5 || player_y == 0 || player_y == 5) {
        return 1;
    }

    // Check if the player has collected all the score points
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (table[i][j] == 1) {
                return 0;
            }
        }
    }

    return 1;
}