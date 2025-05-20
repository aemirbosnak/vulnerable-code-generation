//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_start_message() {
    printf("======================================\n");
    printf("     Welcome to the Mystic Quest!    \n");
    printf("======================================\n");
    printf("You are an explorer in a magical world. Your goal is to find the lost\n");
    printf("treasure of the legendary Dragon King. Choose wisely as your decisions\n");
    printf("will shape your fate!\n");
    printf("\n");
}

void print_choices() {
    printf("What would you like to do?\n");
    printf("1. Enter the dark forest.\n");
    printf("2. Explore the ancient ruins.\n");
    printf("3. Visit the village of Eldoria.\n");
    printf("4. Check your inventory.\n");
    printf("5. Exit the game.\n");
}

void enter_forest() {
    printf("You step into the dark forest. Shadows loom around every tree.\n");
    printf("Suddenly, a wild beast appears! What do you want to do?\n");
    printf("1. Fight the beast.\n");
    printf("2. Run away.\n");
    
    int choice;
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("You bravely fight the beast and manage to scare it away!\n");
        printf("You find a silver key on the ground. It might be useful later.\n");
    } else {
        printf("You run away as fast as you can, but you trip and fall!\n");
        printf("You stumble back to the forest entrance, heart racing.\n");
    }
}

void explore_ruins() {
    printf("You approach the ancient ruins. They are covered in vines and moss.\n");
    printf("As you explore, you find an old map hidden under a stone slab!\n");
}

void visit_village() {
    printf("You arrive in the village of Eldoria. It's bustling with life!\n");
    printf("You can:\n");
    printf("1. Buy supplies.\n");
    printf("2. Talk to the villagers.\n");

    int choice;
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("You buy some healing potions and a sturdy rope from the merchant.\n");
    } else {
        printf("The villagers share tales of the Dragon King's treasure with you.\n");
    }
}

void inventory() {
    printf("Your inventory is currently empty. Explore more to find items!\n");
}

int main() {
    print_start_message();
    int continue_game = 1;

    while (continue_game) {
        print_choices();
        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                enter_forest();
                break;
            case 2:
                explore_ruins();
                break;
            case 3:
                visit_village();
                break;
            case 4:
                inventory();
                break;
            case 5:
                continue_game = 0;
                printf("Thank you for playing!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}