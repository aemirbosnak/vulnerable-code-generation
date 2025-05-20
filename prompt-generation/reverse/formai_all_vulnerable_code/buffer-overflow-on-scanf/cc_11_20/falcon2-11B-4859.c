//Falcon2-11B DATASET v1.0 Category: Table Game ; Style: peaceful
#include <stdio.h>
#include <string.h>

int main() {
    char table[6][6] = {
        {'W', 'W', 'W', 'W', 'W', 'W'},
        {'W', 'W', 'W', 'W', 'W', 'W'},
        {'W', 'W', 'W', 'W', 'W', 'W'},
        {'W', 'W', 'W', 'W', 'W', 'W'},
        {'W', 'W', 'W', 'W', 'W', 'W'},
        {'W', 'W', 'W', 'W', 'W', 'W'}
    };

    char player_name[16];
    printf("Welcome to the peaceful game table!\n");
    printf("Please enter your name: ");
    scanf("%s", player_name);
    printf("Hello, %s! Welcome to the game table.\n", player_name);

    int row = 1;
    int col = 1;
    int move = 0;

    printf("The game table is a peaceful place where players can enjoy a friendly game of chess.\n");
    printf("Please select your piece:\n");
    printf("(1) Pawn\n");
    printf("(2) Knight\n");
    printf("(3) Bishop\n");
    printf("(4) Rook\n");
    printf("(5) Queen\n");
    printf("(6) King\n");

    printf("Enter your selection: ");
    scanf("%d", &move);
    printf("You have selected the %c piece.\n", table[row-1][col-1]);

    while (1) {
        printf("Please select your destination:\n");
        printf("(1) Up\n");
        printf("(2) Down\n");
        printf("(3) Left\n");
        printf("(4) Right\n");
        printf("(5) Diagonal Up Left\n");
        printf("(6) Diagonal Up Right\n");
        printf("(7) Diagonal Down Left\n");
        printf("(8) Diagonal Down Right\n");

        printf("Enter your selection: ");
        scanf("%d", &move);

        if (move == 1 || move == 2 || move == 3 || move == 4) {
            if (table[row-1][col]!= 'W') {
                table[row-1][col] = 'W';
                col++;
            }
            else if (table[row-1][col]!= 'B') {
                table[row-1][col] = 'W';
                col--;
            }
            else {
                printf("Invalid move!\n");
            }
            row++;
        }
        else if (move == 5 || move == 6 || move == 7 || move == 8) {
            if (table[row][col-1]!= 'W') {
                table[row][col-1] = 'W';
                col--;
            }
            else if (table[row][col-1]!= 'B') {
                table[row][col-1] = 'W';
                col++;
            }
            else {
                printf("Invalid move!\n");
            }
            row++;
        }
        else {
            printf("Invalid move!\n");
        }

        if (table[row][col] == 'W' && move == 6) {
            printf("Congratulations, %s! You have won the game!\n", player_name);
            break;
        }
        else if (table[row][col] == 'B' && move == 6) {
            printf("Sorry, %s, but you have lost the game!\n", player_name);
            break;
        }
    }

    printf("Thank you for playing the peaceful game table! Please come again.\n");

    return 0;
}