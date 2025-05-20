//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 10
#define MAX_USERNAME_LENGTH 20
#define MAX_URL_LENGTH 100

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char url[MAX_URL_LENGTH];
    int is_valid_url;
} Player;

void init_player(Player *player) {
    strcpy(player->username, "");
    strcpy(player->url, "");
    player->is_valid_url = 0;
}

int is_valid_url(char *url) {
    char *protocols[] = {"http", "https", "ftp", "ftps", "sftp", "smb", "ssh", "telnet", "tftp", NULL};
    int i;
    for (i = 0; protocols[i]!= NULL; i++) {
        if (strstr(url, protocols[i])!= NULL) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int num_players;
    char input[MAX_USERNAME_LENGTH + MAX_URL_LENGTH + 2];
    Player players[MAX_PLAYERS];

    printf("Enter number of players: ");
    scanf("%d", &num_players);

    printf("Enter usernames and URLs for each player:\n");
    int i;
    for (i = 0; i < num_players; i++) {
        printf("Player %d:\n", i + 1);
        printf("Username: ");
        scanf("%s", input);
        strcpy(players[i].username, input);

        printf("URL: ");
        scanf("%s", input);
        strcpy(players[i].url, input);

        if (is_valid_url(players[i].url)) {
            printf("Valid URL\n");
            players[i].is_valid_url = 1;
        } else {
            printf("Invalid URL\n");
        }
    }

    printf("Players:\n");
    for (i = 0; i < num_players; i++) {
        printf("Player %d: %s (%s)\n", i + 1, players[i].username, players[i].is_valid_url? "Valid URL" : "Invalid URL");
    }

    return 0;
}