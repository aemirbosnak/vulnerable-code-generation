//Code Llama-13B DATASET v1.0 Category: Terminal Based Game ; Style: invasive
// Invasive Terminal Based Game Example

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ROWS 10
#define MAX_COLS 10
#define MAX_SHIPS 5

// Structures
typedef struct {
    int row;
    int col;
    char type;
} Ship;

typedef struct {
    int row;
    int col;
    char type;
} Bomb;

// Function Prototypes
void clear_screen();
void print_game_board(char game_board[][MAX_COLS]);
void print_ship_status(Ship ships[], int num_ships);
void print_bomb_status(Bomb bombs[], int num_bombs);
void place_ships(Ship ships[], int num_ships);
void place_bombs(Bomb bombs[], int num_bombs);
void print_game_status();
void game_loop();

// Global Variables
char game_board[MAX_ROWS][MAX_COLS];
Ship ships[MAX_SHIPS];
Bomb bombs[MAX_ROWS * MAX_COLS];
int num_ships = 0;
int num_bombs = 0;

// Function Implementations
void clear_screen() {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            game_board[i][j] = ' ';
        }
    }
}

void print_game_board(char game_board[][MAX_COLS]) {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            printf("%c", game_board[i][j]);
        }
        printf("\n");
    }
}

void print_ship_status(Ship ships[], int num_ships) {
    printf("Ships:\n");
    for (int i = 0; i < num_ships; i++) {
        printf("  %c: (%d, %d)\n", ships[i].type, ships[i].row, ships[i].col);
    }
}

void print_bomb_status(Bomb bombs[], int num_bombs) {
    printf("Bombs:\n");
    for (int i = 0; i < num_bombs; i++) {
        printf("  (%d, %d)\n", bombs[i].row, bombs[i].col);
    }
}

void place_ships(Ship ships[], int num_ships) {
    for (int i = 0; i < num_ships; i++) {
        int row, col;
        char type;
        printf("Enter ship %d's coordinates (row, col, type): ", i + 1);
        scanf("%d %d %c", &row, &col, &type);
        ships[i].row = row;
        ships[i].col = col;
        ships[i].type = type;
    }
}

void place_bombs(Bomb bombs[], int num_bombs) {
    for (int i = 0; i < num_bombs; i++) {
        int row, col;
        printf("Enter bomb %d's coordinates (row, col): ", i + 1);
        scanf("%d %d", &row, &col);
        bombs[i].row = row;
        bombs[i].col = col;
    }
}

void print_game_status() {
    clear_screen();
    print_game_board(game_board);
    print_ship_status(ships, num_ships);
    print_bomb_status(bombs, num_bombs);
}

void game_loop() {
    while (1) {
        print_game_status();
        int row, col;
        printf("Enter a bomb's coordinates (row, col): ");
        scanf("%d %d", &row, &col);
        if (game_board[row][col] == 'X') {
            printf("You missed!\n");
            continue;
        }
        if (game_board[row][col] == 'O') {
            printf("You hit a ship!\n");
            game_board[row][col] = 'X';
            continue;
        }
        if (game_board[row][col] == ' ') {
            printf("You sunk a ship!\n");
            game_board[row][col] = 'X';
            continue;
        }
    }
}

int main() {
    srand(time(NULL));
    printf("Welcome to Invasive Terminal Based Game!\n");
    printf("Enter the number of ships: ");
    scanf("%d", &num_ships);
    printf("Enter the number of bombs: ");
    scanf("%d", &num_bombs);
    place_ships(ships, num_ships);
    place_bombs(bombs, num_bombs);
    game_loop();
    return 0;
}