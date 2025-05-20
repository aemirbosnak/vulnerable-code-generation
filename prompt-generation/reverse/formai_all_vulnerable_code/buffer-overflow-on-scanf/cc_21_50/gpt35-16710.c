//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // setting the seed for random number generation based on time
    
    // array of spooky messages to be randomly displayed throughout the program
    char messages[5][50] = {
        "You hear creaky footsteps in the distance.",
        "A chill runs down your spine as the wind howls.",
        "The shadows seem to be moving of their own accord.",
        "You feel like you're being watched.",
        "A strange mist begins to envelope the area."
    };
    
    int room = 1; // starting room
    
    // game loop
    while (1) {
        printf("\n\n--- Room %d ---\n", room);
        
        // display random message
        printf("%s\n", messages[rand() % 5]);
        
        // display room description based on current room
        switch (room) {
            case 1:
                printf("You find yourself in a dimly lit hallway. There is a door to your left and a door to your right.\n");
                break;
            case 2:
                printf("You enter a dusty old bedroom. The bed is unmade and there are cobwebs in the corners.\n");
                break;
            case 3:
                printf("You step into a dark study. There are books and scrolls scattered about.\n");
                break;
            case 4:
                printf("You find yourself in a decrepit dining hall. The table is set for a feast that never happened.\n");
                break;
            case 5:
                printf("You enter a grand ballroom. The chandelier sways back and forth as if alive.\n");
                break;
            case 6:
                printf("You stand before a massive set of double doors. They seem to be the only way out.\n");
                break;
        }
        
        int choice;
        // prompt player for choice
        printf("What do you do?\n");
        printf("1. Go left\n");
        printf("2. Go right\n");
        printf("3. Go straight\n");
        printf("Choice: ");
        scanf("%d", &choice);
        
        // update room based on choice
        switch (room) {
            case 1:
                if (choice == 1) {
                    room = 2;
                } else if (choice == 2) {
                    room = 3;
                } else {
                    printf("You can't go that way.\n");
                }
                break;
            case 2:
                if (choice == 2) {
                    room = 1;
                } else if (choice == 3) {
                    room = 4;
                } else {
                    printf("You can't go that way.\n");
                }
                break;
            case 3:
                if (choice == 1) {
                    room = 1;
                } else if (choice == 3) {
                    room = 5;
                } else {
                    printf("You can't go that way.\n");
                }
                break;
            case 4:
                if (choice == 2) {
                    room = 3;
                } else if (choice == 3) {
                    room = 6;
                } else {
                    printf("You can't go that way.\n");
                }
                break;
            case 5:
                if (choice == 1) {
                    room = 3;
                } else if (choice == 2) {
                    room = 4;
                } else if (choice == 3) {
                    room = 6;
                } else {
                    printf("You can't go that way.\n");
                }
                break;
            case 6:
                printf("You push open the double doors and step outside. The sun is rising and the birds are singing. The nightmare is over...\n");
                exit(0); // end game
        }
    }
    
    return 0;
}