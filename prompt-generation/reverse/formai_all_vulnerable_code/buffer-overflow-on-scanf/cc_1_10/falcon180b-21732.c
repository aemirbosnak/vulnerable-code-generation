//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int choice;
    int health = 100;
    int gold = 0;
    int location = 1;
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You wake up in a small village surrounded by lush green forests.\n");
    printf("You have %d health points and %d gold coins.\n", health, gold);
    while(1) {
        system("clear");
        printf("Location: %d\n", location);
        printf("Health: %d\n", health);
        printf("Gold: %d\n", gold);
        printf("\n");
        printf("What would you like to do?\n");
        printf("1. Explore the village\n");
        printf("2. Enter the forest\n");
        printf("3. Visit the blacksmith\n");
        printf("4. Go to the inn\n");
        printf("5. Quit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("You explore the village and find a hidden treasure!\n");
                printf("You gained %d gold coins!\n", rand() % 50 + 1);
                gold += rand() % 50 + 1;
                break;
            case 2:
                printf("You enter the forest and get lost...\n");
                printf("You lose %d health points!\n", rand() % 10 + 1);
                health -= rand() % 10 + 1;
                break;
            case 3:
                printf("You visit the blacksmith and buy a sword.\n");
                printf("You spent %d gold coins!\n", 50);
                gold -= 50;
                break;
            case 4:
                printf("You go to the inn and rest.\n");
                printf("You regained %d health points!\n", rand() % 20 + 1);
                health += rand() % 20 + 1;
                break;
            case 5:
                printf("Goodbye!");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}