//GPT-4o-mini DATASET v1.0 Category: Game ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void introduction() {
    printf("Welcome to The Dark Forest Adventure!\n");
    printf("You are a brave knight on a quest to find the hidden treasure.\n");
    printf("But beware! The forest is filled with dangers.\n");
    printf("Make your choices wisely to survive and succeed!\n\n");
}

void print_choice() {
    printf("You are standing at the edge of a dark forest.\n");
    printf("What would you like to do?\n");
    printf("1. Enter the forest.\n");
    printf("2. Walk along the path.\n");
    printf("3. Go back to the village.\n");
    printf("Choose (1-3): ");
}

int enter_forest() {
    printf("\nYou bravely step into the forest.\n");
    int encounter = rand() % 3; // Random encounter generator
    if (encounter == 0) {
        printf("You encounter a wild beast! Do you:\n");
        printf("1. Fight it.\n");
        printf("2. Run away.\n");
        printf("Choose (1-2): ");
        int choice;
        scanf("%d", &choice);
        if (choice == 1) {
            printf("With courage, you fought and defeated the beast!\n");
            return 1; // Victory
        } else {
            printf("You fled back to the entrance of the forest.\n");
            return 0; // No victory
        }
    } 
    else if (encounter == 1) {
        printf("You find a magical fountain! Do you:\n");
        printf("1. Drink from it.\n");
        printf("2. Ignore it.\n");
        printf("Choose (1-2): ");
        int choice;
        scanf("%d", &choice);
        if (choice == 1) {
            printf("You feel invincible! Your courage is increased!\n");
            return 1; // Benefit gained
        } else {
            printf("You walk past the fountain, missing a chance to gain strength.\n");
            return 0; // No benefit gained
        }
    } 
    else {
        printf("You find a hidden treasure chest! Do you:\n");
        printf("1. Open it.\n");
        printf("2. Leave it alone.\n");
        printf("Choose (1-2): ");
        int choice;
        scanf("%d", &choice);
        if (choice == 1) {
            printf("You opened the chest and found gold! You are rich!\n");
            return 1; // Wealth gained
        } else {
            printf("You chose not to open the chest. Perhaps another brave soul will.\n");
            return 0; // No wealth gained
        }
    }
}

int walk_path() {
    printf("\nYou walk along the path, searching for adventure.\n");
    int challenge = rand() % 2; // Random challenge generator
    if (challenge == 0) {
        printf("You come across a rickety bridge. Do you:\n");
        printf("1. Cross it.\n");
        printf("2. Turn back.\n");
        printf("Choose (1-2): ");
        int choice;
        scanf("%d", &choice);
        if (choice == 1) {
            printf("You crossed the bridge safely! Kudos to your bravery!\n");
            return 1; // Safe crossing
        } else {
            printf("You wisely decide to turn back and look for a safer path.\n");
            return 0; // No adventure taken
        }
    } else {
        printf("You encounter a traveler who offers you wisdom. Do you:\n");
        printf("1. Listen to them.\n");
        printf("2. Ignore them.\n");
        printf("Choose (1-2): ");
        int choice;
        scanf("%d", &choice);
        if (choice == 1) {
            printf("You gained valuable knowledge for your adventure!\n");
            return 1; // Wisdom gained
        } else {
            printf("You ignore the traveler and miss a chance to learn.\n");
            return 0; // No knowledge gained
        }
    }
}

int go_back() {
    printf("\nYou chose to go back to the village. Perhaps another day...\n");
    return 0; // No adventure taken
}

int main() {
    srand(time(0)); // Seed for random number generation
    int choice;
    
    introduction();

    while (1) {
        print_choice();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                if (enter_forest()) {
                    printf("You bravely continued your adventure!\n");
                } else {
                    printf("You chose a different path.\n");
                }
                break;
        
            case 2:
                if (walk_path()) {
                    printf("You found new strength for your journey!\n");
                } else {
                    printf("You decided to play it safe.\n");
                }
                break;
        
            case 3:
                go_back();
                exit(0);
        
            default:
                printf("Invalid choice! Please choose (1-3).\n");
                break;
        }
        printf("\n");
    }
    
    return 0;
}