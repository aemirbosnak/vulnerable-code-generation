//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to display the current room description
void describeRoom(int roomNum) {
    printf("You enter room %d\n", roomNum);
    printf("The room is dark and musty, with cobwebs covering the corners.\n");
    printf("You can hear strange noises in the distance.\n");
}

int main() {
    srand(time(NULL)); // seed the random number generator
    
    int totalRooms = 10; // total number of rooms in the house
    int currentRoom = 1; // start in room 1
    int hasKey = 0; // player does not have the key yet
    int hasFlashlight = 0; // player does not have the flashlight yet
    int isNight = 0; // it's daytime
    
    printf("Welcome to the post-apocalyptic haunted house!\n");
    printf("Your goal is to find the key and escape before nightfall.\n");
    printf("Use your wits to navigate through the house and avoid the ghosts.\n");
    printf("Good luck!\n\n");

    while (1) { // loop forever (until player escapes or is caught)
        
        // display the current room and its description
        describeRoom(currentRoom);
        
        if (currentRoom == totalRooms && hasKey) { // player has reached the exit with the key
            printf("Congratulations! You have escaped the haunted house and survived the apocalypse!\n");
            break;
        }
        else if (isNight) { // it's night and the ghosts are out
            printf("The ghosts have caught up to you and dragged you away...\n");
            break;
        }
        
        // ask the player what they want to do
        printf("What do you want to do? (1: move to next room, 2: search the room)\n");
        int choice;
        scanf("%d", &choice);
        
        if (choice == 1) { // move to the next room
            currentRoom++;
        }
        else if (choice == 2) { // search the current room
            int oddsOfFindingSomething = rand() % 10 + 1; // 1 in 10 chance of finding something
            
            if (oddsOfFindingSomething == 1) { // found the key
                printf("You found the key!\n");
                hasKey = 1;
            }
            else if (oddsOfFindingSomething == 2 && !hasFlashlight) { // found the flashlight
                printf("You found a flashlight!\n");
                hasFlashlight = 1;
            }
            else { // nothing found
                printf("You found nothing of interest.\n");
            }
        }
        
        // check if it's night yet
        if (currentRoom == totalRooms / 2 && !hasFlashlight) {
            printf("It's getting dark and hard to see. You might want to find a flashlight.\n");
        }
        else if (currentRoom == totalRooms / 2 && hasFlashlight) {
            printf("You turn on the flashlight and continue, the ghosts seem to be drawn to the light.\n");
        }
        else if (currentRoom == totalRooms - 1) { // it's night
            printf("It's now dark outside and the ghosts are out to play...\n");
            isNight = 1;
        }
    }
    
    return 0;
}