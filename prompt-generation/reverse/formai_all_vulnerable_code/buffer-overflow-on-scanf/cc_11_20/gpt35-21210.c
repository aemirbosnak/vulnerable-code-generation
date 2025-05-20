//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // initialize values
    int distance = 100;
    int energy = 100;
    int oxygen = 100;
    int aliens = 0;
    int fuel = 0;
    int choice = 0;
    int random_event = 0;

    // seed random number generator
    srand( time(NULL) );

    // introduction
    printf("Welcome to Procedural Space Adventure!\n");
    printf("Your mission is to travel to the planet Zargalon and retrieve precious resources for your home planet.\n\n");

    // game loop
    while(distance > 0 && energy > 0 && oxygen > 0)
    {
        // print current status
        printf("Current status:\n");
        printf("Distance to Zargalon: %d\n", distance);
        printf("Energy level: %d\n", energy);
        printf("Oxygen level: %d\n", oxygen);
        printf("%d alien encounters successfully fought off\n", aliens);
        printf("%d units of fuel collected\n\n", fuel);

        // prompt for action
        printf("What do you want to do?\n");
        printf("1. Travel to Zargalon\n");
        printf("2. Search for fuel\n");
        printf("3. Rest and recharge\n");
        printf("4. Check surroundings\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        printf("\n");

        // handle player choice
        switch(choice)
        {
            case 1:
                // travel to Zargalon
                distance -= 20;
                energy -= 10;
                oxygen -= 10;

                // randomly determine if there is an alien encounter
                random_event = rand() % 10;
                if(random_event < 3)
                {
                    printf("You encounter an alien spacecraft!\n");
                    printf("Do you want to fight (1) or flee (2)? ");
                    scanf("%d", &choice);
                    printf("\n");

                    if(choice == 1)
                    {
                        printf("You successfully fight off the alien spacecraft and continue on your journey.\n\n");
                        aliens++;
                    }
                    else
                    {
                        printf("You are unsuccessful in fleeing and suffer damage to your ship. You continue on your journey.\n\n");
                        energy -= 20;
                    }
                }
                else
                {
                    printf("You travel to Zargalon successfully.\n\n");
                }

                break;

            case 2:
                // search for fuel
                energy -= 5;
                oxygen -= 5;

                // randomly determine amount of fuel found
                random_event = rand() % 4;
                if(random_event == 0)
                {
                    printf("You find a large deposit of fuel! You collect 10 units.\n\n");
                    fuel += 10;
                }
                else
                {
                    printf("You search but are unable to find any fuel.\n\n");
                }

                break;

            case 3:
                // rest and recharge
                energy += 20;
                oxygen += 20;

                // cap energy and oxygen levels at 100
                if(energy > 100) energy = 100;
                if(oxygen > 100) oxygen = 100;

                printf("You rest and recharge your ship's systems.\n\n");

                break;

            case 4:
                // check surroundings
                energy -= 5;
                oxygen -= 5;

                // randomly determine if there is an alien encounter
                random_event = rand() % 10;
                if(random_event < 2)
                {
                    printf("You encounter an alien lifeform!\n");
                    printf("Do you want to study it (1) or capture it (2)? ");
                    scanf("%d", &choice);
                    printf("\n");

                    if(choice == 1)
                    {
                        printf("You learn valuable information about the alien lifeform and continue on your journey.\n\n");
                    }
                    else
                    {
                        printf("You successfully capture the alien lifeform and bring it aboard your ship. It will be studied by scientists on your home planet.\n\n");
                    }
                }
                else
                {
                    printf("You do not find anything of interest.\n\n");
                }

                break;

            default:
                // invalid choice
                printf("Invalid choice. Please try again.\n\n");

                break;
        }
    }

    // determine game outcome
    if(distance <= 0)
    {
        printf("Congratulations! You have successfully reached Zargalon and collected the precious resources you needed.\n");
        printf("You return home to your planet a hero!\n");
    }
    else if(energy <= 0)
    {
        printf("Your ship's energy levels have run too low. You drift aimlessly in space and slowly succumb to the void.\n");
    }
    else if(oxygen <= 0)
    {
        printf("Your oxygen levels have dropped to critical levels. You slowly suffocate in the vacuum of space.\n");
    }

    return 0;
}