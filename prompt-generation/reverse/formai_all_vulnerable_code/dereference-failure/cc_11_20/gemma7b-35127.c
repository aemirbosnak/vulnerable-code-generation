//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, j, k;
    char ch;
    srand(time(NULL));

    // Create a haunted house
    char **house = (char**)malloc(10 * sizeof(char*));
    for(i = 0; i < 10; i++)
    {
        house[i] = (char*)malloc(20 * sizeof(char));
    }

    // Fill the house with spooky stuff
    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < 20; j++)
        {
            house[i][j] = rand() % 32 + 65;
        }
    }

    // Open the haunted house
    printf("Enter the key to unlock the haunted house: ");
    scanf("%c", &ch);

    // Check if the key is correct
    if(ch == 'H')
    {
        // The house is open
        printf("The haunted house is open. Prepare for a fright!\n");

        // Move through the house
        for(k = 0; k < 10; k++)
        {
            printf("You are in room %d. The air is thick with the smell of decay.\n", k + 1);
            printf("Suddenly, a ghostly figure appears before you. What do you do? (q/a/s/r)\n");

            // Get the user's input
            scanf(" %c", &ch);

            // Take action based on the user's input
            switch(ch)
            {
                case 'q':
                    printf("You flee the house in terror.\n");
                    break;
                case 'a':
                    printf("You attack the ghostly figure. It disappears.\n");
                    break;
                case 's':
                    printf("You scream in terror. The ghostly figure disappears.\n");
                    break;
                case 'r':
                    printf("You recite a prayer. The ghostly figure retreats.\n");
                    break;
                default:
                    printf("Invalid input.\n");
            }
        }

        // Close the house
        printf("You have escaped the haunted house. Thank you for playing.\n");
    }
    else
    {
        // The key is incorrect
        printf("Incorrect key. The haunted house remains closed.\n");
    }

    // Free the memory
    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < 20; j++)
        {
            free(house[i][j]);
        }
        free(house[i]);
    }
    free(house);

    return 0;
}