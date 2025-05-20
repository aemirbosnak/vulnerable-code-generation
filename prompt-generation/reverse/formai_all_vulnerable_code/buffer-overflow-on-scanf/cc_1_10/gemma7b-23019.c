//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void haunting_sounds(int);
void ghostly_presence(int);

int main()
{
    int choice;
    int spooky_meter = 0;

    printf("Enter the haunted house number: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            haunting_sounds(1);
            ghostly_presence(1);
            break;
        case 2:
            haunting_sounds(2);
            ghostly_presence(2);
            break;
        default:
            printf("Invalid haunted house number!\n");
    }

    printf("Thank you for visiting the haunted house!\n");

    return 0;
}

void haunting_sounds(int floor)
{
    switch (floor)
    {
        case 1:
            printf("Sounds of footsteps on the first floor...\n");
            break;
        case 2:
            printf("Sounds of whispers and creaking floorboards on the second floor...\n");
            break;
        default:
            printf("No sounds of haunting.\n");
    }
}

void ghostly_presence(int floor)
{
    switch (floor)
    {
        case 1:
            printf("A ghostly figure appears on the first floor...\n");
            break;
        case 2:
            printf("A ghostly voice whispers secrets in your ear on the second floor...\n");
            break;
        default:
            printf("No ghostly presence.\n");
    }
}