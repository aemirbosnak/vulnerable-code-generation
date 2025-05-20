#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_COMPONENT_TYPE_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char componentType[MAX_COMPONENT_TYPE_LENGTH];
} Player;

int main() {
    int numPlayers;
    printf("Enter the number of players: ");
    scanf("%d", &numPlayers);

    Player players[numPlayers];

    for (int i = 0; i < numPlayers; i++) {
        printf("Enter player %d's name: ", i + 1);
        scanf("%s", players[i].name);
        printf("Enter player %d's component type: ", i + 1);
        scanf("%s", players[i].componentType);
    }

    printf("\nPlayer details:\n");
    for (int i = 0; i < numPlayers; i++) {
        printf("Player %d: Name - %s, Component Type - %s\n", i + 1, players[i].name, players[i].componentType);
    }

    return 0;
}
