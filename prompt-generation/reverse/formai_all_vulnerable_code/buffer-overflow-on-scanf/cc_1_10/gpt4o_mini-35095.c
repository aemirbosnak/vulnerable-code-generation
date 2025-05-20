//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESPONSE_LENGTH 100

void print_intro();
void forest_path();
void cave_path();
void river_path();
void campfire_scene();
void display_choices();

int main() {
    print_intro();
    forest_path();
    return 0;
}

void print_intro() {
    printf("Welcome to the Mysterious Forest Adventure!\n");
    printf("You are about to embark on an exciting journey filled with choices.\n");
    printf("Make your decisions wisely!\n\n");
}

void forest_path() {
    int choice;
    printf("You find yourself at the edge of a dark forest.\n");
    printf("You can:\n");
    printf("1. Enter the forest\n");
    printf("2. Go back home\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("You have entered the forest. It's eerily quiet...\n");
        display_choices();
    } else {
        printf("You decided to go back home. Adventure over!\n");
    }
}

void display_choices() {
    int choice;
    printf("\nYou see three paths in front of you:\n");
    printf("1. Path leading deeper into the forest\n");
    printf("2. A dark cave to your left\n");
    printf("3. A river to your right\n");
    printf("Choose a path (1, 2, or 3): ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            printf("You venture deeper into the forest...\n");
            river_path();
            break;
        case 2:
            printf("You cautiously enter the cave...\n");
            cave_path();
            break;
        case 3:
            printf("You stroll towards the river...\n");
            river_path();
            break;
        default:
            printf("Invalid choice. Try again.\n");
            display_choices();
            break;
    }
}

void cave_path() {
    printf("Inside the cave, you find glowing crystals, but you hear a growl...\n");
    printf("What will you do?\n");
    printf("1. Investigate the crystals\n");
    printf("2. Run back\n");
    
    int choice;
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("The growl was from a sleeping dragon! You have discovered its treasure!\n");
        printf("Congratulations, you are rich!\n");
    } else {
        printf("You ran back to safety but missed out on the treasure.\n");
    }
}

void river_path() {
    printf("At the river, you see a small boat.\n");
    printf("Will you:\n");
    printf("1. Take the boat down the river\n");
    printf("2. Fish from the riverbank\n\n");

    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        printf("You glide down the river until you find an island filled with exotic wildlife!\n");
        campfire_scene();
    } else {
        printf("You catch a fish but realize it was a mystical creature that grants wishes!\n");
        printf("You are now the owner of a magical fish!\n");
    }
}

void campfire_scene() {
    printf("You set up a campfire and enjoy the beautiful scenery.\n");
    printf("You hear whispers in the wind. Choose to:\n");
    printf("1. Investigate the whispers\n");
    printf("2. Ignore them and rest\n");

    int choice;
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("The whispers guide you to a hidden treasure! You've succeeded in your adventure!\n");
    } else {
        printf("You had a peaceful night and returned home safely. Adventure completed!\n");
    }
}