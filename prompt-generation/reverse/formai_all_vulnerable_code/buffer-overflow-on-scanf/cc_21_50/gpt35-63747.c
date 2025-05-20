//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int inventory[4] = {0, 0, 0, 0}; //player's initial inventory

int main() {
    char playerName[20];
    int playerHealth = 100;
    int currentRoom = 0;
    int roomVisited[5] = {0, 0, 0, 0, 0}; //array to keep track of visited rooms

    printf("Welcome to the Adventure Game! Please enter your name: \n");
    scanf("%s", playerName);
    printf("\nHello %s! Your journey begins now.\n\n", playerName);

    while (playerHealth > 0) {
        if (currentRoom == 0 && roomVisited[0] == 0) {
            //tutorial room
            printf("You find yourself in a dark room. You can't see anything.\n\n");
            printf("You suddenly hear a voice.\n");
            printf("Voice: 'Welcome to the game!'\n\n");
            printf("Voice: 'Before we begin, let me teach you how to play.'\n");
            printf("Voice: 'To move to a different room, type 'move' followed by the room number.'\n");
            printf("Voice: 'To check your inventory, type 'inventory'.'\n\n");

            roomVisited[0] = 1; //mark room as visited
        }
        else if (currentRoom == 1 && roomVisited[1] == 0) {
            //room with key
            printf("You entered room %d. You can see a shiny object on a table.\n", currentRoom);
            printf("As you approach the object, you realize it is a key.\n\n");
            printf("What do you want to do next?\n");
            printf("1. Add key to inventory\n");
            printf("2. Leave the key\n");

            int choice;
            scanf("%d", &choice);

            if (choice == 1) {
                inventory[0] = 1; //add key to inventory
                printf("\nYou added the key to your inventory.\n\n");
            }
            else {
                printf("\nYou left the key on the table.\n\n");
            }

            roomVisited[1] = 1; //mark room as visited
        }
        else if (currentRoom == 2 && roomVisited[2] == 0) {
            //room with monster
            printf("You entered room %d. You can see a monster!\n", currentRoom);
            printf("Your health is currently at %d\n\n", playerHealth);
            printf("What do you want to do next?\n");
            printf("1. Fight the monster\n");
            printf("2. Run away\n");

            int choice;
            scanf("%d", &choice);

            if (choice == 1) {
                if (inventory[0] == 1) {
                    printf("\nYou used the key to kill the monster. Great job!\n\n");
                    roomVisited[2] = 1; //mark room as visited
                }
                else {
                    playerHealth -= 25; //subtract 25 from player's health if they don't have key
                    printf("\nThe monster attacked you! Your health is now %d\n\n", playerHealth);
                    if (playerHealth <= 0) {
                        printf("\nYou died! Game over.\n");
                        exit(0); //end program if player's health is 0 or below
                    }
                }
            }
            else {
                printf("\nYou ran away and returned to the previous room.\n\n");
            }
        }
        else if (currentRoom == 3 && roomVisited[3] == 0) {
            //room with treasure
            printf("You entered room %d. You can see a treasure chest in the corner.\n", currentRoom);
            printf("What do you want to do next?\n");
            printf("1. Open the treasure chest\n");
            printf("2. Leave the room\n");

            int choice;
            scanf("%d", &choice);

            if (choice == 1) {
                printf("\nYou opened the treasure chest and found a health potion!\n\n");
                inventory[1] = 1; //add health potion to inventory
            }
            else {
                printf("\nYou left the room.\n\n");
            }

            roomVisited[3] = 1; //mark room as visited
        }
        else if (currentRoom == 4 && roomVisited[4] == 0) {
            //final room
            if (inventory[1] == 0) { //check if player has health potion
                printf("You have reached the final room, but you don't have a health potion!\n");
                printf("You slowly died from the wounds inflicted by the monster.\n");
                printf("GAME OVER.\n"); //end game if player doesn't have potion
                exit(0);
            }
            else {
                printf("Congratulations! You have reached the final room with a health potion!\n");
                printf("You healed yourself with the potion and opened the exit.\n");
                printf("Thanks for playing! GAME OVER.\n"); //end game if player has potion
                exit(0);
            }

            roomVisited[4] = 1; //mark room as visited
        }
        else {
            printf("You entered room %d. There is nothing here.\n\n", currentRoom);
        }

        printf("What do you want to do next?\n");
        printf("1. Move to a different room\n");
        printf("2. Check inventory\n");

        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\nWhich room do you want to go to?\n");
            scanf("%d", &currentRoom);
            printf("\n");
        }
        else {
            printf("\nInventory:\n");
            printf("[1] Key: %s\n", inventory[0] == 1 ? "YES" : "NO");
            printf("[2] Health Potion: %s\n\n", inventory[1] == 1 ? "YES" : "NO");
        }
    }

    printf("Oops, something went wrong. Please restart the game.\n");
    return 0;
}