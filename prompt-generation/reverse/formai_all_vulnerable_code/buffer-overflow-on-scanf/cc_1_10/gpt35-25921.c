//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

void panic(char* message) {
    printf("ERROR: %s\n", message);
    exit(EXIT_FAILURE);
}

int main() {
    printf("Welcome to Procedural Space Adventure!\n");

    // Initialize game variables
    int fuel = 100;
    int health = 100;
    int distance = 0;
    int aliens = 0;

    char answer;

    // Game loop
    while (distance < 1000) {
        printf("\nYou have traveled %d light years.\n", distance);
        printf("You have %d units of fuel and %d health remaining.\n", fuel, health);
        printf("You have encountered %d aliens.\n", aliens);

        printf("\nWhat do you want to do? (F)uel up, (H)eal, (E)ncounter aliens, (Q)uit: ");
        scanf(" %c", &answer);

        switch (answer) {
            case 'F':
            case 'f':
                printf("You fueled up.\n");
                fuel += 50;
                break;
            case 'H':
            case 'h':
                printf("You healed.\n");
                health += 50;
                break;
            case 'E':
            case 'e':
                if (aliens == 0) {
                    printf("You did not encounter any aliens.\n");
                } else {
                    printf("You encountered %d aliens.\n", aliens);
                    printf("You fought off the alien attack but your health suffered.\n");
                    health -= aliens * 10;
                }
                break;
            case 'Q':
            case 'q':
                printf("Quitting game.\n");
                exit(EXIT_SUCCESS);
            default:
                panic("Invalid input.");
                break;
        }

        // Update game variables
        fuel -= 10;
        health -= 5;
        aliens += 1;

        if (fuel <= 0 || health <= 0) {
            printf("You ran out of fuel or health.\n");
            printf("GAME OVER.\n");
            exit(EXIT_FAILURE);
        }

        distance += 50;
    }

    printf("Congratulations, you completed your space adventure!\n");
    printf("You traveled %d light years and encountered %d aliens.\n", distance, aliens);
    printf("You have %d units of fuel and %d health remaining.\n", fuel, health);

    return 0;
}