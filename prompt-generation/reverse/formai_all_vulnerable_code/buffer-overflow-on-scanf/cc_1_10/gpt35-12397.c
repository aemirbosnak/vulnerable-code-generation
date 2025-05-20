//FormAI DATASET v1.0 Category: Memory Game ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_board(char board[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%c ", board[i]);
    }
    printf("\n");
}

int main() {
    printf("Welcome to the Memory Game!\n");
    printf("Match the letters to win!\n");

    // Initialize the board
    char board[16] = {'A', 'A', 'B', 'B', 'C', 'C', 'D', 'D', 'E', 'E', 'F', 'F', 'G', 'G', 'H', 'H'};
    int size = sizeof(board) / sizeof(board[0]);

    // Shuffle the board
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        int j = rand() % size;
        char temp = board[i];
        board[i] = board[j];
        board[j] = temp;
    }

    // Initialize variables to keep track of the game
    int first_choice_index = -1;
    int second_choice_index = -1;
    int num_matches = 0;
    int num_turns = 0;

    // Play the game!
    while (num_matches < size / 2) {
        printf("Turn %d\n", num_turns);
        print_board(board, size);

        // Get user input
        int choice;
        printf("Enter the index of your first choice: ");
        scanf("%d", &choice);
        if (choice < 0 || choice >= size || board[choice] == '-') {
            printf("Invalid choice, please try again!\n");
            continue;
        }

        // Reveal first choice
        board[choice] = board[choice] + 32; // Convert to lowercase
        print_board(board, size);

        if (first_choice_index == -1) {
            // Store first choice
            first_choice_index = choice;
        } else {
            // Store second choice and check for match
            second_choice_index = choice;
            if (board[first_choice_index] == board[second_choice_index]) {
                // Match found, mark choices as matched
                printf("MATCH!\n");
                board[first_choice_index] = '-';
                board[second_choice_index] = '-';
                num_matches++;
            } else {
                // No match, hide choices again
                printf("NO MATCH!\n");
                board[first_choice_index] = board[first_choice_index] - 32; // Convert back to uppercase
                board[second_choice_index] = board[second_choice_index] - 32;
            }
            // Reset variables for next turn
            first_choice_index = -1;
            second_choice_index = -1;
            num_turns++;
        }
    }

    // End of game
    printf("Congratulations, you won in %d turns!\n", num_turns);

    return 0;
}