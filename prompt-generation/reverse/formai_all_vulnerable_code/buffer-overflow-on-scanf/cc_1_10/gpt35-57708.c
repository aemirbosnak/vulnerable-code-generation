//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char grid[3][3]; // the game board
int x, y; // the position of the next move

// initialize the game board
void init_board() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            grid[i][j] = '-';
        }
    }
}

// display the game board to the console
void print_board() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

// check if the game is over
int is_gameover() {
    int i, j;
    for (i = 0; i < 3; i++) {
        // check rows
        if (grid[i][0] != '-' && grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2]) {
            return 1;
        }
        // check columns
        if (grid[0][j] != '-' && grid[0][j] == grid[1][j] && grid[1][j] == grid[2][j]) {
            return 1;
        }
    }
    // check diagonals
    if (grid[0][0] != '-' && grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) {
        return 1;
    }
    if (grid[0][2] != '-' && grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]) {
        return 1;
    }
    // check if the board is full
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (grid[i][j] == '-') {
                return 0;
            }
        }
    }
    return 2; // tie game
}

// the AI's turn
void ai_move() {
    int i, j;
    // generate a random position
    do {
        srand(time(NULL)); // seed the random number generator
        i = rand() % 3;
        j = rand() % 3;
    } while (grid[i][j] != '-'); // keep generating positions until we find an empty spot
    grid[i][j] = 'O';
    x = i;
    y = j;
}

// the player's turn
void player_move() {
    int i, j;
    printf("Enter row and column [0-2]: ");
    scanf("%d %d", &i, &j);
    while (grid[i][j] != '-') { // make sure the spot is empty
        printf("Invalid move. Enter row and column [0-2]: ");
        scanf("%d %d", &i, &j);
    }
    grid[i][j] = 'X';
    x = i;
    y = j;
}

int main() {
    int gameover = 0;
    int turn = 0; // keep track of whose turn it is
    init_board();
    while (!gameover) {
        print_board();
        if (turn % 2 == 0) { // player's turn
            player_move();
        } else { // AI's turn
            ai_move();
        }
        gameover = is_gameover();
        turn++;
    }
    print_board();
    if (gameover == 1) {
        printf("Game over. %c wins!\n", grid[x][y]);
    } else if (gameover == 2) {
        printf("Game over. Tie game!\n");
    }
    return 0;
}