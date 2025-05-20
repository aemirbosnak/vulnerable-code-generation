//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print out the welcome message
void printWelcome()
{
    printf("Welcome to the Haunted House simulator!\n");
    printf("You are walking towards a large, old mansion.\n");
    printf("As you get closer, you hear strange noises and see the windows glowing ominously.\n");
    printf("Do you dare to enter? (y/n)\n");
}

// Function to generate a random number between min and max
int getRandomNumber(int min, int max)
{
    srand(time(NULL));
    return rand() % (max - min + 1) + min;
}

// Function to simulate a spooky event
void spookyEvent()
{
    int event = getRandomNumber(1, 5);

    switch (event)
    {
        case 1:
            printf("You hear footsteps coming from the attic...\n");
            break;
        case 2:
            printf("The lights start flickering...\n");
            break;
        case 3:
            printf("You feel a cold breath on your neck...\n");
            break;
        case 4:
            printf("You see a shadowy figure in the corner of your eye...\n");
            break;
        case 5:
            printf("You hear a loud scream...\n");
            break;
        default:
            printf("Error: Invalid event!\n");
            break;
    }
}

int main()
{
    char answer;
    int count = 0;

    printWelcome();

    // Loop until the user decides not to continue
    while (1)
    {
        scanf(" %c", &answer);

        if (answer == 'n')
        {
            printf("You decide not to enter the haunted house. Good choice!\n");
            return 0;
        }
        else if (answer == 'y')
        {
            printf("You enter the haunted house...\n");

            while (1)
            {
                printf("You are in the hallway. There are 3 doors. Which one do you want to open? (1/2/3)\n");
                scanf(" %c", &answer);

                if (answer == '1')
                {
                    printf("You open the door and enter the room...\n");
                    spookyEvent();
                    count++;

                    if (count == 3)
                    {
                        printf("You found the key to the exit!\n");
                        break;
                    }
                }
                else if (answer == '2')
                {
                    printf("You open the door and enter the bathroom...\n");
                    spookyEvent();
                }
                else if (answer == '3')
                {
                    printf("You open the door and enter the kitchen...\n");
                    spookyEvent();
                }
                else
                {
                    printf("Invalid input. Try again.\n");
                }
            }

            printf("Congratulations! You made it out of the haunted house in one piece!\n");
            return 0;
        }
        else
        {
            printf("Invalid input. Try again.\n");
        }
    }
}