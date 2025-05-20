//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: invasive
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <string.h>

int main() 
{ 
    srand(time(NULL)); // seed for random values
    
    char player[20];
    printf("Welcome to the Haunted House Simulator.\n");
    printf("What is your name, player? ");
    scanf("%s", player);
    printf("Hello, %s! You have trespassed into the abandoned haunted house on the outskirts of town. You must find the key to escape before the ghosts catch you.\n", player);
    printf("There are three rooms in the house. Each room has a different object that will help you find the key.\n");
    printf("Enter any key to continue...\n");
    getchar();

    int room = 1;
    int ghost = 0;
    int has_light = 0;
    int has_gift = 0;
    int has_mirror = 0;
    int has_key = 0;
    
    while (1) {
        printf("You are in room %d.\n", room);
        
        if (ghost) {
            printf("A ghost caught you and you died. Game over.\n");
            break;
        }
        
        if (room == 1) {
            printf("You see a ghost in the room.\n");
            printf("What will you do? 1. Run away 2. Attack it with a weapon\n");
            int choice;
            scanf("%d", &choice);
            if (choice == 1) {
                printf("You ran away from the ghost.\n");
            } else if (choice == 2) {
                if (has_light) {
                    printf("You scared away the ghost with the light.\n");
                    ghost = 0;
                } else if (has_mirror) {
                    printf("You reflected the ghost with the mirror and it disappeared.\n");
                    ghost = 0;
                } else {
                    printf("You didn't have anything to attack the ghost with. It caught you and you died.\n");
                    ghost = 1;
                }
            }
        } else if (room == 2) {
            printf("You see a gift box in the room. Do you want to open it? 1. Yes 2. No\n");
            int choice;
            scanf("%d", &choice);
            if (choice == 1) {
                printf("You opened the gift box and found a flashlight inside.\n");
                has_light = 1;
                has_gift = 1;
            } else {
                printf("You didn't open the gift box.\n");
            }
        } else if (room == 3) {
            printf("You see a mirror in the room. Do you want to pick it up? 1. Yes 2. No\n");
            int choice;
            scanf("%d", &choice);
            if (choice == 1) {
                printf("You picked up the mirror.\n");
                has_mirror = 1;
            } else {
                printf("You didn't pick up the mirror.\n");
            }
        }
        
        if (has_gift && !has_key) {
            printf("You found a key inside the flashlight. You can use it to escape now.\n");
            has_key = 1;
        }
        
        if (has_key) {
            printf("You found the key and escaped from the haunted house! Congratulations %s, you survived!\n", player);
            break;
        }
        
        printf("Enter any key to continue...\n");
        getchar();
        
        room = rand() % 3 + 1;
    }
    
    return 0; 
}