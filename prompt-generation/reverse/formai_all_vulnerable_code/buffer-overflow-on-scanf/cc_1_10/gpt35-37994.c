//FormAI DATASET v1.0 Category: Chess AI ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BOARD_SIZE 8

/* Board represented as an 8x8 array */
char board[BOARD_SIZE][BOARD_SIZE];

/* Define piece types */
#define EMPTY  '.'
#define PAWN   'p'
#define ROOK   'r'
#define KNIGHT 'n'
#define BISHOP 'b'
#define QUEEN  'q'
#define KING   'k'

/* Define player types */
#define COMPUTER 1
#define HUMAN 2

/* Function prototypes */
void init_board();
void print_board();
void clear_board();
void move(char*, char*);
void computer_move();
void human_move();
int legal_move(char*, char*);
int is_in_check(int);

int main(void) {
    init_board();
    print_board();

    int player = HUMAN;

    while (1) {
        if (player == HUMAN) {
            human_move();
            player = COMPUTER;
        }
        else {
            computer_move();
            player = HUMAN;
        }

        print_board();
        if (is_in_check(player)) {
            printf("CHECK!\n");
        }
    }

    return 0;
}

/* Initializes the board with default starting positions */
void init_board() {
    memset(board, EMPTY, BOARD_SIZE*BOARD_SIZE);

    /* Set pawns */
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[1][i] = PAWN;
        board[6][i] = PAWN;
    }

    /* Set rooks */
    board[0][0] = ROOK;
    board[0][7] = ROOK;
    board[7][0] = ROOK;
    board[7][7] = ROOK;

    /* Set knights */
    board[0][1] = KNIGHT;
    board[0][6] = KNIGHT;
    board[7][1] = KNIGHT;
    board[7][6] = KNIGHT;

    /* Set bishops */
    board[0][2] = BISHOP;
    board[0][5] = BISHOP;
    board[7][2] = BISHOP;
    board[7][5] = BISHOP;

    /* Set queens */
    board[0][3] = QUEEN;
    board[7][3] = QUEEN;

    /* Set kings */
    board[0][4] = KING;
    board[7][4] = KING;
}

/* Prints out the current board */
void print_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

/* Clears the board */
void clear_board() {
    memset(board, EMPTY, BOARD_SIZE*BOARD_SIZE);
}

/* Parses input and calls move function with the appropriate arguments */
void human_move() {
    printf("Enter move (e.g. e2-e4): ");
    char input[9];
    scanf("%s", input);

    char* from = strtok(input, "-");
    char* to = strtok(NULL, "-");

    move(from, to);
}

/* Calculates and executes a move for the computer */
void computer_move() {
    /* Seed random number generator */
    srand(time(NULL));

    /* Generate random legal move */
    char from[3], to[3];
    do {
        from[0] = rand() % BOARD_SIZE + 'a';
        from[1] = rand() % BOARD_SIZE + '1';
        to[0] = rand() % BOARD_SIZE + 'a';
        to[1] = rand() % BOARD_SIZE + '1';
        from[2] = to[2] = '\0';
    } while (!legal_move(from, to));

    printf("Computer moves %s-%s\n", from, to);
    move(from, to);
}

/* Moves a piece from one square to another */
void move(char* from, char* to) {
    int from_x = from[0] - 'a';
    int from_y = from[1] - '1';
    int to_x = to[0] - 'a';
    int to_y = to[1] - '1';

    board[to_y][to_x] = board[from_y][from_x];
    board[from_y][from_x] = EMPTY;
}

/* Returns 1 if a move from 'from' to 'to' is legal, 0 otherwise */
int legal_move(char* from, char* to) {
    /* TODO: Implement this function */
    return 1;
}

/* Returns 1 if the current player is in check */
int is_in_check(int player) {
    /* TODO: Implement this function */
    return 0;
}