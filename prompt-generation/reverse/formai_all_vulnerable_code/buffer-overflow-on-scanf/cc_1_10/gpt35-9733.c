//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char choice;
    int fuel = 100, health = 100, planet = 0;
    srand(time(NULL));

    printf("Welcome to Procedural Space Adventure!\n");
    printf("You wake up to find yourself on board a spaceship headed to the nearest planet. Your mission is to collect resources and return to Earth. Are you ready?\n");

    while (health > 0 && fuel > 0) {
        printf("------------------\n");
        printf("Health: %d   Fuel: %d\n", health, fuel);
        printf("Choose an action:\n");
        printf("1. Fly to next planet\n");
        printf("2. Gather resources\n");
        printf("3. Repair spaceship\n");
        printf("4. Quit game\n");
        scanf(" %c", &choice);
        printf("------------------\n");

        switch(choice) {
            case '1':
                planet++;
                fuel -= rand() % 20 + 10;
                health -= rand() % 30 + 10;
                printf("You flew to Planet %d\n", planet);
                if (health <= 0) {
                    printf("Oh no! Your spaceship is too damaged to continue. Game over.\n");
                    return 0;
                } else if (fuel <= 0) {
                    printf("You ran out of fuel! Game over.\n");
                    return 0;
                }
                break;
            
            case '2':
                fuel -= rand() % 10 + 5;
                health -= rand() % 20 + 5;
                printf("You found some resources on Planet %d\n", planet);
                break;
            
            case '3':
                fuel -= rand() % 5 + 1;
                health += rand() % 10 + 5;
                printf("You repaired your spaceship\n");
                break;
            
            case '4':
                printf("Thanks for playing Procedural Space Adventure!\n");
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
                break;
        }

        if (planet == 5) {
            printf("You collected all necessary resources and safely returned to Earth. Congratulations, you win!\n");
            return 0;
        }
    }

    return 0;
}