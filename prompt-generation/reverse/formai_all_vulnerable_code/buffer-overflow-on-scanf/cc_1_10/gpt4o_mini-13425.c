//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_PLAYERS 5
#define MAX_LENGTH 256

typedef struct {
    int player_id;
    char name[50];
    int time_taken; // in milliseconds
} Player;

Player players[MAX_PLAYERS];
int player_count = 0;

void* player_typing(void* arg) {
    Player* player = (Player*)arg;
    char input[MAX_LENGTH];
    char* phrase = "The quick brown fox jumps over the lazy dog"; // example phrase

    printf("Player %d (%s), start typing the following phrase:\n", player->player_id + 1, player->name);
    printf("\"%s\"\n", phrase);
    
    clock_t start_time = clock();
    fgets(input, MAX_LENGTH, stdin);
    clock_t end_time = clock();

    // Calculate time taken in milliseconds
    player->time_taken = (end_time - start_time) * 1000 / CLOCKS_PER_SEC;

    // Check if the input matches the phrase
    if (strncmp(input, phrase, strlen(phrase)) == 0) {
        printf("Player %d (%s) finished typing! Time taken: %dms\n", player->player_id + 1, player->name, player->time_taken);
    } else {
        printf("Player %d (%s) made a mistake in typing!\n", player->player_id + 1, player->name);
    }
    
    return NULL;
}

void start_typing_test() {
    pthread_t threads[MAX_PLAYERS];
    
    for (int i = 0; i < player_count; i++) {
        pthread_create(&threads[i], NULL, player_typing, (void*)&players[i]);
    }
    
    for (int i = 0; i < player_count; i++) {
        pthread_join(threads[i], NULL);
    }
}

int main() {
    printf("Welcome to the Multiplayer Typing Speed Test!\n");
    printf("Enter the number of players (1 - %d): ", MAX_PLAYERS);
    
    scanf("%d", &player_count);
    getchar(); // To consume the newline character after the player count input

    if (player_count < 1 || player_count > MAX_PLAYERS) {
        printf("Invalid number of players. Exiting...\n");
        return -1;
    }

    for (int i = 0; i < player_count; i++) {
        printf("Enter the name of Player %d: ", i + 1);
        fgets(players[i].name, sizeof(players[i].name), stdin);
        players[i].name[strcspn(players[i].name, "\n")] = 0; // Remove newline character
        players[i].player_id = i;
        players[i].time_taken = 0; // Initialize time taken
    }

    printf("\n*** The typing test will now begin! ***\n");
    start_typing_test();

    printf("\n*** Typing Test Over! Results: ***\n");
    for (int i = 0; i < player_count; i++) {
        printf("Player %d (%s): Time taken: %dms\n", players[i].player_id + 1, players[i].name, players[i].time_taken);
    }
    
    return 0;
}