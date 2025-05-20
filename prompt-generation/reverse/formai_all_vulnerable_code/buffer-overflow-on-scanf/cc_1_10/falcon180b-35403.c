//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    int score = 0;
    char name[20];

    // Introductions
    printf("Welcome to the world of Enigma!\n");
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("Hello %s! You find yourself in a mysterious castle.\n", name);

    // Game loop
    while(1) {
        // Display options
        printf("\n");
        printf("You are in a dimly lit hallway with three doors.\n");
        printf("Which door do you choose?\n");
        printf("1. Door with a golden knob\n");
        printf("2. Door with a silver knob\n");
        printf("3. Door with a bronze knob\n");
        printf("\n");

        // Get choice
        scanf("%d", &choice);

        // Check choice
        switch(choice) {
            case 1:
                printf("You open the door with the golden knob and find a treasure chest!\n");
                score += 10;
                break;
            case 2:
                printf("You open the door with the silver knob and find a secret passage!\n");
                score += 20;
                break;
            case 3:
                printf("You open the door with the bronze knob and find a dead end.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

        // Check for win
        if(score >= 30) {
            printf("\nCongratulations %s! You have solved the mystery of the castle and won the game!\n", name);
            break;
        }
    }

    return 0;
}