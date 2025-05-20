//FormAI DATASET v1.0 Category: Robot movement control ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 10
#define COL 10

void print_board(char board[ROW][COL], int* pos) {
    printf("\n");
    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            if(i == pos[0] && j == pos[1]) {
                printf("R ");
            } else {
                printf("%c ", board[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    char board[ROW][COL] = {
        {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
        {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
        {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
        {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
        {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
        {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
        {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
        {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
        {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
        {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'}
    };
    int pos[2] = {0, 0};
    board[pos[0]][pos[1]] = 'R';
    char input;
    while(1) {
        print_board(board, pos);
        printf("\nEnter direction (w=up, s=down, a=left, d=right): ");
        scanf("%c", &input);
        getchar();
        switch(input) {
            case 'w':
                if(pos[0] > 0) {
                    board[pos[0]][pos[1]] = '*';
                    pos[0] -= 1;
                    board[pos[0]][pos[1]] = 'R';
                } else {
                    printf("\nInvalid move! Out of bounds.\n");
                }
                break;
            case 's':
                if(pos[0] < ROW-1) {
                    board[pos[0]][pos[1]] = '*';
                    pos[0] += 1;
                    board[pos[0]][pos[1]] = 'R';
                } else {
                    printf("\nInvalid move! Out of bounds.\n");
                }
                break;
            case 'a':
                if(pos[1] > 0) {
                    board[pos[0]][pos[1]] = '*';
                    pos[1] -= 1;
                    board[pos[0]][pos[1]] = 'R';
                } else {
                    printf("\nInvalid move! Out of bounds.\n");
                }
                break;
            case 'd':
                if(pos[1] < COL-1) {
                    board[pos[0]][pos[1]] = '*';
                    pos[1] += 1;
                    board[pos[0]][pos[1]] = 'R';
                } else {
                    printf("\nInvalid move! Out of bounds.\n");
                }
                break;
            default:
                printf("\nInvalid input! Please enter w, s, a or d.\n");
                break;
        }
    }
    return 0;
}