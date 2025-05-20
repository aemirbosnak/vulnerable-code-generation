//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PLAYERS 10
#define MAX_STRING_LENGTH 100

typedef struct {
    char name[MAX_STRING_LENGTH];
    int score;
} player;

void init_player(player* p) {
    strcpy(p->name, "");
    p->score = 0;
}

int main() {
    player players[MAX_PLAYERS];
    int num_players;
    char input[MAX_STRING_LENGTH];
    char name[MAX_STRING_LENGTH];
    char temp[MAX_STRING_LENGTH];
    int i;

    printf("Enter number of players: ");
    scanf("%d", &num_players);

    for (i = 0; i < num_players; i++) {
        printf("Enter player %d's name: ", i+1);
        scanf("%s", name);
        strcpy(players[i].name, name);
        players[i].score = 0;
    }

    while (1) {
        printf("\nEnter command: ");
        scanf("%s", input);

        if (strcmp(input, "quit") == 0) {
            break;
        } else if (strcmp(input, "score") == 0) {
            printf("\nPlayer Scores:\n");
            for (i = 0; i < num_players; i++) {
                printf("%s: %d\n", players[i].name, players[i].score);
            }
        } else if (strcmp(input, "addscore") == 0) {
            printf("\nEnter player name: ");
            scanf("%s", name);

            for (i = 0; i < num_players; i++) {
                if (strcmp(players[i].name, name) == 0) {
                    printf("\nEnter score to add: ");
                    scanf("%d", &temp);
                    players[i].score += temp;
                    break;
                }
            }

            if (i == num_players) {
                printf("\nPlayer not found.\n");
            }
        } else {
            printf("\nInvalid command.\n");
        }
    }

    return 0;
}