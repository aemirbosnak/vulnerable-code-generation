//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function declarations
void draw_board(char board[]);
int get_user_move(char board[]);
int get_computer_move(char board[]);
int check_winning_move(char board[], char mark);

// main function
int main() {
    char board[9] = {'1','2','3','4','5','6','7','8','9'};
    int player_turn = 1, game_over = 0;
    char user_mark, computer_mark;

    printf("Welcome to Tic Tac Toe!\n");
    printf("Do you want to be X or O? ");
    scanf("%c", &user_mark);
    if(user_mark == 'X' || user_mark == 'x') {
        computer_mark = 'O';
    } else {
        computer_mark = 'X';
    }

    // game loop
    while(!game_over) {
        // player turn
        if(player_turn) {
            draw_board(board);
            int move = get_user_move(board);
            board[move] = user_mark;
            if(check_winning_move(board, user_mark)) {
                draw_board(board);
                printf("Congratulations! You won!\n");
                game_over = 1;
            }
            player_turn = 0;
        }
        // computer turn
        else {
            int move = get_computer_move(board);
            board[move] = computer_mark;
            if(check_winning_move(board, computer_mark)) {
                draw_board(board);
                printf("Sorry, you lost. Better luck next time!\n");
                game_over = 1;
            }
            player_turn = 1;
        }
        // check for tie game
        int count = 0;
        for(int i = 0; i < 9; i++) {
            if(board[i] == 'X' || board[i] == 'O') {
                count++;
            }
        }
        if(count == 9) {
            draw_board(board);
            printf("It's a tie game!\n");
            game_over = 1;
        }
    }

    return 0;
}

// function implementations
void draw_board(char board[]) {
    printf("\n");
    printf(" %c | %c | %c \n", board[0], board[1], board[2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[3], board[4], board[5]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[6], board[7], board[8]);
    printf("\n");
}

int get_user_move(char board[]) {
    int move;
    printf("Enter your move (1-9): ");
    scanf("%d", &move);
    move--;
    while(board[move] == 'X' || board[move] == 'O') {
        printf("That square is taken. Enter another move: ");
        scanf("%d", &move);
        move--;
    }
    return move;
}

int get_computer_move(char board[]) {
    int move;
    // check if there's a winning move for computer
    for(int i = 0; i < 9; i++) {
        if(board[i] != 'X' && board[i] != 'O') {
            char temp = board[i];
            board[i] = 'O';
            if(check_winning_move(board, 'O')) {
                move = i;
                return move;
            }
            board[i] = temp;
        }
    }
    // check if there's a winning move for user
    for(int i = 0; i < 9; i++) {
        if(board[i] != 'X' && board[i] != 'O') {
            char temp = board[i];
            board[i] = 'X';
            if(check_winning_move(board, 'X')) {
                move = i;
                board[i] = 'O';
                return move;
            }
            board[i] = temp;
        }
    }
    // if no winning move, pick a random corner or middle square
    int corners[4] = {0,2,6,8};
    srand(time(0));
    int random_index = rand() % 5;
    if(board[4] != 'X' && board[4] != 'O') {
        move = 4;
    } else {
        while(board[corners[random_index]] == 'X' || board[corners[random_index]] == 'O') {
            random_index = rand() % 5;
        }
        move = corners[random_index];
    }
    return move;
}

int check_winning_move(char board[], char mark) {
    // check rows
    for(int i = 0; i < 9; i += 3) {
        if(board[i] == mark && board[i+1] == mark && board[i+2] == mark) {
            return 1;
        }
    }
    // check columns
    for(int i = 0; i < 3; i += 1) {
        if(board[i] == mark && board[i+3] == mark && board[i+6] == mark) {
            return 1;
        }
    }
    // check diagonals
    if(board[0] == mark && board[4] == mark && board[8] == mark) {
        return 1;
    }
    if(board[2] == mark && board[4] == mark && board[6] == mark) {
        return 1;
    }
    return 0;
}