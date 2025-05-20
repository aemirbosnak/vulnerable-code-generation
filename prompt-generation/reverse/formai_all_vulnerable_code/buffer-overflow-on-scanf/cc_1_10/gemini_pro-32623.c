//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

// Player struct
typedef struct player {
    char name[20];
    int score;
    pthread_t thread;
} player_t;

// Global variables
player_t players[4];
int num_players = 0;
pthread_mutex_t lock;

// Function to get CPU usage
double get_cpu_usage() {
    FILE *fp;
    char buf[1024];
    double user, nice, system, idle, iowait, irq, softirq;

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("fopen");
        return -1.0;
    }

    fgets(buf, sizeof(buf), fp);
    sscanf(buf, "cpu %lf %lf %lf %lf %lf %lf %lf", &user, &nice, &system, &idle, &iowait, &irq, &softirq);
    fclose(fp);

    return (user + nice + system + irq + softirq) / (user + nice + system + idle + iowait + irq + softirq);
}

// Function to update player score
void update_player_score(player_t *player) {
    double cpu_usage = get_cpu_usage();

    pthread_mutex_lock(&lock);
    player->score += cpu_usage * 100;
    pthread_mutex_unlock(&lock);
}

// Function to run player thread
void *run_player_thread(void *arg) {
    player_t *player = (player_t *)arg;

    while (1) {
        update_player_score(player);
        sleep(1);
    }

    return NULL;
}

// Function to start game
void start_game() {
    int i;

    for (i = 0; i < num_players; i++) {
        pthread_create(&players[i].thread, NULL, run_player_thread, &players[i]);
    }
}

// Function to stop game
void stop_game() {
    int i;

    for (i = 0; i < num_players; i++) {
        pthread_cancel(players[i].thread);
    }
}

// Function to print player scores
void print_player_scores() {
    int i;

    for (i = 0; i < num_players; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }
}

// Main function
int main() {
    int i;

    // Initialize mutex
    pthread_mutex_init(&lock, NULL);

    // Get number of players
    printf("Enter number of players (1-4): ");
    scanf("%d", &num_players);

    // Get player names
    for (i = 0; i < num_players; i++) {
        printf("Enter player %d name: ", i + 1);
        scanf("%s", players[i].name);
    }

    // Start game
    start_game();

    // Sleep for 10 seconds
    sleep(10);

    // Stop game
    stop_game();

    // Print player scores
    print_player_scores();

    return 0;
}