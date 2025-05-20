//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[50];
    int health;
} Player;

void initPlayer(Player* player) {
    strcpy(player->name, "John");
    player->health = 100;
}

void printPlayerInfo(Player player) {
    printf("Name: %s\n", player.name);
    printf("Health: %d\n", player.health);
}

int main() {
    srand(time(0));

    Player player;
    initPlayer(&player);

    int choice;
    char input[50];

    while(1) {
        printf("You wake up in a post-apocalyptic world.\n");
        printf("The air is thick with radiation and the sky is dark.\n");
        printf("You have %d health points left.\n", player.health);

        printf("\nWhat do you want to do?\n");
        printf("1. Search for food\n");
        printf("2. Search for water\n");
        printf("3. Rest\n");
        printf("4. Continue journey\n");
        printf("5. Quit\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("You start searching for food...\n");
                if(rand() % 2 == 0) {
                    printf("You find some canned food.\n");
                    player.health += 10;
                } else {
                    printf("You couldn't find any food.\n");
                }
                break;
            case 2:
                printf("You start searching for water...\n");
                if(rand() % 2 == 0) {
                    printf("You find a bottle of water.\n");
                    player.health += 5;
                } else {
                    printf("You couldn't find any water.\n");
                }
                break;
            case 3:
                printf("You take a rest...\n");
                player.health += 5;
                break;
            case 4:
                printf("You continue your journey...\n");
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }

        printPlayerInfo(player);
    }

    return 0;
}