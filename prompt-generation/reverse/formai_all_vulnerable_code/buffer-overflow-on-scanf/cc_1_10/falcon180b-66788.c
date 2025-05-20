//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_PLAYERS 4
#define MAX_DATE_LENGTH 100

typedef struct {
    char name[20];
    int score;
} Player;

Player players[MAX_PLAYERS];
char date_str[MAX_DATE_LENGTH];

void initialize_players() {
    for (int i = 0; i < MAX_PLAYERS; i++) {
        players[i].name[0] = '\0';
        players[i].score = 0;
    }
}

void print_players() {
    printf("Player Name | Score\n");
    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("%s | %d\n", players[i].name, players[i].score);
    }
}

int main() {
    initialize_players();

    while (1) {
        printf("Enter a date (YYYY-MM-DD): ");
        scanf("%s", date_str);

        for (int i = 0; i < MAX_PLAYERS; i++) {
            if (players[i].name[0] == '\0') {
                printf("Enter player name: ");
                scanf("%s", players[i].name);
                break;
            }
        }

        time_t t = time(NULL);
        struct tm *tm = localtime(&t);
        strftime(date_str, MAX_DATE_LENGTH, "%A, %B %d, %Y", tm);

        int player_index = -1;
        for (int i = 0; i < MAX_PLAYERS; i++) {
            if (strcmp(players[i].name, "Player 1") == 0) {
                player_index = i;
                break;
            }
        }

        if (player_index == -1) {
            printf("Player not found.\n");
        } else {
            printf("Player %s, today is %s.\n", players[player_index].name, date_str);
        }
    }

    return 0;
}