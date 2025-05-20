//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 10
#define MAX_FUEL 100

// function prototypes
void generateMap(int map[][MAP_SIZE]);
void printMap(int map[][MAP_SIZE], int x, int y);
void movePlayer(int map[][MAP_SIZE], int *x, int *y, int *fuel);
int scanInput();

int main()
{
    int map[MAP_SIZE][MAP_SIZE];
    int playerX, playerY, fuel;
    srand(time(NULL));

    // initialize player position and fuel
    playerX = rand() % MAP_SIZE;
    playerY = rand() % MAP_SIZE;
    fuel = MAX_FUEL;

    generateMap(map);
    printMap(map, playerX, playerY);

    while (fuel > 0)
    {
        movePlayer(map, &playerX, &playerY, &fuel);
        printMap(map, playerX, playerY);
    }

    printf("Game over. You ran out of fuel.\n");

    return 0;
}

// function to randomly generate map
void generateMap(int map[][MAP_SIZE])
{
    for (int i = 0; i < MAP_SIZE; i++)
    {
        for (int j = 0; j < MAP_SIZE; j++)
        {
            int randNum = rand() % 10;
            if (randNum == 0)
            {
                map[i][j] = 1; // asteroid
            }
            else
            {
                map[i][j] = 0; // empty space
            }
        }
    }
}

// function to print the map
void printMap(int map[][MAP_SIZE], int x, int y)
{
    system("clear"); // clear the console

    for (int i = 0; i < MAP_SIZE; i++)
    {
        for (int j = 0; j < MAP_SIZE; j++)
        {
            if (i == y && j == x)
            {
                printf("O"); // player position
            }
            else if (map[i][j] == 1)
            {
                printf("*"); // asteroid
            }
            else
            {
                printf("-"); // empty space
            }
        }
        printf("\n");
    }

    printf("Fuel: %d\n", MAX_FUEL);
}

// function to move the player
void movePlayer(int map[][MAP_SIZE], int *x, int *y, int *fuel)
{
    int direction = scanInput();
    int newX = *x;
    int newY = *y;

    if (direction == 0) // up
    {
        newY--;
    }
    else if (direction == 1) // down
    {
        newY++;
    }
    else if (direction == 2) // left
    {
        newX--;
    }
    else if (direction == 3) // right
    {
        newX++;
    }

    // check if new position is within boundary
    if (newX < 0 || newX >= MAP_SIZE || newY < 0 || newY >= MAP_SIZE)
    {
        printf("You cannot move outside the map.\n");
    }
    else
    {
        // check for asteroid collision
        if (map[newY][newX] == 1)
        {
            printf("You crashed into an asteroid. Game over.\n");
            *fuel = 0;
            return;
        }

        // update player position and fuel
        *x = newX;
        *y = newY;
        (*fuel)--;
    }
}

// function to scan user input
int scanInput()
{
    char input;
    printf("Enter direction (w/a/s/d): ");
    scanf(" %c", &input);

    if (input == 'w')
    {
        return 0; // up
    }
    else if (input == 's')
    {
        return 1; // down
    }
    else if (input == 'a')
    {
        return 2; // left
    }
    else if (input == 'd')
    {
        return 3; // right
    }
    else
    {
        printf("Invalid input.\n");
        return scanInput(); // prompt user to input again
    }
}