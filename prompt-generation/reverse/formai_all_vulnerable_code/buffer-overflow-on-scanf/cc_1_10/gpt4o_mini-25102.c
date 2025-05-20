//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHOICE 3

void print_intro() {
    printf("Welcome to the Enchanted Forest Adventure!\n");
    printf("You find yourself at the entrance of a mystical forest. The trees are tall, and their leaves whisper secrets.\n");
    printf("Your journey begins here, choose wisely as every pathway leads to a different adventure...\n\n");
}

void print_options() {
    printf("You have three paths to choose from:\n");
    printf("1. The path of Shadows\n");
    printf("2. The path of Light\n");
    printf("3. The path of Silence\n");
    printf("Which path will you take? (1-3): ");
}

void path_of_shadows() {
    printf("\nYou venture down the path of Shadows. A chilling breeze sends shivers down your spine.\n");
    printf("You encounter a mysterious figure cloaked in darkness. They hold a glowing crystal.\n");
    printf("What will you do?\n");
    printf("1. Approach the figure.\n");
    printf("2. Run away.\n");
    printf("Your choice (1-2): ");
    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
        printf("\nThe figure turns to you, revealing a kind face. \"You have bravery, young adventurer. Here, take this crystal.\"\n");
        printf("You gain a magical crystal that grants you insight into future events.\n");
    } else {
        printf("\nYou run away, heart racing. As you escape, you hear laughter in the wind. You have missed an opportunity.\n");
    }
}

void path_of_light() {
    printf("\nYou step onto the path of Light. Sunbeams filter through the leaves, illuminating your way.\n");
    printf("Ahead, you see a majestic unicorn drinking from a sparkling stream.\n");
    printf("What will you do?\n");
    printf("1. Try to pet the unicorn.\n");
    printf("2. Sit quietly and observe.\n");
    printf("Your choice (1-2): ");
    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
        printf("\nThe unicorn allows you to pet it, and in return, it blesses you with a gift of healing.\n");
    } else {
        printf("\nThe unicorn notices your presence and gracefully approaches you. You feel a sense of peace.\n");
    }
}

void path_of_silence() {
    printf("\nYou walk down the path of Silence, where the air is still and the forest is hushed.\n");
    printf("You find a hidden glade, and in the center is a stone statue of a fallen warrior.\n");
    printf("What will you do?\n");
    printf("1. Examine the statue.\n");
    printf("2. Leave the glade.\n");
    printf("Your choice (1-2): ");
    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
        printf("\nYou notice an inscription on the statue. It tells the tale of bravery and sacrifice. You feel inspired.\n");
    } else {
        printf("\nYou leave the glade quietly, feeling a sense of tranquility wash over you.\n");
    }
}

int main() {
    print_intro();
    int path_choice;
    while (1) {
        print_options();
        scanf("%d", &path_choice);
        if (path_choice < 1 || path_choice > MAX_CHOICE) {
            printf("Invalid choice. Please choose again.\n");
            continue;
        }
        switch (path_choice) {
            case 1:
                path_of_shadows();
                break;
            case 2:
                path_of_light();
                break;
            case 3:
                path_of_silence();
                break;
        }
        printf("\nDo you wish to explore another path? (1 for Yes / 0 for No): ");
        int continue_choice;
        scanf("%d", &continue_choice);
        if (continue_choice == 0) {
            printf("Thank you for playing! The forest will always welcome you back.\n");
            break;
        }
    }
    return 0;
}