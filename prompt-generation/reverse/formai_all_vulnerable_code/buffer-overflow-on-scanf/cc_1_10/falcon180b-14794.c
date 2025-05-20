//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: realistic
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

void generateCard(Player *player) {
    int i, j;
    srand(time(NULL));
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            player->card[i][j] = rand() % 15 + 1;
        }
    }
}

void printCard(Player player) {
    int i, j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%d ", player.card[i][j]);
        }
        printf("\n");
    }
}

void generateNumbers(int numbers[MAX_NUMBERS]) {
    int i;
    srand(time(NULL));
    for (i = 0; i < MAX_NUMBERS; i++) {
        numbers[i] = rand() % 75 + 1;
    }
}

int checkWin(Player player, int numbers[MAX_NUMBERS]) {
    int i, j, count = 0;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (player.card[i][j] == numbers[count]) {
                count++;
            }
        }
    }
    return count == 25;
}

int main() {
    int i, j, k, players = 0, numbers[MAX_NUMBERS];
    char name[20];
    Player player[MAX_PLAYERS];

    printf("Enter number of players: ");
    scanf("%d", &players);

    for (i = 0; i < players; i++) {
        printf("Enter name for player %d: ", i + 1);
        scanf("%s", name);
        strcpy(player[i].name, name);
        generateCard(&player[i]);
    }

    generateNumbers(numbers);

    int winner = -1;
    for (i = 0; i < players; i++) {
        if (checkWin(player[i], numbers)) {
            winner = i;
            break;
        }
    }

    if (winner == -1) {
        printf("No winner!\n");
    } else {
        printf("Player %s wins!\n", player[winner].name);
    }

    return 0;
}