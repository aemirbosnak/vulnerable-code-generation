//FormAI DATASET v1.0 Category: Table Game ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Global Variables
int turn;
int game_board[3][3];
int game_active;
int move_row;
int move_column;

// Function Declarations
void initialize_game_board();
void play_game();
void print_game_board();
void get_player_move();
int is_game_over();
int check_winner();

// Main Function
int main() {
    printf("Welcome to the unique C Table Game\n");

    do{
        printf("\nEnter 1 to play or 0 to quit: ");
        scanf("%d", &game_active);
    } while(game_active != 1 && game_active != 0);

    srand(time(NULL));
    turn = rand() % 2;
    initialize_game_board();
    print_game_board();
    play_game();

    return 0;
}

// Function Definitions
void initialize_game_board() {
    int row, col;
    for(row = 0; row < 3; row++) {
        for(col = 0; col < 3; col++) {
            game_board[row][col] = -1;
        }
    }
}

void play_game() {
    while(is_game_over() == -1) {
        printf("It's Player %d's turn.\n", turn+1);
        get_player_move();
        print_game_board();
        turn = (turn + 1) % 2;
    }

    int winner = check_winner();
    if(winner == 0) {
        printf("Cat's game! Nobody wins!\n");
    } else {
        printf("*** Player %d wins! ***\n", winner);
    }
}

void print_game_board() {
    int row, col;
    printf("\n");
    for(row = 0; row < 3; row++) {
        for(col = 0; col < 3; col++) {
            if(game_board[row][col] == -1) {
                printf("_ ");
            } else if(game_board[row][col] == 0) {
                printf("O ");
            } else {
                printf("X ");
            }
        }
        printf("\n");
    }
}

void get_player_move() {
    do{
        printf("Enter a row (0, 1, or 2) and column (0, 1, or 2) to make your move: ");
        scanf("%d %d", &move_row, &move_column);
    } while((move_row > 2 || move_row < 0) || (move_column > 2 || move_column < 0) || game_board[move_row][move_column] != -1);

    game_board[move_row][move_column] = turn;
}

int is_game_over() {
    int row, col;
    for(row = 0; row < 3; row++) {
        for(col = 0; col < 3; col++) {
            if(game_board[row][col] == -1) {
                return -1;
            }
        }
    }
    return 1;
}

int check_winner() {
    int row;
    //check rows
    for(row = 0; row < 3; row++) {
        if(game_board[row][0] == game_board[row][1] && game_board[row][1] == game_board[row][2]) {
            return game_board[row][0];
        }
    }

    int col;
    //check columns
    for(col = 0; col < 3; col++) {
        if(game_board[0][col] == game_board[1][col] && game_board[1][col] == game_board[2][col]) {
            return game_board[0][col];
        }
    }

    //check diagonal 1
    if(game_board[0][0] == game_board[1][1] && game_board[1][1] == game_board[2][2]) {
        return game_board[0][0];
    }

    //check diagonal 2
    if(game_board[0][2] == game_board[1][1] && game_board[1][1] == game_board[2][0]) {
        return game_board[0][2];
    }

    //nobody wins
    return 0;
}