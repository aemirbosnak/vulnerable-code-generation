//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 10
#define TIME_QUANTUM 2

typedef struct {
    int player_id;
    int burst_time; // time required for this event
    int remaining_time;
    int score;
} Player;

void FCFS(Player players[], int count);
void SJF(Player players[], int count);
void RoundRobin(Player players[], int count);
void printPlayers(Player players[], int count);
void initializePlayers(Player players[], int count);

int main() {
    Player players[MAX_PLAYERS];
    int count = 0;

    printf("Enter number of players (max 10): ");
    scanf("%d", &count);

    if (count > MAX_PLAYERS || count <= 0) {
        printf("Invalid number of players. Exiting...\n");
        return 1;
    }

    initializePlayers(players, count);

    printf("Players Created:\n");
    printPlayers(players, count);

    printf("\n=== FCFS Scheduling ===\n");
    FCFS(players, count);

    printf("\n=== SJF Scheduling ===\n");
    SJF(players, count);

    printf("\n=== Round Robin Scheduling ===\n");
    RoundRobin(players, count);

    return 0;
}

void initializePlayers(Player players[], int count) {
    for (int i = 0; i < count; i++) {
        players[i].player_id = i + 1;
        players[i].burst_time = rand() % 10 + 1; // Random burst time between 1 and 10
        players[i].remaining_time = players[i].burst_time;
        players[i].score = 0;
    }
}

void printPlayers(Player players[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Player ID: %d, Burst Time: %d, Remaining Time: %d, Score: %d\n",
               players[i].player_id, players[i].burst_time, players[i].remaining_time, players[i].score);
    }
}

void FCFS(Player players[], int count) {
    int total_time = 0;
    for (int i = 0; i < count; i++) {
        printf("Player %d is playing for %d seconds.\n", players[i].player_id, players[i].burst_time);
        total_time += players[i].burst_time;
        players[i].score += players[i].burst_time; // Simple score increment
    }
    printf("Total gameplay time: %d seconds.\n", total_time);
}

void SJF(Player players[], int count) {
    Player temp;

    // Sort players based on burst_time (SJF logic)
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (players[i].burst_time > players[j].burst_time) {
                temp = players[i];
                players[i] = players[j];
                players[j] = temp;
            }
        }
    }

    int total_time = 0;
    for (int i = 0; i < count; i++) {
        printf("Player %d is playing for %d seconds.\n", players[i].player_id, players[i].burst_time);
        total_time += players[i].burst_time;
        players[i].score += players[i].burst_time;
    }
    printf("Total gameplay time: %d seconds.\n", total_time);
}

void RoundRobin(Player players[], int count) {
    int total_time = 0;
    int completed = 0;

    while (completed < count) {
        for (int i = 0; i < count; i++) {
            if (players[i].remaining_time > 0) {
                int time_spent = players[i].remaining_time > TIME_QUANTUM ? TIME_QUANTUM : players[i].remaining_time;
                players[i].remaining_time -= time_spent;
                total_time += time_spent;
                players[i].score += time_spent;

                printf("Player %d is playing for %d seconds. Remaining time: %d\n",
                       players[i].player_id, time_spent, players[i].remaining_time);

                if (players[i].remaining_time == 0) {
                    completed++;
                }
            }
        }
    }

    printf("Total gameplay time in Round Robin: %d seconds.\n", total_time);
}