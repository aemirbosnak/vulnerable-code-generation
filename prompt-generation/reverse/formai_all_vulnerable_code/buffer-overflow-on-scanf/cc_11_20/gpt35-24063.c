//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: portable
#include <stdio.h>

int main() {
    int room = 1; // Start the game in Room 1
    int hasKey = 0; // The player does not have the key yet
    
    printf("Welcome to the Adventure Game!\n");
    printf("You find yourself in Room 1. The door is locked.\n");
    
    while (room != 4) {
        // Room 1
        if(room == 1) {
            printf("What will you do? Type 'look' or 'open door': ");
            char input[50];
            scanf("%s", input);
            
            if(strcmp(input, "look") == 0) {
                printf("There is a key on the table.\n");
            } else if(strcmp(input, "open door") == 0) {
                if(hasKey) {
                    printf("You unlocked the door and entered Room 2.\n");
                    room = 2;
                } else {
                    printf("The door is locked and you need a key.\n");
                }
            } else {
                printf("Invalid input. Try again.\n");
            }
        }
        
        // Room 2
        if(room == 2) {
            printf("You are now in Room 2.\n");
            printf("What will you do? Type 'look' or 'go back': ");
            char input[50];
            scanf("%s", input);
            
            if(strcmp(input, "look") == 0) {
                printf("There is a piece of paper on the floor.\n");
            } else if(strcmp(input, "go back") == 0) {
                printf("You returned to Room 1.\n");
                room = 1;
            } else {
                printf("Invalid input. Try again.\n");
            }
        }
        
        // Room 3
        if(room == 3) {
            printf("You are now in Room 3.\n");
            printf("You see a chest in the corner of the room. Type 'open chest' to check it out or 'go back' to return to Room 2: ");
            char input[50];
            scanf("%s", input);
            
            if(strcmp(input, "open chest") == 0) {
                printf("Inside the chest is a map which shows you the way out of the dungeon.\n");
            } else if(strcmp(input, "go back") == 0) {
                printf("You returned to Room 2.\n");
                room = 2;
            } else {
                printf("Invalid input. Try again.\n");
            }
        }
    }
    
    printf("Congratulations! You found your way out of the dungeon and won the game!\n");
    
    return 0;
}