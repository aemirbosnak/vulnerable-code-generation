//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char name[20];
    int choice;
    
    printf("Welcome to the Cryptic Caverns adventure game.\n");
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Hello, %s! Your journey begins now...\n\n", name);
    
    printf("You are standing at the entrance of the cavern. There are two paths to choose from.\n");
    printf("1) Enter the left path.\n");
    printf("2) Enter the right path.\n");
    printf("What do you want to do? ");
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("\nYou enter the left path and see a door that is locked.\n");
        printf("There is also a note on the floor that says 'The key is hidden behind the waterfall'.\n");
        printf("What do you want to do now?\n");
        printf("1) Search for the key behind the waterfall.\n");
        printf("2) Try to break the door down.\n");
        printf("3) Return to the entrance.\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            printf("\nYou find the key behind the waterfall and use it to unlock the door.\n");
            printf("Inside the room, you see a treasure chest and a trap door on the floor.\n");
            printf("What do you want to do?\n");
            printf("1) Open the treasure chest.\n");
            printf("2) Explore the trap door.\n");
            printf("3) Return to the entrance.\n");
            printf("Your choice: ");
            scanf("%d", &choice);
            
            if (choice == 1) {
                printf("\nAs you open the treasure chest, you are attacked by a swarm of bats.\n");
                printf("You try to defend yourself, but you are outnumbered and eventually overwhelmed by the bats.\n");
                printf("Game over, %s! Better luck next time.\n", name);
                exit(0);
            }
            else if (choice == 2) {
                printf("\nYou climb down the trap door and find an underground river that leads to a small island with a chest on it.\n");
                printf("You approach the chest and open it to find a golden key and a map that leads to the exit of the cavern.\n");
                printf("You take the items and head back to the entrance of the cavern.\n");
            }
            else {
                printf("\nYou return to the entrance of the cavern.\n");
            }
        }
        else if (choice == 2) {
            printf("\nYou try to break the door down, but it is too strong.\n");
            printf("You hear a sound behind you and turn to see a group of goblins approaching you.\n");
            printf("You draw your weapon and prepare to fight...\n");
            // Placeholder for combat sequence
        }
        else {
            printf("\nYou return to the entrance of the cavern.\n");
        }
    }
    else {
        printf("\nYou enter the right path and see a dark tunnel.\n");
        printf("What do you want to do?\n");
        printf("1) Light a torch and explore the tunnel.\n");
        printf("2) Turn back and choose the left path.\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            printf("\nAs you explore the tunnel, you come across a room with a puzzle.\n");
            printf("There are four levers and two doors. The levers are labeled 1-4.\n");
            printf("The doors have arrows pointing in different directions, but no labels.\n");
            printf("What do you want to do?\n");
            printf("1) Try random combinations of levers and doors.\n");
            printf("2) Inspect the room for clues.\n");
            printf("3) Return to the entrance.\n");
            printf("Your choice: ");
            scanf("%d", &choice);
            
            if (choice == 1) {
                printf("\nYou try different combinations of levers and doors, but nothing seems to work.\n");
                printf("You hear a loud noise and the walls start closing in on you. You are trapped!\n");
                printf("Game over, %s! Better luck next time.\n", name);
                exit(0);
            }
            else if (choice == 2) {
                printf("\nYou notice that there is a painting on the wall that depicts four animals - an eagle, a lion, a snake, and a wolf.\n");
                printf("You also notice that each lever has a symbol on it - an eagle on lever 1, a lion on lever 2, a snake on lever 3, and a wolf on lever 4.\n");
                printf("You try pulling the levers in the order of the animals in the painting - eagle, lion, snake, wolf.\n");
                printf("The doors open and you see a staircase leading down to the exit of the cavern.\n");
                printf("Congratulations, %s! You have completed the Cryptic Caverns adventure game!\n", name);
            }
            else {
                printf("\nYou return to the entrance of the cavern.\n");
            }
        }
        else {
            printf("\nYou return to the entrance of the cavern.\n");
        }
    }
    
    return 0;
}