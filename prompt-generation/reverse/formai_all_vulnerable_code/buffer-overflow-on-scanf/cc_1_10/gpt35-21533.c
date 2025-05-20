//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 50
#define MAX_PLAYERS 10
#define MAX_WORDS 20
#define NUM_ALIEN_CHARS 10
#define ALPHABET "abcdefghijklmnopqrstuvwxyz"

typedef struct {
    char alien_char;
    char translation[10];
} AlienChar;

typedef struct {
    char name[MAX_LEN];
    AlienChar dictionary[NUM_ALIEN_CHARS];
} Player;

void print_instructions() {
    printf("Welcome to the Alien Language Translator!\n");
    printf("To start, each player will need to create their own unique alien language, using up to 10 characters from the English alphabet.\n");
    printf("Once all players have created their languages, you will take turns translating phrases from your own language to the other players' languages.\n");
    printf("Happy translating!\n");
}

void create_language(Player *player) {
    int i, j;
    char char_input[MAX_LEN];
    printf("%s, please enter up to 10 unique characters from the English alphabet to use in your alien language:\n", player->name);
    for (i = 0; i < NUM_ALIEN_CHARS; i++) {
        printf("Enter character #%d: ", i+1);
        scanf(" %s", char_input);
        // check that input is a single letter
        while (strlen(char_input) > 1) {
            printf("Invalid input, please enter a single letter.\n");
            printf("Enter character #%d: ", i+1);
            scanf(" %s", char_input);
        }
        // check that input hasn't already been used
        for (j = 0; j < i; j++) {
            if (char_input[0] == player->dictionary[j].alien_char) {
                printf("%c has already been used in your language, please choose a different letter.\n", char_input[0]);
                printf("Enter character #%d: ", i+1);
                scanf(" %s", char_input);
                while (strlen(char_input) > 1) {
                    printf("Invalid input, please enter a single letter.\n");
                    printf("Enter character #%d: ", i+1);
                    scanf(" %s", char_input);
                }
                j = -1;
            }
        }
        player->dictionary[i].alien_char = char_input[0];
        printf("Great, what does %c mean in your language?\n", char_input[0]);
        scanf(" %s", player->dictionary[i].translation);
    }
}

void print_languages(Player *players, int num_players) {
    int i, j;
    printf("Here are the current languages:\n");
    for (i = 0; i < num_players; i++) {
        printf("%s: ", players[i].name);
        for (j = 0; j < NUM_ALIEN_CHARS; j++) {
            printf("%c -> %s, ", players[i].dictionary[j].alien_char, players[i].dictionary[j].translation);
        }
        printf("\n");
    }
}

int is_valid_word(char *word, AlienChar *dictionary) {
    int i, j;
    for (i = 0; i < strlen(word); i++) {
        for (j = 0; j < NUM_ALIEN_CHARS; j++) {
            if (word[i] == dictionary[j].alien_char) {
                break;
            }
            if (j == NUM_ALIEN_CHARS - 1) {
                return 0;
            }
        }
    }
    return 1;
}

void translate_phrase(Player *players, int num_players) {
    char input[MAX_LEN];
    int valid_input = 0, i, j;
    while (!valid_input) {
        printf("Enter a phrase to translate: ");
        scanf(" %[^\n]s", input);
        valid_input = 1;
        for (i = 0; i < strlen(input); i++) {
            if (!is_valid_word(&input[i], players[0].dictionary)) {
                printf("Invalid input, all words in the phrase must use only letters from your language.\n");
                valid_input = 0;
                break;
            }
        }
    }
    printf("Translation options:\n");
    for (i = 0; i < num_players; i++) {
        if (strcmp(players[i].name, players[0].name) != 0) {
            printf("%s: ", players[i].name);
            for (j = 0; j < strlen(input); j++) {
                for (int k = 0; k < NUM_ALIEN_CHARS; k++) {
                    if (input[j] == players[0].dictionary[k].alien_char) {
                        printf("%s", players[i].dictionary[k].translation);
                        break;
                    }
                    if (k == NUM_ALIEN_CHARS - 1) {
                        printf("%c", input[j]);
                    }
                }
            }
            printf("\n");
        }
    }
}

int main() {
    Player players[MAX_PLAYERS];
    int num_players = 0, play_again = 1, i, j;
    char input[MAX_LEN];
    print_instructions();
    printf("How many players will be playing? (up to %d): ", MAX_PLAYERS);
    scanf(" %d", &num_players);
    while (num_players < 2 || num_players > MAX_PLAYERS) {
        printf("Invalid input, please enter a number between 2 and %d: ", MAX_PLAYERS);
        scanf(" %d", &num_players);
    }
    for (i = 0; i < num_players; i++) {
        printf("Enter a name for player %d: ", i+1);
        scanf(" %[^\n]s", input);
        strcpy(players[i].name, input);
        create_language(&players[i]);
        printf("\n");
    }
    while (play_again) {
        print_languages(players, num_players);
        translate_phrase(players, num_players);
        printf("Translate another phrase? (y/n): ");
        scanf(" %c", input);
        while (input[0] != 'y' && input[0] != 'n') {
            printf("Invalid input, please enter y or n: ");
            scanf(" %c", input);
        }
        if (input[0] == 'n') {
            play_again = 0;
        }
    }
    printf("Thanks for playing!\n");
    return 0;
}