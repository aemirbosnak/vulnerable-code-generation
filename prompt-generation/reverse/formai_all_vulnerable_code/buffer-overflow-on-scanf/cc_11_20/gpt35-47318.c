//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main() {
    //Initializing Variables
    bool isLightsOn = false;
    bool isDoorLocked = true;
    bool isMonsterPresent = true;
    bool isPlayerAlive = true;
    char player[20];
    int choice;
    srand(time(0));

    //Welcome Message
    printf("Welcome to the Haunted Castle Simulator\n");
    printf("Enter your name: ");
    scanf("%s", &player);
    printf("\n");

    //Game Loop
    while (isPlayerAlive) {
        printf("\n%s, you are in a haunted castle. What would you like to do?\n", player);
        printf("1. Turn on the lights\n");
        printf("2. Try to unlock the door\n");
        printf("3. Search for a weapon\n");
        printf("4. Leave the castle\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                if (isLightsOn) {
                    printf("The lights are already on!\n");
                } else {
                    printf("You turn on the lights and see a ghostly figure standing in front of you! ");
                    printf("You freeze in fear and the ghost suddenly disappears.\n");
                    isLightsOn = true;
                    isMonsterPresent = true;
                }
                break;
            case 2:
                if (!isLightsOn) {
                    printf("It is too dark to unlock the door. Turn on the lights first!\n");
                } else if (isDoorLocked) {
                    printf("You try to unlock the door but it is stuck. ");
                    printf("You hear a scream coming from behind the door and decide to stay inside.\n");
                } else {
                    printf("You successfully unlock the door and escape the castle! Congratulations, %s!\n", player);
                    isPlayerAlive = false;
                }
                break;
            case 3:
                if (!isLightsOn) {
                    printf("It is too dark to search for a weapon. Turn on the lights first!\n");
                } else {
                    int random = rand() % 2;
                    if (random == 0) {
                        printf("You find a sword and feel safer now.\n");
                    } else {
                        printf("You find a rusty dagger, but it is better than nothing.\n");
                    }
                }
                break;
            case 4:
                if (!isDoorLocked) {
                    printf("You try to escape the castle, but a monster blocks the way. ");
                    printf("You die in combat. Game over, %s.\n", player);
                    isPlayerAlive = false;
                } else {
                    printf("The door is locked! You need to find the key to unlock it.\n");
                }
                break;
            default:
                printf("Invalid choice! Try again.\n");
                break;
        }

        //Monster Attack
        if (isMonsterPresent) {
            int random = rand() % 4;
            if (random == 0) {
                printf("The monster attacks you and you die! Game over, %s.\n", player);
                isPlayerAlive = false;
            } else {
                printf("You hear strange noises, but the monster doesn't attack this time.\n");
            }
        }
    }

    return 0;
}