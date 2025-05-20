//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: automated
// Haunted House Simulator Program
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL)); // initializes random seed
    int choice, room, ghost = 0, key = 0, door_locked = 1;
    printf("Welcome to the Haunted House Simulator!\n");
    printf("In this game, you are trapped in a haunted house and must find a key to unlock the door and escape.\n");
    printf("You have entered the house. You are in the foyer. You can see four doors. Which door will you choose?\n");

    while(1){
        room = rand() % 4 + 1;
        
        if(ghost == 1){
            printf("You are in the room. You see a ghost! Run! Run!\n");
            ghost = 0;
        }
        
        printf("\n1. Room 1\n2. Room 2\n3. Room 3\n4. Room 4\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if(choice < 1 || choice > 4){
            printf("Invalid choice. Try again.\n");
            continue;
        }

        if(choice == room){
            if(key == 1){
                printf("Congratulations! You found the key!\n");
                printf("You run to the door, unlock it and escape the haunted house!\n");
                printf("Game over.\n");
                break;
            }else{
                printf("You are in the room. You see a key. Pick it up!\n");
                key = 1;
            }
        }else{
            if(door_locked == 1){
                printf("You try the door. It is locked.\n");
            }else{
                printf("You try the door. It is unlocked.\n");
            }
        }

        if(rand() % 2 == 0){
            ghost = 1;
        }
        
        door_locked = rand() % 2;
    }
    return 0;
}