//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void pause(int); // Function prototype

int main() {
    
    char player_name[20];
    int option, random_number, choice, wait_time, key = 0, matches = 0, candle = 0, flashlight = 0, ghost_room = 0, player_health = 100;

    // Introduction
    printf("Welcome to the Haunted House Simulator\n");
    printf("Please enter your name: ");
    scanf("%s", player_name);
    printf("\nHello %s, you have entered the Haunted House. Your mission is to find the hidden key and get out alive!\n", player_name);
    printf("You have 3 lives and a health bar of 100. Good luck!\n");

    pause(2);

    // Start of game
    printf("\nYou are in the foyer of the haunted house. There are 3 doors in front of you and a staircase to your left.\n");
    printf("What would you like to do?\n\n");
    printf("1. Go through the left door\n");
    printf("2. Go through the middle door\n");
    printf("3. Go through the right door\n");
    printf("4. Go up the staircase\n");
    printf("5. Quit game\n\n");

    scanf("%d", &option);

    switch(option) {
        case 1: // Left door
            printf("\nYou opened the left door and walked into the kitchen. You notice a matchbox on the counter.\n");
            printf("What would you like to do?\n\n");
            printf("1. Take the matchbox\n");
            printf("2. Leave the matchbox\n");
            scanf("%d", &choice);
            if(choice == 1) {
                matches = 1;
                printf("\nYou took the matchbox.\n");
            }
            else {
                printf("\nYou left the matchbox.\n");
            }
            break;

        case 2: // Middle door
            printf("\nYou opened the middle door and entered the living room. You saw a candle on the mantel.\n");
            printf("What would you like to do?\n\n");
            printf("1. Take the candle\n");
            printf("2. Leave the candle\n");
            scanf("%d", &choice);
            if(choice == 1) {
                candle = 1;
                printf("\nYou took the candle.\n");
            }
            else {
                printf("\nYou left the candle.\n");
            }
            break;

        case 3: // Right door
            printf("\nYou opened the right door and found yourself in a bedroom. You notice a flashlight on the nightstand.\n");
            printf("What would you like to do?\n\n");
            printf("1. Take the flashlight\n");
            printf("2. Leave the flashlight\n");
            scanf("%d", &choice);
            if(choice == 1) {
                flashlight = 1;
                printf("\nYou took the flashlight.\n");
            }
            else {
                printf("\nYou left the flashlight.\n");
            }
            break;

        case 4: // Staircase
            printf("\nYou climbed up the staircase and arrived on the second floor.\n");
            printf("There are two doors in front of you and a set of stairs leading up to the attic.\n");
            printf("What would you like to do?\n\n");
            printf("1. Go through the left door\n");
            printf("2. Go through the right door\n");
            printf("3. Go up to the attic\n");
            printf("4. Go back down the stairs to the foyer\n");
            scanf("%d", &option);

            if(option == 1) {
                printf("\nYou opened the left door and walked into the bathroom.\n");
                printf("You see a first aid kit on the sink.\n");
                printf("What would you like to do?\n\n");
                printf("1. Take the first aid kit\n");
                printf("2. Leave the first aid kit\n");
                scanf("%d", &choice);
                if(choice == 1) {
                    player_health += 20;
                    printf("\nYou took the first aid kit and healed yourself. Your health is now %d.\n", player_health);
                }
                else {
                    printf("\nYou left the first aid kit.\n");
                }
            }
            else if(option == 2) {
                printf("\nYou opened the right door and walked into a child's bedroom.\n");
                printf("Suddenly, you were sucked into a ghost room!\n");

                if(matches == 1) {
                    printf("You light a match to see and notice a ghostly figure blocking your exit.\n");
                    printf("You quickly leave the room and run down the stairs back to the foyer.\n");
                    matches = 0;
                    pause(2);
                    break;
                }
                else if(candle == 1) {
                    printf("You light the candle to see and notice a ghostly figure blocking your exit.\n");
                    printf("You quickly leave the room and run down the stairs back to the foyer.\n");
                    candle = 0;
                    pause(2);
                    break;
                }
                else if(flashlight == 1) {
                    printf("You turn on the flashlight to see and notice a ghostly figure blocking your exit.\n");
                    printf("You quickly leave the room and run down the stairs back to the foyer.\n");
                    flashlight = 0;
                    pause(2);
                    break;
                }
                else {
                    printf("You can't see anything in the dark, and you feel a ghostly presence surrounding you.\n");
                    printf("You lose 20 health points!\n");
                    player_health -= 20;

                    if(player_health <= 0) {
                        printf("You have died and lost the game.\n");
                        exit(0);
                    }
                    else {
                        printf("Your health is now %d.\n", player_health);
                    }
                }
            }
            else if(option == 3) {
                printf("\nYou climbed up to the attic and found an old chest.\n");
                printf("You attempted to open the chest, but it was locked.\n");
                printf("What would you like to do?\n\n");
                printf("1. Use the key\n");
                printf("2. Try to break the lock\n");
                printf("3. Leave the chest\n");
                scanf("%d", &choice);

                if(choice == 1 && key == 1) {
                    printf("\nYou used the key to open the chest.\n");
                    printf("Inside the chest, you found the hidden key!\n");
                    printf("You took the key and climbed back down the stairs to the foyer.\n");
                    key = 0;
                    pause(2);
                    break;
                }
                else if(choice == 1 && key == 0) {
                    printf("\nYou don't have the key to unlock the chest.\n");
                    printf("You climb back down the stairs to the foyer.\n");
                    pause(2);
                    break;
                }
                else if(choice == 2) {
                    printf("\nYou attempted to break the lock with force, but failed.\n");
                    printf("You hurt yourself in the process and lose 10 health points!\n");
                    player_health -= 10;

                    if(player_health <= 0) {
                        printf("You have died and lost the game.\n");
                        exit(0);
                    }
                    else {
                        printf("Your health is now %d.\n", player_health);
                    }
                    printf("You climb back down the stairs to the foyer.\n");
                    pause(2);
                    break;
                }
                else {
                    printf("You leave the chest and climb back down the stairs to the foyer.\n");
                    break;
                }
            }
            else {
                printf("You go back down the stairs to the foyer.\n");
                pause(2);
                break;
            }
        
        case 5: // Quit game
            exit(0);

        default:
            printf("\nInvalid choice. Please choose again.\n");
            break;
    }

    // Random key placement
    srand(time(NULL));
    random_number = rand() % 4;

    if(random_number == 0) {
        printf("\nWhile exploring the haunted house, you found the hidden key!\n");
        printf("Congratulations, %s, you have won the game!\n", player_name);
        exit(0);
    }
    else {
        printf("\nYou didn't find the key this time. Keep exploring!\n");
        pause(2);
        if(random_number == 2 && ghost_room == 0) {
            printf("\nSuddenly, you were sucked into a ghostly room!\n");

            if(matches == 1) {
                printf("You light a match and see a ghostly figure blocking your exit.\n");
                printf("You quickly leave the room and run down the stairs back to the foyer.\n");
                matches = 0;
            }
            else if(candle == 1) {
                printf("You light the candle and see a ghostly figure blocking your exit.\n");
                printf("You quickly leave the room and run down the stairs back to the foyer.\n");
                candle = 0;
            }
            else if(flashlight == 1) {
                printf("You turn on the flashlight and see a ghostly figure blocking your exit.\n");
                printf("You quickly leave the room and run down the stairs back to the foyer.\n");
                flashlight = 0;
            }
            else {
                printf("\nYou can't see anything in the dark, and you feel a ghostly presence surrounding you.\n");
                printf("You lose 20 health points!\n");
                player_health -= 20;

                if(player_health <= 0) {
                    printf("You have died and lost the game.\n");
                    exit(0);
                }
                else {
                    printf("Your health is now %d.\n", player_health);
                }
            }
            ghost_room = 1;
        }
        else {
            printf("You continue exploring the haunted house.\n");
        }
    }

    // Random key placement
    srand(time(NULL));
    random_number = rand() % 4;

    if(random_number == 0) {
        key = 1;
        printf("\nYou found a key!\n");
    }

    return 0;
}

void pause(int time) {
    int wait_time = time * CLOCKS_PER_SEC;
    clock_t end_time = wait_time + clock();
    while(wait_time < end_time) {
        wait_time = clock();
    }
}