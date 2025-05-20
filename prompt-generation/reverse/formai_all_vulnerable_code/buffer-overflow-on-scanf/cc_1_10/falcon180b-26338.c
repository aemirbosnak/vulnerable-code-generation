//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 20
#define MAX_NUM_OF_WORDS 100
#define MAX_NUM_OF_PLAYERS 10

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} Word;

typedef struct {
    char name[20];
    int score;
} Player;

void generate_word(char *word) {
    int length = rand() % 5 + 4;
    for (int i = 0; i < length; i++) {
        char c = rand() % 26 + 'a';
        word[i] = c;
    }
    word[length] = '\0';
}

int is_correct(char *guess, char *word) {
    for (int i = 0; i < strlen(guess); i++) {
        if (guess[i]!= word[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int num_of_players;
    printf("Enter the number of players (1-10): ");
    scanf("%d", &num_of_players);
    if (num_of_players < 1 || num_of_players > MAX_NUM_OF_PLAYERS) {
        printf("Invalid number of players.\n");
        return 1;
    }
    Player players[MAX_NUM_OF_PLAYERS];
    for (int i = 0; i < num_of_players; i++) {
        printf("Enter player %d name: ", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }
    srand(time(NULL));
    Word word;
    int num_of_rounds = 5;
    for (int i = 0; i < num_of_rounds; i++) {
        generate_word(word.word);
        printf("Round %d: ", i + 1);
        for (int j = 0; j < strlen(word.word); j++) {
            printf("_ ");
        }
        printf("\n");
        for (int j = 0; j < num_of_players; j++) {
            printf("Player %d, enter your guess: ", j + 1);
            scanf("%s", players[j].name);
            if (is_correct(players[j].name, word.word)) {
                printf("Correct!\n");
                players[j].score++;
            } else {
                printf("Incorrect.\n");
            }
        }
    }
    printf("Game over.\n");
    for (int i = 0; i < num_of_players; i++) {
        printf("Player %d score: %d\n", i + 1, players[i].score);
    }
    return 0;
}