//FormAI DATASET v1.0 Category: Table Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 8
#define NUM_PLAYERS 2
#define MAX_MOVES 200

// Structure for a player
typedef struct Player {
    int id;
    char name[20];
    int score;
    char colour;
} Player;

// Structure for a square on the board
typedef struct Square {
    int x;
    int y;
    char colour;
    char occupied;
    int piece_id;
} Square;

// Structure for a piece on the board
typedef struct Piece {
    int id;
    char type[20];
    int current_pos[2];
    char colour;
} Piece;

// Function to reset the board to its initial state
void reset_board(Square board[BOARD_SIZE][BOARD_SIZE]) {
    // Set each square's colour
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 0) {
                board[i][j].colour = 'W';
            } else {
                board[i][j].colour = 'B';
            }
            board[i][j].occupied = ' ';
            board[i][j].piece_id = -1;
            board[i][j].x = i;
            board[i][j].y = j;
        }
    }
    // Add the pieces to the board
    for (int i = 0; i < NUM_PLAYERS; i++) {
        board[i==0 ? 0: BOARD_SIZE-1][0].occupied = 'P';
        board[i==0 ? 0: BOARD_SIZE-1][0].piece_id = i;
        board[i==0 ? 0: BOARD_SIZE-1][0].colour = 'B';
        board[i==0 ? 0: BOARD_SIZE-1][7].occupied = 'P';
        board[i==0 ? 0: BOARD_SIZE-1][7].piece_id = i;
        board[i==0 ? 0: BOARD_SIZE-1][7].colour = 'B';
        board[i==0 ? 1: BOARD_SIZE-2][1].occupied = 'P';
        board[i==0 ? 1: BOARD_SIZE-2][1].piece_id = i;
        board[i==0 ? 1: BOARD_SIZE-2][1].colour = 'B';
        board[i==0 ? 1: BOARD_SIZE-2][6].occupied = 'P';
        board[i==0 ? 1: BOARD_SIZE-2][6].piece_id = i;
        board[i==0 ? 1: BOARD_SIZE-2][6].colour = 'B';
        board[i==0 ? 0: BOARD_SIZE-1][1].occupied = ' ';
        board[i==0 ? 0: BOARD_SIZE-1][6].occupied = ' ';
        board[i==0 ? 0: BOARD_SIZE-1][1].piece_id = -1;
        board[i==0 ? 0: BOARD_SIZE-1][6].piece_id = -1;
        board[i==0 ? 0: BOARD_SIZE-1][1].colour = 'W';
        board[i==0 ? 0: BOARD_SIZE-1][6].colour = 'W';
    }
}

// Function to print the board
void print_board(Square board[BOARD_SIZE][BOARD_SIZE]) {
    printf("\n   A  B  C  D  E  F  G  H\n");
    printf("  +-----------------------+\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d |", i+1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf(" %c |", board[j][i].occupied);
        }
        printf(" %d\n", i+1);
        printf("  +-----------------------+\n");
    }
    printf("   A  B  C  D  E  F  G  H\n\n");
}

// Function to get the next player
Player get_next_player(Player players[NUM_PLAYERS], int current_player) {
    if (current_player == NUM_PLAYERS-1) {
        return players[0];
    } else {
        return players[current_player+1];
    }
}

// Function to check if a move is valid
int is_valid_move(Square board[BOARD_SIZE][BOARD_SIZE], int x1, int y1, int x2, int y2, char piece) {
    // Check if the start and end positions are within the bounds of the board
    if (x1 < 0 || x1 >= BOARD_SIZE || y1 < 0 || y1 >= BOARD_SIZE || x2 < 0 || x2 >= BOARD_SIZE || y2 < 0 || y2 >= BOARD_SIZE) {
        return 0;
    }
    // Check if the start position is occupied by the selected piece
    if (board[x1][y1].occupied != piece) {
        return 0;
    }
    // Check if the end position is empty or occupied by an opponent's piece
    if (board[x2][y2].occupied == ' ') {
        return 1;
    } else if (board[x2][y2].occupied == piece) {
        return 0;
    } else if (board[x2][y2].piece_id != board[x1][y1].piece_id) {
        return 1;
    } else {
        return 0;
    }
}

// Function to make a move
void make_move(Square board[BOARD_SIZE][BOARD_SIZE], Piece pieces[NUM_PLAYERS*4], int current_player, int x1, int y1, int x2, int y2) {
    // Move the piece on the board
    board[x2][y2].occupied = board[x1][y1].occupied;
    board[x2][y2].piece_id = board[x1][y1].piece_id;
    board[x1][y1].occupied = ' ';
    board[x1][y1].piece_id = -1;
    // Update the piece's current position
    for (int i = 0; i < NUM_PLAYERS*4; i++) {
        if (pieces[i].colour == current_player && pieces[i].current_pos[0] == x1 && pieces[i].current_pos[1] == y1) {
            pieces[i].current_pos[0] = x2;
            pieces[i].current_pos[1] = y2;
            break;
        }
    }
}

// Function to check if the game is over
int is_game_over(int moves) {
    if (moves >= MAX_MOVES) {
        printf("The game has ended in a draw.\n");
        return 1;
    }
    return 0;
}

int main() {
    Square board[BOARD_SIZE][BOARD_SIZE];
    Piece pieces[NUM_PLAYERS*4];
    Player players[NUM_PLAYERS];
    int current_player = 0;
    int x1, y1, x2, y2, valid_move;
    int moves = 0;

    // Set up the players
    for (int i = 0; i < NUM_PLAYERS; i++) {
        players[i].id = i;
        printf("Enter player %d's name: ", i+1);
        scanf("%s", players[i].name);
        players[i].score = 0;
        players[i].colour = i == 0 ? 'W' : 'B';
    }

    // Set up the board
    reset_board(board);

    // Set up the pieces
    for (int i = 0; i < NUM_PLAYERS*4; i++) {
        pieces[i].id = i;
        if (i % 4 == 0 || i % 4 == 3) {
            strcpy(pieces[i].type, "Rook");
        } else if (i % 4 == 1 || i % 4 == 6) {
            strcpy(pieces[i].type, "Knight");
        } else if (i % 4 == 2 || i % 4 == 5) {
            strcpy(pieces[i].type, "Bishop");
        } else {
            strcpy(pieces[i].type, "Queen");
        }
        pieces[i].current_pos[0] = i < 4 ? i : BOARD_SIZE-1-(i-4);
        pieces[i].current_pos[1] = i < 4 ? 0 : BOARD_SIZE-1;
        pieces[i].colour = i < 4 ? 'W' : 'B';
        board[pieces[i].current_pos[0]][pieces[i].current_pos[1]].occupied = 'P';
        board[pieces[i].current_pos[0]][pieces[i].current_pos[1]].piece_id = i;
    }

    // Game loop
    while (1) {
        // Print the board
        printf("Current score:\n");
        for (int i = 0; i < NUM_PLAYERS; i++) {
            printf("%s: %d ", players[i].name, players[i].score);
        }
        printf("\n");
        print_board(board);

        // Get the current player's move
        printf("%s's turn. Enter your move (e.g. B1 C3): ", players[current_player].name);
        scanf("%c%d %c%d", &x1, &y1, &x2, &y2);
        getchar();

        // Check if the move is valid
        valid_move = is_valid_move(board, x1-'A', y1-1, x2-'A', y2-1, players[current_player].colour);
        if (!valid_move) {
            printf("Invalid move.\n");
            continue;
        }

        // Make the move
        make_move(board, pieces, players[current_player].colour, x1-'A', y1-1, x2-'A', y2-1);

        // Check if the game is over
        if (is_game_over(++moves)) {
            break;
        }

        // Get the next player
        current_player = (current_player + 1) % NUM_PLAYERS;
    }

    return 0;
}