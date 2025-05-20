//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Haunted House Simulator!\n\n");
    char name[20];
    printf("What is your name? ");
    scanf("%s", name);
    printf("\nHello, %s! You find yourself standing in front of a haunted house on a dark, stormy night.\n", name);
    printf("Are you brave enough to enter? (y/n) ");
    char choice;
    scanf(" %c", &choice);
    if (choice == 'y') {
        printf("\nYou open the creaky door and step inside the dark hallway. The door slams shut behind you, and you are plunged into darkness.\n\n");
        printf("Do you want to look for a light switch? (y/n) ");
        char choice2;
        scanf(" %c", &choice2);
        if (choice2 == 'y') {
            printf("\nYou fumble around in the dark, feeling the walls for a light switch. You find one and flick it on, revealing a dimly-lit room filled with cobwebs and old furniture.\n");
        }
        else {
            printf("\nYou decide to soldier on in the dark, feeling your way down the hallway. You trip and stumble, but eventually make it into a room with a dim light.\n");
        }
        printf("\nAs you look around, you notice strange things happening - doors creaking open, objects moving on their own, and eerie whispers in the air.\n");
        printf("Are you sure you want to keep going? (y/n) ");
        char choice3;
        scanf(" %c", &choice3);
        if (choice3 == 'n') {
            printf("\nYou turn to leave, but the door won't budge. You're trapped inside the haunted house forever...");
            exit(0);
        }
        printf("\nYou venture further into the house, and suddenly hear a loud crash. A suit of armor comes to life and charges towards you!\n");
        printf("\nDo you fight back or run away? (f/r) ");
        char choice4;
        scanf(" %c", &choice4);
        if (choice4 == 'f') {
            printf("\nYou bravely take on the suit of armor, but it's no use - it's possessed by a powerful spirit. You fall to the ground, defeated.");
            exit(0);
        }
        else {
            printf("\nYou make a break for it, running down the hallway as fast as you can. Thankfully, the suit of armor can't keep up with you.\n");
        }
        printf("\nYou come to a staircase leading upwards. Do you go up or stay on this level? (u/s) ");
        char choice5;
        scanf(" %c", &choice5);
        if (choice5 == 'u') {
            printf("\nYou ascend the stairs, feeling like you're being watched. When you reach the top, you come face-to-face with a ghostly figure.\n");
            printf("\nDo you try to communicate with it or run away? (c/r) ");
            char choice6;
            scanf(" %c", &choice6);
            if (choice6 == 'c') {
                printf("\nYou attempt to speak with the ghost, but it's too far gone to make any sense. You're left feeling frustrated and confused.");
            }
            else {
                printf("\nYou run down the stairs and out the front door. As you look back, you see the ghostly figure staring at you from an upstairs window.\n");
            }
        }
        else {
            printf("\nYou explore the rest of this level, discovering hidden rooms and secret passageways. However, the atmosphere grows increasingly eerie. You start to feel like you're not alone.\n");
            printf("\nDo you keep exploring or retreat to a safer area? (e/r) ");
            char choice7;
            scanf(" %c", &choice7);
            if (choice7 == 'e') {
                printf("\nYou continue your exploration, but your fears are confirmed when you come face-to-face with a terrifying monster. You never make it out alive.");
                exit(0);
            }
            else {
                printf("\nYou backtrack to a more familiar area, feeling a sense of relief wash over you. However, the whispers in the air don't stop - they only grow louder.\n");
            }
        }
        printf("\nYou continue on, deeper and deeper into the haunted house. What horrors will you uncover? Only time will tell...");
    }
    else {
        printf("\nYou turn and walk away from the haunted house, feeling nervous but relieved. Maybe it's better not to tempt fate tonight...\n");
    }
    return 0;
}