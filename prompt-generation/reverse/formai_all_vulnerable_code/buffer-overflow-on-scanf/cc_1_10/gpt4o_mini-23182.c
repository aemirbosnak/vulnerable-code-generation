//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ROWS 5
#define MAX_COLS 5
#define MAX_OBJECTIVES 3

typedef struct {
    int x, y;
} Position;

typedef struct {
    Position pos;
    char symbol;
} GameObject;

typedef struct {
    GameObject player;
    GameObject objectives[MAX_OBJECTIVES];
    int score;
} GameState;

void initializeGame(GameState *game) {
    srand(time(0));
    game->player.pos.x = 0;
    game->player.pos.y = 0;
    game->player.symbol = 'P';
    game->score = 0;

    for (int i = 0; i < MAX_OBJECTIVES; i++) {
        game->objectives[i].pos.x = rand() % MAX_ROWS;
        game->objectives[i].pos.y = rand() % MAX_COLS;
        game->objectives[i].symbol = 'O';
    }
}

void printBoard(GameState *game) {
    char board[MAX_ROWS][MAX_COLS] = { ' ' };

    board[game->player.pos.x][game->player.pos.y] = game->player.symbol;

    for (int i = 0; i < MAX_OBJECTIVES; i++) {
        if (game->objectives[i].pos.x != -1) {
            board[game->objectives[i].pos.x][game->objectives[i].pos.y] = game->objectives[i].symbol;
        }
    }

    printf("\nScore: %d\n", game->score);
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            printf("| %c ", board[i][j]);
        }
        printf("|\n");
        for (int j = 0; j < MAX_COLS; j++) {
            printf("----");
        }
        printf("\n");
    }
}

int checkObjective(GameState *game) {
    for (int i = 0; i < MAX_OBJECTIVES; i++) {
        if (game->player.pos.x == game->objectives[i].pos.x && 
            game->player.pos.y == game->objectives[i].pos.y) {
            game->score++;
            game->objectives[i].pos.x = -1;  // Mark as collected
            return 1;
        }
    }
    return 0;
}

void processInput(GameState *game) {
    char input;
    printf("Move (w/a/s/d): ");
    scanf(" %c", &input);

    switch(input) {
        case 'w': 
            if (game->player.pos.x > 0) game->player.pos.x--; 
            break;
        case 's': 
            if (game->player.pos.x < MAX_ROWS - 1) game->player.pos.x++; 
            break;
        case 'a': 
            if (game->player.pos.y > 0) game->player.pos.y--; 
            break;
        case 'd': 
            if (game->player.pos.y < MAX_COLS - 1) game->player.pos.y++; 
            break;
        default:
            printf("Invalid move! Use w/a/s/d.\n");
            break;
    }

    if (checkObjective(game)) {
        printf("You've collected an objective!\n");
    }
}

int main() {
    GameState game;
    initializeGame(&game);
    
    while (1) {
        printBoard(&game);
        processInput(&game);
        if (game.score == MAX_OBJECTIVES) {
            printf("Congratulations! You've collected all objectives!\n");
            break;
        }
    }

    return 0;
}