//FormAI DATASET v1.0 Category: Memory Game ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_ATTEMPTS 5
#define BOARD_SIZE 16

void create_board(int board[], int size); // function to create the game board
void print_board(int board[], int size); // function to print the game board
void swap(int *a, int *b); // function to swap two elements in an array

int main()
{
    int board[BOARD_SIZE]; // game board
    int attempts[MAX_ATTEMPTS]; // number of attempts per player
    int player1_score = 0, player2_score = 0; // scores for both players
    int i, j, curr_player, curr_guess, curr_guess2, temp;

    // set random seed for shuffling the game board
    srand(time(NULL));

    // initialize game board and print
    create_board(board, BOARD_SIZE);
    print_board(board, BOARD_SIZE);

    // initialize attempts array to 0
    for (i = 0; i < MAX_ATTEMPTS; i++) {
        attempts[i] = 0;
    }

    // game loop
    for (i = 0; i < BOARD_SIZE / 2 && player1_score <= BOARD_SIZE / 2 && player2_score <= BOARD_SIZE / 2; i++) {
        curr_player = i % 2 + 1; // player 1 or 2
        printf("Player %d, please enter your first guess: ", curr_player);
        scanf("%d", &curr_guess);
        printf("Player %d, please enter your second guess: ", curr_player);
        scanf("%d", &curr_guess2);
    
        // check if both guesses are within board bounds
        if (curr_guess < 0 || curr_guess >= BOARD_SIZE || curr_guess2 < 0 || curr_guess2 >= BOARD_SIZE) {
            printf("Invalid guess.\n");
        }
        // check if guesses are the same
        else if (curr_guess == curr_guess2) {
            printf("You entered the same guess twice.\n");
        }
        // check if both guesses are already revealed
        else if (board[curr_guess] == -1 || board[curr_guess2] == -1) {
            printf("That tile has already been revealed.\n");
        }
        // check if guesses match
        else if (board[curr_guess] == board[curr_guess2]) {
            printf("Match!\n");
            board[curr_guess] = -1; // mark tiles as revealed
            board[curr_guess2] = -1;
            if (curr_player == 1) {
                player1_score++;
            } else {
                player2_score++;
            }
        }
        // guesses do not match
        else {
            printf("Sorry, no match.\n");
            temp = curr_player - 1;
            attempts[temp]++;
            if (attempts[temp] == MAX_ATTEMPTS) {
                printf("Player %d has run out of attempts.\n", curr_player);
                if (curr_player == 1) {
                    player2_score = BOARD_SIZE / 2 + 1;
                } else {
                    player1_score = BOARD_SIZE / 2 + 1;
                }
            }
        }
        // print current game board
        print_board(board, BOARD_SIZE);
        printf("Player 1 score: %d\n", player1_score);
        printf("Player 2 score: %d\n", player2_score);
    }

    // print final scores and winner
    printf("Player 1 final score: %d\n", player1_score);
    printf("Player 2 final score: %d\n", player2_score);
    if (player1_score > player2_score) {
        printf("Player 1 Wins!\n");
    } else if (player2_score > player1_score) {
        printf("Player 2 Wins!\n");
    } else {
        printf("Tie Game!\n");
    }

    return 0;
}

void create_board(int board[], int size)
{
    int i, j;
    int nums[size / 2];
    // fill nums array with pairs of numbers
    for (i = 0; i < size / 2; i++) {
        nums[i] = i + 1;
    }
    // shuffle nums array
    for (i = 0; i < size / 2; i++) {
        swap(&nums[i], &nums[rand() % (size/2)]);
    }
    // fill board with pairs of shuffled numbers
    for (i = 0; i < size / 2; i++) {
        board[i] = nums[i];
        board[i + size / 2] = nums[i];
    }
    // shuffle board
    for (i = 0; i < size; i++) {
        swap(&board[i], &board[rand() % size]);
    }
}

void print_board(int board[], int size)
{
    int i, j;
    printf("\n");
    for (i = 0; i < size; i++) {
        if (board[i] == -1) {
            printf("    ");
        } else {
            printf("[%2d]", board[i]);
        }
        if ((i + 1) % 4 == 0) {
            printf("\n");
        }
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}