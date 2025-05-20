//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void spaceAdventure(void);

int main()
{
    spaceAdventure();
    return 0;
}

void spaceAdventure(void)
{
    int option;
    char name[20];
    int fuel = 100;
    int distance = 2000;
    srand(time(NULL)); // initialize random seed

    printf("*** Welcome to Procedural Space Adventure! ***\n\n");
    printf("What is your name, space traveler? \n");
    scanf("%s", name);

    printf("Welcome, %s! You are on a mission to explore the galaxy and find new planets for humanity to colonize.\n", name);

    do {
        printf("\nYou are currently %d light years away from Earth with %d units of fuel.\n", distance, fuel);
        printf("What would you like to do next?\n");
        printf("1. Fly to a nearby planet\n");
        printf("2. Refuel your spaceship\n");
        printf("3. Check current distance from Earth\n");
        printf("4. Quit the game\n");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                distance -= (rand() % 101 + 50);
                fuel -= (rand() % 11 + 5);
                printf("You flew to a nearby planet!\n");
                break;
            case 2:
                fuel = 100;
                printf("Your spaceship has been refueled!\n");
                break;
            case 3:
                printf("You are currently %d light years away from Earth.\n", distance);
                break;
            case 4:
                printf("Thank you for playing Procedural Space Adventure, %s!\n", name);
                exit(0);
            default:
                printf("Invalid option, please try again.\n");
        }

        if (fuel <= 0) {
            printf("Your spaceship has run out of fuel! Game over.\n");
            exit(0);
        }

        if (distance <= 0) {
            printf("Congratulations, you have reached Earth! You win.\n");
            exit(0);
        }

    } while(option != 4);
}