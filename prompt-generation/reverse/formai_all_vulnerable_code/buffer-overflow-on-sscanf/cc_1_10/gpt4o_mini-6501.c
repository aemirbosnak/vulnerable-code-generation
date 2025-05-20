//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_LINE_LENGTH 256
#define MAX_PLAYERS 100

typedef struct {
    char name[50];
    int score;
    int level;
} Player;

Player players[MAX_PLAYERS];
int player_count = 0;
pthread_mutex_t lock;

void *query_player(void *arg) {
    char *player_name = (char *)arg;
    pthread_mutex_lock(&lock);
    
    for (int i = 0; i < player_count; i++) {
        if (strcmp(players[i].name, player_name) == 0) {
            printf("Player: %s, Score: %d, Level: %d\n", players[i].name, players[i].score, players[i].level);
            pthread_mutex_unlock(&lock);
            return NULL;
        }
    }
    printf("Player %s not found!\n", player_name);
    pthread_mutex_unlock(&lock);
    
    return NULL;
}

void load_csv() {
    FILE *file = fopen("players.csv", "r");
    if (!file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }
    
    char line[MAX_LINE_LENGTH];
    fgets(line, sizeof(line), file); // Skip header line
    
    while (fgets(line, sizeof(line), file)) {
        Player p;
        sscanf(line, "%[^,],%d,%d", p.name, &p.score, &p.level);
        players[player_count++] = p;
    }
    
    fclose(file);
}

int main() {
    load_csv();
    
    pthread_mutex_init(&lock, NULL);
    
    char input[50];
    pthread_t threads[10];
    int thread_count = 0;

    while (1) {
        printf("Enter player name to query (or 'exit' to quit): ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0; // Remove newline character

        if (strcmp(input, "exit") == 0) {
            break;
        } else if (thread_count < 10) {
            pthread_create(&threads[thread_count], NULL, query_player, (void *)strdup(input));
            thread_count++;
        } else {
            printf("Maximum concurrent queries reached! Please wait...\n");
            for (int i = 0; i < thread_count; i++) {
                pthread_join(threads[i], NULL);
            }
            thread_count = 0; // Reset thread count after joining
        }
    }
    
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&lock);
    return 0;
}