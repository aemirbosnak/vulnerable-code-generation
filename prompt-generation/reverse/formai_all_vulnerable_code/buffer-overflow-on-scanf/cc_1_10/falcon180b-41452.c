//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int choice;
    char playerName[20];

    // Introduction
    printf("Welcome to the Space Adventure!\n");
    printf("You are a space explorer traveling through the galaxy.\n");
    printf("Please enter your name: ");
    scanf("%s", playerName);

    // Game loop
    while(1) {
        system("clear"); // Clear the console
        printf("\n%s, you are currently in sector %d.\n", playerName, rand() % 10 + 1); // Random sector number
        printf("What would you like to do?\n");
        printf("1. Explore\n");
        printf("2. Trade\n");
        printf("3. Upgrade ship\n");
        printf("4. Quit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nYou start exploring the sector...\n");
                int event = rand() % 3; // Random event
                if(event == 0) {
                    printf("\nYou find a hidden planet with valuable resources!");
                } else if(event == 1) {
                    printf("\nYou encounter a friendly alien race and establish diplomatic relations!");
                } else {
                    printf("\nYou stumble upon an ancient artifact that grants you special abilities!");
                }
                break;
            case 2:
                printf("\nYou decide to trade with the local merchants...\n");
                int profit = rand() % 100 + 1; // Random profit
                printf("\nYou make a profit of %d space credits!\n", profit);
                break;
            case 3:
                printf("\nYou visit the local shipyard to upgrade your ship...\n");
                int upgrade = rand() % 3; // Random upgrade
                if(upgrade == 0) {
                    printf("\nYour ship's shields have been reinforced!");
                } else if(upgrade == 1) {
                    printf("\nYour ship's engines have been upgraded for faster travel!");
                } else {
                    printf("\nYour ship's weapons have been enhanced for more firepower!");
                }
                break;
            case 4:
                printf("\n%s, thank you for playing Space Adventure!", playerName);
                return 0;
            default:
                printf("\nInvalid choice, please try again.");
        }
    }

    return 0;
}