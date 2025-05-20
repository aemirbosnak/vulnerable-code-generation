//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 100

void print_intro() {
    printf("------------------------------------------------\n");
    printf("    WELCOME TO THE MYSTICAL ADVENTURE GAME!    \n");
    printf("------------------------------------------------\n");
    printf("As a brave adventurer, you will embark on a thrilling journey! \n");
    printf("Your choices will dictate your fate in this adventurous land!\n\n");
}

void print_menu() {
    printf("Choose your action:\n");
    printf("1. Venture into the Forest\n");
    printf("2. Explore the Mysterious Cave\n");
    printf("3. Cross the Enchanted River\n");
    printf("4. Check your inventory\n");
    printf("5. Exit Game\n");
}

void explore_forest() {
    printf("You step into the lush, green forest. The sounds of wildlife surround you.\n");
    printf("Suddenly, a wild deer crosses your path and looks at you curiously.\n");
    printf("What will you do?\n");
    printf("1. Attempt to befriend the deer.\n");
    printf("2. Follow the deer.\n");
    printf("3. Turn back to the village.\n");
}

void explore_cave() {
    printf("You enter the dark cave, the sound of dripping water echoes around. \n");
    printf("As your eyes adjust, you see glowing crystals on the walls, illuminating the way.\n");
    printf("What will you do?\n");
    printf("1. Collect some crystals.\n");
    printf("2. Explore deeper into the cave.\n");
    printf("3. Leave the cave.\n");
}

void cross_river() {
    printf("You approach the sparkling river, the water flows swiftly beside you.\n");
    printf("Do you want to:\n");
    printf("1. Build a raft to cross the river.\n");
    printf("2. Search for a bridge.\n");
    printf("3. Swim across.\n");
}

void check_inventory(int *inventory) {
    printf("You check your inventory:\n");
    if (inventory[0] > 0) {
        printf("You have %d glowing crystals!\n", inventory[0]);
    } else {
        printf("Your inventory is empty.\n");
    }
}

int main() {
    int choice, sub_choice;
    int inventory[1] = {0}; // Inventory for crystals
    srand(time(NULL));

    print_intro();

    while (1) {
        print_menu();
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                explore_forest();
                printf("Enter your action (1-3): ");
                scanf("%d", &sub_choice);
                switch (sub_choice) {
                    case 1:
                        printf("You approach the deer gently and soon earn its trust! It leads you to a hidden glade!\n");
                        break;
                    case 2:
                        printf("You follow the deer and discover a treasure chest filled with gold coins!\n");
                        break;
                    case 3:
                        printf("You decide to turn back and head to safety in the village.\n");
                        break;
                    default:
                        printf("Invalid choice. The forest whispers goodbye as you ponder your fate.\n");
                }
                break;

            case 2:
                explore_cave();
                printf("Enter your action (1-3): ");
                scanf("%d", &sub_choice);
                switch (sub_choice) {
                    case 1:
                        inventory[0]++;
                        printf("You collect some sparkling crystals! They will surely be useful on your journey!\n");
                        break;
                    case 2:
                        printf("You delve deeper into the cave and find a hidden underground lake!\n");
                        break;
                    case 3:
                        printf("You decide to leave before the cave gets too dark.\n");
                        break;
                    default:
                        printf("Invalid choice. The cave echoes your indecision.\n");
                }
                break;

            case 3:
                cross_river();
                printf("Enter your action (1-3): ");
                scanf("%d", &sub_choice);
                switch (sub_choice) {
                    case 1:
                        printf("You build a sturdy raft and skillfully paddle across the river! You made it!\n");
                        break;
                    case 2:
                        printf("You search for a bridge and find a friendly old man who helps you cross.\n");
                        break;
                    case 3:
                        printf("You bravely swim across, but the water is colder than you expected!\n");
                        break;
                    default:
                        printf("Invalid choice. The river laughs as you stumble on the bank.\n");
                }
                break;

            case 4:
                check_inventory(inventory);
                break;

            case 5:
                printf("Thanks for playing! Your adventure ends here... for now!\n");
                exit(0);
                break;

            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    }

    return 0;
}