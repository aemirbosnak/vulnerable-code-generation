//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, j, n;

    srand(time(NULL));

    printf("Welcome to the Haunted House Simulator!\n\n");
    printf("You are exploring a haunted house that is rumored to be cursed.\n");
    printf("Your mission is to find a way out of the house without being captured by the ghosts.\n\n");

    printf("Enter the size of the house (must be greater than 5 and less than 20): ");
    scanf("%d", &n);

    while(n<6 || n>19)
    {
        printf("Invalid input! Please enter a number between 6 and 19: ");
        scanf("%d", &n);
    }

    //initialize the house
    char house[n][n];
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            house[i][j] = '-';
        }
    }

    //place the ghosts randomly in the house
    int num_ghosts = n*n/8;
    for(i=0; i<num_ghosts; i++)
    {
        int x = rand() % n;
        int y = rand() % n;
        if(house[x][y] != 'G')
        {
            house[x][y] = 'G';
        }
        else
        {
            i--;
        }
    }

    //place the exit randomly in the house
    int x = rand() % n;
    int y = rand() % n;
    while(house[x][y] == 'G' || house[x][y] == 'E')
    {
        x = rand() % n;
        y = rand() % n;
    }
    house[x][y] = 'E';

    printf("\n");

    //print the initial state of the house
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%c  ", house[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    int steps = 0;
    while(1)
    {
        steps++;

        printf("Enter the coordinates of the room you want to explore (x y): ");
        scanf("%d %d", &x, &y);

        //check if the input coordinates are valid
        while(x<0 || x>=n || y<0 || y>=n)
        {
            printf("Invalid input! Please enter valid coordinates (x y): ");
            scanf("%d %d", &x, &y);
        }

        //check if the room has already been explored
        if(house[x][y] == 'X')
        {
            printf("You have already explored this room. Please enter new coordinates (x y).\n\n");
            continue;
        }

        //check if the room has a ghost
        if(house[x][y] == 'G')
        {
            printf("Oh no! You have been captured by a ghost and lost the game.\n");
            break;
        }

        //explore the room
        house[x][y] = 'X';

        //print the current state of the house
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                printf("%c  ", house[i][j]);
            }
            printf("\n");
        }
        printf("\n");

        //check if the exit has been found
        if(house[x][y] == 'E')
        {
            printf("Congratulations! You have found the exit and won the game in %d steps!\n", steps);
            break;
        }
    }

    return 0;
}