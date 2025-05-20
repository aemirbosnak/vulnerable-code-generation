//Gemma-7B DATASET v1.0 Category: Disk space analyzer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_Players 4

typedef struct Player {
    char name[20];
    int disk_space;
    int used_space;
    int remaining_space;
} Player;

void analyze_disk_space(Player *players) {
    for (int i = 0; i < MAX_Players; i++) {
        struct stat st;
        stat(players[i].name, &st);
        players[i].disk_space = st.st_size;
        players[i].used_space = st.st_size - players[i].remaining_space;
        players[i].remaining_space = players[i].disk_space - players[i].used_space;
    }
}

int main() {
    Player players[MAX_Players];

    // Initialize players
    for (int i = 0; i < MAX_Players; i++) {
        players[i].name[0] = '\0';
        players[i].disk_space = 0;
        players[i].used_space = 0;
        players[i].remaining_space = 0;
    }

    // Get player names
    for (int i = 0; i < MAX_Players; i++) {
        printf("Enter your name: ");
        scanf("%s", players[i].name);
    }

    // Analyze disk space
    analyze_disk_space(players);

    // Print results
    for (int i = 0; i < MAX_Players; i++) {
        printf("%s has %d MB of disk space.\n", players[i].name, players[i].disk_space);
        printf("%s is using %d MB of disk space.\n", players[i].name, players[i].used_space);
        printf("%s has %d MB of remaining space.\n", players[i].name, players[i].remaining_space);
    }

    return 0;
}