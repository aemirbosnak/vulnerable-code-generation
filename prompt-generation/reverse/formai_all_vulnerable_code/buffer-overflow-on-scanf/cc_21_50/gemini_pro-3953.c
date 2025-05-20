//GEMINI-pro DATASET v1.0 Category: Sorting ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 4
#define MAX_NUMBERS 10

typedef struct {
    char name[20];
    int numbers[MAX_NUMBERS];
    int sorted_count;
} Player;

int main() {
    Player players[MAX_PLAYERS];
    int i, j, k, n;

    // Get player names and numbers
    for (i = 0; i < MAX_PLAYERS; i++) {
        printf("Enter player %d's name: ", i + 1);
        scanf("%s", players[i].name);

        printf("Enter %d numbers for player %s: ", MAX_NUMBERS, players[i].name);
        for (j = 0; j < MAX_NUMBERS; j++) {
            scanf("%d", &players[i].numbers[j]);
        }

        players[i].sorted_count = 0;
    }

    // Sort the numbers for each player
    for (i = 0; i < MAX_PLAYERS; i++) {
        for (j = 0; j < MAX_NUMBERS - 1; j++) {
            for (k = j + 1; k < MAX_NUMBERS; k++) {
                if (players[i].numbers[j] > players[i].numbers[k]) {
                    int temp = players[i].numbers[j];
                    players[i].numbers[j] = players[i].numbers[k];
                    players[i].numbers[k] = temp;
                }
            }
        }
    }

    // Check if all players have sorted their numbers
    while (1) {
        n = 0;
        for (i = 0; i < MAX_PLAYERS; i++) {
            if (players[i].sorted_count == MAX_NUMBERS) {
                n++;
            }
        }

        if (n == MAX_PLAYERS) {
            break;
        }

        // Display the unsorted numbers for each player
        for (i = 0; i < MAX_PLAYERS; i++) {
            if (players[i].sorted_count < MAX_NUMBERS) {
                printf("%s: ", players[i].name);
                for (j = 0; j < MAX_NUMBERS; j++) {
                    if (players[i].numbers[j] == -1) {
                        printf(" ");
                    } else {
                        printf("%d ", players[i].numbers[j]);
                    }
                }
                printf("\n");
            }
        }

        // Get the next number to sort for each player
        for (i = 0; i < MAX_PLAYERS; i++) {
            if (players[i].sorted_count < MAX_NUMBERS) {
                int num;
                printf("%s, enter the next number to sort: ", players[i].name);
                scanf("%d", &num);

                for (j = 0; j < MAX_NUMBERS; j++) {
                    if (players[i].numbers[j] == -1) {
                        players[i].numbers[j] = num;
                        players[i].sorted_count++;
                        break;
                    }
                }
            }
        }
    }

    // Display the sorted numbers for each player
    for (i = 0; i < MAX_PLAYERS; i++) {
        printf("%s: ", players[i].name);
        for (j = 0; j < MAX_NUMBERS; j++) {
            printf("%d ", players[i].numbers[j]);
        }
        printf("\n");
    }

    return 0;
}