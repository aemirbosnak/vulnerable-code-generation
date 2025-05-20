//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void haunted_house(int floor)
{
    int i;
    char sound[20];

    // Play a random sound
    srand(time(NULL));
    i = rand() % 3;
    switch (i)
    {
        case 0:
            sound[0] = 'A';
            break;
        case 1:
            sound[0] = 'B';
            break;
        case 2:
            sound[0] = 'C';
            break;
    }

    // Increase floor number if going upstairs
    if (floor < 5)
    {
        floor++;
        haunted_house(floor);
    }

    // Create a spooky atmosphere
    printf("You are on floor %d.\n", floor);
    printf("The smell of decay fills the air.\n");
    printf("You hear a rustling sound in the hallway.\n");
    printf("Suddenly, you hear a %s.\n", sound);
    printf("Do you want to continue exploring?\n");

    // Get user input
    char answer;
    scanf(" %c", &answer);

    // If the user wants to continue, go to the next floor
    if (answer == 'Y')
    {
        haunted_house(floor);
    }
    else
    {
        printf("You flee the haunted house.\n");
    }
}

int main()
{
    haunted_house(1);

    return 0;
}