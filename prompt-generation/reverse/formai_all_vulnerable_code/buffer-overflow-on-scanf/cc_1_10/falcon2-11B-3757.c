//Falcon2-11B DATASET v1.0 Category: Procedural Space Adventure ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    char race[50];
} Player;

Player players[10];
int player_count = 0;

void add_player() {
    if (player_count < 10) {
        printf("Enter player name: ");
        scanf("%s", players[player_count].name);
        printf("Enter player age: ");
        scanf("%d", &players[player_count].age);
        printf("Enter player race: ");
        scanf(" %s", players[player_count].race);
        player_count++;
    } else {
        printf("Max number of players reached.\n");
    }
}

void show_players() {
    for (int i = 0; i < player_count; i++) {
        printf("Player %d: %s, Age: %d, Race: %s\n", i+1, players[i].name, players[i].age, players[i].race);
    }
}

int main() {
    int choice;
    while (1) {
        printf("1. Add player\n2. Show players\n3. Quit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_player();
                break;
            case 2:
                show_players();
                break;
            case 3:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    return 0;
}