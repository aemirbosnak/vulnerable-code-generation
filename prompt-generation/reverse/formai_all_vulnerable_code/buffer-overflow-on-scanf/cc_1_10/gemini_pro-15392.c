//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_PLAYERS 4
#define MAX_MESSAGE_LENGTH 1024

char *morse_code[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--..", "-.-.--", "..--..",
    "...--...", "---...", "-....-", "-..-.", "-.--.", "-....-", "-.--.-",
    "--..--",
};

struct player {
    int id;
    char *name;
    pthread_t thread;
    char *message;
    int message_length;
    int turn;
};

struct player players[MAX_PLAYERS];

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

int current_turn = 0;

void *player_thread(void *arg) {
    struct player *player = (struct player *)arg;

    while (1) {
        pthread_mutex_lock(&mutex);

        while (player->turn != current_turn) {
            pthread_cond_wait(&cond, &mutex);
        }

        printf("%s (%d): %s\n", player->name, player->id, player->message);

        current_turn++;
        if (current_turn >= MAX_PLAYERS) {
            current_turn = 0;
        }

        pthread_cond_broadcast(&cond);
        pthread_mutex_unlock(&mutex);
    }

    return NULL;
}

int main() {
    int i;

    for (i = 0; i < MAX_PLAYERS; i++) {
        players[i].id = i + 1;
        players[i].name = malloc(100);
        players[i].message = malloc(MAX_MESSAGE_LENGTH);
        players[i].message_length = 0;
        players[i].turn = i;

        printf("Enter player %d's name: ", i + 1);
        scanf("%s", players[i].name);

        printf("Enter player %d's message: ", i + 1);
        scanf("%s", players[i].message);

        players[i].message_length = strlen(players[i].message);

        pthread_create(&players[i].thread, NULL, player_thread, &players[i]);
    }

    for (i = 0; i < MAX_PLAYERS; i++) {
        pthread_join(players[i].thread, NULL);
    }

    return 0;
}