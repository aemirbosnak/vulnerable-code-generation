//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int roomsVisited = 0;
    int hasGhost = 0;
    int hasTreasure = 0;
    int trapChance = 20;

    printf("Welcome to the Haunted House Simulator!\n");
    printf("You are standing in front of a spooky old house. Do you enter? (y/n)\n");

    char answer;
    scanf("%c", &answer);

    if (answer == 'y') {
        printf("You cautiously enter the house...\n");
        while (1) {
            int random = rand() % 3;

            if (random == 0) {
                printf("You have entered the room of the restless spirit...\n");
                hasGhost = 1;

                if (rand() % trapChance == 1) {
                    printf("The room was also a trap! You were killed...\n");
                    printf("Game over. You visited %d rooms.\n", roomsVisited);
                    break;
                }
            }

            else if (random == 1) {
                printf("You have entered the treasure room! You find a chest filled with gold and jewels...\n");
                hasTreasure = 1;

                if (rand() % trapChance == 1) {
                    printf("The chest was also a trap! You were killed...\n");
                    printf("Game over. You visited %d rooms.\n", roomsVisited);
                    break;
                }
            }

            else {
                printf("You have entered an empty room...\n");
                if (rand() % trapChance == 1) {
                    printf("The room was a trap! You were killed...\n");
                    printf("Game over. You visited %d rooms.\n", roomsVisited);
                    break;
                }
            }

            roomsVisited++;
            
            if (hasGhost && hasTreasure) {
                printf("You have visited every room in the house!\n");
                printf("Congratulations! You have found the treasure and escaped the haunted house in %d rooms.\n", roomsVisited);
                break;
            }

            printf("Do you want to enter the next room? (y/n)\n");
            scanf(" %c", &answer);

            if (answer == 'n') {
                printf("You have ended your adventure in the haunted house.\n");
                printf("You visited %d rooms.\n", roomsVisited);
                break;
            }
        }
    }

    else {
        printf("You have chosen not to enter the haunted house.\n");
    }

    return 0;
}