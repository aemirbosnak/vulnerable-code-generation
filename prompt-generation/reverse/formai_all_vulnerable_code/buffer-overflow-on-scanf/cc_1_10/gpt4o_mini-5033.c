//GPT-4o-mini DATASET v1.0 Category: Bingo Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define BINGO_SIZE 5
#define TOTAL_NUMBERS 75
#define MAX_PLAYERS 10

typedef struct {
    int card[BINGO_SIZE][BINGO_SIZE];
    bool marked[BINGO_SIZE][BINGO_SIZE];
} BingoCard;

typedef struct {
    char name[30];
    BingoCard card;
} Player;

void generate_card(BingoCard *bingoCard) {
    int num, i, j, colRange[5][2] = {{1, 15}, {16, 30}, {31, 45}, {46, 60}, {61, 75}};
    bool used[TOTAL_NUMBERS + 1] = {false};

    for (j = 0; j < BINGO_SIZE; j++) {
        for (i = 0; i < BINGO_SIZE; i++) {
            if (j == 2 && i == 2) { // Free spot in the center
                bingoCard->card[i][j] = 0;
                bingoCard->marked[i][j] = true;
                continue;
            }
            do {
                num = rand() % (colRange[j][1] - colRange[j][0] + 1) + colRange[j][0];
            } while (used[num]);
            used[num] = true;
            bingoCard->card[i][j] = num;
            bingoCard->marked[i][j] = false;
        }
    }
}

void print_card(BingoCard bingoCard) {
    printf(" B   I   N   G   O\n");
    for (int i = 0; i < BINGO_SIZE; i++) {
        for (int j = 0; j < BINGO_SIZE; j++) {
            if (bingoCard.marked[i][j]) {
                printf("[%2d] ", bingoCard.card[i][j]);
            } else {
                printf(" %2d  ", bingoCard.card[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

void mark_number(BingoCard *bingoCard, int number) {
    for (int i = 0; i < BINGO_SIZE; i++) {
        for (int j = 0; j < BINGO_SIZE; j++) {
            if (bingoCard->card[i][j] == number) {
                bingoCard->marked[i][j] = true;
            }
        }
    }
}

bool check_bingo(BingoCard bingoCard) {
    for (int i = 0; i < BINGO_SIZE; i++) {
        if ((bingoCard.marked[i][0] && bingoCard.marked[i][1] && bingoCard.marked[i][2] &&
             bingoCard.marked[i][3] && bingoCard.marked[i][4]) ||
            (bingoCard.marked[0][i] && bingoCard.marked[1][i] && bingoCard.marked[2][i] &&
             bingoCard.marked[3][i] && bingoCard.marked[4][i])) {
            return true;
        }
    }
    if ((bingoCard.marked[0][0] && bingoCard.marked[1][1] && bingoCard.marked[2][2] &&
         bingoCard.marked[3][3] && bingoCard.marked[4][4]) ||
        (bingoCard.marked[0][4] && bingoCard.marked[1][3] && bingoCard.marked[2][2] &&
         bingoCard.marked[3][1] && bingoCard.marked[4][0])) {
        return true;
    }
    return false;
}

void draw_numbers(int *drawnNumbers, int *count) {
    while (*count < TOTAL_NUMBERS) {
        int number = rand() % TOTAL_NUMBERS + 1;
        if (!drawnNumbers[number]) {
            drawnNumbers[number] = 1;
            (*count)++;
            printf("Drawn number: %d\n", number);
            break;
        }
    }
}

int main() {
    srand(time(NULL));

    int drawnNumbers[TOTAL_NUMBERS + 1] = {0};
    int drawnCount = 0;

    Player players[MAX_PLAYERS];
    int playerCount;

    printf("Enter number of players (1-%d): ", MAX_PLAYERS);
    scanf("%d", &playerCount);
    while (playerCount < 1 || playerCount > MAX_PLAYERS) {
        printf("Invalid number of players. Please enter again: ");
        scanf("%d", &playerCount);
    }

    for (int i = 0; i < playerCount; i++) {
        printf("Enter name for player %d: ", i + 1);
        scanf("%s", players[i].name);
        generate_card(&players[i].card);
        printf("Generated Bingo Card for %s:\n", players[i].name);
        print_card(players[i].card);
    }

    printf("Starting the Bingo game!\n");
    while (drawnCount < TOTAL_NUMBERS) {
        draw_numbers(drawnNumbers, &drawnCount);
        for (int i = 0; i < playerCount; i++) {
            mark_number(&players[i].card, drawnNumbers[drawnCount]);
            printf("Bingo Card for %s after drawing number %d:\n", players[i].name, drawnNumbers[drawnCount]);
            print_card(players[i].card);
            if (check_bingo(players[i].card)) {
                printf("Bingo! %s wins with card:\n", players[i].name);
                print_card(players[i].card);
                return 0;
            }
        }
        printf("\n");
    }

    printf("No winners this time!\n");
    return 0;
}