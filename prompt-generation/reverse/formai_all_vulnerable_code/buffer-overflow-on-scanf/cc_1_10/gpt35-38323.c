//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    // initialize variables
    char name[20];
    int choice;
    int health = 10;
    int has_key = 0;
    int has_treasure = 0;
    
    // seed random number generator
    srand(time(NULL));
    
    // get player name
    printf("Welcome to the Adventure Game! What is your name?\n");
    scanf("%s", name);
    printf("Nice to meet you, %s! Your adventure begins.\n", name);
    
    // game loop
    while (health > 0) {
        printf("\nYou have %d health.\n", health);
        printf("What would you like to do?\n");
        printf("1. Explore the forest\n");
        printf("2. Enter the cave\n");
        printf("3. Quit game\n");
        scanf("%d", &choice);
        
        // explore the forest
        if (choice == 1) {
            printf("\nYou enter the forest and begin exploring.\n");
            int r = rand() % 2; // generate random number 0 or 1
            if (r == 0) {
                printf("You find a potion on the ground and drink it. Your health increases by 2.\n");
                health += 2;
            } else {
                printf("A snake bites you! Your health decreases by 2.\n");
                health -= 2;
            }
        }
        
        // enter the cave
        else if (choice == 2) {
            printf("\nYou enter the cave and see two paths.\n");
            printf("Which one do you take?\n");
            printf("1. Left path\n");
            printf("2. Right path\n");
            scanf("%d", &choice);
            if (choice == 1) {
                printf("\nYou find a key!\n");
                has_key = 1;
            } else {
                printf("\nYou fall into a pit and lose 3 health.\n");
                health -= 3;
            }
        }
        
        // quit game
        else if (choice == 3) {
            printf("\nThanks for playing, %s!\n", name);
            return 0;
        }
        
        // invalid choice
        else {
            printf("\nInvalid choice. Try again.\n");
        }
        
        // check if player has key and treasure
        if (has_key == 1 && has_treasure == 1) {
            printf("\nCongratulations, you have found the treasure and won the game!\n");
            return 0;
        }
    }
    
    // game over
    printf("\nGame over, %s. Better luck next time.\n", name);
    return 0;
}