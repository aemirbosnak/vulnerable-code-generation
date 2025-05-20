//GPT-4o-mini DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_PLAYERS 10
#define MAX_SSID_LENGTH 32
#define MAX_BUFFER 256

typedef struct {
    char ssid[MAX_SSID_LENGTH];
    int signal_strength;
} WiFiNetwork;

typedef struct {
    int player_id;
    WiFiNetwork networks[10];
} PlayerData;

PlayerData players[MAX_PLAYERS];
int player_count = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* analyze_signal(void* arg) {
    PlayerData* player = (PlayerData*)arg;
    
    char command[MAX_BUFFER];
    sprintf(command, "sudo iwlist wlan0 scan | grep -E 'Signal|ESSID'");

    FILE* pipe = popen(command, "r");
    if (pipe == NULL) {
        perror("popen");
        return NULL;
    }

    char line[MAX_BUFFER];
    int index = 0;
    while (fgets(line, sizeof(line), pipe) != NULL) {
        if (strstr(line, "Signal")) {
            sscanf(line, " Signal level=%d", &player->networks[index].signal_strength);
        } else if (strstr(line, "ESSID")) {
            sscanf(line, " ESSID:\"%[^\"]\"", player->networks[index].ssid);
            index++;
            if (index >= 10) break; // Store only first 10 networks
        }
    }
    pclose(pipe);

    pthread_mutex_lock(&mutex);
    printf("Player %d analyzed Wi-Fi networks:\n", player->player_id);
    for (int i = 0; i < index; i++) {
        printf("\tSSID: %s, Signal Strength: %d dBm\n", player->networks[i].ssid, player->networks[i].signal_strength);
    }
    pthread_mutex_unlock(&mutex);
    
    return NULL;
}

void add_player() {
    if (player_count >= MAX_PLAYERS) {
        printf("Maximum number of players reached!\n");
        return;
    }
    
    players[player_count].player_id = player_count + 1;
    pthread_t thread;
    pthread_create(&thread, NULL, analyze_signal, &players[player_count]);
    pthread_detach(thread);
    
    player_count++;
}

int main() {
    while (1) {
        char input;
        printf("Press 'a' to add a player to analyze Wi-Fi signal strength, or 'q' to quit: ");
        scanf(" %c", &input);
        
        if (input == 'a') {
            add_player();
        } else if (input == 'q') {
            break;
        } else {
            printf("Invalid input. Please try again.\n");
        }
    }
    
    printf("Exiting Wi-Fi Signal Strength Analyzer.\n");
    return 0;
}