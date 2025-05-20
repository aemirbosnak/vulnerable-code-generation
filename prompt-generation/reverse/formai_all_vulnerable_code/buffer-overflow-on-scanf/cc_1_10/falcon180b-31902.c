//Falcon-180B DATASET v1.0 Category: Table Game ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_ROUNDS 3
#define MAX_DICE_VALUE 6

typedef struct {
    char name[20];
    int gold;
} Player;

void init_player(Player *player) {
    strcpy(player->name, "Unknown");
    player->gold = 0;
}

void display_player(Player player) {
    printf("Name: %s\nGold: %d\n", player.name, player.gold);
}

void roll_dice(int *dice_value) {
    *dice_value = rand() % MAX_DICE_VALUE + 1;
}

int main() {
    srand(time(NULL));

    Player players[MAX_PLAYERS];
    for (int i = 0; i < MAX_PLAYERS; i++) {
        init_player(&players[i]);
    }

    int active_player = 0;
    while (1) {
        system("clear");
        printf("Welcome to the Medieval Table Game!\n");
        for (int i = 0; i < MAX_PLAYERS; i++) {
            display_player(players[i]);
        }
        printf("\nActive player: %s\n", players[active_player].name);
        printf("Enter command: ");
        char command[20];
        scanf("%s", command);

        if (strcmp(command, "roll") == 0) {
            int dice_value;
            roll_dice(&dice_value);
            printf("You rolled a %d!\n", dice_value);
        } else if (strcmp(command, "gold") == 0) {
            printf("You have %d gold.\n", players[active_player].gold);
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}