//GPT-4o-mini DATASET v1.0 Category: Poker Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

#define MAX_PLAYERS 4
#define CARDS_PER_HAND 5
#define MAX_NAME_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    int hand[CARDS_PER_HAND];
    int balance;
    int isPlaying;
} Player;

Player players[MAX_PLAYERS];
pthread_mutex_t lock;
int currentPlayerIndex = 0;

void shuffleDeck(int *deck, int size) {
    for (int i = 0; i < size; ++i) {
        int j = rand() % size;
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void dealCards(int *deck) {
    for (int i = 0; i < MAX_PLAYERS; ++i) {
        if (players[i].isPlaying) {
            memcpy(players[i].hand, &deck[i * CARDS_PER_HAND], CARDS_PER_HAND * sizeof(int));
        }
    }
}

void *playerTurn(void *arg) {
    int playerIndex = *(int *)arg;
    printf("%s, it's your turn! Your hand: ", players[playerIndex].name);
    for (int i = 0; i < CARDS_PER_HAND; ++i) {
        printf("%d ", players[playerIndex].hand[i]);
    }
    printf("\n");

    sleep(1);  // Simulate thinking time

    pthread_mutex_lock(&lock);
    printf("%s is deciding to bet\n", players[playerIndex].name);
    players[playerIndex].balance -= 10; // betting
    printf("%s has %d left.\n", players[playerIndex].name, players[playerIndex].balance);
    pthread_mutex_unlock(&lock);

    return NULL;
}

void startGame() {
    int deck[52];
    for (int i = 0; i < 52; ++i) {
        deck[i] = i + 1;  // Just using card numbers 1-52
    }

    shuffleDeck(deck, 52);
    dealCards(deck);

    pthread_t threads[MAX_PLAYERS];
    int playerIndices[MAX_PLAYERS];
    for (int i = 0; i < MAX_PLAYERS; ++i) {
        if (players[i].isPlaying) {
            playerIndices[i] = i;
            pthread_create(&threads[i], NULL, playerTurn, &playerIndices[i]);
        }
    }

    for (int i = 0; i < MAX_PLAYERS; ++i) {
        if (players[i].isPlaying) {
            pthread_join(threads[i], NULL);
        }
    }
}

void initializePlayers() {
    for (int i = 0; i < MAX_PLAYERS; ++i) {
        printf("Enter the name for Player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].balance = 100;  // starting balance
        players[i].isPlaying = 1;   // all players are playing for now
    }
}

int main() {
    srand(time(NULL));
    pthread_mutex_init(&lock, NULL);

    initializePlayers();
    startGame();

    pthread_mutex_destroy(&lock);
    return 0;
}