//Falcon-180B DATASET v1.0 Category: QR code reader ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_PLAYER_NAME_LENGTH 20

typedef struct {
    char name[MAX_PLAYER_NAME_LENGTH];
    int score;
} Player;

Player players[MAX_PLAYERS];
int num_players;

void init_players() {
    for (int i = 0; i < MAX_PLAYERS; i++) {
        strcpy(players[i].name, "Player ");
        sprintf(&players[i].name[8], "%d", i + 1);
        players[i].score = 0;
    }
    num_players = 0;
}

void add_player() {
    if (num_players >= MAX_PLAYERS) {
        printf("Maximum number of players reached!\n");
        return;
    }
    printf("Enter player name: ");
    scanf("%s", players[num_players].name);
    players[num_players].score = 0;
    num_players++;
}

void display_players() {
    printf("Players:\n");
    for (int i = 0; i < num_players; i++) {
        printf("%d. %s: %d\n", i + 1, players[i].name, players[i].score);
    }
}

void start_game() {
    srand(time(NULL));
    int qr_value;
    char qr_string[20];
    while (true) {
        qr_value = rand() % 1000;
        sprintf(qr_string, "http://example.com/qr/%d", qr_value);
        printf("Scan the QR code:\n%s\n", qr_string);
        int correct_player = -1;
        for (int i = 0; i < num_players; i++) {
            if (strcmp(players[i].name, qr_string) == 0) {
                correct_player = i;
                break;
            }
        }
        if (correct_player == -1) {
            printf("Invalid QR code!\n");
            continue;
        }
        players[correct_player].score++;
        display_players();
        printf("Player %d wins!\n", correct_player + 1);
        break;
    }
}

int main() {
    init_players();
    while (num_players < MAX_PLAYERS) {
        add_player();
    }
    start_game();
    return 0;
}