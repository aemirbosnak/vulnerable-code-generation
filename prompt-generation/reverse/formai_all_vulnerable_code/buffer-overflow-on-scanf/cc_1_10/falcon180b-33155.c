//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_bingo_card(int card[5][5]) {
    int i, j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%d ", card[i][j]);
        }
        printf("\n");
    }
}

void generate_bingo_card(int card[5][5]) {
    int i, j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            card[i][j] = rand() % 15 + 1;
        }
    }
}

int check_win(int card[5][5], int num) {
    int i, j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (card[i][j] == num) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int card[5][5], i, j, num;
    srand(time(NULL));
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            card[i][j] = 0;
        }
    }
    generate_bingo_card(card);
    printf("Bingo Card:\n");
    print_bingo_card(card);
    printf("Enter a number: ");
    scanf("%d", &num);
    if (check_win(card, num)) {
        printf("Bingo! You win!\n");
    } else {
        printf("Sorry, you lose.\n");
    }
    return 0;
}