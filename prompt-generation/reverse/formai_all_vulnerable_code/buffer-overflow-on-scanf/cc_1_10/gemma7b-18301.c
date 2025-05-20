//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int choice, i, j;
    char name[20];

    // Intro
    printf("Welcome to the futuristic haunted house of Morbus Prime!\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    // Choose a room
    printf("Please choose a room number: ");
    scanf("%d", &choice);

    // Room selection
    switch (choice)
    {
        case 1:
            printf("You have chosen the Electric Chamber.\n");
            break;
        case 2:
            printf("You have chosen the Bloodstained Corridor.\n");
            break;
        case 3:
            printf("You have chosen the Phantom Library.\n");
            break;
        default:
            printf("Invalid room number.\n");
    }

    // Atmosphere creation
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf("%c ", rand() % 2);
        }
        printf("\n");
    }

    // Haunted event
    switch (rand() % 3)
    {
        case 0:
            printf("A ghostly figure whispers your name.\n");
            break;
        case 1:
            printf("The lights flicker and the air turns cold.\n");
            break;
        case 2:
            printf("You hear footsteps in the hallway.\n");
            break;
    }

    // Conclusion
    printf("Thank you for visiting Morbus Prime. We hope you enjoyed your stay.\n");

    return 0;
}