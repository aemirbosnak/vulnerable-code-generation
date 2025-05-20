//FormAI DATASET v1.0 Category: Table Game ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes
void print_board(char board[]);
int is_valid_move(char board[], int move);
char get_winner(char board[]);
void make_move(char board[], int move, char player);
int get_computer_move(char board[]);
void play_game(char board[], char player, char computer);

// main function
int main(void) {
    char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char player, computer;
    int choice;

    // ask the player to choose their symbol (X or O)
    printf("Choose your symbol (X or O): ");
    scanf("%c", &player);

    // set the computer's symbol to the opposite of the player's symbol
    computer = (player == 'X') ? 'O' : 'X';

    // ask the player if they want to go first or second
    printf("Do you want to go first (1) or second (2)? ");
    scanf("%d", &choice);

    // make the first move depending on the player's choice
    if (choice == 1) {
        print_board(board);
        printf("Your move (1-9): ");
        scanf("%d", &choice);
        make_move(board, choice - 1, player);
        print_board(board);
    } else {
        choice = get_computer_move(board);
        make_move(board, choice, computer);
        printf("Computer's move: %d\n", choice + 1);
        print_board(board);
    }

    // play the game until there is a winner or the board is full
    play_game(board, player, computer);

    return 0;
}

// function to print the game board
void print_board(char board[]) {
    printf("\n");
    printf("%c | %c | %c\n", board[0], board[1], board[2]);
    printf("--+---+--\n");
    printf("%c | %c | %c\n", board[3], board[4], board[5]);
    printf("--+---+--\n");
    printf("%c | %c | %c\n", board[6], board[7], board[8]);
    printf("\n");
}

// function to check if a move is valid
int is_valid_move(char board[], int move) {
    if (move < 0 || move > 8 || board[move] == 'X' || board[move] == 'O') {
        return 0;
    } else {
        return 1;
    }
}

// function to check for a winner
char get_winner(char board[]) {
    if (board[0] == board[1] && board[1] == board[2]) {
        return board[0];
    } else if (board[3] == board[4] && board[4] == board[5]) {
        return board[3];
    } else if (board[6] == board[7] && board[7] == board[8]) {
        return board[6];
    } else if (board[0] == board[3] && board[3] == board[6]) {
        return board[0];
    } else if (board[1] == board[4] && board[4] == board[7]) {
        return board[1];
    } else if (board[2] == board[5] && board[5] == board[8]) {
        return board[2];
    } else if (board[0] == board[4] && board[4] == board[8]) {
        return board[0];
    } else if (board[2] == board[4] && board[4] == board[6]) {
        return board[2];
    } else if (board[0] != '1' && board[1] != '2' && board[2] != '3' && board[3] != '4'
        && board[4] != '5' && board[5] != '6' && board[6] != '7' && board[7] != '8'
        && board[8] != '9') {
        return 'T';
    } else {
        return ' ';
    }
}

// function to make a move
void make_move(char board[], int move, char player) {
    board[move] = player;
}

// function to get the computer's move
int get_computer_move(char board[]) {
    int move;
    srand(time(NULL));
    do {
        move = rand() % 9;
    } while (!is_valid_move(board, move));
    return move;
}

// function to play the game
void play_game(char board[], char player, char computer) {
    int choice;
    char winner;
    while (1) {
        // player's turn
        printf("Your move (1-9): ");
        scanf("%d", &choice);
        while (!is_valid_move(board, choice - 1)) {
            printf("Invalid move. Try again: ");
            scanf("%d", &choice);
        }
        make_move(board, choice - 1, player);
        print_board(board);
        winner = get_winner(board);
        if (winner != ' ') {
            break;
        }

        // computer's turn
        choice = get_computer_move(board);
        make_move(board, choice, computer);
        printf("Computer's move: %d\n", choice + 1);
        print_board(board);
        winner = get_winner(board);
        if (winner != ' ') {
            break;
        }
    }
    if (winner == player) {
        printf("You win!\n");
    } else if (winner == computer) {
        printf("Computer wins!\n");
    } else {
        printf("It's a tie!\n");
    }
}