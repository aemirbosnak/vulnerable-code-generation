//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdarg.h>

#define MAX_PLAYERS 10
#define MAX_MESSAGE_LENGTH 1000
#define MAX_SPAM_WORDS 100

typedef struct {
    char name[20];
    int score;
} Player;

Player players[MAX_PLAYERS];
int num_players;
char spam_words[MAX_SPAM_WORDS][20];
int num_spam_words;

void add_spam_word(char* word) {
    if (num_spam_words >= MAX_SPAM_WORDS) {
        printf("Error: Too many spam words.\n");
        return;
    }
    strcpy(spam_words[num_spam_words], word);
    num_spam_words++;
}

int is_spam(char* message) {
    int i;
    for (i = 0; i < num_spam_words; i++) {
        if (strstr(message, spam_words[i])!= NULL) {
            return 1;
        }
    }
    return 0;
}

void send_message(Player* sender, char* message) {
    printf("%s: %s\n", sender->name, message);
}

int main() {
    srand(time(NULL));
    num_players = rand() % MAX_PLAYERS + 2;
    printf("Number of players: %d\n", num_players);

    int i;
    for (i = 0; i < num_players; i++) {
        sprintf(players[i].name, "Player %d", i + 1);
        players[i].score = 0;
    }

    int j;
    for (j = 0; j < MAX_SPAM_WORDS; j++) {
        char* word = (char*)malloc(20 * sizeof(char));
        sprintf(word, "spam%d", j + 1);
        add_spam_word(word);
    }

    while (1) {
        int sender_id = rand() % num_players;
        Player* sender = &players[sender_id];
        char message[MAX_MESSAGE_LENGTH];
        printf("%s is sending a message...\n", sender->name);
        scanf("%[^\n]", message);
        if (is_spam(message)) {
            printf("%s sent a spam message.\n", sender->name);
            sender->score--;
        } else {
            printf("%s sent a normal message.\n", sender->name);
            sender->score++;
        }
        send_message(sender, message);
    }

    return 0;
}