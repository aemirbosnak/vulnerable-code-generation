//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 5
#define NUM_PLAYERS 2

typedef struct {
    int row;
    int col;
} Position;

typedef struct {
    char name[20];
    Position position;
    int score;
} Player;

void print_grid(char grid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

void place_player(char grid[GRID_SIZE][GRID_SIZE], Player player) {
    grid[player.position.row][player.position.col] = player.name[0];
}

void move_player(char grid[GRID_SIZE][GRID_SIZE], Player *player, int direction) {
    switch (direction) {
        case 'w':
            if (player->position.row > 0) {
                player->position.row--;
            }
            break;
        case 'a':
            if (player->position.col > 0) {
                player->position.col--;
            }
            break;
        case 's':
            if (player->position.row < GRID_SIZE - 1) {
                player->position.row++;
            }
            break;
        case 'd':
            if (player->position.col < GRID_SIZE - 1) {
                player->position.col++;
            }
            break;
    }

    place_player(grid, *player);
}

int check_winner(char grid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] == 'X' && grid[i][j + 1] == 'X' && grid[i][j + 2] == 'X') {
                return 1;
            }
            if (grid[i][j] == 'O' && grid[i][j + 1] == 'O' && grid[i][j + 2] == 'O') {
                return 2;
            }
            if (grid[i][j] == 'X' && grid[i + 1][j] == 'X' && grid[i + 2][j] == 'X') {
                return 1;
            }
            if (grid[i][j] == 'O' && grid[i + 1][j] == 'O' && grid[i + 2][j] == 'O') {
                return 2;
            }
        }
    }

    return 0;
}

int main() {
    srand(time(NULL));

    char grid[GRID_SIZE][GRID_SIZE];
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = '.';
        }
    }

    Player players[NUM_PLAYERS];
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("Enter player %d's name: ", i + 1);
        scanf("%s", players[i].name);

        players[i].position.row = rand() % GRID_SIZE;
        players[i].position.col = rand() % GRID_SIZE;
        players[i].score = 0;

        place_player(grid, players[i]);
    }

    print_grid(grid);

    int current_player = 0;
    while (1) {
        printf("%s's turn: ", players[current_player].name);

        char direction;
        scanf(" %c", &direction);

        move_player(grid, &players[current_player], direction);

        print_grid(grid);

        int winner = check_winner(grid);
        if (winner != 0) {
            printf("%s wins!\n", players[winner - 1].name);
            break;
        }

        current_player = (current_player + 1) % NUM_PLAYERS;
    }

    return 0;
}