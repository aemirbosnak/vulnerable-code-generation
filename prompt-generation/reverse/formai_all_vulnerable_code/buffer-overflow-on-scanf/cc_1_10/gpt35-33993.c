//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

int main() {

    int choice = 0;

    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You are in a forest and need to find your way out.\n");

    while (choice != 3) {
        printf("\nWhat would you like to do?\n");
        printf("1. Look for a path\n");
        printf("2. Climb a tree for a better view\n");
        printf("3. Sit and wait for rescue\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nYou wander off in search of a path.\n");
                printf("After a couple of hours, you come across two paths.\n");
                printf("1. Take the left path\n");
                printf("2. Take the right path\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                if (choice == 1) {
                    printf("\nYou take the left path and walk for hours.\n");
                    printf("As it is getting dark, you stumble upon a cabin.\n");
                    printf("1. Enter the cabin\n");
                    printf("2. Keep walking\n");
                    printf("Enter your choice: ");
                    scanf("%d", &choice);

                    if (choice == 1) {
                        printf("\nAs soon as you enter the cabin, you feel an eerie presence.\n");
                        printf("Suddenly, the cabin begins to shake and you pass out.\n");
                        printf("You wake up outside the cabin with a map in your hand.\n");
                        printf("You use the map to find your way out of the forest.\n");
                        printf("Congratulations, you have won the game!\n");
                        return 0;
                    }
                    else {
                        printf("\nYou keep walking, but it is too dark now.\n");
                        printf("You find a spot to rest for the night and wait for morning.\n");
                        printf("You wake up the next day and use the map to find your way out of the forest.\n");
                        printf("Congratulations, you have won the game!\n");
                        return 0;
                    }
                }
                else {
                    printf("\nYou take the right path and walk for hours.\n");
                    printf("As it is getting dark, you come across a river.\n");
                    printf("1. Try to cross the river\n");
                    printf("2. Look for a bridge\n");
                    printf("Enter your choice: ");
                    scanf("%d", &choice);

                    if (choice == 1) {
                        printf("\nYou try to cross the river, but the current is too strong.\n");
                        printf("You get swept away and drown.\n");
                        printf("Game Over.\n");
                        return 0;
                    }
                    else {
                        printf("\nYou look for a bridge and find one.\n");
                        printf("You use the map to find your way out of the forest.\n");
                        printf("Congratulations, you have won the game!\n");
                        return 0;
                    }
                }
                
            case 2:
                printf("\nYou climb a tall tree and look around.\n");
                printf("You see two paths, but it is too far to tell which one to take.\n");
                printf("You climb down the tree and continue on your journey.\n");
                break;

            case 3:
                printf("\nYou sit and wait, but no one comes to rescue you.\n");
                printf("You realize that you need to find your way out on your own.\n");
                printf("You use the map to find your way out of the forest.\n");
                printf("Congratulations, you have won the game!\n");
                return 0;
            
            default:
                printf("\nInvalid choice. Please enter a valid choice.\n");
                break;
        }
    }

    return 0;
}