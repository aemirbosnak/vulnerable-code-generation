//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PLAYERS 10
#define MAX_CHAT_LENGTH 100

typedef struct {
    char name[20];
    int score;
    time_t last_active;
} Player;

Player players[MAX_PLAYERS];
int num_players;

void init() {
    srand(time(NULL));
    num_players = 0;
}

void add_player(char* name) {
    if (num_players >= MAX_PLAYERS) {
        printf("Sorry, too many players already.\n");
        return;
    }
    strcpy(players[num_players].name, name);
    players[num_players].score = 0;
    players[num_players].last_active = time(NULL);
    num_players++;
}

void list_players() {
    printf("Players:\n");
    for (int i = 0; i < num_players; i++) {
        printf("%s - Score: %d\n", players[i].name, players[i].score);
    }
}

void chat(char* message) {
    time_t now = time(NULL);
    for (int i = 0; i < num_players; i++) {
        if (difftime(now, players[i].last_active) <= 60) {
            printf("%s: %s\n", players[i].name, message);
        }
    }
}

int main() {
    init();
    while (1) {
        printf("Enter your name: ");
        char name[20];
        scanf("%s", name);
        add_player(name);
        printf("Welcome, %s!\n", name);
        while (1) {
            printf("Enter a message: ");
            char message[MAX_CHAT_LENGTH];
            scanf("%[^\n]", message);
            chat(message);
        }
    }
    return 0;
}