//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_WORD_LENGTH 100

typedef struct {
    char name[20];
    char word[MAX_WORD_LENGTH];
    int score;
    int word_length;
} Player;

void init_player(Player* player, char* name) {
    strcpy(player->name, name);
    player->word[0] = '\0';
    player->score = 0;
    player->word_length = 0;
}

int generate_word(char* word) {
    int length = rand() % (MAX_WORD_LENGTH - 5) + 5;
    for (int i = 0; i < length; i++) {
        word[i] = rand() % 26 + 'a';
    }
    word[length] = '\0';
    return length;
}

int compare_words(const void* a, const void* b) {
    const char* word1 = *(const char**)a;
    const char* word2 = *(const char**)b;
    return strcmp(word1, word2);
}

void update_scores(Player* players, int num_players, char* word) {
    qsort(players, num_players, sizeof(Player), compare_words);
    for (int i = 0; i < num_players; i++) {
        if (strcmp(players[i].word, word) == 0) {
            players[i].score++;
        }
    }
}

void print_scores(Player* players, int num_players) {
    printf("Scores:\n");
    for (int i = 0; i < num_players; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }
}

int main() {
    srand(time(NULL));

    Player players[MAX_PLAYERS];
    int num_players = 0;

    printf("Enter your name:\n");
    scanf("%s", players[num_players].name);
    init_player(&players[num_players], players[num_players].name);
    num_players++;

    while (num_players < MAX_PLAYERS) {
        printf("Enter name for player %d:\n", num_players + 1);
        scanf("%s", players[num_players].name);
        init_player(&players[num_players], players[num_players].name);
        num_players++;
    }

    char word[MAX_WORD_LENGTH];
    int word_length = generate_word(word);

    printf("The word is %s with %d letters.\n", word, word_length);

    while (1) {
        printf("Enter your guess:\n");
        scanf("%s", players[0].word);
        players[0].word_length = strlen(players[0].word);

        if (players[0].word_length!= word_length) {
            printf("Invalid guess.\n");
            continue;
        }

        update_scores(players, num_players, word);
        print_scores(players, num_players);

        if (players[0].score == num_players - 1) {
            printf("%s wins!\n", players[0].name);
            break;
        }
    }

    return 0;
}