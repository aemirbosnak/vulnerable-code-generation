//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void space_adventure() {
    int choice;
    int health = 100;
    int score = 0;
    char name[20];

    printf("Welcome to the Space Adventure!\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    srand(time(NULL));
    int random_number = rand() % 3;

    if (random_number == 0) {
        printf("\nYou are Captain %s of the starship Enterprise.\n", name);
    } else if (random_number == 1) {
        printf("\nYou are Luke Skywalker, a Jedi Knight.\n");
    } else {
        printf("\nYou are Indiana Jones, an archaeologist and adventurer.\n");
    }

    while (health > 0) {
        system("clear");
        printf("\nYou are in a spaceship flying through the galaxy.\n");
        printf("Your current health is %d.\n", health);
        printf("Your current score is %d.\n\n", score);

        printf("What would you like to do?\n");
        printf("1. Explore a planet\n");
        printf("2. Fight an alien\n");
        printf("3. Repair the spaceship\n");
        printf("4. Continue flying\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nYou land on a nearby planet and begin exploring.\n");
                health -= 10;
                score += 5;
                break;
            case 2:
                printf("\nYou encounter an alien and engage in battle.\n");
                health -= 20;
                score += 10;
                break;
            case 3:
                printf("\nYou repair the spaceship and continue your journey.\n");
                health += 10;
                score += 5;
                break;
            case 4:
                printf("\nYou continue flying through the galaxy.\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }

        if (health <= 0) {
            printf("\nGame over! You have died.\n");
            exit(0);
        }
    }

    printf("\nCongratulations! You have completed the Space Adventure with a score of %d.\n", score);
}

int main() {
    space_adventure();
    return 0;
}