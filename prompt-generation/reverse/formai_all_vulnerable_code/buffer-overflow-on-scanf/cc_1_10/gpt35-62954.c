//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate random number for event occurrence
int generateRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    // player details
    char playerName[20];
    int playerHealth = 100;
    int playerRoom = 1;

    // game map
    int map[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // game events
    char events[5][50] = {
        "You found a space crystal!",
        "You encountered some friendly aliens.",
        "You stumbled upon an ancient space station.",
        "You spotted a rare space creature.",
        "You found a secret room filled with treasure."
    };

    // seed the random number generator with current time
    srand(time(NULL));

    printf("Welcome to Space Adventure!\n");
    printf("Please enter your name: ");
    scanf("%s", playerName);

    printf("Greetings, %s! Your mission is to explore space and collect as many space crystals as possible.\n", playerName);

    while (playerHealth > 0) {
        printf("You are currently in Room %d.\n", playerRoom);
        printf("What would you like to do?\n");
        printf("1. Move left\n");
        printf("2. Move up\n");
        printf("3. Move right\n");
        printf("4. Move down\n");
        printf("5. Quit game\n");

        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            if (playerRoom % 3 == 1) {
                printf("There is no room to move left.\n");
                continue;
            }
            playerRoom--;
        } else if (choice == 2) {
            if (playerRoom <= 3) {
                printf("There is no room to move up.\n");
                continue;
            }
            playerRoom -= 3;
        } else if (choice == 3) {
            if (playerRoom % 3 == 0) {
                printf("There is no room to move right.\n");
                continue;
            }
            playerRoom++;
        } else if (choice == 4) {
            if (playerRoom >= 7) {
                printf("There is no room to move down.\n");
                continue;
            }
            playerRoom += 3;
        } else if (choice == 5) {
            printf("Thanks for playing, %s! Goodbye!\n", playerName);
            return 0;
        } else {
            printf("Invalid choice! Please try again.\n");
            continue;
        }

        printf("You are now in Room %d.\n", playerRoom);

        int eventChance = generateRandomNumber(1, 10);
        if (eventChance <= 3) {
            int eventIndex = generateRandomNumber(0, 4);
            printf("%s\n", events[eventIndex]);
            if (eventIndex == 0) {
                printf("+10 health points!\n");
                playerHealth += 10;
            } else if (eventIndex == 1) {
                printf("+5 health points!\n");
                playerHealth += 5;
            } else if (eventIndex == 2) {
                printf("+20 health points!\n");
                playerHealth += 20;
            } else if (eventIndex == 3) {
                printf("-10 health points!\n");
                playerHealth -= 10;
            } else if (eventIndex == 4) {
                printf("+50 health points!\n");
                playerHealth += 50;
            }
        }

        printf("Your current health is %d.\n", playerHealth);

        if (map[playerRoom/3][playerRoom%3-1] == 5) {
            printf("Congratulations, %s! You have found a space crystal!\n", playerName);
        }
    }

    printf("Oh no, %s! Your health has reached 0. Game over!\n", playerName);

    return 0;
}