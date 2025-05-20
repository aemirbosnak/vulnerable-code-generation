//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

// Function to print a pattern
void print_pattern(int n, int m) {
    int i, j, k;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int n, m, player_count, player_number, current_player;
    char player_name[50];

    // Get the number of players
    printf("Enter the number of players: ");
    scanf("%d", &player_count);

    // Get the names of the players
    printf("Enter the names of the players:\n");
    for (int i = 0; i < player_count; i++) {
        scanf("%s", player_name[i]);
    }

    // Get the number of rows and columns for the pattern
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    printf("Enter the number of columns: ");
    scanf("%d", &m);

    // Initialize the current player to 0
    current_player = 0;

    // Print the pattern for each player
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j % 2 == 0) {
                printf("%s's turn\n", player_name[current_player]);
                current_player = (current_player + 1) % player_count;
            }
            print_pattern(n, m);
        }
    }

    return 0;
}