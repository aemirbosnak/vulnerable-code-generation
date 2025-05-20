//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PLAYERS 4
#define MAX_CONVERSIONS 10
#define MAX_PLAYER_NAME_LENGTH 20
#define MAX_CONVERSION_NAME_LENGTH 20

typedef struct {
    char name[MAX_PLAYER_NAME_LENGTH];
    int score;
    int conversions[MAX_CONVERSIONS];
} Player;

void init_player(Player *player) {
    strcpy(player->name, "");
    player->score = 0;
    memset(player->conversions, 0, sizeof(player->conversions));
}

void print_player(Player player) {
    printf("Name: %s\n", player.name);
    printf("Score: %d\n", player.score);
    for (int i = 0; i < MAX_CONVERSIONS; i++) {
        if (player.conversions[i]) {
            printf("Conversion %d: %s\n", i+1, player.conversions[i]);
        }
    }
}

void play_game(Player players[MAX_PLAYERS]) {
    char input[MAX_PLAYER_NAME_LENGTH];
    int player_count = 0;

    while (player_count < MAX_PLAYERS) {
        printf("Enter your name: ");
        scanf("%s", input);
        strcpy(players[player_count].name, input);
        player_count++;
    }

    int round_count = 0;
    while (round_count < MAX_CONVERSIONS) {
        char conversion[MAX_CONVERSION_NAME_LENGTH];
        printf("Enter a conversion to perform: ");
        scanf("%s", conversion);
        for (int i = 0; i < strlen(conversion); i++) {
            if (!isalpha(conversion[i])) {
                printf("Invalid input: %s\n", conversion);
                continue;
            }
        }
        strcpy(players[player_count-1].conversions[round_count], conversion);
        round_count++;
    }

    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("Player %d:\n", i+1);
        print_player(players[i]);
    }
}

int main() {
    Player players[MAX_PLAYERS];
    for (int i = 0; i < MAX_PLAYERS; i++) {
        init_player(&players[i]);
    }
    play_game(players);
    return 0;
}