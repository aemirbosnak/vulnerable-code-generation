//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5
#define MAX_TREASURES 3
#define MAX_TRAPS 2

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    Position position;
    int treasures;
} Player;

char board[SIZE][SIZE];
Player player;

void init_game() {
    srand(time(NULL));
    player.position.x = 0;
    player.position.y = 0;
    player.treasures = 0;

    // Initialize board with empty places
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = '.';
        }
    }

    // Place treasures and traps
    for (int i = 0; i < MAX_TREASURES; i++) {
        int x, y;
        do {
            x = rand() % SIZE;
            y = rand() % SIZE;
        } while (board[x][y] != '.');
        board[x][y] = 'T'; // Treasure
    }

    for (int i = 0; i < MAX_TRAPS; i++) {
        int x, y;
        do {
            x = rand() % SIZE;
            y = rand() % SIZE;
        } while (board[x][y] != '.');
        board[x][y] = 'X'; // Trap
    }

    board[player.position.x][player.position.y] = 'P'; // Player's starting position
}

void display_board() {
    printf("\nCurrent board:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("Treasures collected: %d\n", player.treasures);
}

void move_player(char direction) {
    int new_x = player.position.x;
    int new_y = player.position.y;

    switch (direction) {
        case 'w': new_x--; break; // Up
        case 's': new_x++; break; // Down
        case 'a': new_y--; break; // Left
        case 'd': new_y++; break; // Right
        default: printf("Invalid direction. Use w/a/s/d to move.\n"); return;
    }

    // Check boundaries
    if (new_x < 0 || new_x >= SIZE || new_y < 0 || new_y >= SIZE) {
        printf("Out of bounds! Try again.\n");
        return;
    }

    // Update player position
    board[player.position.x][player.position.y] = '.';
    player.position.x = new_x;
    player.position.y = new_y;

    // Check for treasure or trap
    if (board[new_x][new_y] == 'T') {
        player.treasures++;
        printf("You found a treasure! Total treasures: %d\n", player.treasures);
    } else if (board[new_x][new_y] == 'X') {
        printf("Oh no! You fell into a trap! Game Over.\n");
        exit(0);
    }
    
    board[new_x][new_y] = 'P'; // Update player position on board
}

int main() {
    char command;
    init_game();
    
    while (1) {
        display_board();
        printf("Enter move (w/a/s/d) or q to quit: ");
        scanf(" %c", &command); // space before %c to ignore any whitespace

        if (command == 'q') {
            printf("Thanks for playing!\n");
            break;
        }

        move_player(command);
    }

    return 0;
}