//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printWelcome() {
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You are about to enter a spooky house full of surprises...\n");
    printf("Choose wisely, or you might not make it out!\n");
}

void hallOptions() {
    printf("\nYou are in a dark hallway with two doors:\n");
    printf("1. Enter the Door on the Left\n");
    printf("2. Enter the Door on the Right\n");
    printf("3. Turn back and leave the house\n");
}

void leftDoor() {
    printf("\nYou opened the left door and entered a creepy room...\n");
    printf("In the room, you see a ghost floating around.\n");
    printf("Do you:\n");
    printf("1. Approach the ghost\n");
    printf("2. Run away\n");

    int choice;
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("The ghost reveals itself as a friendly spirit and grants you a wish!\n");
        printf("You wished for a safe way out of the haunted house. You win!\n");
    } else {
        printf("You ran away screaming and tripped over a skull. You are haunted forever!\n");
    }
}

void rightDoor() {
    printf("\nYou opened the right door and found a treasure chest!\n");
    printf("Do you:\n");
    printf("1. Open the treasure chest\n");
    printf("2. Leave the chest and go back\n");

    int choice;
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("Inside the chest, you find piles of gold and a cursed artifact!\n");
        printf("Do you:\n");
        printf("1. Take the gold\n");
        printf("2. Take the artifact\n");

        int second_choice;
        scanf("%d", &second_choice);

        if (second_choice == 1) {
            printf("You take the gold and leave, living happily ever after. Congratulations!\n");
        } else {
            printf("The artifact curses you, and you become a monster in the house forever!\n");
        }
    } else {
        printf("You step back and exit the room safely. You decide to leave the house.\n");
    }
}

int main() {
    int enterHouse;

    srand(time(NULL)); // Seed for random number generation

    printWelcome();
    
    do {
        hallOptions();
        printf("Choose an option (1-3): ");
        scanf("%d", &enterHouse);

        switch (enterHouse) {
            case 1:
                leftDoor();
                break;
            case 2:
                rightDoor();
                break;
            case 3:
                printf("You chose to leave the haunted house. Maybe another time!\n");
                break;
            default:
                printf("Invalid choice. Please select option 1, 2, or 3.\n");
        }

        // Asking if the player wants to play again
        if (enterHouse != 3) {
            printf("\nDo you want to play again? (1 for Yes, 0 for No): ");
            scanf("%d", &enterHouse);
        }

    } while (enterHouse != 0);

    printf("Thanks for playing the Haunted House Simulator! Goodbye!\n");
    return 0;
}