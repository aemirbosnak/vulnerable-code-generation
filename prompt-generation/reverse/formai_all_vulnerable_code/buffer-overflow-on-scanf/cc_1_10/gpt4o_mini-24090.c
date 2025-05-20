//GPT-4o-mini DATASET v1.0 Category: URL Sanitizer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048
#define MAX_PLAYERS 4
#define URLS_PER_PLAYER 3

typedef struct {
    char name[50];
    char urls[URLS_PER_PLAYER][MAX_URL_LENGTH];
} Player;

void sanitize_url(const char* src, char* dest) {
    const char* hex = "0123456789ABCDEF";
    int i = 0, j = 0;
    
    while (src[i] != '\0' && j < MAX_URL_LENGTH - 1) {
        if (isalnum((unsigned char)src[i])) {
            dest[j++] = src[i];
        } else {
            dest[j++] = '%';
            dest[j++] = hex[(unsigned char)src[i] / 16];
            dest[j++] = hex[(unsigned char)src[i] % 16];
        }
        i++;
    }
    dest[j] = '\0'; // Null-terminate the string
}

void collect_urls(Player* players, int num_players) {
    for (int i = 0; i < num_players; i++) {
        printf("Enter URLs for player %s:\n", players[i].name);
        for (int j = 0; j < URLS_PER_PLAYER; j++) {
            printf("URL %d: ", j + 1);
            fgets(players[i].urls[j], MAX_URL_LENGTH, stdin);
            players[i].urls[j][strcspn(players[i].urls[j], "\n")] = '\0'; // Remove newline
        }
    }
}

void sanitize_urls(Player* players, int num_players) {
    char sanitized_url[MAX_URL_LENGTH];
    for (int i = 0; i < num_players; i++) {
        for (int j = 0; j < URLS_PER_PLAYER; j++) {
            sanitize_url(players[i].urls[j], sanitized_url);
            printf("Sanitized URL from player %s, original: %s, sanitized: %s\n", 
                   players[i].name, players[i].urls[j], sanitized_url);
        }
    }
}

int main() {
    Player players[MAX_PLAYERS];
    int num_players;

    printf("Enter number of players (max %d): ", MAX_PLAYERS);
    scanf("%d", &num_players);
    getchar(); // consume newline after number input

    if (num_players > MAX_PLAYERS || num_players <= 0) {
        printf("Invalid number of players. Please restart the program.\n");
        return 1;
    }

    for (int i = 0; i < num_players; i++) {
        printf("Enter name for player %d: ", i + 1);
        fgets(players[i].name, sizeof(players[i].name), stdin);
        players[i].name[strcspn(players[i].name, "\n")] = '\0'; // Remove newline
    }

    collect_urls(players, num_players);
    sanitize_urls(players, num_players);

    return 0;
}