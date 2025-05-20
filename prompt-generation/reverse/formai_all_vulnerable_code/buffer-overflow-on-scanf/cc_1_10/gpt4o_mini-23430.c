//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void print_intro() {
    printf("=========================================================\n");
    printf("                   Welcome to the Unknown!              \n");
    printf("=========================================================\n");
    printf("You find yourself in a mysterious land, filled with strange creatures and unknown challenges.\n");
    printf("Your goal is to navigate through the land and find the hidden treasure.\n");
    printf("But beware! Many surprises await...\n");
    printf("=========================================================\n");
}

void print_choices() {
    printf("What would you like to do?\n");
    printf("1. Explore the forest\n");
    printf("2. Enter the dark cave\n");
    printf("3. Visit the ancient ruins\n");
    printf("4. Check your inventory\n");
    printf("5. Quit Game\n");
}

void explore_forest() {
    printf("As you wander through the lush forest, you hear rustling in the bushes.\n");
    printf("A curious creature jumps out!\n");
    srand(time(NULL));
    int encounter = rand() % 3;
    
    if (encounter == 0) {
        printf("It's a friendly fairy! She offers you a magic potion.\n");
    } else if (encounter == 1) {
        printf("Oh no! A wild boar charges at you!\n");
    } else {
        printf("You find a hidden treasure chest!\n");
    }
}

void enter_cave() {
    printf("The cave is damp and dark. You can barely see anything.\n");
    printf("Suddenly, you hear a dripping sound... it gets louder and louder!\n");
    
    srand(time(NULL));
    int challenge = rand() % 2;
    
    if (challenge == 0) {
        printf("It’s a giant bat! It flutters around, blocking your path!\n");
    } else {
        printf("You find a glowing crystal embedded in the wall. It feels powerful!\n");
    }
}

void visit_ruins() {
    printf("The ancient ruins are covered with vines and moss. As you examine the stones...\n");
    printf("You discover strange inscriptions that glow as you touch them.\n");
    
    srand(time(NULL));
    int discovery = rand() % 2;
    
    if (discovery == 0) {
        printf("You solve the puzzle and unlock a secret passage!\n");
    } else {
        printf("Suddenly, a ghost appears, warning you to leave!\n");
    }
}

void check_inventory(int *inventory) {
    printf("You check your inventory:\n");
    printf("1. Magic Potion: %s\n", inventory[0] == 1 ? "Available" : "Not available");
    printf("2. Crystal: %s\n", inventory[1] == 1 ? "Available" : "Not available");
    printf("3. Treasure: %s\n", inventory[2] == 1 ? "Available" : "Not available");
}

int main() {
    int running = 1;
    int inventory[3] = {0, 0, 0}; // 0: Not available, 1: Available

    print_intro();
    
    while (running) {
        print_choices();
        
        int choice;
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                explore_forest();
                inventory[0] = 1; // Collect magic potion
                break;
            case 2:
                enter_cave();
                inventory[1] = 1; // Collect crystal
                break;
            case 3:
                visit_ruins();
                inventory[2] = 1; // Collect treasure
                break;
            case 4:
                check_inventory(inventory);
                break;
            case 5:
                printf("Thank you for playing! Goodbye!\n");
                running = 0;
                break;
            default:
                printf("Surprisingly, that's not a valid choice! Please try again.\n");
                break;
        }
        
        printf("\n");
    }

    return 0;
}