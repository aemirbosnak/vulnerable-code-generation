//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int choice;
    char name[20];

    printf("Welcome to the Enchanted Forest!\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    printf("\nYou are %s, a brave adventurer exploring the magical woods.\n", name);
    printf("Guide me through this mystical journey.\n");

    int health = 100;
    int gold = 0;

    while (health > 0) {
        system("clear");
        printf("\nYou are in a beautiful clearing, surrounded by tall trees and colorful flowers.\n");
        printf("To the north, you see a sparkling river.\n");
        printf("To the east, there's a mysterious cave.\n");
        printf("To the west, you spot an old bridge leading to another part of the forest.\n");
        printf("What would you like to do?\n");
        printf("1. Go north to the river\n");
        printf("2. Explore the cave to the east\n");
        printf("3. Cross the bridge to the west\n");
        printf("4. Rest and regain health\n");
        printf("5. Quit adventure\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nYou approach the river and dip your feet in the cool water.\n");
                printf("The soothing sound of the flowing water heals you.\n");
                health += 10;
                break;
            case 2:
                printf("\nAs you enter the cave, you feel a chill in the air.\n");
                printf("Suddenly, a group of bats attack you!\n");
                health -= 20;
                if (health <= 0) {
                    printf("\nGame Over! You have been defeated by the bats.\n");
                    exit(0);
                }
                break;
            case 3:
                printf("\nYou carefully cross the old bridge, avoiding any loose planks.\n");
                printf("On the other side, you find a hidden treasure!\n");
                gold += 50;
                break;
            case 4:
                printf("\nYou take a break and rest under a tree.\n");
                printf("Your health is restored to full.\n");
                health = 100;
                break;
            case 5:
                printf("\nThank you for playing! Goodbye, %s.\n", name);
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}