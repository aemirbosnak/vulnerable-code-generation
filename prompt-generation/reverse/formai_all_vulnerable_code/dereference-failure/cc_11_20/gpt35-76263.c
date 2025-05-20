//FormAI DATASET v1.0 Category: Table Game ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void print_board(int *board, int size) {
    printf(" ");
    for (int i = 0; i < size; i++) {
        printf(" %d", i);
    }
    printf("\n");

    for (int i = 0; i < size; i++) {
        printf("%d ", i);
        for (int j = 0; j < size; j++) {
            if (board[i*size + j] == 1) {
                printf("# ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    int size = rand()%10 + 5;
    int num_bombs = (size*size)/4;

    int *board = malloc(sizeof(int)*size*size);
    memset(board, 0, sizeof(int)*size*size);

    for (int i = 0; i < num_bombs; i++) {
        int x = rand()%size;
        int y = rand()%size;

        if (board[x*size + y] != 1) {
            board[x*size + y] = 1;
        } else {
            i--;
        }
    }

    printf("Instructions on how to play the game:\n");
    printf("* This is a surrealistic game. The board is a metaphor of your subconscious mind, and the bombs represent your fears and inner demons.\n");
    printf("* The goal of the game is to uncover all the safe spots. This represents facing and overcoming your fears and becoming a better person. Or, if you prefer, it can represent success and growth in your professional or personal life.\n");
    printf("* You can select a spot on the board by entering its coordinates (row, column) in the format 'row,column'.\n");
    printf("* If you select a bomb, you will lose. This represents giving in to your fears and letting them control your life.\n");
    printf("* If you select a safe spot, the number 0 will appear. This means that all adjacent spots are clear of bombs as well. This represents finding a way to overcome your fears by facing them head on and discovering that they were not so scary after all.\n");
    printf("\n");

    print_board(board, size);

    int num_safe = 0;
    int num_uncovered = 0;

    while (num_uncovered < size*size - num_bombs) {
        printf("Enter the coordinates of the spot you want to uncover: ");
        char input[10];
        fgets(input, 10, stdin);
        int row = input[0] - '0';
        int col = input[2] - '0';

        if (board[row*size + col] == 1) {
            printf("BOOM! You hit a bomb. Game over.\n");
            break;
        } else {
            num_uncovered++;
            int num_adj_bombs = 0;
            for (int i = row-1; i <= row+1; i++) {
                for (int j = col-1; j <= col+1; j++) {
                    if (i >= 0 && i < size && j >= 0 && j < size && board[i*size + j] == 1) {
                        num_adj_bombs++;
                    }
                }
            }
            board[row*size + col] = num_adj_bombs + 2;
            if (num_adj_bombs == 0) {
                for (int i = row-1; i <= row+1; i++) {
                    for (int j = col-1; j <= col+1; j++) {
                        if (i >= 0 && i < size && j >= 0 && j < size && board[i*size + j] == 0) {
                            num_uncovered++;
                            board[i*size + j] = 2;
                            int num_adj_bombs2 = 0;
                            for (int k = i-1; k <= i+1; k++) {
                                for (int l = j-1; l <= j+1; l++) {
                                    if (k >= 0 && k < size && l >= 0 && l < size && board[k*size + l] == 1) {
                                        num_adj_bombs2++;
                                    }
                                }
                            }
                            board[i*size + j] = num_adj_bombs2 + 2;
                        }
                    }
                }
            }
            print_board(board, size);
            num_safe++;
        }
    }

    if (num_safe == size*size - num_bombs) {
        printf("Congratulations! You have uncovered all the safe spots and defeated your inner demons.\n");
    }

    free(board);

    return 0;
}