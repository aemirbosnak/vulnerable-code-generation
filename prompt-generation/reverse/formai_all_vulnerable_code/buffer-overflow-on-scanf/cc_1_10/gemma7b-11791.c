//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void haunted_house(int floor, int room)
{
    int i, j, choice;

    // Create a haunted atmosphere
    srand(time(NULL));
    printf("You are on the %d floor of the haunted house.\n", floor);
    printf("There are %d rooms on this floor.\n", room);

    // Randomly choose a room
    i = rand() % room;

    // Enter the room
    printf("You have entered room %d.\n", i);

    // Check if the room is haunted
    if (rand() % 2 == 0)
    {
        // The room is haunted
        printf("The room is haunted. You hear voices and see ghostly figures.\n");
    }
    else
    {
        // The room is not haunted
        printf("The room is not haunted. You feel safe.\n");
    }

    // Recursively call the haunted_house function
    if (floor < 5)
    {
        printf("Do you want to go to the next floor? (Y/N): ");
        scanf("%c", &choice);

        if (choice == 'Y')
        {
            haunted_house(floor + 1, room);
        }
    }
    else
    {
        // You have reached the top floor
        printf("You have reached the top floor of the haunted house. You feel a sense of relief.\n");
    }
}

int main()
{
    haunted_house(1, 10);

    return 0;
}