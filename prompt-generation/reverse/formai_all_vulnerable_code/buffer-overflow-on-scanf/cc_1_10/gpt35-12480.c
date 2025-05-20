//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: portable
#include <stdio.h>
#include <string.h>

// Function to determine if two strings are equal
int areStringsEqual(char str1[], char str2[]) {
    if(strcmp(str1, str2) == 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    printf("You wake up in a dark room with no windows. There is a door in front of you and a windowless wall to your left.\n");
    
    char userInput[20];
    char direction[10];
    int isDoorLocked = 1;
    
    while(1) {
        printf("What do you want to do? ");
        scanf("%s", userInput);
        if(areStringsEqual(userInput, "look")) {
            printf("You notice a keyhole on the door.\n");
        } else if(areStringsEqual(userInput, "go")) {
            scanf("%s", direction);
            if(areStringsEqual(direction, "left")) {
                printf("You cannot go left. There is a wall in the way.\n");
            } else if(areStringsEqual(direction, "forward")) {
                if(isDoorLocked) {
                    printf("The door is locked. You need to find a key.\n");
                } else {
                    printf("You walk through the door and find yourself in a long hallway.\n");
                    break;
                }
            }
        } else if(areStringsEqual(userInput, "use")) {
            scanf("%s", userInput);
            if(areStringsEqual(userInput, "key")) {
                isDoorLocked = 0;
                printf("You unlocked the door.\n");
            } else {
                printf("You cannot use that.\n");
            }
        } else if(areStringsEqual(userInput, "help")) {
            printf("You can do the following: look, go, use, help.\n");
        } else {
            printf("I do not understand. Type 'help' if you need assistance.\n");
        }
    }

    printf("Congratulations! You completed the first part of the game.\n");

    return 0;
}