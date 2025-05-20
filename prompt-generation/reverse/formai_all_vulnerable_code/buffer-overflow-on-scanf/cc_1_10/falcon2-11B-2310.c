//Falcon2-11B DATASET v1.0 Category: Procedural Space Adventure ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 100

typedef struct {
    char name[50];
    int age;
    char occupation[50];
    int money;
} Player;

int main() {
    Player player1;
    Player player2;

    // Initialize players
    strcpy(player1.name, "John Doe");
    player1.age = 25;
    strcpy(player1.occupation, "Astronaut");
    player1.money = 100000;

    strcpy(player2.name, "Jane Smith");
    player2.age = 30;
    strcpy(player2.occupation, "Astronomer");
    player2.money = 500000;

    // Print player information
    printf("Player 1:\n");
    printf("Name: %s\n", player1.name);
    printf("Age: %d\n", player1.age);
    printf("Occupation: %s\n", player1.occupation);
    printf("Money: $%.2f\n", player1.money);

    printf("\nPlayer 2:\n");
    printf("Name: %s\n", player2.name);
    printf("Age: %d\n", player2.age);
    printf("Occupation: %s\n", player2.occupation);
    printf("Money: $%.2f\n", player2.money);

    // Game loop
    while (1) {
        // Print game menu
        printf("1. Go on a mission\n");
        printf("2. Visit a planet\n");
        printf("3. Go back to Earth\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");

        // Read user input
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Going on a mission...\n");
                break;
            case 2:
                printf("Visiting a planet...\n");
                break;
            case 3:
                printf("Going back to Earth...\n");
                break;
            case 4:
                printf("Quitting the game...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}