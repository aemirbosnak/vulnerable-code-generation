//FormAI DATASET v1.0 Category: Memory Game ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define NUM_CARDS 16
#define NUM_COLORS 4
#define TRUE 1
#define FALSE 0

int card_order[NUM_CARDS];
int cards[NUM_CARDS];
int matches[NUM_COLORS];
int num_players;
int curr_player = 0;
int curr_turn = 1;
int finished = FALSE;
pthread_mutex_t mutex_lock;
pthread_cond_t cond_var;

/* Initialize the cards and card order */
void init_cards() {
    int i, j;
    for (i = 0; i < NUM_CARDS; i++) {
        cards[i] = i / 2;
        card_order[i] = i;
    }
    srand(time(NULL)); // seed for random shuffle
    for (i = 0; i < NUM_CARDS; i++) {
        j = rand() % NUM_CARDS;
        int temp = card_order[i];
        card_order[i] = card_order[j];
        card_order[j] = temp;
    }
}

/* Check if all cards are matched */
int all_matched() {
    int i;
    for (i = 0; i < NUM_COLORS; i++) {
        if (matches[i] < 2) {
            return FALSE;
        }
    }
    return TRUE;
}

/* Play a turn */
void play_turn() {
    int card1, card2;
    printf("\nPlayer %d, it is your turn (%d/%d)\n", curr_player+1, curr_turn, NUM_CARDS/2);
    printf("Enter the two cards you want to flip:\n");
    scanf("%d%d", &card1, &card2);
    while (card1 == card2 || cards[card_order[card1]] == -1 || cards[card_order[card2]] == -1) {
        printf("Invalid move. Please enter two different card numbers:\n");
        scanf("%d%d", &card1, &card2);
    }
    printf("Player %d flipped cards %d and %d: %d and %d\n", curr_player+1, card1, card2, cards[card_order[card1]], cards[card_order[card2]]);
    if (cards[card_order[card1]] == cards[card_order[card2]]) {
        printf("MATCH!\n");
        matches[cards[card_order[card1]]]++;
        cards[card_order[card1]] = -1;
        cards[card_order[card2]] = -1;
    }
    curr_turn++;
    curr_player = (curr_player + 1) % num_players;
}

/* Thread function for playing the game */
void *game_thread(void* arg) {
    int i;
    int player_number = *(int*)arg;
    while (!finished) {
        pthread_mutex_lock(&mutex_lock);
        while (curr_player != player_number || all_matched()) {
            pthread_cond_wait(&cond_var, &mutex_lock);
        }
        play_turn();
        pthread_cond_broadcast(&cond_var);
        pthread_mutex_unlock(&mutex_lock);
    }
    return NULL;
}

/* Main function */
int main() {
    int i;
    printf("Welcome to the C Memory Game!\n");
    printf("Enter the number of players (2-4):\n");
    scanf("%d", &num_players);
    while (num_players < 2 || num_players > 4) {
        printf("Invalid number of players. Please enter a number between 2 and 4:\n");
        scanf("%d", &num_players);
    }
    pthread_t threads[num_players];
    init_cards();
    pthread_mutex_init(&mutex_lock, NULL);
    pthread_cond_init(&cond_var, NULL);
    for (i = 0; i < NUM_COLORS; i++) {
        matches[i] = 0;
    }
    for (i = 0; i < num_players; i++) {
        int* arg = malloc(sizeof(*arg));
        *arg = i;
        pthread_create(&threads[i], NULL, game_thread, arg);
    }
    for (i = 0; i < num_players; i++) {
        pthread_join(threads[i], NULL);
    }
    pthread_mutex_destroy(&mutex_lock);
    pthread_cond_destroy(&cond_var);
    printf("Thanks for playing!\n");
    return 0;
}