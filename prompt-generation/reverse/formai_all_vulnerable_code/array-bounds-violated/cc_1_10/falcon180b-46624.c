//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

// Global variables
int num_players = 2;
int player_score[2] = {0};
int current_player = 0;
int game_over = 0;

// Function prototypes
void *play_game(void *arg);
void update_score(int player_num);
void print_scores();

int main() {
    pthread_t thread_id[2];

    // Create threads
    for (int i = 0; i < num_players; i++) {
        pthread_create(&thread_id[i], NULL, play_game, (void *)i);
    }

    // Join threads
    for (int i = 0; i < num_players; i++) {
        pthread_join(thread_id[i], NULL);
    }

    return 0;
}

void *play_game(void *arg) {
    int player_num = *((int *)arg);

    while (!game_over) {
        // Player's turn
        int roll = rand() % 6 + 1;
        printf("Player %d rolled %d.\n", player_num, roll);

        if (roll == 6) {
            player_score[player_num] += 3;
        } else if (roll == 5 || roll == 4 || roll == 3 || roll == 2 || roll == 1) {
            player_score[player_num] += 1;
        } else {
            printf("Invalid roll.\n");
        }

        update_score(player_num);

        // Switch to next player
        current_player = (current_player + 1) % num_players;
    }

    printf("Game over.\n");
    printf("Final scores:\n");
    print_scores();
}

void update_score(int player_num) {
    if (player_score[player_num] >= 21) {
        game_over = 1;
    }
}

void print_scores() {
    printf("Player 1 score: %d\n", player_score[0]);
    printf("Player 2 score: %d\n", player_score[1]);
}