//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(unsigned int msec) {
    clock_t start = clock();
    while (clock() - start <= msec);
}

int main() {
    int choice, flashlight = 0, ghost = 0;
    
    srand(time(NULL)); // Seeds the random number generator
    
    printf("You enter a spooky haunted house...\n\n");
    delay(2000);
    
    printf("You see a closet and a staircase. What do you do?\n");
    printf("1. Open the closet.\n");
    printf("2. Climb the staircase.\n\n");
    printf("Choice: ");
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("\nYou approach the closet and slowly open the door...\n");
        delay(3000);
        printf("BOO! A ghost jumps out and scares you!\n");
        ghost++;
    }
    else if (choice == 2) {
        printf("\nYou climb the staircase, which creaks with every step...\n");
        delay(3000);
        printf("You reach the top and see a dark room and a hallway.\n");
        printf("1. Enter the dark room.\n");
        printf("2. Walk down the hallway.\n\n");
        printf("Choice: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            printf("\nYou cautiously enter the dark room...\n");
            delay(3000);
            printf("You see a flashlight on a table. Do you take it?\n");
            printf("1. Take the flashlight.\n");
            printf("2. Leave it.\n\n");
            printf("Choice: ");
            scanf("%d", &choice);
            
            if (choice == 1) {
                printf("\nYou take the flashlight and turn it on...\n");
                flashlight++;
            }
            else if (choice == 2) {
                printf("\nYou leave the flashlight and move on...\n");
            }
            
            printf("As you turn to leave, you hear a spooky noise...\n");
            delay(3000);
            
            if (flashlight > 0) {
                printf("You shine your flashlight around the room and see a ghost!\n");
                ghost++;
            }
            else {
                printf("You can't see anything in the dark!\n");
            }
        }
        else if (choice == 2) {
            printf("\nYou walk down the hallway, which seems to go on forever...\n");
            delay(5000);
            printf("You reach a door. Do you open it?\n");
            printf("1. Open the door.\n");
            printf("2. Turn back.\n\n");
            printf("Choice: ");
            scanf("%d", &choice);
            
            if (choice == 1) {
                printf("\nYou open the door and see a ghost! BOO!\n");
                ghost++;
            }
            else if (choice == 2) {
                printf("\nYou turn back and head down the stairs...\n");
                delay(3000);
                printf("As you descend, you feel a cold breeze on the back of your neck...\n");
            }
        }
    }
    
    printf("\n\nYou run out of the haunted house and look back...\n");
    delay(3000);
    
    if (ghost == 0) {
        printf("There was no ghost! You're safe!\n");
    }
    else if (ghost == 1) {
        printf("There was 1 ghost... that was scary!\n");
    }
    else {
        printf("There were %d ghosts! Too spooky for me!\n", ghost);
    }
    
    return 0;
}