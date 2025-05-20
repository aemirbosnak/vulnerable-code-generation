//FormAI DATASET v1.0 Category: Memory Game ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 16
#define MAX_TRIES 100

// function to initialize the board for the game
void initialize_board(int* board) {
    int values[8];
    int i, j, counter;

    // populate values with two of each number from 1 to 8
    for(i = 0; i < 8; i++) {
        values[i] = i+1;
        values[i+8] = i+1;
    }

    // shuffle the values
    for(i = 0; i < BOARD_SIZE; i++) {
        j = rand() % BOARD_SIZE;
        int tmp = values[i];
        values[i] = values[j];
        values[j] = tmp;
    }

    // place the shuffled values on the board
    counter = 0;
    for(i = 0; i < BOARD_SIZE; i++) {
        *(board+i) = values[counter];
        counter++;
        if(counter == 8) {
            counter = 0;
        }
    }
}

// function to print the current board state
void print_board(int* board, int* revealed) {
    int i;

    printf("Current Board State:\n");
    for(i = 0; i < BOARD_SIZE; i++) {
        if(*(revealed+i)) {
            printf("%d ", *(board+i));
        } else {
            printf("? ");
        }
        if((i+1) % 4 == 0) {
            printf("\n");
        }
    }
}

int main() {
    int board[BOARD_SIZE];
    int revealed[BOARD_SIZE] = {0};
    int user_choices[2];
    int num_choices = 0;
    int num_tries = 0;
    int i, j, correct = 0;

    srand(time(NULL));
    initialize_board(board);
    print_board(board, revealed);

    while(correct < 8) {
        if(num_tries == MAX_TRIES) {
            printf("\nGame Over - Maximum Tries Reached!\n");
            return 0;
        }

        printf("\nPlease enter two positions to reveal (1-16): ");
        scanf("%d %d", &user_choices[0], &user_choices[1]);
        num_tries++;

        // check for valid input
        for(i = 0; i < 2; i++) {
            if(user_choices[i] < 1 || user_choices[i] > BOARD_SIZE) {
                printf("Invalid choice - please enter a number between 1-16\n");
                num_choices = 0;
                break;
            } else {
                user_choices[i]--;
            }
        }

        // check for matching values
        if(board[user_choices[0]] == board[user_choices[1]]) {
            printf("Match!\n");
            for(i = 0; i < 2; i++) {
                revealed[user_choices[i]] = 1;
                num_choices = 0;
                correct++;
            }
        } else {
            printf("No match - try again.\n");
            for(i = 0; i < 2; i++) {
                num_choices = 0;
                if(!revealed[user_choices[i]]) {
                    revealed[user_choices[i]] = 1;
                }
            }
        }

        print_board(board, revealed);
    }

    printf("\nCongratulations - You Win!\n");
    printf("Number of Tries: %d\n", num_tries);

    return 0;
}