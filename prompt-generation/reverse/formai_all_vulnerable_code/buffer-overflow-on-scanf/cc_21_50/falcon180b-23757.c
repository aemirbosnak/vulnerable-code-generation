//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int bingo_card[5][5] = {0};
    int i, j, num, count = 0, flag = 0;
    int player_choice = 0;
    int choice[5];
    char play_again;

    srand(time(NULL));

    do {
        system("clear");
        printf("\n\n\t\t\tWelcome to Bingo!\n\n");
        printf("Please choose a difficulty level:\n");
        printf("1. Easy\n2. Medium\n3. Hard\n");
        scanf("%d", &player_choice);

        if (player_choice == 1) {
            for (i = 0; i < 5; i++) {
                for (j = 0; j < 5; j++) {
                    num = rand() % 15 + 1;
                    bingo_card[i][j] = num;
                    printf("%d ", num);
                }
                printf("\n");
            }
        } else if (player_choice == 2) {
            for (i = 0; i < 5; i++) {
                for (j = 0; j < 5; j++) {
                    num = rand() % 30 + 1;
                    bingo_card[i][j] = num;
                    printf("%d ", num);
                }
                printf("\n");
            }
        } else {
            for (i = 0; i < 5; i++) {
                for (j = 0; j < 5; j++) {
                    num = rand() % 50 + 1;
                    bingo_card[i][j] = num;
                    printf("%d ", num);
                }
                printf("\n");
            }
        }

        printf("\n\nYour Bingo card:\n");
        for (i = 0; i < 5; i++) {
            for (j = 0; j < 5; j++) {
                printf("%d ", bingo_card[i][j]);
            }
            printf("\n");
        }

        while (1) {
            system("clear");
            printf("\n\n\t\t\tWelcome to Bingo!\n\n");
            printf("Please choose a number between 1 and %d:\n", 75);
            scanf("%d", &num);

            if (num <= 0 || num > 75) {
                printf("Invalid input. Please try again.\n");
                continue;
            }

            for (i = 0; i < 5; i++) {
                for (j = 0; j < 5; j++) {
                    if (bingo_card[i][j] == num) {
                        bingo_card[i][j] = 0;
                        count++;
                    }
                }
            }

            if (count == 25) {
                flag = 1;
                break;
            }
        }

        if (flag) {
            printf("\n\n\t\t\tCongratulations! You won!\n\n");
        } else {
            printf("\n\n\t\t\tSorry, you lost.\n\n");
        }

        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &play_again);
    } while (play_again == 'y' || play_again == 'Y');

    return 0;
}