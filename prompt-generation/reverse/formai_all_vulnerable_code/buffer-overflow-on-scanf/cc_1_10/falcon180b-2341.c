//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void space_adventure() {
    int choice;
    int health = 100;
    int score = 0;

    printf("Welcome to the Space Adventure!\n");
    srand(time(NULL));

    while (1) {
        printf("\n");
        printf("You are in a spaceship, flying through the galaxy.\n");
        printf("You have %d health points and %d score points.\n", health, score);

        printf("\n");
        printf("What do you want to do?\n");
        printf("1. Fly forward\n");
        printf("2. Turn left\n");
        printf("3. Turn right\n");
        printf("4. Shoot laser\n");
        printf("5. Repair spaceship\n");
        printf("6. Quit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n");
                printf("You fly forward...\n");
                break;
            case 2:
                printf("\n");
                printf("You turn left...\n");
                break;
            case 3:
                printf("\n");
                printf("You turn right...\n");
                break;
            case 4:
                printf("\n");
                printf("You shoot a laser...\n");
                break;
            case 5:
                printf("\n");
                printf("You repair the spaceship...\n");
                break;
            case 6:
                printf("\n");
                printf("Goodbye! Thanks for playing!\n");
                exit(0);
            default:
                printf("\n");
                printf("Invalid choice! Try again.\n");
        }

        if (health <= 0) {
            printf("\n");
            printf("Game over! You lose.\n");
            exit(0);
        }

        if (score >= 100) {
            printf("\n");
            printf("Congratulations! You win!\n");
            exit(0);
        }
    }
}

int main() {
    space_adventure();
    return 0;
}