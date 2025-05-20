//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/* Function Declaration */
void travel(int distance, int speed, int fuel);
int planetLanding(int planet);
void shop(int budget, int fuel, int *shields, int *repairs);

int main()
{
    int distance = 1000;                        // Distance to the final planet
    int speed = 0;                              // Current speed of the ship
    int fuel = 100;                             // Fuel level of the ship
    int planet = 0;                             // Current planet number
    int shields = 100;                          // Shield strength of the ship
    int repairs = 0;                            // Number of ship repairs taken
    int budget = 1000;                          // Available credits
    char playAgain = 'y';                       // Play again flag

    // Set the seed for random number generation
    srand(time(NULL));

    // Start the game loop
    while(playAgain == 'y')
    {
        // Print current game state
        printf("Planet: %d\tFuel: %d\tShields: %d\n", planet, fuel, shields);

        // Prompt the player for their action
        printf("What would you like to do? (1)Travel (2)Land on Planet (3)Visit Shop\n");
        int action;
        scanf("%d", &action);

        switch(action)
        {
            // Travel to the next planet
            case 1:
                travel(distance, speed, fuel);
                break;

            // Land on the current planet
            case 2:
                planet = planetLanding(planet);
                break;

            // Visit the space shop
            case 3:
                shop(budget, fuel, &shields, &repairs);
                break;

            // Invalid input
            default:
                printf("Invalid input, try again\n");
        }

        // Check if the player has won
        if(planet == 10 && fuel > 0)
        {
            printf("Congratulations! You made it to the final planet\n");
            playAgain = 'n';
        }

        // Check if the player has lost
        if(fuel <= 0 || shields <= 0)
        {
            printf("Game Over! Your ship was destroyed\n");
            playAgain = 'n';
        }
    }

    return 0;
}

/*
* Simulate traveling to the next planet
* Distance: Distance to the final planet
* Speed: Current speed of the ship
* Fuel: Fuel level of the ship
*/
void travel(int distance, int speed, int fuel)
{
    // Calculate the new distance
    distance -= speed;

    // Consume fuel based on the speed
    fuel -= speed * 2;

    // Randomly damage the ship's shields
    int damage = rand() % 10;
    printf("Ship's shields were damaged by %d\n", damage);

    // Subtract damage from the shield strength
    int shields = 100;
    shields -= damage;

    // Print information to the console
    printf("Traveled %d units and used %d fuel\n", speed, speed * 2);
}

/*
* Simulate landing on a planet
* Planet: Current planet number
* Returns: Next planet number
*/
int planetLanding(int planet)
{
    // Generate some random events
    int event = rand() % 3;

    switch(event)
    {
        // Nothing interesting happens
        case 0:
            printf("Nothing interesting happens on this planet\n");
            break;

        // Find some credits on the planet
        case 1:
            printf("You found some credits on the planet\n");
            break;

        // Encounter hostile aliens
        case 2:
            printf("Hostile aliens attack your ship\n");
            break;

        default:
            printf("Unknown event happened\n");
    }

    // Calculate the new planet number
    planet++;

    return planet;
}

/*
* Visit the space shop
* Budget: Available credits
* Fuel: Fuel level of the ship
* Shields: Current shield strength of the ship
* Repairs: Number of previous ship repairs taken
*/
void shop(int budget, int fuel, int *shields, int *repairs)
{
    // Ask the player what they want to buy
    printf("Welcome to the space shop! What do you want to buy? (1)Fuel (2)Shields (3)Repairs\n");
    int item;
    scanf("%d", &item);

    switch(item)
    {
        // Buy fuel for the ship
        case 1:
            printf("How many units of fuel do you want to buy?\n");
            int units;
            scanf("%d", &units);

            // Calculate the cost of the fuel
            int cost = units * 10;

            // Check if the player has enough credits
            if(budget >= cost)
            {
                // Substract the cost from the budget
                budget -= cost;

                // Add the fuel to the ship
                fuel += units;

                printf("You bought %d units of fuel for %d credits\n", units, cost);
            }
            else
            {
                printf("Not enough credits to buy fuel\n");
            }

            break;

        // Buy shields for the ship
        case 2:
            printf("How much do you want to spend on shields?\n");
            int amount;
            scanf("%d", &amount);

            // Calculate the cost of the shields
            cost = amount * 5;

            // Check if the player has enough credits
            if(budget >= cost)
            {
                // Subtract the cost from the budget
                budget -= cost;

                // Add the shields to the ship
                *shields += amount;

                printf("You bought %d shields for %d credits\n", amount, cost);
            }
            else
            {
                printf("Not enough credits to buy shields\n");
            }

            break;

        // Repair the ship
        case 3:
            // Check if the ship needs repairs
            if(*repairs > 0)
            {
                printf("Your ship is already repaired\n");
            }
            else
            {
                // Check if the player has enough credits
                if(budget >= 50)
                {
                    // Subtract the cost from the budget
                    budget -= 50;

                    // Set repairs to 1
                    *repairs = 1;

                    printf("Your ship has been repaired for 50 credits\n");
                }
                else
                {
                    printf("Not enough credits to repair your ship\n");
                }
            }

            break;

        // Invalid input
        default:
            printf("Invalid input, try again\n");
    }
}