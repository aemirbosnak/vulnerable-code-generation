//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 10
#define MAX_INPUT_LENGTH 20

typedef struct {
    char name[MAX_INPUT_LENGTH];
    int score;
} Player;

int main() {
    int numPlayers;
    char input[MAX_INPUT_LENGTH];
    Player players[MAX_PLAYERS];
    int i;

    printf("Enter the number of players (up to %d): ", MAX_PLAYERS);
    scanf("%d", &numPlayers);

    for (i = 0; i < numPlayers; i++) {
        printf("Enter player %d's name: ", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }

    while (1) {
        printf("Enter a date (YYYY-MM-DD) or type'score' to see the scores: ");
        scanf("%s", input);

        if (strcmp(input, "score") == 0) {
            for (i = 0; i < numPlayers; i++) {
                printf("%s: %d\n", players[i].name, players[i].score);
            }
        } else {
            time_t date;
            struct tm *tm;

            if (strlen(input)!= 10 || sscanf(input, "%d-%d-%d", &tm->tm_year, &tm->tm_mon, &tm->tm_mday)!= 3) {
                printf("Invalid date format.\n");
                continue;
            }

            tm->tm_year -= 1900;
            tm->tm_mon--;

            date = mktime(tm);

            for (i = 0; i < numPlayers; i++) {
                if (players[i].score < date) {
                    players[i].score = date;
                }
            }
        }
    }

    return 0;
}