//Gemma-7B DATASET v1.0 Category: Game ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char data;
    struct Node* next;
} Node;

typedef struct Game {
    Node* head;
    char board[MAX_BUFFER_SIZE];
    int score;
    int current_player;
} Game;

void initialize_game(Game* game) {
    game->head = NULL;
    game->score = 0;
    game->current_player = 0;
    game->board[0] = 'A';
    game->board[1] = 'B';
    game->board[2] = 'C';
    game->board[3] = 'D';
    game->board[4] = 'E';
    game->board[5] = 'F';
    game->board[6] = 'G';
    game->board[7] = 'H';
    game->board[8] = 'I';
    game->board[9] = 'J';
    game->board[10] = '\0';
}

void add_node(Game* game, char data) {
    Node* new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (game->head == NULL) {
        game->head = new_node;
    } else {
        game->head->next = new_node;
    }
}

void play_game(Game* game) {
    char move;
    int valid_move = 0;

    while (!valid_move) {
        printf("Enter your move (a-h): ");
        scanf(" %c", &move);

        for (int i = 0; i < 9; i++) {
            if (move == game->board[i] && game->board[i] != '-') {
                valid_move = 1;
            }
        }

        if (!valid_move) {
            printf("Invalid move. Please try again.\n");
        }
    }

    game->board[move] = 'O';

    // Check if the player has won or if the game is a draw
    if (check_win(game) || draw_game(game)) {
        valid_move = 0;
    }
}

int check_win(Game* game) {
    // Check rows
    for (int i = 0; i < 9; i++) {
        if (game->board[i] == game->board[i + 1] && game->board[i] == game->board[i + 2] && game->board[i] != '-') {
            return 1;
        }
    }

    // Check columns
    for (int i = 0; i < 9; i++) {
        if (game->board[i] == game->board[i + 3] && game->board[i] == game->board[i + 6] && game->board[i] != '-') {
            return 1;
        }
    }

    // Check diagonals
    if (game->board[0] == game->board[4] && game->board[0] == game->board[8] && game->board[0] != '-') {
        return 1;
    }

    if (game->board[2] == game->board[4] && game->board[2] == game->board[6] && game->board[2] != '-') {
        return 1;
    }

    return 0;
}

int draw_game(Game* game) {
    for (int i = 0; i < 9; i++) {
        if (game->board[i] == '-') {
            return 0;
        }
    }

    return 1;
}

int main() {
    Game game;
    initialize_game(&game);

    while (!game.score) {
        play_game(&game);
    }

    printf("Game Over! The winner is: ");
    printf("Player %c\n", game.board[game.current_player]);

    return 0;
}