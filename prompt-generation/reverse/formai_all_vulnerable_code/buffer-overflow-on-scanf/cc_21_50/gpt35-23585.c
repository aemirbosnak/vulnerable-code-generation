//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Initializing the random seed

    char name[20];
    int health = 100, ammo = 10, distance = 0, aliens = 0;
    int decision, random_event;

    printf("Welcome to the Procedural Space Adventure!\n");
    printf("What is your name? ");
    scanf("%s", name);
    printf("Greetings, %s!\n\n", name);

    // Game loop
    while (health > 0 && distance < 500) {
        printf("Your current status:\n\thealth: %d\n\tammo: %d\n\tdistance travelled: %d km\n\taliens defeated: %d\n\n", health, ammo, distance, aliens);

        printf("What would you like to do?\n");
        printf("\t1. Continue travelling\n");
        printf("\t2. Search for resources\n");
        printf("\t3. Rest and recover\n");
        printf("\t4. Quit\n");
        printf("\nEnter your decision: ");
        scanf("%d", &decision);

        switch (decision) {
            case 1:
                printf("\nTravelling to the next destination...\n");
                distance += rand() % 100 + 50; // Moving to a random distance
                ammo--; // Using 1 ammo
                aliens += rand() % 3; // Chance to encounter aliens
                break;

            case 2:
                printf("\nSearching for resources...\n");

                random_event = rand() % 4; // Generating a random event

                if (random_event == 0) {
                    printf("You found a crate of ammo!\n");
                    ammo += rand() % 6 + 5; // Adding 5-10 ammo
                } else if (random_event == 1) {
                    printf("You found a medkit!\n");
                    health += rand() % 21 + 10; // Healing 10-30 health
                    if (health > 100) health = 100; // Health cannot exceed 100
                } else if (random_event == 2) {
                    printf("You found a broken spaceship.\n");
                    printf("You spent some time repairing it...\n");
                    health -= 10; // Losing 10 health while repairing
                    if (health <= 0) break; // If health becomes 0 or lower, game over
                    printf("Your ship is now fully repaired!\n");
                    printf("You gained some distance...\n");
                    distance += rand() % 51 + 25; // Moving 25-75 km additional distance
                } else {
                    printf("You found nothing of value...\n");
                }
                break;

            case 3:
                printf("\nResting and recovering...\n");
                health += rand() % 21 + 10; // Healing 10-30 health
                if (health > 100) health = 100; // Health cannot exceed 100
                ammo--; // Using 1 ammo for guard duty
                printf("You guarded the camp during your rest.\n");
                aliens += rand() % 2; // Chance to encounter aliens during guard duty
                break;

            case 4:
                printf("\nQuitting the game...\n");
                return 0;

            default:
                printf("\nInvalid decision!\n");
                break;
        }

        if (aliens > 0) {
            printf("\nYou encountered %d alien(s)!\n", aliens);

            while (aliens > 0 && health > 0) {
                printf("Your health: %d\nAlien%s left: %d\n", health, aliens > 1 ? "s" : "", aliens);
                printf("What would you like to do?\n");
                printf("\t1. Fight\n");
                printf("\t2. Run\n");
                printf("\nEnter your decision: ");
                scanf("%d", &decision);

                switch (decision) {
                    case 1:
                        printf("\nYou attacked the alien!\n");
                        if (rand() % 2 == 0) {
                            printf("You defeated the alien!\n");
                            aliens--;
                        } else {
                            printf("The alien attacked you!\n");
                            health -= rand() % 11 + 5; // Losing 5-15 health
                            if (health <= 0) break; // If health becomes 0 or lower, game over
                        }
                        ammo--;
                        break;

                    case 2:
                        printf("\nYou ran away from the aliens...\n");
                        aliens = 0;
                        break;

                    default:
                        printf("\nInvalid decision!\n");
                        break;
                }
            }

            if (health <= 0) break; // If health becomes 0 or lower, game over

            printf("\nThe battle is over. ");

            if (aliens == 0) {
                printf("You emerged victorious!\n");
                distance += rand() % 51 + 25; // Moving 25-75 km additional distance after winning the battle
            } else {
                printf("You were defeated...\n");
                break; // Game over
            }
        }
    }

    if (health <= 0) {
        printf("\nGame over, %s. You died on your adventure.\n", name);
    } else {
        printf("\nCongratulations, %s! You completed your adventure.\n", name);
    }

    printf("Final status:\n\thealth: %d\n\tammo: %d\n\tdistance travelled: %d km\n\taliens defeated: %d\n\n", health, ammo, distance, aliens);

    return 0;
}