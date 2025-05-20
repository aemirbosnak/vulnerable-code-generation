//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_PLAYERS 5
#define BUFFER_SIZE 256

typedef struct {
    char directory[BUFFER_SIZE];
} Player;

void* scan_directory(void* arg) {
    Player* player = (Player*)arg;
    DIR* dir;
    struct dirent* entry;

    printf("Player scanning: %s\n", player->directory);
    
    // Open the directory
    dir = opendir(player->directory);
    if (dir == NULL) {
        perror("Failed to open directory");
        return NULL;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip the current and parent directory entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;
        
        // Check if the file is a ".virus" file
        if (strstr(entry->d_name, ".virus") != NULL) {
            printf("Malicious file detected: %s/%s\n", player->directory, entry->d_name);
        }
    }

    closedir(dir);
    return NULL;
}

int main() {
    pthread_t threads[MAX_PLAYERS];
    Player players[MAX_PLAYERS];
    int player_count = 0;

    printf("Welcome to the C Antivirus Multiplayer Scanner!\n");
    printf("Max players allowed: %d\n", MAX_PLAYERS);

    while (player_count < MAX_PLAYERS) {
        printf("Enter directory path for Player %d (or 'exit' to quit): ", player_count + 1);
        scanf("%s", players[player_count].directory);

        if (strcmp(players[player_count].directory, "exit") == 0) {
            break; // Exit if the user types 'exit'
        }

        // Create a thread for each player to scan their directory
        if (pthread_create(&threads[player_count], NULL, scan_directory, (void*)&players[player_count]) != 0) {
            perror("Failed to create thread");
            return 1;
        }

        player_count++;
    }

    // Wait for all threads to finish
    for (int i = 0; i < player_count; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All scans complete. Thank you for using the C Antivirus Scanner!\n");
    return 0;
}