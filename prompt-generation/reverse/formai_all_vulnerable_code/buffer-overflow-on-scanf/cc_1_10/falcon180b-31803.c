//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MAX_NUM 15

void generate_bingo_card(int card[ROWS][COLS]) {
    int i, j, num;
    srand(time(NULL));
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            num = rand() % MAX_NUM + 1;
            card[i][j] = num;
        }
    }
}

void print_bingo_card(int card[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", card[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int bingo_card[ROWS][COLS];
    int i, j, num;
    char input[3];
    int flag = 0;
    int player_num;

    printf("Welcome to the Post-Apocalyptic Bingo!\n");
    printf("How many players? ");
    scanf("%d", &player_num);

    for (i = 0; i < player_num; i++) {
        generate_bingo_card(bingo_card[i]);
        printf("Player %d's card:\n", i + 1);
        print_bingo_card(bingo_card[i]);
    }

    int called_numbers[MAX_NUM];
    int called_num_count = 0;

    while (flag == 0) {
        int num = rand() % MAX_NUM + 1;
        called_numbers[called_num_count] = num;
        called_num_count++;

        printf("Called number: %d\n", num);

        for (i = 0; i < player_num; i++) {
            for (j = 0; j < COLS; j++) {
                if (bingo_card[i][j] == num) {
                    bingo_card[i][j] = -1;
                }
            }
            for (j = 0; j < COLS; j++) {
                if (bingo_card[i][j] == -1) {
                    flag = 1;
                    printf("Player %d wins!\n", i + 1);
                }
            }
        }
    }

    return 0;
}