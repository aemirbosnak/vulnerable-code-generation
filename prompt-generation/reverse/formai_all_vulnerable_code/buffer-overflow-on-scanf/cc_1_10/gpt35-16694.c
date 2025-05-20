//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLUMNS 5

// This struct represents a player
typedef struct {
    char name[20];
    int board[ROWS][COLUMNS];
    int bingo;
} player;

// This struct represents a bingo game
typedef struct {
    player players[4];
    int balls[75];
    int ball_count;
    int current_player;
} game;

// This function initializes a new game
void init_game(game* g) {
    srand(time(NULL));
    g->ball_count = 0;
    g->current_player = 0;

    // Initialize players' boards
    for (int i = 0; i < 4; i++) {
        printf("Enter name for player %d: ", i + 1);
        scanf("%s", g->players[i].name);
        for (int j = 0; j < ROWS; j++) {
            for (int k = 0; k < COLUMNS; k++) {
                g->players[i].board[j][k] = -1;
            }
        }
        g->players[i].bingo = 0;
    }

    // Initialize ball array
    for (int i = 0; i < 75; i++) {
        g->balls[i] = i + 1;
    }
}

// This function shuffles the array of balls
void shuffle_balls(int* balls, int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = balls[i];
        balls[i] = balls[j];
        balls[j] = temp;
    }
}

// This function draws a ball
int draw_ball(game* g) {
    if (g->ball_count >= 75) {
        return -1;
    }
    int ball = g->balls[g->ball_count];
    g->ball_count++;
    return ball;
}

// This function checks if a player has a bingo
int check_bingo(player* p) {
    int row, column, diagonal1, diagonal2;
    row = column = diagonal1 = diagonal2 = 0;

    // Check rows and columns
    for (int i = 0; i < ROWS; i++) {
        if (p->board[i][0] != -1 && p->board[i][0] == p->board[i][1] && p->board[i][0] == p->board[i][2] && p->board[i][0] == p->board[i][3] && p->board[i][0] == p->board[i][4]) {
            row = 1;
        }
        if (p->board[0][i] != -1 && p->board[0][i] == p->board[1][i] && p->board[0][i] == p->board[2][i] && p->board[0][i] == p->board[3][i] && p->board[0][i] == p->board[4][i]) {
            column = 1;
        }
    }

    // Check diagonals
    if (p->board[0][0] != -1 && p->board[0][0] == p->board[1][1] && p->board[0][0] == p->board[2][2] && p->board[0][0] == p->board[3][3] && p->board[0][0] == p->board[4][4]) {
        diagonal1 = 1;
    }
    if (p->board[0][4] != -1 && p->board[0][4] == p->board[1][3] && p->board[0][4] == p->board[2][2] && p->board[0][4] == p->board[3][1] && p->board[0][4] == p->board[4][0]) {
        diagonal2 = 1;
    }

    // Check if player has a bingo
    if (row || column || diagonal1 || diagonal2) {
        return 1;
    }
    return 0;
}

// This function prints a player's board
void print_board(player* p) {
    printf("Player: %s\n", p->name);
    printf("---------------------\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (j != 0) {
                printf("|");
            }
            if (p->board[i][j] == -1) {
                printf("  ");
            } else {
                printf("%-2d", p->board[i][j]);
            }
        }
        printf("\n");
    }
    printf("---------------------\n");
}

// This function prints the current game state
void print_game(game* g) {
    printf("\n\nCurrent Ball: %d\n", g->balls[g->ball_count - 1]);
    print_board(&g->players[g->current_player]);
    if (g->players[g->current_player].bingo) {
        printf("%s has BINGO!\n", g->players[g->current_player].name);
    }
}

int main() {
    // Initialize game
    game g;
    init_game(&g);
    shuffle_balls(g.balls, 75);

    // Main game loop
    while (1) {
        // Print game state
        print_game(&g);

        // Check for end of game
        if (g.ball_count >= 75 || g.players[g.current_player].bingo) {
            break;
        }

        // Get input from user
        printf("%s, enter 'd' to draw a ball or 'q' to quit: ", g.players[g.current_player].name);
        char c;
        scanf(" %c", &c);

        // Handle input
        if (c == 'd') {
            int ball = draw_ball(&g);
            if (ball == -1) {
                break;
            }

            // Update player's board
            for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLUMNS; j++) {
                    if (g.players[g.current_player].board[i][j] == ball) {
                        g.players[g.current_player].board[i][j] = -1;
                    }
                }
            }
            for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLUMNS; j++) {
                    if (g.players[g.current_player].board[i][j] == -1 && !check_bingo(&g.players[g.current_player])) {
                        g.players[g.current_player].board[i][j] = ball;
                        i = j = 5;
                    }
                }
            }

            // Check for bingo
            if (check_bingo(&g.players[g.current_player])) {
                g.players[g.current_player].bingo = 1;
            }

            // Switch to next player
            g.current_player = (g.current_player + 1) % 4;
        } else if (c == 'q') {
            break;
        } else {
            printf("Invalid input.\n");
        }
    }

    // Print final game state
    printf("\n\nFinal State:\n");
    print_game(&g);

    return 0;
}