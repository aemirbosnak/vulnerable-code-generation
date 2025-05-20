//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 6
#define MAX_ATCG 100

char atcg[] = "ATCG";
char sequence[MAX_ATCG];
int chosen_indexes[MAX_ATCG][MAX_PLAYERS];

//Function to generate random DNA sequences
void generate_sequence(int length) {
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        sequence[i] = atcg[rand() % 4];
    }
    sequence[length] = '\0';
    printf("The generated DNA sequence is: %s\n", sequence);
}

//Function to choose indexes for players to simulate DNA sequencing
void choose_indexes(int player_count, int length) {
    int chosen = 0;
    while (chosen < player_count) {
        int index = rand() % length;
        int i, j;
        for (i = 0; i < chosen; i++) {
            for (j = 0; j < chosen_indexes[index][i]; j++) {
                if (chosen_indexes[j][i] == index) {
                    break;
                }
            }
            if (j < chosen_indexes[j][i]) {
                break;
            }
        }
        if (i == chosen) {
            chosen_indexes[index][chosen] = index;
            chosen++;
        }
    }
}

//Function to simulate genome sequencing
void sequencing(int player_count, int length, int turns) {
    for (int i = 0; i < turns; i++) {
        printf("Turn %d\n", i + 1);
        for (int j = 0; j < player_count; j++) {
            printf("Player %d's sequence: ", j + 1);
            for (int k = 0; k < length; k++) {
                if (chosen_indexes[k][j] == k) {
                    printf("%c", sequence[k]);
                } else {
                    printf("-");
                }
            }
            printf("\n");
        }
    }
}

int main() {
    int player_count, length, turns;
    printf("Welcome to the Genome Sequencing Simulator!\n");
    printf("Enter number of players (1-%d): ", MAX_PLAYERS);
    scanf("%d", &player_count);
    if (player_count > MAX_PLAYERS || player_count < 1) {
        printf("Invalid choice of players.\n");
        return 1;
    }
    printf("Enter sequence length (1-%d): ", MAX_ATCG);
    scanf("%d", &length);
    if (length > MAX_ATCG || length < 1) {
        printf("Invalid sequence length.\n");
        return 1;
    }
    printf("Enter number of turns: ");
    scanf("%d", &turns);
    if (turns < 1) {
        printf("Invalid number of turns.\n");
        return 1;
    }
    generate_sequence(length);
    choose_indexes(player_count, length);
    sequencing(player_count, length, turns);
    printf("Simulation complete.\n");
    return 0;
}