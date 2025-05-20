//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: recursive
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

void mark_bingo_card(int card[5][5], int num) {
    int i, j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (card[i][j] == num) {
                card[i][j] = 0;
            }
        }
    }
}

int check_bingo(int card[5][5]) {
    int i, j, count = 0;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (card[i][j]!= 0) {
                count++;
            }
        }
    }
    if (count == 0) {
        return 1;
    } else {
        return 0;
    }
}

void play_bingo(int card[5][5]) {
    int i, j, num;
    srand(time(NULL));
    while (1) {
        generate_bingo_card(card);
        print_bingo_card(card);
        printf("Do you want to mark a number? (y/n): ");
        scanf("%s", &num);
        if (num == 'y' || num == 'Y') {
            printf("Enter the number you want to mark: ");
            scanf("%d", &num);
            mark_bingo_card(card, num);
        } else if (num == 'n' || num == 'N') {
            if (check_bingo(card)) {
                printf("Bingo!\n");
                break;
            }
        } else {
            printf("Invalid input. Please try again.\n");
        }
    }
}

int main() {
    int card[5][5];
    play_bingo(card);
    return 0;
}