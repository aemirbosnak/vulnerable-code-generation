//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4
#define NUM_PAIRS 8

typedef struct {
    int row;
    int col;
} Position;

typedef struct {
    int value;
    int is_matched;
} Card;

Card board[BOARD_SIZE][BOARD_SIZE];
Position cursor;
int num_matched_pairs;

void initialize_board()
{
    int values[NUM_PAIRS * 2];
    for (int i = 0; i < NUM_PAIRS * 2; i++) {
        values[i] = (i / 2) + 1;
    }

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            int index = rand() % (NUM_PAIRS * 2);
            board[i][j].value = values[index];
            board[i][j].is_matched = 0;
            values[index] = values[NUM_PAIRS * 2 - 1];
        }
    }
}

void print_board()
{
    printf(" ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf(" %d", i + 1);
    }
    printf("\n");

    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].is_matched) {
                printf(" ~~");
            } else if (i == cursor.row && j == cursor.col) {
                printf(" **");
            } else {
                printf(" ||");
            }
        }
        printf("\n");
    }
}

int get_input()
{
    int choice;
    while (1) {
        printf("Enter your choice (1-16, or 0 to exit): ");
        scanf("%d", &choice);
        if (choice >= 0 && choice <= 16) {
            return choice;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }
}

void make_move(int choice)
{
    int row = (choice - 1) / BOARD_SIZE;
    int col = (choice - 1) % BOARD_SIZE;

    if (board[row][col].is_matched) {
        printf("That card is already matched. Please try again.\n");
    } else {
        cursor.row = row;
        cursor.col = col;

        printf("You chose card %d, %d.\n", row + 1, col + 1);

        if (board[row][col].value == board[cursor.row][cursor.col].value) {
            printf("Match! You matched two cards with the value %d.\n", board[row][col].value);

            board[row][col].is_matched = 1;
            board[cursor.row][cursor.col].is_matched = 1;

            num_matched_pairs++;

            if (num_matched_pairs == NUM_PAIRS) {
                printf("Congratulations! You matched all the cards.\n");
                exit(0);
            }
        } else {
            printf("No match. Please try again.\n");
        }
    }
}

int main()
{
    srand(time(NULL));

    initialize_board();
    print_board();

    while (1) {
        int choice = get_input();
        if (choice == 0) {
            printf("Thank you for playing! Goodbye.\n");
            exit(0);
        } else {
            make_move(choice);
            print_board();
        }
    }

    return 0;
}