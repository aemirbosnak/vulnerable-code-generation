//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: innovative
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void print_intro() {
    printf("Welcome to the Mystery of the Enchanted Forest!\n");
    printf("You find yourself at the edge of a dark and mysterious forest.\n");
    printf("Legends say many treasures lie within, but beware of the creatures lurking in the shadows...\n\n");
}

void print_choices() {
    printf("What would you like to do?\n");
    printf("1. Enter the forest.\n");
    printf("2. Walk along the edge of the forest.\n");
    printf("3. Turn back and go home.\n");
}

void enter_forest() {
    printf("You bravely step into the forest...\n");
    printf("The trees close in around you, and you hear strange whispers.\n");
    printf("After walking for a while, you come to a fork in the path.\n");
    
    printf("Do you wish to:\n");
    printf("1. Take the left path.\n");
    printf("2. Take the right path.\n");
    
    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        printf("You chose the left path and encounter a mischievous fairy!\n");
        printf("She offers to grant you a wish if you can answer her riddle.\n");
        printf("What has keys but can't open locks?\n");
        
        char answer[50];
        scanf("%s", answer);
        
        if (strcmp(answer, "piano") == 0) {
            printf("Correct! The fairy grants you a magical amulet.\n");
            printf("With the amulet, you feel powerful. You can now explore deeper into the forest!\n");
        } else {
            printf("Incorrect! The fairy laughs and turns you into a frog.\n");
            printf("Now you must hop your way out of the forest...\n");
        }
        
    } else {
        printf("You chose the right path and fall into a hidden pit!\n");
        printf("You're stuck in the pit until someone finds you. Game Over!\n");
    }
}

void edge_forest() {
    printf("You decide to walk along the edge of the forest...\n");
    printf("You find some wild berries, do you wish to:\n");
    printf("1. Eat the berries.\n");
    printf("2. Ignore them and continue walking.\n");
    
    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        printf("The berries were poisonous! You collapse and drift into unconsciousness.\n");
        printf("Game Over!\n");
    } else {
        printf("You wisely ignore the berries and continue walking.\n");
        printf("Eventually, you find a hidden treasure chest containing gold coins!\n");
        printf("Congratulations! You have become rich beyond your wildest dreams!\n");
    }
}

void turn_back() {
    printf("You choose to turn back and head home.\n");
    printf("You live a safe and boring life, never knowing what adventures awaited you in the forest.\n");
}

int main() {
    print_intro();
    
    while (true) {
        print_choices();
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enter_forest();
                break;
            case 2:
                edge_forest();
                break;
            case 3:
                turn_back();
                return 0;  // Exit the game
            default:
                printf("Invalid choice, please try again.\n");
        }
        
        printf("\nWould you like to play again? (1 for Yes, 0 for No): ");
        int play_again;
        scanf("%d", &play_again);
        if (!play_again) {
            printf("Thank you for playing! Goodbye!\n");
            break;
        }
        
        printf("\n");
    }
    
    return 0;
}