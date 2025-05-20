//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PLAYERS 10
#define MAX_LENGTH 100
#define ALIEN_NUM 5

char *alien_chars[ALIEN_NUM] = {"Zog", "Krill", "Blip", "Norp", "Fvid"};
char *galactic_phrases[ALIEN_NUM] = {"Greetings!", "Wecome to the universe!", "Beware of black holes!", "Innovation is key!", "Explore new worlds!"};

typedef struct {
    char name[MAX_LENGTH];
    char message[MAX_LENGTH];
} Player;

void init_players(Player players[], int num_players);
void translate_to_alien(Player player);
void display_player_messages(Player players[], int count);
char* to_alien_language(const char *message);

int main() {
    Player players[MAX_PLAYERS];
    int num_players;

    printf("Welcome to the Galactic Alien Translator Game!\n");
    printf("Enter the number of players (1-%d): ", MAX_PLAYERS);
    scanf("%d", &num_players);
    getchar();  

    if (num_players < 1 || num_players > MAX_PLAYERS) {
        printf("Invalid number of players.\n");
        return 1;
    }

    init_players(players, num_players);

    for (int i = 0; i < num_players; i++) {
        printf("\nTranslating messages for %s:\n", players[i].name);
        translate_to_alien(players[i]);
    }

    printf("\n--- Player Messages in Alien Language ---\n");
    display_player_messages(players, num_players);

    printf("\nThank you for playing! Engage warp drive!\n");
    return 0;
}

void init_players(Player players[], int num_players) {
    for (int i = 0; i < num_players; i++) {
        printf("Enter name for player %d: ", i + 1);
        fgets(players[i].name, MAX_LENGTH, stdin);
        players[i].name[strcspn(players[i].name, "\n")] = 0;  // Remove newline

        printf("Enter message for %s: ", players[i].name);
        fgets(players[i].message, MAX_LENGTH, stdin);
        players[i].message[strcspn(players[i].message, "\n")] = 0;  // Remove newline
    }
}

void translate_to_alien(Player player) {
    char *translated_message = to_alien_language(player.message);
    printf("Alien translation for '%s': %s\n", player.message, translated_message);
    free(translated_message);
}

char* to_alien_language(const char *message) {
    size_t length = strlen(message);
    char *translated = malloc(length * ALIEN_NUM + length + 1);  // Allocate space for translation
    if (!translated) {
        fprintf(stderr, "Memory allocation error!\n");
        exit(EXIT_FAILURE);
    }
    translated[0] = '\0';

    for (size_t i = 0; i < length; i++) {
        if (isalpha(message[i])) {
            int alien_index = (tolower(message[i]) - 'a') % ALIEN_NUM;
            strcat(translated, alien_chars[alien_index]);
            strcat(translated, " ");
        } else {
            strncat(translated, &message[i], 1);
        }
    }

    return translated;
}

void display_player_messages(Player players[], int count) {
    for (int i = 0; i < count; i++) {
        printf("%s: %s\n", players[i].name, players[i].message);
    }
}