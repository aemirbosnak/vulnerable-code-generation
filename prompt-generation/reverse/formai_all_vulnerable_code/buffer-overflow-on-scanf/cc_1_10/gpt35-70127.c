//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void goNorth() {
    printf("\nYou go North, but it's just a wall with a poster of Justin Bieber.\n");
}

void goSouth() {
    printf("\nYou go South and find a pile of unicorn poop. What a lucky find!\n");
}

void goEast() {
    printf("\nYou go East and trip over a rock. Ouch! That hurt!\n");
}

void goWest() {
    printf("\nYou go West and find yourself in a room with a sign that says 'Danger: Poisonous Snakes'.\n");
}

int main() {
    char choice;
    bool gameover = false;
    
    printf("Welcome to the wacky adventure game! Your goal is to find the golden unicorn!\n");

    while(!gameover) {
        printf("\nWhich direction do you want to go? [N/S/E/W]\n");
        scanf(" %c", &choice);

        switch(choice) {
            case 'N':
            case 'n':
                goNorth();                  
                break;
            case 'S':
            case 's':
                goSouth();                    
                break;
            case 'E':
            case 'e':
                goEast();                    
                break;
            case 'W':
            case 'w':
                goWest();                    
                break;
            default:
                printf("\nInvalid Choice! Try again!\n");
                break;                        
        }

        printf("\nDo you want to continue? [Y/N]\n");
        scanf(" %c", &choice);

        if (choice == 'N' || choice == 'n') {
            printf("\nQuitter! Bye!\n");
            gameover = true;
        }
    }

    printf("\nCongratulations! You have found the Golden Unicorn! You win!\n");

    return 0;
}