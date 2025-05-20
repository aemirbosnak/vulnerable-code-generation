//Falcon2-11B DATASET v1.0 Category: Table Game ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int players = 2;
    char* players_names[2];
    int table[10][10];

    for (int i = 0; i < 2; i++) {
        players_names[i] = malloc(20);
        printf("Enter player %d's name: ", i+1);
        scanf("%s", players_names[i]);
    }

    printf("\nTable:\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i == j)
                table[i][j] = "X";
            else
                table[i][j] = "O";
            printf("%c ", table[i][j]);
        }
        printf("\n");
    }

    int winner = 0;

    while (winner == 0) {
        int player = 1;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (table[i][j] == "X" || table[i][j] == "O") {
                    if (table[i][j] == "X")
                        player = 2;
                    else
                        player = 1;
                    break;
                }
            }
            if (player!= 1 && player!= 2)
                break;
        }

        if (player == 1) {
            printf("Player %d's turn.\n", player);
            printf("Enter the row and column where you want to place your 'X': ");
            int row = 0, column = 0;
            scanf("%d %d", &row, &column);
            if (row >= 0 && row <= 9 && column >= 0 && column <= 9) {
                if (table[row][column] == 0) {
                    table[row][column] = "X";
                    printf("Player %d won!\n", player);
                    winner = 1;
                } else {
                    printf("Invalid move!\n");
                }
            } else {
                printf("Invalid move!\n");
            }
        } else {
            printf("Player %d's turn.\n", player);
            printf("Enter the row and column where you want to place your 'O': ");
            int row = 0, column = 0;
            scanf("%d %d", &row, &column);
            if (row >= 0 && row <= 9 && column >= 0 && column <= 9) {
                if (table[row][column] == 0) {
                    table[row][column] = "O";
                    printf("Player %d won!\n", player);
                    winner = 1;
                } else {
                    printf("Invalid move!\n");
                }
            } else {
                printf("Invalid move!\n");
            }
        }
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (table[i][j] == "X" && table[i][j-1] == "X" && table[i][j+1] == "X" && table[i-1][j] == "X" && table[i+1][j] == "X") {
                table[i][j] = "X";
            }
            if (table[i][j] == "O" && table[i][j-1] == "O" && table[i][j+1] == "O" && table[i-1][j] == "O" && table[i+1][j] == "O") {
                table[i][j] = "O";
            }
        }
    }

    printf("\nTable:\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%c ", table[i][j]);
        }
        printf("\n");
    }

    free(players_names[0]);
    free(players_names[1]);

    return 0;
}