//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

void change_shape(int);

int main()
{
    int choice;
    int shape_change = 0;

    printf("You are a mysterious creature with the ability to shift shape. You find yourself in a strange place.\n");

    while (shape_change == 0)
    {
        printf("What do you want to do? (1) Transform, (2) Explore, (3) Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                change_shape(1);
                break;
            case 2:
                printf("You explore the surroundings and find a hidden treasure.\n");
                break;
            case 3:
                printf("You decide to leave the place.\n");
                shape_change = 1;
                break;
            default:
                printf("Invalid input.\n");
        }
    }

    return 0;
}

void change_shape(int shape)
{
    switch (shape)
    {
        case 1:
            printf("You transform into a mighty lion.\n");
            break;
        case 2:
            printf("You transform into a swift hawk.\n");
            break;
        case 3:
            printf("You transform into a cunning fox.\n");
            break;
        default:
            printf("Invalid shape.\n");
    }
}