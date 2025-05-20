//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: lively
#include <stdio.h>
#include <stdbool.h>

int main() {

    // Haunted house simulator game in C

    printf("Welcome to the Haunted House Simulator game!\n");
    printf("Enter your name to start the game: ");

    char name[20];
    scanf("%s", name);

    printf("\nHello %s, are you ready to enter the spooky haunted house?\n", name);

    int roomNum = 1;
    bool hasKey = false;

    while (roomNum <= 4) {

        switch(roomNum) {
            case 1:
                printf("\nYou are now in the entrance hall.\n");
                printf("There are two doors, one on the left and one on the right.\n");
                printf("Which one do you choose?\n");
                printf("[1] Left door\n");
                printf("[2] Right door\n");

                int doorChoice;
                scanf("%d", &doorChoice);

                if (doorChoice == 1) {
                    printf("You enter the left door and find yourself in the kitchen.\n");
                    printf("There is a key on the counter.\n");
                    printf("Take the key? [1] Yes [2] No\n");

                    int keyChoice;
                    scanf("%d", &keyChoice);

                    if (keyChoice == 1) {
                        printf("You take the key.\n");
                        hasKey = true;
                    } else {
                        printf("You leave the key on the counter and continue exploring.\n");
                    }

                    roomNum = 2;

                } else {
                    printf("You enter the right door and find yourself in the living room.\n");
                    printf("There is a ghostly figure standing in the middle of the room.\n");
                    printf("What do you do?\n");
                    printf("[1] Talk to the ghost\n");
                    printf("[2] Run out of the house\n");

                    int ghostChoice;
                    scanf("%d", &ghostChoice);

                    if (ghostChoice == 2) {
                        printf("You run out of the house in terror.\n");
                        printf("Game Over!\n");
                        return 0;
                    }

                    printf("You start talking to the ghost and realize that it's friendly!\n");
                    printf("The ghost tells you that there is a treasure hidden in the attic.\n");

                    roomNum = 3;
                }

                break;

            case 2:
                printf("\nYou are now in the hallway.\n");
                printf("There is a locked door in front of you.\n");

                if (hasKey == true) {
                    printf("You use the key to unlock the door.\n");
                    printf("You find yourself in the basement.\n");
                    printf("There is a note on the wall that says 'The treasure is in the attic'.\n");
                    roomNum = 3;

                } else {
                    printf("You do not have the key.\n");
                    printf("You turn around and go back to the entrance hall.\n");
                    roomNum = 1;
                }

                break;

            case 3:
                printf("\nYou are now in the attic.\n");
                printf("You find a mysterious chest!\n");
                printf("Do you want to try to open it? [1] Yes [2] No\n");

                int chestChoice;
                scanf("%d", &chestChoice);

                if (chestChoice == 2) {
                    printf("You leave the chest and continue exploring.\n");
                    roomNum = 4;

                } else {
                    printf("You try to open the chest...\n");

                    int randomNumber = rand() % 2;

                    if (randomNumber == 0) {
                        printf("The chest is empty! Bummer.\n");
                        roomNum = 4;

                    } else {
                        printf("Congratulations %s, you have found the treasure!\n", name);
                        printf("You win the game!\n");
                        return 0;
                    }
                }

                break;

            case 4:
                printf("\nYou are now in the backyard.\n");
                printf("You see a car parked outside the gates.\n");
                printf("Do you want to try to escape using the car? [1] Yes [2] No\n");

                int carChoice;
                scanf("%d", &carChoice);

                if (carChoice == 2) {
                    printf("You decide to stay and explore some more.\n");

                } else {
                    printf("You try to hotwire the car...");

                    int randomNumber = rand() % 2;

                    if (randomNumber == 0) {
                        printf("The car won't start! You are stuck in the haunted house forever.\n");
                        printf("Game Over!\n");
                        return 0;

                    } else {
                        printf("You successfully start the car and drive away from the haunted house!\n");
                        printf("Congratulations %s, you have escaped the haunted house!\n", name);
                        printf("You win the game!\n");
                        return 0;
                    }
                }

                break;
        }
    }

    return 0;
}