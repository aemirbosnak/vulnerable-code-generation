//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_PLAYERS 4
#define MAX_CONVERSIONS 10

typedef struct {
    char name[20];
    int score;
    char conversions[MAX_CONVERSIONS][20];
    int num_conversions;
} Player;

int main() {
    int num_players = 2;
    char player_names[MAX_PLAYERS][20];
    int player_scores[MAX_PLAYERS] = {0};
    char conversions[MAX_CONVERSIONS][20];
    int num_conversions = 0;
    int current_player = 0;
    int current_conversion = 0;
    char input[50];
    int i, j, k;

    for (i = 0; i < num_players; i++) {
        printf("Enter the name for player %d: ", i + 1);
        scanf("%s", player_names[i]);
    }

    while (1) {
        printf("\n%s's turn\n", player_names[current_player]);
        printf("Enter a conversion (e.g. '1 meter = 3.28 feet'): ");
        scanf("%s", input);

        for (i = 0; i < num_conversions; i++) {
            if (strcmp(input, conversions[i]) == 0) {
                printf("You already entered that conversion.\n");
                break;
            }
        }

        if (i == num_conversions) {
            strcpy(conversions[num_conversions], input);
            num_conversions++;
            if (num_conversions == MAX_CONVERSIONS) {
                printf("You have entered the maximum number of conversions.\n");
            }
        } else {
            printf("You already entered that conversion.\n");
        }

        for (j = 0; j < num_players; j++) {
            if (j == current_player) {
                continue;
            }

            for (k = 0; k < num_conversions; k++) {
                if (strcmp(conversions[k], player_names[j]) == 0) {
                    printf("%s already entered that conversion.\n", player_names[j]);
                    break;
                }
            }
        }

        if (j == num_players) {
            player_scores[current_player]++;
        }

        current_player = (current_player + 1) % num_players;
    }

    return 0;
}