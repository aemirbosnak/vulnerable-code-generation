//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // seed for random number generation
    int health = 100, energy = 50, credits = 0, planetChoice, taskChoice, energyChoice, prospectChance, alienChoice; // player stats
    printf("Welcome to Procedural Space Adventure!\n\n");
    printf("Your mission is to explore the galaxy and make a fortune.\n");
    while(health > 0) // game loop
    {
        printf("\nYou currently have %d health, %d energy, and %d credits.\n", health, energy, credits);
        printf("What would you like to do?\n");
        printf("1. Land on a planet\n2. Refuel your ship\n3. Prospect for resources\n4. Fight an alien\n5. Quit game\n");
        scanf("%d", &taskChoice);

        switch(taskChoice)
        {
            case 1: // landing on a planet
                printf("\nWhich planet would you like to land on?\n");
                printf("1. Luminar\n2. Valtor\n3. Azura\n");
                scanf("%d", &planetChoice);
                switch(planetChoice)
                {
                    case 1: // Luminar planet
                        printf("\nLanding on Luminar...\n");
                        energy -= 10; // decrease energy
                        prospectChance = rand()%100; // generate random number for prospecting chance
                        if(prospectChance < 50)
                        {
                            printf("You found some valuable resources on Luminar!\n");
                            credits += 50; // increase credits
                        }
                        else
                        {
                            printf("You didn't find anything of value on Luminar...\n");
                        }
                        break;
                    case 2: // Valtor planet
                        printf("\nLanding on Valtor...\n");
                        energy -= 20; // decrease energy
                        prospectChance = rand()%100; // generate random number for prospecting chance
                        if(prospectChance < 30)
                        {
                            printf("You found a rare mineral on Valtor!\n");
                            credits += 100; // increase credits
                        }
                        else
                        {
                            printf("You didn't find anything of value on Valtor...\n");
                        }
                        break;
                    case 3: // Azura planet
                        printf("\nLanding on Azura...\n");
                        energy -= 30; // decrease energy
                        prospectChance = rand()%100; // generate random number for prospecting chance
                        if(prospectChance < 10)
                        {
                            printf("You discovered a hidden cache of treasure on Azura!\n");
                            credits += 500; // increase credits
                        }
                        else
                        {
                            printf("You didn't find anything of value on Azura...\n");
                        }
                        break;
                    default:
                        printf("\nInvalid planet choice...\n");
                        break;
                }
                break;
            case 2: // refueling ship
                printf("\nHow would you like to refuel your ship?\n");
                printf("1. Solar Energy\n2. Energon Crystal\n3. Zorium Gas\n");
                scanf("%d", &energyChoice);
                switch(energyChoice)
                {
                    case 1: // solar energy
                        printf("\nRefueling with Solar Energy...\n");
                        energy += 20; // increase energy
                        break;
                    case 2: // energon crystal
                        printf("\nRefueling with Energon Crystal...\n");
                        energy += 30; // increase energy
                        break;
                    case 3: // zorium gas
                        printf("\nRefueling with Zorium Gas...\n");
                        energy += 40; // increase energy
                        break;
                    default:
                        printf("\nInvalid energy choice...\n");
                        break;
                }
                break;
            case 3: // prospecting for resources
                printf("\nProspecting for resources...\n");
                energy -= 5; // decrease energy
                prospectChance = rand()%100; // generate random number for prospecting chance
                if(prospectChance < 70)
                {
                    printf("You found some resources!\n");
                    credits += 25; // increase credits
                }
                else
                {
                    printf("You didn't find anything of value...\n");
                }
                break;
            case 4: // fighting an alien
                printf("\nFighting an alien...\n");
                energy -= 15; // decrease energy
                alienChoice = rand()%3; // generate random number for alien choice
                if(alienChoice == 1) // weak alien
                {
                    printf("You defeated a weak alien!\n");
                    credits += 50; // increase credits
                }
                else if(alienChoice == 2) // strong alien
                {
                    printf("You were defeated by a strong alien...\n");
                    health -= 20; // decrease health
                }
                else // no alien encounter
                {
                    printf("There were no aliens to fight...\n");
                }
                break;
            case 5: // quitting game
                printf("\nThanks for playing Procedural Space Adventure!\n");
                return 0;
            default:
                printf("\nInvalid task choice...\n");
                break;
        }

        if(health <= 0) // game over if player health reaches 0
        {
            printf("\nGAME OVER\n");
            printf("You ran out of health...\n");
            return 0;
        }
        if(energy <= 0) // player loses if energy reaches 0
        {
            printf("\nGAME OVER\n");
            printf("You ran out of energy...\n");
            return 0;
        }
    }
    return 0; // end of program
}