//FormAI DATASET v1.0 Category: Checkers Game ; Style: relaxed
#include <stdio.h>

// Board size
#define BOARD_SIZE 8

// Player symbols
#define PLAYER_ONE 'X'
#define PLAYER_TWO 'O'

// Board array
char board[BOARD_SIZE][BOARD_SIZE];

// Function to initialize the board
void initialize_board() {
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            if((i+j) % 2 == 0 && i < 3)
                board[i][j] = PLAYER_ONE;
            else if((i+j) % 2 == 0 && i > 4)
                board[i][j] = PLAYER_TWO;
            else
                board[i][j] = ' ';
        }
    }
}

// Function to display the board
void display_board() {
    printf("\n    ");
    for(int i = 0; i < BOARD_SIZE; i++) {
        printf("%c   ", i + 'a');
    }
    printf("\n");

    for(int i = 0; i < BOARD_SIZE; i++) {
        printf("  +");
        for(int j = 0; j < BOARD_SIZE; j++) {
            printf("---+");
        }
        printf("\n%c |", i + '1');
        for(int j = 0; j < BOARD_SIZE; j++) {
            printf(" %c |", board[i][j]);
        }
        printf("\n");
    }

    printf("  +");
    for(int i = 0; i < BOARD_SIZE; i++) {
        printf("---+");
    }
    printf("\n");
}

// Function to check if a move is valid
int is_valid_move(int x1, int y1, int x2, int y2, char player) {
    if(x2 < 0 || x2 >= BOARD_SIZE || y2 < 0 || y2 >= BOARD_SIZE)
        return 0;
    if(board[x2][y2] != ' ')
        return 0;
    int dx = (x2 - x1) > 0 ? 1 : -1;
    int dy = (y2 - y1) > 0 ? 1 : -1;
    if(abs(x2 - x1) != abs(y2 - y1) || abs(x2 - x1) != 2 || board[x1+dx][y1+dy] == ' ' || board[x1+dx][y1+dy] == player)
        return 0;
    return 1;
}

// Function to make a move
int make_move(int x1, int y1, int x2, int y2, char player) {
    if(is_valid_move(x1, y1, x2, y2, player)) {
        board[x1][y1] = ' ';
        board[x2][y2] = player;
        int dx = (x2 - x1) > 0 ? 1 : -1;
        int dy = (y2 - y1) > 0 ? 1 : -1;
        board[x1+dx][y1+dy] = ' ';
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char player = PLAYER_ONE;
    int x1, y1, x2, y2;

    initialize_board();

    while(1) {
        display_board();

        printf("\n%s's turn. Enter the coordinates of the piece you want to move (e.g. a3): ", player == PLAYER_ONE ? "Player One" : "Player Two");
        scanf("%c%d", &y1, &x1);
        x1--;
        y1 -= 'a';
        getchar();

        printf("\nEnter the coordinates of the space you want to move it to (e.g. b4): ");
        scanf("%c%d", &y2, &x2);
        x2--;
        y2 -= 'a';
        getchar();

        if(make_move(x1, y1, x2, y2, player)) {
            if(player == PLAYER_ONE)
                player = PLAYER_TWO;
            else
                player = PLAYER_ONE;
        } else {
            printf("\nInvalid move! Try again.\n");
        }
    }

    return 0;
}