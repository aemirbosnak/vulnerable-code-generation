//GPT-4o-mini DATASET v1.0 Category: Bingo Simulator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <string.h>

#define MAX_PLAYERS 10
#define BINGO_SIZE 5
#define MAX_NUM 75

typedef struct {
    int id;
    int card[BINGO_SIZE][BINGO_SIZE];
    int marked[BINGO_SIZE][BINGO_SIZE];
    int won;
} Player;

int drawn_numbers[MAX_NUM + 1];
pthread_mutex_t lock;
int total_drawn = 0;

void initialize_player_card(Player *player) {
    int numbers[BINGO_SIZE * BINGO_SIZE];
    int idx = 0;

    // Initialize a list of numbers for Bingo card generation
    for (int i = 1; i <= MAX_NUM; i++) {
        numbers[idx++] = i;
    }

    // Shuffle numbers array
    for (int i = 0; i < MAX_NUM; i++) {
        int j = rand() % (MAX_NUM + 1);
        int temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }

    // Fill the Bingo card with numbers
    idx = 0;
    for (int i = 0; i < BINGO_SIZE; i++) {
        for (int j = 0; j < BINGO_SIZE; j++) {
            player->card[i][j] = numbers[idx++];
        }
    }

    // Initialize marked array
    memset(player->marked, 0, sizeof(player->marked));
    player->won = 0;
}

void print_card(Player *player) {
    printf("Player %d's Bingo Card:\n", player->id);
    for (int i = 0; i < BINGO_SIZE; i++) {
        for (int j = 0; j < BINGO_SIZE; j++) {
            if (player->marked[i][j])
                printf("[*%2d*] ", player->card[i][j]);
            else
                printf("[ %2d ] ", player->card[i][j]);
        }
        printf("\n");
    }
}

void mark_number(Player *player, int number) {
    for (int i = 0; i < BINGO_SIZE; i++) {
        for (int j = 0; j < BINGO_SIZE; j++) {
            if (player->card[i][j] == number) {
                player->marked[i][j] = 1;
            }
        }
    }
}

int check_win(Player *player) {
    // Check rows
    for (int i = 0; i < BINGO_SIZE; i++) {
        int complete = 1;
        for (int j = 0; j < BINGO_SIZE; j++) {
            if (!player->marked[i][j]) {
                complete = 0;
                break;
            }
        }
        if (complete) return 1;
    }

    // Check columns
    for (int j = 0; j < BINGO_SIZE; j++) {
        int complete = 1;
        for (int i = 0; i < BINGO_SIZE; i++) {
            if (!player->marked[i][j]) {
                complete = 0;
                break;
            }
        }
        if (complete) return 1;
    }

    // Check diagonals
    int complete = 1;
    for (int i = 0; i < BINGO_SIZE; i++) {
        if (!player->marked[i][i]) {
            complete = 0;
            break;
        }
    }
    if (complete) return 1;

    complete = 1;
    for (int i = 0; i < BINGO_SIZE; i++) {
        if (!player->marked[i][BINGO_SIZE - 1 - i]) {
            complete = 0;
            break;
        }
    }
    if (complete) return 1;

    return 0;
}

void *player_action(void *arg) {
    Player *player = (Player *)arg;
    while (1) {
        pthread_mutex_lock(&lock);
        if (total_drawn >= MAX_NUM) {
            pthread_mutex_unlock(&lock);
            break; // No more numbers to draw
        }
        int number_to_mark = rand() % MAX_NUM + 1;
        if (drawn_numbers[number_to_mark] == 0) {
            drawn_numbers[number_to_mark] = 1;
            total_drawn++;
            printf("Player %d marks number: %d\n", player->id, number_to_mark);
            mark_number(player, number_to_mark);
            print_card(player);
            if (check_win(player)) {
                player->won = 1;
                printf("Player %d has won the game!\n", player->id);
                pthread_mutex_unlock(&lock);
                return NULL;
            }
        }
        pthread_mutex_unlock(&lock);
        sleep(1); // Simulate time delay
    }
    return NULL;
}

int main() {
    srand(time(NULL));
    pthread_mutex_init(&lock, NULL);
    pthread_t players[MAX_PLAYERS];
    Player game_players[MAX_PLAYERS];

    // Initialize drawn numbers
    memset(drawn_numbers, 0, sizeof(drawn_numbers));

    // Create Players
    for (int i = 0; i < MAX_PLAYERS; i++) {
        game_players[i].id = i + 1;
        initialize_player_card(&game_players[i]);
        pthread_create(&players[i], NULL, player_action, &game_players[i]);
    }

    // Wait for all players to finish
    for (int i = 0; i < MAX_PLAYERS; i++) {
        pthread_join(players[i], NULL);
    }

    pthread_mutex_destroy(&lock);
    return 0;
}