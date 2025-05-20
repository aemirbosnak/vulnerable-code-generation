//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char name[50], input[100], decision[20], weapon[20];
    bool hasKey = false, hasWeapon = false, hasReachedEnd = false;
    
    printf("Welcome to the Cryptic Adventure Game!\n");
    printf("What is your name?\n");
    scanf("%s", &name);
    printf("Hello %s!\n", name);
    printf("You find yourself in a dark, damp cave with two tunnels in front of you.\n");
    printf("Do you go left or right?\n");
    scanf("%s", &input);
    
    if (strcmp(input, "left") == 0) {
        printf("You walk down the left tunnel and stumble upon a dead end.\n");
        printf("You see a rusty key on the ground. Do you pick it up?\n");
        scanf("%s", &decision);
        if (strcmp(decision, "yes") == 0) {
            printf("You pick up the key.\n");
            hasKey = true;
        } else {
            printf("You leave the key on the ground and return to the fork in the road.\n");
        }
    } else {
        printf("You walk down the right tunnel and are immediately attacked by a giant spider.\n");
        printf("Quickly, choose a weapon - sword or bow and arrow?\n");
        scanf("%s", &weapon);
        if (strcmp(weapon, "sword") == 0) {
            printf("You defeat the spider and continue down the tunnel.\n");
            hasWeapon = true;
        } else {
            printf("Your arrows bounce off the spider's hard exoskeleton and it devours you.\n");
            printf("Game over.\n");
            exit(EXIT_SUCCESS);
        }
    }
    
    printf("You continue down the tunnel and come across a locked door.\n");
    if (hasKey) {
        printf("You use the key to unlock the door and enter the next room.\n");
    } else {
        printf("You do not have the key. Find it before you can proceed.\n");
        exit(EXIT_SUCCESS);
    }
    
    printf("In the next room, you find a chest with a puzzle lock. Solve the puzzle!\n");
    printf("What starts with an E, ends with an E, but only contains one letter?\n");
    scanf("%s", &input);
    if (strcmp(input, "envelope") == 0) {
        printf("You solve the puzzle!\n");
    } else {
        printf("Incorrect. You hear a loud noise and are attacked by monsters!\n");
        if (!hasWeapon) {
            printf("You have no weapons and are quickly overtaken. Game over.\n");
            exit(EXIT_SUCCESS);
        }
        printf("With your weapon, you are able to fight off the monsters and continue to the next room.\n");
    }
    
    printf("In this room, there is a wall with a button. Push it?\n");
    scanf("%s", &decision);
    if (strcmp(decision, "yes") == 0) {
        printf("You push the button and the wall opens up, revealing a secret passageway!\n");
    } else {
        printf("You do not push the button and return to the previous room.\n");
        exit(EXIT_SUCCESS);
    }
    hasReachedEnd = true;
    
    printf("You crawl through the secret passageway and finally see a light at the end.\n");
    printf("Do you step out into the light?\n");
    scanf("%s", &decision);
    if (strcmp(decision, "yes") == 0) {
        printf("Congratulations! You have successfully completed the Cryptic Adventure Game.\n");
    } else {
        printf("You wait in the passageway and are eventually consumed by the darkness. Game over.\n");
        exit(EXIT_SUCCESS);
    }
    
    return 0;
}