//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PLAYERS 10
#define MAX_NAME_LENGTH 50
#define MAX_MESSAGE_LENGTH 200

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Player;

Player players[MAX_PLAYERS];
int num_players;

void init_players() {
    num_players = 0;
}

void add_player(char* name) {
    if (num_players >= MAX_PLAYERS) {
        printf("Error: Too many players\n");
        return;
    }

    strcpy(players[num_players].name, name);
    players[num_players].score = 0;
    num_players++;
}

void print_scores() {
    printf("Scores:\n");
    for (int i = 0; i < num_players; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }
}

int main() {
    init_players();

    char input[MAX_MESSAGE_LENGTH];
    while (1) {
        printf("Enter your name: ");
        fgets(input, MAX_MESSAGE_LENGTH, stdin);
        char* name = strtok(input, "\n");
        add_player(name);

        if (num_players == 2) {
            break;
        }
    }

    int current_player = 0;
    while (1) {
        printf("Player %s's turn\n", players[current_player].name);
        printf("Enter a date (YYYY-MM-DD): ");
        fgets(input, MAX_MESSAGE_LENGTH, stdin);
        char* date_str = strtok(input, "\n");

        time_t date_time;
        struct tm date_struct;

        if (strptime(date_str, "%Y-%m-%d", &date_struct) == NULL) {
            printf("Invalid date format\n");
            continue;
        }

        date_time = mktime(&date_struct);
        if (date_time == -1) {
            printf("Invalid date\n");
            continue;
        }

        char date_buffer[80];
        strftime(date_buffer, sizeof(date_buffer), "%A, %B %d, %Y", &date_struct);
        printf("The date is: %s\n", date_buffer);

        if (++current_player >= num_players) {
            current_player = 0;
        }

        if (players[current_player].score >= 5) {
            printf("Player %s wins!\n", players[current_player].name);
            break;
        }
    }

    return 0;
}