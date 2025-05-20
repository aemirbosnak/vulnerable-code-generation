//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

void main()
{
    system("clear");
    printf("You hear a rustle in the hallway...\n");

    int choice = 0;
    printf("Enter 1 to investigate, 2 to hide, or 3 to wait: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("You cautiously approach the source of the sound, but find nothing.\n");
            break;
        case 2:
            printf("You frantically hide in a nearby closet.\n");
            break;
        case 3:
            printf("You wait for a moment, but nothing happens.\n");
            break;
        default:
            printf("Invalid input. Please try again.\n");
            break;
    }

    system("clear");
    printf("Suddenly, a loud crash echoes through the halls...\n");

    printf("Enter 1 to confront the source of the sound, 2 to flee, or 3 to barricade the door: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("You cautiously approach the source of the sound and find a masked figure standing there.\n");
            printf("The figure turns around and points a gun at you. What do you do?\n");
            break;
        case 2:
            printf("You flee, but the figure is close behind. You hear the sound of a knife being drawn. What do you do?\n");
            break;
        case 3:
            printf("You barricade the door, but the figure is able to break down the barrier and enter. What do you do?\n");
            break;
        default:
            printf("Invalid input. Please try again.\n");
            break;
    }

    system("clear");
    printf("The end.\n");
    return;
}