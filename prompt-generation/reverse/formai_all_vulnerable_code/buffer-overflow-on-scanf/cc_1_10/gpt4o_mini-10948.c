//GPT-4o-mini DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PLAYERS 5
#define MAX_NETWORKS 50
#define BUFFER_SIZE 256

typedef struct {
    char ssid[BUFFER_SIZE];
    int signal_strength;
} Network;

typedef struct {
    char name[BUFFER_SIZE];
    Network networks[MAX_NETWORKS];
    int network_count;
} Player;

void scan_networks(Player *player) {
    FILE *fp;
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "sudo iwlist wlan0 scan | grep 'ESSID\\|Signal level' > networks.txt");

    system(command);
    
    fp = fopen("networks.txt", "r");
    if (!fp) {
        perror("Failed to open file");
        return;
    }

    char line[BUFFER_SIZE];
    player->network_count = 0;
    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, "ESSID:")) {
            sscanf(line, " ESSID:\"%[^\"]\"", player->networks[player->network_count].ssid);
        } else if (strstr(line, "Signal level=")) {
            sscanf(line, " Signal level=%d", &player->networks[player->network_count].signal_strength);
            player->network_count++;
        }
    }

    fclose(fp);
}

void print_player_networks(const Player *player) {
    printf("%s's Networks:\n", player->name);
    for (int i = 0; i < player->network_count; ++i) {
        printf("Network SSID: %s | Signal Strength: %d dBm\n", 
                player->networks[i].ssid, 
                player->networks[i].signal_strength);
    }
}

int find_strongest_network(const Player *player) {
    int max_strength = -100; // Arbitrarily low number
    int winning_index = -1;

    for (int i = 0; i < player->network_count; ++i) {
        if (player->networks[i].signal_strength > max_strength) {
            max_strength = player->networks[i].signal_strength;
            winning_index = i;
        }
    }

    return winning_index;
}

int main() {
    Player players[MAX_PLAYERS];
    int player_count;

    printf("Enter number of players (max %d): ", MAX_PLAYERS);
    scanf("%d", &player_count);

    if (player_count > MAX_PLAYERS) {
        printf("Exceeds maximum number of players.\n");
        return 1;
    }

    for (int i = 0; i < player_count; i++) {
        printf("Enter name for player %d: ", i + 1);
        scanf("%s", players[i].name);
        scan_networks(&players[i]);
        print_player_networks(&players[i]);
    }

    int winning_index = -1;
    int max_strength = -100; // Initialize to a low strength

    for (int i = 0; i < player_count; ++i) {
        int strongest_index = find_strongest_network(&players[i]);
        if (strongest_index != -1 && players[i].networks[strongest_index].signal_strength > max_strength) {
            max_strength = players[i].networks[strongest_index].signal_strength;
            winning_index = i;
        }
    }

    if (winning_index != -1) {
        printf("The winner is %s with a network of %s having %d dBm signal strength!\n",
               players[winning_index].name,
               players[winning_index].networks[find_strongest_network(&players[winning_index])].ssid,
               max_strength);
    } else {
        printf("No networks found.\n");
    }

    // Clean up the temporary file
    system("rm networks.txt");

    return 0;
}