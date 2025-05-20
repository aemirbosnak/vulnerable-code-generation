//Falcon-180B DATASET v1.0 Category: Table Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 5

int main() {
    srand(time(NULL));
    int arr[SIZE][SIZE] = {0};
    int player = 1;
    int comp = 2;
    int choice;
    int flag = 0;
    int i, j;

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            arr[i][j] = rand() % 2;
        }
    }

    do {
        system("clear");
        printf("Player 1: X and Player 2: O\n");
        printf("Player %d's Turn\n", player);
        printf("Enter your choice of row and column: ");
        scanf("%d%d", &i, &j);

        if (arr[i - 1][j - 1]!= 0 && arr[i - 1][j - 1]!= 2) {
            arr[i - 1][j - 1] = player;
            player = (player % 2)? 1 : 2;
            flag = 1;
        } else {
            printf("Invalid move! Try again.\n");
        }

    } while (flag == 0);

    do {
        system("clear");
        printf("Player 1: X and Player 2: O\n");
        printf("Player %d's Turn\n", comp);
        int k, l;
        for (k = 0; k < SIZE; k++) {
            for (l = 0; l < SIZE; l++) {
                if (arr[k][l] == 0) {
                    arr[k][l] = comp;
                    comp = (comp % 2)? 1 : 2;
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
                break;
        }
    } while (flag == 0);

    int count1 = 0, count2 = 0;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (arr[i][j] == 1)
                count1++;
            else if (arr[i][j] == 2)
                count2++;
        }
    }

    if (count1 > count2)
        printf("Player 1 wins!\n");
    else if (count2 > count1)
        printf("Player 2 wins!\n");
    else
        printf("It's a draw!\n");

    return 0;
}