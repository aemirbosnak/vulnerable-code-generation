//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 4

typedef struct {
    char name[20];
    int score;
} player_t;

player_t players[MAX_PLAYERS];

void print_color_code(int color) {
    switch (color) {
        case 0:
            printf("Red");
            break;
        case 1:
            printf("Green");
            break;
        case 2:
            printf("Blue");
            break;
        case 3:
            printf("Yellow");
            break;
        case 4:
            printf("Magenta");
            break;
        case 5:
            printf("Cyan");
            break;
        case 6:
            printf("White");
            break;
        case 7:
            printf("Black");
            break;
        default:
            printf("Invalid color");
    }
}

int main() {
    int num_players;
    printf("Enter the number of players (1-%d): ", MAX_PLAYERS);
    scanf("%d", &num_players);

    if (num_players < 1 || num_players > MAX_PLAYERS) {
        printf("Invalid number of players");
        return 1;
    }

    for (int i = 0; i < num_players; i++) {
        printf("Enter player %d's name: ", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }

    while (1) {
        printf("\n");
        for (int i = 0; i < num_players; i++) {
            printf("%s: %d\n", players[i].name, players[i].score);
        }

        int player_index;
        printf("Enter the player index (1-%d) to convert a color code: ", num_players);
        scanf("%d", &player_index);

        if (player_index < 1 || player_index > num_players) {
            printf("Invalid player index");
            continue;
        }

        int color_code;
        printf("Enter the color code (0-7): ");
        scanf("%d", &color_code);

        if (color_code < 0 || color_code > 7) {
            printf("Invalid color code");
            continue;
        }

        print_color_code(color_code);
        printf("\n");

        players[player_index - 1].score++;
    }

    return 0;
}