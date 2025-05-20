//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 5
#define MAX_COLS 5
#define MAX_NUMBERS 24

void print_bingo_card(int card[MAX_ROWS][MAX_COLS]) {
    int i, j;
    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            printf("%d ", card[i][j]);
        }
        printf("\n");
    }
}

int is_valid_number(int num) {
    if (num >= 1 && num <= 75) {
        return 1;
    }
    return 0;
}

void generate_bingo_card(int card[MAX_ROWS][MAX_COLS]) {
    int i, j, num;
    srand(time(NULL));
    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            do {
                num = rand() % MAX_NUMBERS + 1;
            } while (!is_valid_number(num));
            card[i][j] = num;
        }
    }
}

int main() {
    int bingo_card[MAX_ROWS][MAX_COLS];
    int user_card[MAX_ROWS][MAX_COLS];
    int i, j, k, match_count;

    generate_bingo_card(bingo_card);
    printf("Bingo Card:\n");
    print_bingo_card(bingo_card);

    printf("\nEnter your numbers separated by spaces: ");
    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            scanf("%d", &user_card[i][j]);
        }
    }

    match_count = 0;
    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            for (k = 0; k < MAX_NUMBERS; k++) {
                if (bingo_card[i][k] == user_card[k][j]) {
                    match_count++;
                    break;
                }
            }
        }
    }

    if (match_count == MAX_NUMBERS) {
        printf("\nBingo! You win!\n");
    } else {
        printf("\nSorry, you did not win this time.\n");
    }

    return 0;
}