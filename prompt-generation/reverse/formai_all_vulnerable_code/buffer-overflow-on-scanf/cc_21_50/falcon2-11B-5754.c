//Falcon2-11B DATASET v1.0 Category: Bingo Simulator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int bingo[5][5] = {0};
    int row_num, col_num, num, i, j;
    char bingo_string[5][5] = {0};
    char bingo_char = 'X';
    char bingo_string_formatted[5][5] = {0};
    int bingo_number = 0;

    printf("Welcome to Romantic Bingo Simulator!\n");
    printf("Please enter your name:\n");
    scanf("%s", bingo_string[0]);
    printf("Hello, %s!\n", bingo_string[0]);

    printf("\nBingo cards are numbered from 1 to 5. Please choose your card:\n");
    printf("Enter 1 for the first card, 2 for the second card, 3 for the third card, 4 for the fourth card, or 5 for the fifth card:\n");
    scanf("%d", &row_num);

    for (i = 0; i < row_num; i++) {
        printf("\nEnter the number of the first column:\n");
        scanf("%d", &col_num);

        for (j = 0; j < col_num; j++) {
            printf("\nEnter the number to be called:\n");
            scanf("%d", &num);

            if (num == 1) {
                printf("Number 1 has been called!\n");
                bingo[row_num - 1][col_num - 1] = num;
            }
            else if (num == 2) {
                printf("Number 2 has been called!\n");
                bingo[row_num - 1][col_num - 2] = num;
            }
            else if (num == 3) {
                printf("Number 3 has been called!\n");
                bingo[row_num - 1][col_num - 3] = num;
            }
            else if (num == 4) {
                printf("Number 4 has been called!\n");
                bingo[row_num - 2][col_num - 4] = num;
            }
            else if (num == 5) {
                printf("Number 5 has been called!\n");
                bingo[row_num - 2][col_num - 5] = num;
            }
            else if (num == 6) {
                printf("Number 6 has been called!\n");
                bingo[row_num - 2][col_num - 6] = num;
            }
            else if (num == 7) {
                printf("Number 7 has been called!\n");
                bingo[row_num - 2][col_num - 7] = num;
            }
            else if (num == 8) {
                printf("Number 8 has been called!\n");
                bingo[row_num - 2][col_num - 8] = num;
            }
            else if (num == 9) {
                printf("Number 9 has been called!\n");
                bingo[row_num - 2][col_num - 9] = num;
            }
            else if (num == 10) {
                printf("Number 10 has been called!\n");
                bingo[row_num - 2][col_num - 10] = num;
            }
            else {
                printf("Invalid number entered.\n");
            }
        }

        printf("\nCurrent bingo board:\n");
        for (i = 0; i < row_num; i++) {
            for (j = 0; j < col_num; j++) {
                if (bingo[i][j] == 1) {
                    bingo_string_formatted[i][j] = '1';
                }
                else if (bingo[i][j] == 2) {
                    bingo_string_formatted[i][j] = '2';
                }
                else if (bingo[i][j] == 3) {
                    bingo_string_formatted[i][j] = '3';
                }
                else if (bingo[i][j] == 4) {
                    bingo_string_formatted[i][j] = '4';
                }
                else if (bingo[i][j] == 5) {
                    bingo_string_formatted[i][j] = '5';
                }
                else if (bingo[i][j] == 6) {
                    bingo_string_formatted[i][j] = '6';
                }
                else if (bingo[i][j] == 7) {
                    bingo_string_formatted[i][j] = '7';
                }
                else if (bingo[i][j] == 8) {
                    bingo_string_formatted[i][j] = '8';
                }
                else if (bingo[i][j] == 9) {
                    bingo_string_formatted[i][j] = '9';
                }
                else if (bingo[i][j] == 10) {
                    bingo_string_formatted[i][j] = '10';
                }
                else {
                    printf("Error: invalid number entered.\n");
                    break;
                }

                printf("%c ", bingo_string_formatted[i][j]);
            }

            printf("\n");
        }

        printf("\n");
    }

    printf("\nCongratulations! You have won the Romantic Bingo Simulator!\n");

    return 0;
}