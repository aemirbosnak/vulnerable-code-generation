//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void scarePlayer() {
    int randNum = rand() % 3;
    if (randNum == 0) {
        printf("Ghost appears from the dark!\n");
    } else if (randNum == 1) {
        printf("You hear a loud scream!\n");
    } else {
        printf("The floor creaks beneath your feet!\n");
    }
}

int main() {
    srand(time(NULL));
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You are standing in front of the entrance to the haunted house.\n");
    printf("You notice a sign that says 'Abandoned for 50 years'.\n");
    printf("Do you want to enter? (Y/N)\n");

    char response;
    scanf("%c", &response);

    if (response == 'Y' || response == 'y') {
        printf("You push open the door and step inside.\n");
        printf("You can hear strange noises coming from the darkness.\n");
        printf("As you walk down the creaky hallway, you notice a candle flickering in the distance.\n");
        printf("Do you want to investigate? (Y/N)\n");

        scanf(" %c", &response);

        if (response == 'Y' || response == 'y') {
            printf("You cautiously approach the candle.\n");
            scarePlayer();
            printf("You turn around to leave, but the door has been locked.\n");
            printf("You are trapped in the haunted house!\n");
            printf("You must find a way out.\n");
        } else {
            printf("You decide to leave the candle alone.\n");
            printf("As you continue down the hallway, you hear whispers in your ear.\n");
            scarePlayer();
            printf("You see a door in front of you.\n");
            printf("Do you want to open it? (Y/N)\n");

            scanf(" %c", &response);

            if (response == 'Y' || response == 'y') {
                printf("You open the door and step inside.\n");
                printf("The room is filled with a thick mist.\n");
                scarePlayer();
                printf("You notice a key on the table.\n");
                printf("Do you want to pick it up? (Y/N)\n");

                scanf(" %c", &response);

                if (response == 'Y' || response == 'y') {
                    printf("You pick up the key.\n");
                    printf("As you turn to leave, you see a figure standing in front of you!\n");
                    printf("It is a ghost!\n");
                    printf("You quickly use the key to unlock the door and escape.\n");
                    printf("You made it out of the haunted house alive!\n");
                } else {
                    printf("You decide to leave the key alone.\n");
                    printf("As you turn to leave, you see a figure standing in front of you!\n");
                    printf("It is a ghost!\n");
                    printf("You try to run, but the ghost catches you.\n");
                    printf("You are now trapped in the haunted house forever.\n");
                }
            } else {
                printf("You decide not to open the door.\n");
                printf("As you turn around, you see a ghost floating towards you!\n");
                printf("You try to run, but the ghost grabs you.\n");
                printf("You are now trapped in the haunted house forever.\n");
            }
        }
    } else {
        printf("You decide not to enter the haunted house.\n");
    }

    return 0;
}