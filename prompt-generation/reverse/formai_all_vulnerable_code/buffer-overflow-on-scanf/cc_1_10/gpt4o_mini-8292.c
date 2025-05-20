//GPT-4o-mini DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_USERS 10
#define MAX_SSID_LENGTH 32
#define MAX_NETWORKS 50

typedef struct {
    char ssid[MAX_SSID_LENGTH];
    int signal_level; // Signal level in dBm
} WifiNetwork;

typedef struct {
    int user_id;
    WifiNetwork networks[MAX_NETWORKS];
    int network_count;
} User;

User users[MAX_USERS];
int user_count = 0;
pthread_mutex_t lock;

void* analyze_signal_strength(void* arg) {
    User* user = (User*)arg;
    char command[256];
    sprintf(command, "sudo iwlist wlan0 scan | grep -E 'ESSID|Signal' > user_%d.txt", user->user_id);
    
    system(command); // Run the system command to get Wi-Fi data
    
    FILE* fp;
    char line[256];
    int index = 0;

    // Open the generated output
    sprintf(command, "user_%d.txt", user->user_id);
    fp = fopen(command, "r");
   
    if (fp == NULL) {
        perror("Failed to open file");
        return NULL;
    }

    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, "ESSID:")) {
            sscanf(line, " ESSID:\"%[^\"]\"", user->networks[index].ssid);
        }
        if (strstr(line, "Signal level=")) {
            sscanf(line, " Signal level=%d", &user->networks[index].signal_level);
            index++;
        }
    }
    
    user->network_count = index;
    fclose(fp);
    
    // Cleanup
    sprintf(command, "rm user_%d.txt", user->user_id);
    system(command);
    
    return NULL;
}

void display_results(User* user) {
    printf("\n--- User %d Wi-Fi Signal Strength Results ---\n", user->user_id);
    for (int i = 0; i < user->network_count; i++) {
        printf("SSID: %s, Signal Level: %d dBm\n", user->networks[i].ssid, user->networks[i].signal_level);
    }
}

int main() {
    pthread_t threads[MAX_USERS];
    printf("Welcome to the Wi-Fi Signal Strength Analyzer!\n");
    
    while (user_count < MAX_USERS) {
        printf("Enter your user ID (0 to finish): ");
        int user_id;
        scanf("%d", &user_id);
        
        if (user_id == 0) break; // Exit

        pthread_mutex_lock(&lock);
        users[user_count].user_id = user_id;
        user_count++;
        pthread_mutex_unlock(&lock);

        pthread_create(&threads[user_count - 1], NULL, analyze_signal_strength, (void*)&users[user_count - 1]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < user_count; i++) {
        pthread_join(threads[i], NULL);
        display_results(&users[i]);
    }

    printf("Analysis complete. Goodbye!\n");
    return 0;
}