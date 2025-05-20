//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: grateful
#include <stdio.h>

// Function to check if input is valid
int isValidInput(int input)
{
    if (input == 1 || input == 2)
    {
        return 1;
    }
    else
    {
        printf("Invalid input. Please enter 1 or 2.\n");
        return 0;
    }
}

int main()
{
    int choice;
    printf("Welcome to the Procedural Space Adventure!\n");
    printf("Choose your adventure:\n");
    printf("1. Explore the Remnants of a Lost Civilization\n");
    printf("2. Battle against an Alien Invasion\n");

    // Get user input for game choice
    do
    {
        scanf("%d", &choice);
    } while (!isValidInput(choice));

    // Adventure 1: Explore the Remnants of a Lost Civilization
    if (choice == 1)
    {
        printf("\nYou are the captain of the spaceship 'Discovery.'\n");
        printf("Your mission is to explore the remnants of a lost civilization.\n");
        printf("As you approach the planet, a strange energy field surrounds your ship.\n");
        printf("Suddenly, your instruments go haywire!\n");
        printf("You have no choice but to crash-land on the planet.\n");
        printf("As you explore the ruins of the civilization, you discover something incredible -\n");
        printf("a portal to a different dimension!\n");
        printf("Do you take the risk and enter the portal? (1 for Yes / 2 for No)\n");

        // Get user input for portal choice
        do
        {
            scanf("%d", &choice);
        } while (!isValidInput(choice));

        if (choice == 1)
        {
            printf("\nYou enter the portal and find yourself in an alternate universe.\n");
            printf("The technology and knowledge of the civilization here are far more advanced,\n");
            printf("and you realize that this other dimension holds the key to saving your own universe.\n");
            printf("Armed with your spaceship and newfound knowledge, you set off to save your universe from destruction.\n");
            printf("Good luck!\n");
        }
        else
        {
            printf("\nYou decide to play it safe and leave the portal alone.\n");
            printf("As you continue to explore the ruins, you come across an ancient weapon -\n");
            printf("one that could change the course of your journey and the fate of your universe.\n");
            printf("Do you take the weapon with you? (1 for Yes / 2 for No)\n");

            // Get user input for weapon choice
            do
            {
                scanf("%d", &choice);
            } while (!isValidInput(choice));

            if (choice == 1)
            {
                printf("\nYou take the weapon and continue your exploration.\n");
                printf("As you leave the planet, you encounter the alien invaders.\n");
                printf("With the ancient weapon in your possession, you are able to defeat the invaders and save your universe.\n");
                printf("Congratulations on a successful mission!\n");
            }
            else
            {
                printf("\nYou decide to leave the weapon behind.\n");
                printf("As you leave the planet, you encounter the alien invaders.\n");
                printf("Without the weapon, you are unable to defeat the invaders and your universe falls.\n");
                printf("Game over. Please try again.\n");
            }
        }
    }
    // Adventure 2: Battle against an Alien Invasion
    else
    {
        printf("\nYou are the captain of the spaceship 'Odyssey.'\n");
        printf("Your mission is to defend the planet against an alien invasion.\n");
        printf("As the alien ships approach, you activate your weapons system and prepare for battle.\n");
        printf("You engage in a fierce battle against the alien ships, dodging their laser beams and firing back with your own weapons.\n");
        printf("As the battle rages on, you discover a weakness in the alien ships.\n");
        printf("Do you exploit their weakness and try to defeat them? (1 for Yes / 2 for No)\n");

        // Get user input for exploiting weakness choice
        do
        {
            scanf("%d", &choice);
        } while (!isValidInput(choice));

        if (choice == 1)
        {
            printf("\nYou exploit the weakness and are able to defeat the alien ships.\n");
            printf("As you survey the aftermath of the battle, you discover an alien artifact which could change the course of humanity.\n");
            printf("Do you take the artifact with you? (1 for Yes / 2 for No)\n");

            // Get user input for artifact choice
            do
            {
                scanf("%d", &choice);
            } while (!isValidInput(choice));

            if (choice == 1)
            {
                printf("\nYou take the artifact and return to the planet victorious.\n");
                printf("The artifact proves to be a highly advanced piece of technology,\n");
                printf("which brings about a new era of prosperity for humanity.\n");
                printf("Congratulations on a successful mission!\n");
            }
            else
            {
                printf("\nYou decide to leave the artifact behind.\n");
                printf("As you return to the planet, you are hailed as a hero,\n");
                printf("but without the artifact, humanity struggles to advance and faces uncertain times ahead.\n");
                printf("Game over. Please try again.\n");
            }
        }
        else
        {
            printf("\nYou decide not to exploit the weakness and continue the battle.\n");
            printf("The battle proves to be long and grueling,\n");
            printf("but with your superior tactics and firepower, you are eventually able to defeat the alien ships.\n");
            printf("As you land back on the planet, you are hailed as a hero,\n");
            printf("having saved the planet from certain destruction.\n");
            printf("Congratulations on a successful mission!\n");
        }
    }

    return 0;
}