//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 5
#define COL 5
#define MAX_NUM 15
#define MIN_NUM 1

void print_bingo_card(int card[ROW][COL]) {
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            printf("%d ", card[i][j]);
        }
        printf("\n");
    }
}

void generate_bingo_card(int card[ROW][COL]) {
    int i, j;
    srand(time(NULL));
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            card[i][j] = rand() % MAX_NUM + MIN_NUM;
        }
    }
}

void check_win_condition(int card[ROW][COL]) {
    int i, j, count = 0;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            if (card[i][j] == 0) {
                count++;
            }
        }
    }
    if (count == 0) {
        printf("Congratulations! You won!\n");
    }
}

int main() {
    int bingo_card[ROW][COL];
    generate_bingo_card(bingo_card);
    printf("Your Bingo Card:\n");
    print_bingo_card(bingo_card);
    int called_num;
    printf("Enter called number: ");
    scanf("%d", &called_num);
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            if (bingo_card[i][j] == called_num) {
                bingo_card[i][j] = 0;
            }
        }
    }
    check_win_condition(bingo_card);
    return 0;
}