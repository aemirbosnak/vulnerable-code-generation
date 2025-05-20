//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void startAdventure();
void forestPath();
void cavePath();
void treasure();
void monster();
void endGame();

int main() {
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You find yourself in a mysterious land. What do you want to do?\n");
    startAdventure();

    return 0;
}

void startAdventure() {
    int choice;

    printf("1. Explore the forest\n");
    printf("2. Enter the cave\n");
    printf("Choose your path (1 or 2): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            forestPath();
            break;
        case 2:
            cavePath();
            break;
        default:
            printf("Invalid choice! Please choose 1 or 2.\n");
            startAdventure();
            break;
    }
}

void forestPath() {
    int choice;

    printf("You walk into the dense forest. You can hear the chirping of birds and rustling of leaves.\n");
    printf("Suddenly, you find two paths.\n");
    printf("1. Follow the sound of water\n");
    printf("2. Climb the steep hill\n");
    printf("Which path do you take? (1 or 2): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            treasure();
            break;
        case 2:
            monster();
            break;
        default:
            printf("Invalid choice! Please choose 1 or 2.\n");
            forestPath();
            break;
    }
}

void cavePath() {
    int choice;

    printf("As you step into the cave, it's dark and damp. You can smell the earth.\n");
    printf("You see two tunnels.\n");
    printf("1. The tunnel on the left seems to glow faintly\n");
    printf("2. The tunnel on the right looks dark and ominous\n");
    printf("Which tunnel do you choose? (1 or 2): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            treasure();
            break;
        case 2:
            monster();
            break;
        default:
            printf("Invalid choice! Please choose 1 or 2.\n");
            cavePath();
            break;
    }
}

void treasure() {
    printf("Congratulations! You have found a hidden treasure!\n");
    printf("You discover gold coins and ancient artifacts.\n");
    printf("You can take the treasure and leave, or explore further.\n");

    int choice;
    printf("1. Leave with the treasure\n");
    printf("2. Explore further into the cave/forest\n");
    printf("What do you do? (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("You leave with the treasure, a hero of the land!\n");
    } else {
        printf("As you explore, you trigger a trap! You have fallen into a pit!\n");
        endGame();
    }
    endGame();
}

void monster() {
    printf("A wild monster appears! It's huge and terrifying!\n");
    printf("You have two choices:\n");
    printf("1. Fight the monster\n");
    printf("2. Run away\n");
    
    int choice;
    printf("What do you do? (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("You bravely fight the monster and manage to defeat it!\n");
        treasure();
    } else {
        printf("You run away and escape safely, but you lost your chance for treasure!\n");
    }
    endGame();
}

void endGame() {
    printf("Thank you for playing! Would you like to play again? (1 for Yes, 0 for No): ");
    int choice;
    scanf("%d", &choice);
    
    if (choice == 1) {
        startAdventure();
    } else {
        printf("Farewell, adventurer!\n");
        exit(0);
    }
}