//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 10
#define MAX_CARDS 75
#define MAX_NUMBERS 75

typedef struct {
    char name[20];
    int card[5][5];
} Player;

void initCard(Player *player) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            player->card[i][j] = 0;
        }
    }
}

void drawNumber(int numbers[MAX_NUMBERS]) {
    for (int i = 0; i < MAX_NUMBERS; i++) {
        int num = rand() % 75 + 1;
        while (num == 0 || num == 1 || num == 2 || num == 3 || num == 4 || num == 5 || num == 6 || num == 7 || num == 8 || num == 9) {
            num = rand() % 75 + 1;
        }
        numbers[i] = num;
    }
}

int checkWin(Player *player, int numbers[MAX_NUMBERS]) {
    int win = 0;
    for (int i = 0; i < 5; i++) {
        int count = 0;
        for (int j = 0; j < 5; j++) {
            if (player->card[i][j] == numbers[count]) {
                count++;
            }
        }
        if (count == 5) {
            win = 1;
            break;
        }
    }
    return win;
}

int main() {
    srand(time(NULL));
    Player players[MAX_PLAYERS];
    int numbers[MAX_NUMBERS];

    int numPlayers = 0;
    printf("How many players? ");
    scanf("%d", &numPlayers);

    for (int i = 0; i < numPlayers; i++) {
        printf("Player %d name: ", i+1);
        scanf("%s", players[i].name);
        initCard(&players[i]);
    }

    drawNumber(numbers);

    int winner = 0;
    for (int i = 0; i < numPlayers; i++) {
        if (checkWin(&players[i], numbers)) {
            winner = i + 1;
            break;
        }
    }

    printf("The winner is Player %d!\n", winner);

    return 0;
}