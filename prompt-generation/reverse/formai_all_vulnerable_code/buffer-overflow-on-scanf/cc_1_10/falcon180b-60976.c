//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARDS 100
#define MAX_PLAYERS 10

typedef struct {
    int id;
    char name[20];
    int card[MAX_CARDS];
} Player;

Player players[MAX_PLAYERS];
int num_players = 0;

void init_players() {
    int choice;
    do {
        printf("Enter number of players (1-10): ");
        scanf("%d", &choice);
    } while (choice < 1 || choice > MAX_PLAYERS);

    num_players = choice;

    for (int i = 0; i < num_players; i++) {
        printf("Enter player %d's name: ", i+1);
        scanf("%s", players[i].name);
        players[i].id = i+1;
    }
}

void shuffle(int deck[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        int j = rand() % n;
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

int main() {
    init_players();

    int deck[MAX_CARDS];
    for (int i = 1; i <= 75; i++) {
        deck[i-1] = i;
    }

    shuffle(deck, 75);

    for (int i = 0; i < num_players; i++) {
        for (int j = 0; j < 5; j++) {
            players[i].card[j] = deck[5*i+j];
        }
    }

    int called_num;
    printf("Press enter to start game\n");
    getchar();

    while (1) {
        for (int i = 0; i < num_players; i++) {
            printf("Player %d's cards:\n", players[i].id);
            for (int j = 0; j < 5; j++) {
                printf("%d ", players[i].card[j]);
            }
            printf("\n");
        }

        printf("Enter a number to call: ");
        scanf("%d", &called_num);

        int found = 0;
        for (int i = 0; i < num_players; i++) {
            for (int j = 0; j < 5; j++) {
                if (players[i].card[j] == called_num) {
                    players[i].card[j] = 0;
                    found = 1;
                    break;
                }
            }
            if (found) break;
        }

        if (!found) {
            printf("Invalid number called.\n");
            continue;
        }

        int winner = -1;
        for (int i = 0; i < num_players; i++) {
            int count = 0;
            for (int j = 0; j < 5; j++) {
                if (players[i].card[j]!= 0) {
                    count++;
                }
            }
            if (count == 0) {
                winner = i;
                break;
            }
        }

        if (winner == -1) {
            printf("Tie game.\n");
        } else {
            printf("Player %d wins!\n", players[winner].id);
            break;
        }
    }

    return 0;
}