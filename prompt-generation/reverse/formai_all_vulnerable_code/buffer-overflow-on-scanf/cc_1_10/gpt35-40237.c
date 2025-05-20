//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 8
#define GENOME_LEN 1000

struct player {
    char name[20];
    char genome[GENOME_LEN];
    int score;
};

int num_players;
struct player players[MAX_PLAYERS];

void generate_genome(char* genome) {
    char bases[4] = {'A', 'C', 'G', 'T'};
    for (int i = 0; i < GENOME_LEN; i++) {
        genome[i] = bases[rand() % 4];
    }
}

void print_genome(char* genome, int start, int end) {
    for (int i = start; i <= end; i++) {
        printf("%c", genome[i]);
    }
    printf("\n");
}

int score_genome(char* genome, int start, int end, char* target) {
    int score = 0;
    for (int i = start; i <= end; i++) {
        if (genome[i] == target[i-start]) {
            score++;
        }
    }
    return score;
}

void print_scores() {
    printf("Current scores:\n");
    for (int i = 0; i < num_players; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }
}

int main() {
    srand(time(NULL));
    printf("Welcome to Genome Sequencing Simulator!\n");

    printf("Enter the number of players (max 8): ");
    scanf("%d", &num_players);

    if (num_players < 2 || num_players > 8) {
        printf("Invalid number of players!\n");
        return 1;
    }

    for (int i = 0; i < num_players; i++) {
        printf("Enter player %d's name: ", i+1);
        scanf("%s", players[i].name);
        generate_genome(players[i].genome);
        players[i].score = 0;
    }

    char target[GENOME_LEN/2];
    printf("Enter the target genome sequence (length %d): ", GENOME_LEN/2);
    scanf("%s", target);

    int round = 0;
    while (1) {
        printf("=== Round %d ===\n", round+1);

        for (int i = 0; i < num_players; i++) {
            printf("%s, it's your turn!\n", players[i].name);
            printf("Your genome (length %d): ", GENOME_LEN);
            print_genome(players[i].genome, 0, GENOME_LEN-1);

            char guess[GENOME_LEN/2];
            printf("Make your guess (length %d): ", GENOME_LEN/2);
            scanf("%s", guess);

            int score = score_genome(players[i].genome, 0, GENOME_LEN/2-1, guess);
            players[i].score += score;

            printf("You scored %d points!\n", score);
            print_scores();
        }

        round++;

        if (round == 5) {
            printf("Game over!\n");
            break;
        }
    }

    return 0;
}