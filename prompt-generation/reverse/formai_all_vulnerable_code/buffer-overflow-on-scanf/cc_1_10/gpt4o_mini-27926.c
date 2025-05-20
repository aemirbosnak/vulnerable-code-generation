//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 100

void display_intro();
int get_choice();
void forest();
void cave();
void lake();
void treasure_room();

int main() {
    display_intro();

    while (1) {
        int choice = get_choice();
        switch (choice) {
            case 1:
                forest();
                break;
            case 2:
                cave();
                break;
            case 3:
                lake();
                break;
            case 4:
                printf("Thank you for playing! Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}

void display_intro() {
    printf("Welcome to the Mysterious Forest Adventure!\n");
    printf("In this text-based adventure game, you will explore \n");
    printf("different locations and make choices that will lead to \n");
    printf("various outcomes. Choose wisely!\n\n");
}

int get_choice() {
    int choice;
    printf("You stand at a crossroad in a dense forest. Where do you want to go?\n");
    printf("1. Explore the Forest\n");
    printf("2. Enter the Dark Cave\n");
    printf("3. Visit the Shimmering Lake\n");
    printf("4. Exit the game\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);
    return choice;
}

void forest() {
    printf("\nYou wander into the forest. The tall trees loom overhead, \n");
    printf("and you can hear the sound of rustling leaves.\n");
    printf("Suddenly, you spot a curious creature...\n");
    
    char action[MAX_INPUT_SIZE];
    printf("Do you want to (1) approach the creature or (2) back away? Enter 1 or 2: ");
    scanf("%s", action);

    if (strcmp(action, "1") == 0) {
        printf("The creature turns out to be a friendly sprite!\n");
        printf("It grants you a magical ability to speak with animals. You feel powerful!\n");
    } else {
        printf("You back away slowly and safely exit the forest.\n");
    }
}

void cave() {
    printf("\nAs you step into the cave, it’s dark and damp.\n");
    printf("You find glowing crystals on the walls, illuminating the path ahead.\n");
    
    char action[MAX_INPUT_SIZE];
    printf("Do you want to (1) collect a crystal or (2) explore deeper into the cave? Enter 1 or 2: ");
    scanf("%s", action);

    if (strcmp(action, "1") == 0) {
        printf("You collect a crystal! It’s beautiful and sparkles in your hands.\n");
        printf("You can use it to light your way later.\n");
    } else {
        printf("You venture deeper and discover a hidden treasure room!\n");
        treasure_room();
    }
}

void lake() {
    printf("\nYou arrive at the shimmering lake, reflecting the blue sky.\n");
    printf("You see something glinting in the water...\n");
    
    char action[MAX_INPUT_SIZE];
    printf("Do you want to (1) dive in the water or (2) sit on the shore? Enter 1 or 2: ");
    scanf("%s", action);

    if (strcmp(action, "1") == 0) {
        printf("You dive into the lake and discover an underwater cave filled with gold coins!\n");
    } else {
        printf("You sit quietly and enjoy the scenery.\n");
        printf("You feel at peace and decide to head back home.\n");
    }
}

void treasure_room() {
    printf("In the treasure room, you find piles of gold and jewels!\n");
    printf("Do you want to (1) take some treasure or (2) leave it untouched? Enter 1 or 2: ");
    char choice[MAX_INPUT_SIZE];
    scanf("%s", choice);

    if (strcmp(choice, "1") == 0) {
        printf("You gather some treasure and feel rich!\n");
    } else {
        printf("You decide to leave the treasure untouched, respecting the cave's secrets.\n");
    }
}