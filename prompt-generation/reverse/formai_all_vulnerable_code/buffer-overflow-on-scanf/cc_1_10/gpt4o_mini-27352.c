//GPT-4o-mini DATASET v1.0 Category: Game ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void intro();
void forest();
void encounter();
void treasure();
void help();

int main() {
    srand(time(0)); // Seed the random number generator
    intro();
    forest();
    return 0;
}

void intro() {
    printf("=====================================\n");
    printf("        WELCOME TO MYSTIC FOREST    \n");
    printf("=====================================\n");
    printf("You find yourself at the edge of a vast and enchanting forest.\n");
    printf("Legends say that there are untold treasures and creatures lurking within.\n");
    printf("Be brave and wise in your choices, for they will shape your fate!\n");
    printf("\n");
}

void forest() {
    int choice;
    printf("You can:\n");
    printf("1. Enter the forest\n");
    printf("2. Read the map\n");
    printf("3. Exit the game\n");
    printf("What do you want to do? (1-3): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            encounter();
            break;
        case 2:
            help();
            forest();
            break;
        case 3:
            printf("Thank you for playing! Goodbye!\n");
            exit(0);
        default:
            printf("Invalid choice! Please select 1, 2, or 3.\n");
            forest();
            break;
    }
}

void encounter() {
    int creatureEncounter = rand() % 3; // Random encounter

    if (creatureEncounter == 0) {
        printf("A friendly fairy appears!\n");
        printf("She offers you a choice to:\n");
        printf("1. Receive a magical item\n");
        printf("2. Ask for directions\n");
        printf("What do you want to do? (1-2): ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            printf("You received a Magical Compass! It will guide you.\n");
            treasure();
        } else {
            printf("The fairy directs you to the hidden treasure in the forest.\n");
            treasure();
        }

    } else if (creatureEncounter == 1) {
        printf("Oh no! A hungry wolf appears!\n");
        printf("You must:\n");
        printf("1. Fight the wolf\n");
        printf("2. Try to escape\n");
        printf("What do you want to do? (1-2): ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            printf("You bravely face the wolf and defeat it!\n");
            treasure();
        } else {
            printf("You managed to escape, but you lost your opportunity for treasure.\n");
            forest();
        }

    } else {
        printf("A wise old owl helps you out!\n");
        printf("He can teach you:\n");
        printf("1. Wisdom to solve puzzles\n");
        printf("2. Knowledge for seeking hidden paths\n");
        printf("What do you want to do? (1-2): ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            printf("The owl shares a riddle with you! Solve it to continue.\n");
            printf("I speak without a mouth and hear without ears. I have no body, but I come alive with the wind. What am I? ");
            char riddleAnswer[30];
            scanf("%s", riddleAnswer);

            if (strcmp(riddleAnswer, "echo") == 0) {
                printf("Correct! The owl guides you to a treasure.\n");
                treasure();
            } else {
                printf("Incorrect! The owl can't help you further.\n");
                forest();
            }
        } else {
            printf("The owl gives you directions to seek a hidden path.\n");
            treasure();
        }
    }
}

void treasure() {
    printf("You've reached a clearing filled with golden treasures and gemstones!\n");
    printf("What will you take?\n");
    printf("1. Gold Coins\n");
    printf("2. Precious Gemstones\n");
    printf("3. A Mysterious Artifact\n");
    printf("Choose wisely (1-3): ");
    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("You chose the Gold Coins. You are now rich beyond your dreams!\n");
            break;
        case 2:
            printf("You take the Precious Gemstones. Beauty in your collection!\n");
            break;
        case 3:
            printf("You chose the Mysterious Artifact. You feel a strange power!\n");
            break;
        default:
            printf("Invalid choice. You've dropped your treasure!\n");
            break;
    }

    printf("Thank you for playing! You have completed the adventure!\n");
}

void help() {
    printf("In this game, you navigate through a mystical forest.\n");
    printf("Make choices that will influence your journey and outcomes.\n");
    printf("Be brave and wise, and discover the treasures hidden in the forest!\n");
}