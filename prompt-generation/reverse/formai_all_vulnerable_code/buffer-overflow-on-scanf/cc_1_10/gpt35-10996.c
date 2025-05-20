//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to get random number in given range
int getRandomNumber(int min, int max) {
    srand(time(NULL)); // Using current time as seed for randomization
    return (rand() % (max - min + 1)) + min;
}

int main() {
    printf("Welcome to the Adventure!\n\n");
    printf("You wake up in a dark forest with no memory of how you got there.\n");
    printf("All you have is a compass and a map. You must find your way out of this forest.\n");
    printf("Type 'north', 'south', 'east' or 'west' to move in that direction.\n");

    // Initialize player's position
    int x=0, y=0;
    char direction[10];

    // Game loop until player reaches the end of the map
    while (x != 10 || y != 10) {
        printf("Current position: (%d,%d)\n",x,y);
        printf("Enter direction: ");
        scanf("%s", &direction);

        if(strcmp(direction,"north")==0) {
            y++;
        }
        else if(strcmp(direction,"south")==0) {
            y--;
        }
        else if(strcmp(direction,"east")==0) {
            x++;
        }
        else if(strcmp(direction,"west")==0) {
            x--;
        }
        else {
            printf("Invalid direction!\n");
            continue;
        }

        // Generate random event
        int event = getRandomNumber(1, 5);
        if(event == 1) {
            printf("\nYou found a clearing in the forest. There is a path leading further into the forest.\n");
            printf("Do you want to follow the path (y/n)? ");
            char choice;
            scanf(" %c", &choice);
            if(choice == 'y' || choice == 'Y') {
                x += 2;
                y += 2;
                printf("You followed the path and found a river. You follow the river to the end of the forest.\n");
                printf("You made it out of the forest and found a small village. Congratulations, you finished the game!\n");
                break;
            }
            else {
                printf("You decide not to risk it and continue on your original path.\n");
            }
        }
        else if(event == 2) {
            printf("\nYou stumbled upon a pack of wolves. They attack you, but you manage to fight them off.\n");
        }
        else if(event == 3) {
            printf("\nYou find a cave entrance. Do you want to enter the cave (y/n)? ");
            char choice;
            scanf(" %c", &choice);
            if(choice == 'y' || choice == 'Y') {
                x += 1;
                y += 3;
                printf("You enter the cave but it's too dark to see anything. You start feeling your way around.\n");
                printf("You step on a trap and fall into a pit. You climb out and keep moving.\n");
            }
        }
        else if(event == 4) {
            printf("\nYou hear a strange noise coming from the trees. You decide to run in the opposite direction.\n");
        }
        else if(event == 5) {
            printf("\nYou find a key hidden in a tree trunk. It has a note attached to it that says 'Use this key to unlock your way out'\n");
            printf("Do you want to use the key (y/n)? ");
            char choice;
            scanf(" %c", &choice);
            if(choice == 'y' || choice == 'Y') {
                x += 3;
                y += 1;
                printf("You use the key to open a hidden door and find a shortcut out of the forest.\n");
                printf("You made it out of the forest and found a small village. Congratulations, you finished the game!\n");
                break;
            }
            else {
                printf("You decide to hold onto the key and continue on your original path.\n");
            }
        }
    }

    return 0;
}