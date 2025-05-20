//Falcon2-11B DATASET v1.0 Category: Text-Based Adventure Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main() {
    // Initialize game variables
    char player_name[20];
    int player_health = 100;
    int player_gold = 0;

    // Prompt player for name
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("Please enter your name: ");
    scanf("%s", player_name);
    printf("Hello %s, welcome to the game!\n", player_name);

    // Start game loop
    while (1) {
        // Display game menu
        printf("\nChoose an option:\n");
        printf("1. Look around\n");
        printf("2. Fight monster\n");
        printf("3. Exit\n");

        // Get player's choice
        int choice;
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);

        // Process player's choice
        switch (choice) {
            case 1:
                printf("You look around and see a cave entrance.\n");
                printf("There is a small stream running through the cave.\n");
                break;
            case 2:
                printf("You decide to fight the monster.\n");
                printf("You equip your sword and shield.\n");
                printf("The monster attacks you.\n");
                if (rand() % 2 == 0) {
                    printf("You successfully block the monster's attack.\n");
                    player_health -= 10;
                    printf("You swing your sword at the monster.\n");
                    if (rand() % 2 == 0) {
                        printf("You hit the monster and it retreats.\n");
                        player_gold += 10;
                    } else {
                        printf("You miss the monster.\n");
                    }
                } else {
                    printf("The monster's attack hits you.\n");
                    player_health -= 20;
                    printf("You swing your sword at the monster.\n");
                    if (rand() % 2 == 0) {
                        printf("You hit the monster and it retreats.\n");
                        player_gold += 10;
                    } else {
                        printf("You miss the monster.\n");
                    }
                }
                break;
            case 3:
                printf("Thanks for playing!\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}