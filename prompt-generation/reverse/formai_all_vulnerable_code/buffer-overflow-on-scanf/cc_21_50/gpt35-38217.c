//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int board[3][3];
int choices[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

int check_winner() {
    int i;

    // check rows
    for (i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }

    // check columns
    for (i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i];
        }
    }

    // check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }

    return 0; // no winner yet
}

int ai_move() {
    int available_choices[9];
    int i, j, k = 0;
    int choice;

    // copy choices array to available choices array
    for (i = 0; i < 9; i++) {
        if (choices[i] != -1) {
            available_choices[k] = choices[i];
            k++;
        }
    }

    // randomize available_choices array
    srand(time(NULL));
    for (i = 0; i < k; i++) {
        j = rand() % k;
        choice = available_choices[i];
        available_choices[i] = available_choices[j];
        available_choices[j] = choice;
    }

    // try to win
    for (i = 0; i < k; i++) {
        choice = available_choices[i];

        for (j = 0; j < 3; j++) {
            if (board[j][0] == board[j][1] && board[j][0] == 1 && choice == (j*3)+3) {
                return choice;
            }

            if (board[j][0] == board[j][2] && board[j][0] == 1 && choice == (j*3)+2) {
                return choice;
            }

            if (board[j][1] == board[j][2] && board[j][1] == 1 && choice == (j*3)+1) {
                return choice;
            }

            if (board[0][j] == board[1][j] && board[0][j] == 1 && choice == j+7) {
                return choice;
            }

            if (board[0][j] == board[2][j] && board[0][j] == 1 && choice == j+4) {
                return choice;
            }

            if (board[1][j] == board[2][j] && board[1][j] == 1 && choice == j+1) {
                return choice;
            }
        }

        if (board[0][0] == board[1][1] && board[0][0] == 1 && choice == 9) {
            return choice;
        }

        if (board[0][0] == board[2][2] && board[0][0] == 1 && choice == 5) {
            return choice;
        }

        if (board[1][1] == board[2][2] && board[1][1] == 1 && choice == 1) {
            return choice;
        }

        if (board[0][2] == board[1][1] && board[0][2] == 1 && choice == 7) {
            return choice;
        }

        if (board[0][2] == board[2][0] && board[0][2] == 1 && choice == 5) {
            return choice;
        }

        if (board[1][1] == board[2][0] && board[1][1] == 1 && choice == 3) {
            return choice;
        }
    }

    // try to block opponent
    for (i = 0; i < k; i++) {
        choice = available_choices[i];

        for (j = 0; j < 3; j++) {
            if (board[j][0] == board[j][1] && board[j][0] == 2 && choice == (j*3)+3) {
                return choice;
            }

            if (board[j][0] == board[j][2] && board[j][0] == 2 && choice == (j*3)+2) {
                return choice;
            }

            if (board[j][1] == board[j][2] && board[j][1] == 2 && choice == (j*3)+1) {
                return choice;
            }

            if (board[0][j] == board[1][j] && board[0][j] == 2 && choice == j+7) {
                return choice;
            }

            if (board[0][j] == board[2][j] && board[0][j] == 2 && choice == j+4) {
                return choice;
            }

            if (board[1][j] == board[2][j] && board[1][j] == 2 && choice == j+1) {
                return choice;
            }
        }

        if (board[0][0] == board[1][1] && board[0][0] == 2 && choice == 9) {
            return choice;
        }

        if (board[0][0] == board[2][2] && board[0][0] == 2 && choice == 5) {
            return choice;
        }

        if (board[1][1] == board[2][2] && board[1][1] == 2 && choice == 1) {
            return choice;
        }

        if (board[0][2] == board[1][1] && board[0][2] == 2 && choice == 7) {
            return choice;
        }

        if (board[0][2] == board[2][0] && board[0][2] == 2 && choice == 5) {
            return choice;
        }

        if (board[1][1] == board[2][0] && board[1][1] == 2 && choice == 3) {
            return choice;
        }
    }

    // just return a random available spot
    for (i = 0; i < k; i++) {
        choice = available_choices[i];
        return choice;
    }

    return -1; // should never happen
}

void print_board() {
    int i, j;

    printf("\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == 0) {
                printf(" ");
            } else if (board[i][j] == 1) {
                printf("X");
            } else {
                printf("O");
            }

            if (j != 2) {
                printf("|");
            }
        }

        printf("\n");
        if (i != 2) {
            printf("-+-+-\n");
        }
    }
}

int main() {
    int player = 1;
    int choice, row, column, winner = 0;
    int i;

    printf("Welcome to Tic Tac Toe!\n");

    while (winner == 0 && player <= 9) {
        print_board();
        if (player % 2 == 1) {
            printf("Player 1, enter a number 1-9: ");
            scanf("%d", &choice);

            // make sure choice is valid
            for (i = 0; i < 9; i++) {
                if (choices[i] == choice) {
                    choices[i] = -1;
                    break;
                }
            }

            row = (choice - 1) / 3;
            column = (choice - 1) % 3;

            board[row][column] = 1;
        } else {
            choice = ai_move();

            // make sure choice is valid
            for (i = 0; i < 9; i++) {
                if (choices[i] == choice) {
                    choices[i] = -1;
                    break;
                }
            }

            row = (choice - 1) / 3;
            column = (choice - 1) % 3;

            board[row][column] = 2;

            printf("AI chose %d.\n", choice);
        }

        winner = check_winner();
        player++;
    }

    print_board();

    if (winner == 1) {
        printf("Player 1 wins!\n");
    } else {
        printf("AI wins!\n");
    }

    return 0;
}