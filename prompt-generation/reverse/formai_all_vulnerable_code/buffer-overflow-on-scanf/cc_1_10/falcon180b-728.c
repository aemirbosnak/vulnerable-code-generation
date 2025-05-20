//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_SENTENCES 1000
#define MAX_PLAYERS 10

typedef struct {
    char name[20];
    int score;
    int num_words;
    int num_sentences;
} player_t;

player_t players[MAX_PLAYERS];
int num_players;

char words[MAX_WORDS][20];
int num_words;

char sentences[MAX_SENTENCES][100];
int num_sentences;

void init() {
    num_players = 0;
    num_words = 0;
    num_sentences = 0;
}

void add_player(char* name) {
    strcpy(players[num_players].name, name);
    players[num_players].score = 0;
    players[num_players].num_words = 0;
    players[num_players].num_sentences = 0;
    num_players++;
}

void add_word(char* word) {
    int i;
    for (i = 0; i < num_words; i++) {
        if (strcmp(word, words[i]) == 0) {
            return;
        }
    }
    strcpy(words[num_words], word);
    num_words++;
}

void add_sentence(char* sentence) {
    int i;
    for (i = 0; i < num_sentences; i++) {
        if (strcmp(sentence, sentences[i]) == 0) {
            return;
        }
    }
    strcpy(sentences[num_sentences], sentence);
    num_sentences++;
}

int main() {
    init();
    add_player("Alice");
    add_player("Bob");
    add_player("Charlie");

    int player_id;
    char input[100];
    while (1) {
        printf("Enter player ID: ");
        scanf("%d", &player_id);
        if (player_id >= 0 && player_id < num_players) {
            printf("Enter name: ");
            scanf("%s", input);
            strcpy(players[player_id].name, input);
        } else {
            printf("Invalid player ID\n");
        }
    }

    return 0;
}