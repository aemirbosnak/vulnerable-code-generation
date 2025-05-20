//FormAI DATASET v1.0 Category: Table Game ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to generate a random number between min and max */
int generate_random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

/* Function to print the game board on the console */
void print_game_board(int board_size, int arr[]) {
    for(int i=0; i<board_size; i++) {
        printf("| %d ", arr[i]);
    }
    printf("|\n");
}

/* Function to check if the game is complete */
int is_game_complete(int board_size, int arr[]) {
    for(int i=0; i<board_size; i++) {
        if(arr[i] != 0) {
            return 0;
        }
    }
    return 1;
}

/* Function to check if a particular move is valid */
int is_move_valid(int board_size, int arr[], int player, int move) {
    return (move >= 0 && move < board_size && arr[move] != 0);
}

/* Function to execute a move */
void execute_move(int board_size, int arr[], int player, int move) {
    int i = move;
    while(i < board_size && arr[i] != 0) {
        i++;
    }
    i--;
    arr[i] = player;
    while(i >= 0 && arr[i] != 0) {
        i--;
    }
    i++;
    int j=i+1;
    while(j < board_size && arr[j] == player) {
        arr[j-1] = player;
        j++;
    }
    if(j < board_size && arr[j] != 0) {
        arr[j] = player;
    }
}

/* Function to get the player's move */
int get_player_move(int board_size, int arr[], int player) {
    int move;
    printf("Player %d, please enter your move: ", player);
    scanf("%d", &move);
    while(!is_move_valid(board_size, arr, player, move)) {
        printf("Invalid move! Please enter a valid move: ");
        scanf("%d", &move);
    }
    return move;
}

/* Function to get the computer's move */
int get_computer_move(int board_size, int arr[], int player) {
    int move;
    printf("Computer's turn...\n");
    do {
        move = generate_random_number(0, board_size-1);
    } while(!is_move_valid(board_size, arr, player, move));
    printf("Computer chooses column %d.\n", move+1);
    return move;
}

/* Function to play the game */
void play_game(int board_size) {
    int arr[board_size];
    int player = 1;
    int computer = 2;
    int current_player;
    srand(time(0));
    for(int i=0; i<board_size; i++) {
        arr[i] = 2;
    }
    current_player = generate_random_number(1,2);
    printf("Initial board state:\n");
    print_game_board(board_size, arr);
    while(!is_game_complete(board_size, arr)) {
        int move;
        if(current_player == player) {
            move = get_player_move(board_size, arr, player);
        } else {
            move = get_computer_move(board_size, arr, computer);
        }
        execute_move(board_size, arr, current_player, move);
        printf("Player %d moves to column %d.\n", current_player, move+1); 
        print_game_board(board_size, arr);
        current_player = (current_player == player ? computer : player);
    }
    printf("Game Over!\n");
    printf("Final board state:\n");
    print_game_board(board_size, arr);
    printf("Player 1 score: %d\n", board_size - arr[0]);
    printf("Player 2 score: %d\n", board_size - arr[board_size-1]);
    if(board_size - arr[0] > board_size - arr[board_size-1]) {
        printf("Player 1 wins!\n");
    } else if(board_size - arr[0] < board_size - arr[board_size-1]) {
        printf("Player 2 wins!\n");
    } else {
        printf("It's a tie!\n");
    }
}

/* Main function */
int main() {
    int board_size;
    printf("Welcome to the C Table Game!\n");
    printf("Enter the size of the game board: ");
    scanf("%d", &board_size);
    play_game(board_size);
    return 0;
}