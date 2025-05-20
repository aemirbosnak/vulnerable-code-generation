//FormAI DATASET v1.0 Category: Spell checking ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PLAYERS 4
#define MAX_WORDS 100
#define MAX_CHARS 50
#define DICTIONARY_FILE "dictionary.txt"

char dictionary[MAX_WORDS][MAX_CHARS];
int num_words;

struct player {
    char name[MAX_CHARS];
    int score;
} players[MAX_PLAYERS];

int num_players;

void init_game() {
    num_players = 0;
    num_words = 0;

    char word[MAX_CHARS];
    FILE *fp = fopen(DICTIONARY_FILE, "r");
    while (fgets(word, MAX_CHARS, fp) != NULL) {
        word[strlen(word) - 1] = '\0';
        strcpy(dictionary[num_words], word);
        num_words++;
    }
    fclose(fp);
}

int is_word_present(char *word) {
    for (int i = 0; i < num_words; i++) {
        if (strcmp(dictionary[i], word) == 0) {
            return 1;
        }
    }
    return 0;
}

int is_valid_word(char *word) {
    int len = strlen(word);
    if (len < 3 || len > 8) {
        return 0;
    }
    for (int i = 0; i < len; i++) {
        if (!isalpha(word[i])) {
            return 0;
        }
    }
    return is_word_present(word);
}

int main() {
    init_game();
    printf("Welcome to SpellChecker game!\n\n");

    // get number of players
    do {
        printf("Enter number of players (2-4): ");
        scanf("%d", &num_players);
    } while (num_players < 2 || num_players > 4);

    // get player names
    for (int i = 0; i < num_players; i++) {
        printf("Enter player %d name: ", i + 1);
        scanf("%s", players[i].name);
    }

    // start game
    int turn = 0;
    while (1) {
        printf("\n%s's turn\n", players[turn].name);
        printf("Enter a word (3-8 letters): ");
        char word[MAX_CHARS];
        scanf("%s", word);

        if (is_valid_word(word)) {
            printf("Valid word!\n");
            players[turn].score++;
        } else {
            printf("Invalid word!\n");
        }

        // show scores
        printf("\nCurrent scores:\n");
        for (int i = 0; i < num_players; i++) {
            printf("%s: %d\n", players[i].name, players[i].score);
        }

        // check if game over
        int max_score = 0;
        int winner = -1;
        for (int i = 0; i < num_players; i++) {
            if (players[i].score > max_score) {
                max_score = players[i].score;
                winner = i;
            }
        }
        if (max_score >= 10) {
            printf("\nGame over!\nWinner: %s\n", players[winner].name);
            break;
        }

        // next turn
        turn = (turn + 1) % num_players;
    }

    return 0;
}