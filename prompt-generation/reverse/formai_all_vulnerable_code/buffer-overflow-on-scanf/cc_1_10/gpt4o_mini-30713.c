//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

void start_game();
void forest();
void cave();
void village();
void end_game(int outcome);

int main() {
    start_game();
    return 0;
}

void start_game() {
    int choice;

    printf("Welcome to the Adventure Game!\n");
    printf("You find yourself standing at a crossroad in a mysterious land.\n");
    printf("1. Go to the Forest\n");
    printf("2. Enter the Cave\n");
    printf("3. Visit the Village\n");
    printf("Choose your path (1-3): ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            forest();
            break;
        case 2:
            cave();
            break;
        case 3:
            village();
            break;
        default:
            printf("Invalid choice! The adventure ends here.\n");
            exit(0);
    }
}

void forest() {
    int choice;

    printf("\nYou wander into the dark forest, surrounded by tall trees.\n");
    printf("You see a glimmering light ahead.\n");
    printf("1. Approach the light\n");
    printf("2. Turn back\n");
    printf("Choose your action (1-2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("As you approach the light, a fairy appears!\n");
        end_game(1);
    } else {
        printf("You turn back safely and return to the crossroads.\n");
        start_game();
    }
}

void cave() {
    int choice;

    printf("\nYou enter the dark cave, where the air is damp and cold.\n");
    printf("You hear strange noises coming from deeper within.\n");
    printf("1. Explore deeper\n");
    printf("2. Leave the cave\n");
    printf("Choose your action (1-2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("You find a hidden treasure chest, but a dragon guards it!\n");
        end_game(0);
    } else {
        printf("You safely exit the cave and return to the crossroads.\n");
        start_game();
    }
}

void village() {
    int choice;

    printf("\nYou walk into a quaint village filled with friendly villagers.\n");
    printf("They offer you food and stories of their adventures.\n");
    printf("1. Stay for a while\n");
    printf("2. Continue your journey\n");
    printf("Choose your action (1-2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("You enjoy the village's hospitality and become a local hero!\n");
        end_game(2);
    } else {
        printf("You wave goodbye to the villagers and continue your adventure.\n");
        start_game();
    }
}

void end_game(int outcome) {
    switch (outcome) {
        case 0:
            printf("You have been defeated by the dragon. Game Over!\n");
            break;
        case 1:
            printf("The fairy grants you three wishes! You have won!\n");
            break;
        case 2:
            printf("You lived happily as a local hero in the village! You have won!\n");
            break;
    }
    exit(0);
}