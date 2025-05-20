//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 10
#define MAX_SEQUENCE_LENGTH 1000
#define MAX_MUTATION_RATE 0.1

typedef struct player {
    char name[20];
    int score;
    char sequence[MAX_SEQUENCE_LENGTH];
} Player;

Player players[MAX_PLAYERS];
int num_players;

void initialize_players() {
    srand(time(NULL));
    for(int i = 0; i < MAX_PLAYERS; i++) {
        players[i].score = 0;
        for(int j = 0; j < MAX_SEQUENCE_LENGTH; j++) {
            players[i].sequence[j] = rand() % 4;
        }
    }
}

void print_leaderboard() {
    printf("Leaderboard:\n");
    for(int i = 0; i < num_players; i++) {
        printf("%d. %s - Score: %d\n", i+1, players[i].name, players[i].score);
    }
}

int compare_sequences(char* seq1, char* seq2) {
    int matches = 0;
    for(int i = 0; i < strlen(seq1); i++) {
        if(seq1[i] == seq2[i]) {
            matches++;
        }
    }
    return matches;
}

void simulate_genome_sequencing() {
    printf("Simulating genome sequencing...\n");
    for(int i = 0; i < num_players; i++) {
        for(int j = 0; j < MAX_SEQUENCE_LENGTH; j++) {
            if(rand() % 100 < MAX_MUTATION_RATE) {
                players[i].sequence[j] = rand() % 4;
            }
        }
    }
}

int main() {
    printf("Welcome to the C Genome Sequencing Simulator!\n");
    printf("How many players will be participating? (Max %d): ", MAX_PLAYERS);
    scanf("%d", &num_players);

    printf("Enter player names:\n");
    for(int i = 0; i < num_players; i++) {
        scanf("%s", players[i].name);
    }

    initialize_players();
    int rounds = 0;

    while(1) {
        printf("\nRound %d:\n", rounds+1);
        simulate_genome_sequencing();
        print_leaderboard();
        rounds++;

        if(rounds == 10) {
            break;
        }
    }

    return 0;
}