//Falcon2-11B DATASET v1.0 Category: Table Game ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_ROWS 4
#define NUM_COLS 5

typedef struct {
    char name[20];
    int value;
    char color[6];
} Player;

int main() {
    Player players[NUM_ROWS][NUM_COLS];

    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            char input[20];
            printf("Enter name of player at row %d, column %d: ", i + 1, j + 1);
            fgets(input, sizeof(input), stdin);
            input[strcspn(input, "\n")] = '\0';

            char color[6];
            int value;
            while (1) {
                printf("Enter color of player at row %d, column %d (red, green, blue): ", i + 1, j + 1);
                scanf("%s", color);
                value = strcmp(color, "red") - strcmp(color, "green") + strcmp(color, "blue");
                if (value!= 0) {
                    break;
                }
                printf("Invalid color. Try again: ");
            }

            strncpy(players[i][j].name, input, sizeof(input));
            players[i][j].value = value;
            strncpy(players[i][j].color, color, sizeof(color));
        }
    }

    printf("Table game:\n");
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            printf("Player %s at row %d, column %d: %s\n", players[i][j].name, i + 1, j + 1, players[i][j].color);
        }
    }

    return 0;
}