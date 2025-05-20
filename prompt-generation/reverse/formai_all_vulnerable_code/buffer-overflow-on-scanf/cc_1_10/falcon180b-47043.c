//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <locale.h>

#define MAX_PLAYERS 10
#define MAX_LINE_LEN 80

typedef struct {
    char name[20];
    int score;
} Player;

Player players[MAX_PLAYERS];
int num_players;

void init_players() {
    for (int i = 0; i < MAX_PLAYERS; i++) {
        strcpy(players[i].name, "Player ");
        sprintf(&players[i].name[7], "%d", i+1);
        players[i].score = 0;
    }
    num_players = 0;
}

void add_player() {
    if (num_players < MAX_PLAYERS) {
        strcpy(players[num_players].name, "Player ");
        sprintf(&players[num_players].name[7], "%d", num_players+1);
        players[num_players].score = 0;
        num_players++;
    } else {
        printf("Maximum number of players reached.\n");
    }
}

void print_players() {
    printf("Players:\n");
    for (int i = 0; i < num_players; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }
}

int main() {
    setlocale(LC_ALL, "");
    init_players();
    int choice;
    while (1) {
        printf("1. Add player\n2. Print players\n3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_player();
                break;
            case 2:
                print_players();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}