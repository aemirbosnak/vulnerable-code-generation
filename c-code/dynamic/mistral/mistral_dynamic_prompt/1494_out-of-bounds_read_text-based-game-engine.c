#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    char inventory[10][20];
    int gold;
} Player;

Player *createPlayer(char *name, int gold) {
    Player *player = malloc(sizeof(Player));
    strcpy(player->name, name);
    player->gold = gold;
    for (int i = 0; i < 10; ++i) strcpy(player->inventory[i], "");
    return player;
}

void printInventory(Player *player) {
    printf("Inventory:\n");
    for (int i = 0; i < 10; ++i)
        printf("%s\n", player->inventory[i]);
}

void addItem(Player *player, char *item) {
    for (int i = 0; i < 10; ++i)
        if (!strcmp(player->inventory[i], "")) {
            strcpy(player->inventory[i], item);
            break;
        }
}

int main(int argc, char *argv[]) {
    Player *player = createPlayer(argv[1], atoi(argv[2]));

    for (int i = 3; i < argc; ++i) addItem(player, argv[i]);

    printInventory(player);

    free(player);
    return 0;
}
