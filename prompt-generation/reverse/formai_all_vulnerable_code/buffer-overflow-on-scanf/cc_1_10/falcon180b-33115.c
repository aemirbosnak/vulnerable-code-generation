//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 10
#define MAX_MESSAGE_LENGTH 1000
#define SPAM_THRESHOLD 5

typedef struct {
    char username[20];
    int spam_count;
} Player;

void init_player(Player *player, char *username) {
    strcpy(player->username, username);
    player->spam_count = 0;
}

void print_player(Player player) {
    printf("Username: %s, Spam Count: %d\n", player.username, player.spam_count);
}

int main() {
    char usernames[MAX_PLAYERS][20];
    Player players[MAX_PLAYERS];
    int num_players;
    char input[MAX_MESSAGE_LENGTH];
    int i;

    printf("Enter number of players: ");
    scanf("%d", &num_players);

    for (i = 0; i < num_players; i++) {
        printf("Enter username for player %d: ", i + 1);
        scanf("%s", usernames[i]);
        init_player(&players[i], usernames[i]);
    }

    while (1) {
        printf("Enter message: ");
        fgets(input, MAX_MESSAGE_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';

        int is_spam = 0;
        for (i = 0; i < num_players; i++) {
            if (strstr(input, players[i].username)) {
                players[i].spam_count++;
            }
        }

        if (is_spam) {
            printf("SPAM DETECTED\n");
        } else {
            printf("Message sent successfully\n");
        }
    }

    return 0;
}