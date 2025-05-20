//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // initialize random seed
    srand(time(NULL));

    // set up variables
    int hull = 100;
    int fuel = 50;
    int credits = 0;
    int planet = 0;
    int distance = 0;

    // print welcome message
    printf("Welcome to Procedural Space Adventure!\n\n");

    // game loop
    while (hull > 0 && fuel > 0 && planet < 5)
    {
        // randomly generate distance to next planet
        distance = rand() % 501; // range from 0 to 500 light years
        printf("You are %d light years from the next planet.\n", distance);

        // ask for user input
        char choice;
        printf("Do you want to warp (W) or refuel (R)? ");
        scanf(" %c", &choice);

        // handle user choice
        if (choice == 'W')
        {
            // calculate fuel consumption
            int consumption = distance / 10; // 10 light years per unit of fuel
            fuel -= consumption;

            // handle out of fuel scenario
            if (fuel < 0)
            {
                printf("You ran out of fuel and are stranded in space!\n");
                hull = 0; // game over
            }
            else
            {
                // randomly generate events during warp
                int event = rand() % 3; // 3 events: empty, asteroid, friendly ship

                switch (event)
                {
                    case 0: // empty space
                        printf("You safely warp to the next planet.\n");
                        break;
                    case 1: // asteroid
                        printf("You encounter an asteroid field!\n");
                        int damage = rand() % 51; // range from 0 to 50 hull damage
                        hull -= damage;
                        if (hull < 0) hull = 0; // prevent negative hull
                        printf("Your ship takes %d damage. Hull integrity is now %d.\n", damage, hull);
                        break;
                    case 2: // friendly ship
                        printf("You encounter a friendly ship.\n");
                        int currency = rand() % 101; // range from 0 to 100 credits
                        credits += currency;
                        printf("The other ship offers to sell you fuel for %d credits. Do you accept (Y/N)? ", distance/2);
                        char offer;
                        scanf(" %c", &offer);
                        if (offer == 'Y')
                        {
                            if (credits >= distance/2)
                            {
                                credits -= distance/2;
                                fuel += consumption;
                                printf("You purchase fuel for %d credits.\n", distance/2);
                            }
                            else
                            {
                                printf("You don't have enough credits.\n");
                            }
                        }
                        break;
                }

                // if no event happens, just warp to planet
                planet++;
            }
        }
        else if (choice == 'R')
        {
            // calculate cost of refueling
            int cost = rand() % 21 + 10; // range from 10 to 30 credits
            printf("It will cost %d credits to refuel.\n", cost);

            // handle out of credits scenario
            if (credits < cost)
            {
                printf("You don't have enough credits to refuel!\n");
            }
            else
            {
                credits -= cost;
                fuel = 50; // refill tank
            }
        }
        else
        {
            printf("Invalid choice. Please select W or R.\n");
        }

        // print status updates after user choice
        printf("Hull integrity: %d%%, Fuel level: %d, Credits: %d, Planets visited: %d.\n\n", hull, fuel, credits, planet);
    }

    // handle endgame scenarios
    if (hull == 0)
    {
        printf("Your ship exploded and you died. Game over!\n");
    }
    else if (fuel == 0)
    {
        printf("You ran out of fuel and are stranded in space! Game over.\n");
    }
    else
    {
        printf("Congratulations! You successfully visited %d planets and completed the game!\n", planet);
    }

    return 0;
}