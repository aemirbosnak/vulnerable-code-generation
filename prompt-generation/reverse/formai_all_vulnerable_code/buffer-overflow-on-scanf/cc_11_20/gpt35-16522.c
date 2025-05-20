//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_HEALTH 100
#define MIN_HEALTH 0
#define OUT_OF_FUEL 0
#define FUEL_CAPACITY 10
#define MAX_ENERGY 20
#define MIN_ENERGY 0
#define MAX_DISTANCE 100
#define MIN_DISTANCE 0

int main()
{
    int health = MAX_HEALTH, fuel = FUEL_CAPACITY, energy = MAX_ENERGY, distance = MIN_DISTANCE;

    printf("Welcome to the Paranoid Adventure Game!\n\n");

    printf("You wake up in an unfamiliar place, surrounded by darkness. You have no idea how you got here or what your purpose is. All you know is that you must get out of here and find your way back home.\n\n");

    while (health > MIN_HEALTH && fuel > OUT_OF_FUEL && distance < MAX_DISTANCE)
    {
        printf("Current Health: %d\n", health);
        printf("Current Fuel: %d\n", fuel);
        printf("Current Energy: %d\n", energy);
        printf("Current Distance from Home: %d\n\n", distance);

        printf("What do you want to do?\n");
        printf("1. Search for Food\n");
        printf("2. Search for Fuel\n");
        printf("3. Rest\n");
        printf("4. Continue Journey\n");

        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("You found some strange-looking berries. Do you want to eat them? (1 for yes, 0 for no)\n");
                int eat;
                scanf("%d", &eat);
                if (eat == 1)
                {
                    printf("You start feeling sick. Your health decreases by 20.\n");
                    health -= 20;
                } 
                else
                {
                    printf("You decide not to eat the berries.\n");
                }
                energy -= 2;
                break;
            case 2:
                printf("You come across a car, but it requires a key to start. You can either keep looking or try to break into the car. (1 for keep looking, 2 for break in)\n");
                int break_in;
                scanf("%d", &break_in);
                if (break_in == 1)
                {
                    printf("You keep looking for fuel.\n");
                }
                else
                {
                    printf("You break into the car, but the alarm goes off. You take some fuel and run away. Your health decreases by 10.\n");
                    fuel += 5;
                    health -= 10;
                }
                energy -= 3;
                break;
            case 3:
                printf("You rest for a while and regain some energy. Your energy increases by 5 and your health increases by 10.\n");
                energy += 5;
                health += 10;
                if (energy > MAX_ENERGY) energy = MAX_ENERGY;
                if (health > MAX_HEALTH) health = MAX_HEALTH;
                break;
            case 4:
                printf("You continue on your journey.\n");
                fuel -= 2;
                energy -= 1;
                distance += 10;
                break;
            default:
                printf("Invalid choice. Please choose again.\n");
        }

        if (rand() % 5 == 0)
        {
            printf("You hear strange noises in the distance. You start feeling paranoid.\n");
            int paranoid_choice;
            printf("Do you want to investigate the noise? (1 for yes, 0 for no)\n");
            scanf("%d", &paranoid_choice);
            if (paranoid_choice == 1)
            {
                printf("You investigate the noise and find nothing. You waste some fuel and energy.\n");
                fuel -= 3;
                energy -= 2;
            }
            else
            {
                printf("You continue on your journey, but you can't shake off the feeling of being watched.\n");
            }
        }

        if (distance >= MAX_DISTANCE)
        {
            printf("You finally arrive home, relieved to be back.\n");
        }
        else if (fuel == OUT_OF_FUEL)
        {
            printf("You run out of fuel and are stranded in the middle of nowhere. Game Over.\n");
            break;
        }
        else if (health <= MIN_HEALTH)
        {
            printf("Your health reaches zero. You collapse and die. Game Over.\n");
            break;
        }
        else if (energy <= MIN_ENERGY)
        {
            printf("You run out of energy and can't continue. Game Over.\n");
            break;
        }
    }

    printf("\nThanks for playing the Paranoid Adventure Game!\n");

    return 0;
}