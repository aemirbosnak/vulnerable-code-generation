//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 5
#define MAX_COLS 5
#define NUM_BALLS 75

void print_card(int card[MAX_ROWS][MAX_COLS]) {
    int i, j;

    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            if (card[i][j] == 1) {
                printf("X ");
            } else {
                printf("_ ");
            }
        }
        printf("\n");
    }
}

void generate_ball(int ball[NUM_BALLS]) {
    int i;

    for (i = 0; i < NUM_BALLS; i++) {
        ball[i] = rand() % 15 + 1;
    }
}

int main() {
    int card[MAX_ROWS][MAX_COLS] = {{0}};
    int ball[NUM_BALLS] = {0};
    int i, j, k;

    srand(time(NULL));

    generate_ball(ball);

    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            card[i][j] = ball[i * MAX_COLS + j];
        }
    }

    printf("Bingo Card:\n");
    print_card(card);

    int player_choice[MAX_ROWS][MAX_COLS] = {{0}};

    printf("\nEnter your choices (1-15, separated by space): ");
    scanf("%d", &player_choice[0][0]);
    for (i = 1; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS - 1; j++) {
            scanf("%d", &player_choice[i][j]);
        }
        scanf("%d", &player_choice[i][MAX_COLS - 1]);
    }

    int matches = 0;

    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            if (card[i][j] == player_choice[i][j]) {
                matches++;
            }
        }
    }

    if (matches == 24) {
        printf("\nCongratulations! You won!\n");
    } else {
        printf("\nSorry, you lost.\n");
    }

    return 0;
}