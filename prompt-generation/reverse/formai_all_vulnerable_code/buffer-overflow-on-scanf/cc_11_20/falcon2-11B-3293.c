//Falcon2-11B DATASET v1.0 Category: Procedural Space Adventure ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to the Space Adventure Game!\n");
    printf("You are in a spaceship, and your mission is to explore the galaxy.\n");
    printf("You have three options:\n");
    printf("1. Go to planet 1\n");
    printf("2. Go to planet 2\n");
    printf("3. Go to planet 3\n");
    
    int choice;
    printf("Enter your choice (1, 2, or 3): ");
    scanf("%d", &choice);
    
    switch(choice)
    {
        case 1:
            printf("You have arrived at planet 1!\n");
            printf("The planet is full of aliens, what will you do?\n");
            printf("1. Fight the aliens\n");
            printf("2. Make peace with the aliens\n");
            printf("3. Leave the planet\n");
            int choice2;
            printf("Enter your choice (1, 2, or 3): ");
            scanf("%d", &choice2);
            switch(choice2)
            {
                case 1:
                    printf("You have chosen to fight the aliens.\n");
                    printf("You have won the battle!\n");
                    break;
                case 2:
                    printf("You have chosen to make peace with the aliens.\n");
                    printf("The aliens have accepted you as their friend.\n");
                    break;
                case 3:
                    printf("You have chosen to leave the planet.\n");
                    printf("You have returned to your spaceship.\n");
                    break;
                default:
                    printf("Invalid choice. Try again.\n");
            }
            break;
        case 2:
            printf("You have arrived at planet 2!\n");
            printf("The planet is full of resources, what will you do?\n");
            printf("1. Collect resources\n");
            printf("2. Leave the planet\n");
            int choice3;
            printf("Enter your choice (1 or 2): ");
            scanf("%d", &choice3);
            switch(choice3)
            {
                case 1:
                    printf("You have collected the resources.\n");
                    printf("You have returned to your spaceship.\n");
                    break;
                case 2:
                    printf("You have chosen to leave the planet.\n");
                    printf("You have returned to your spaceship.\n");
                    break;
                default:
                    printf("Invalid choice. Try again.\n");
            }
            break;
        case 3:
            printf("You have arrived at planet 3!\n");
            printf("The planet is full of mysteries, what will you do?\n");
            printf("1. Explore the mysteries\n");
            printf("2. Leave the planet\n");
            int choice4;
            printf("Enter your choice (1 or 2): ");
            scanf("%d", &choice4);
            switch(choice4)
            {
                case 1:
                    printf("You have explored the mysteries.\n");
                    printf("You have returned to your spaceship.\n");
                    break;
                case 2:
                    printf("You have chosen to leave the planet.\n");
                    printf("You have returned to your spaceship.\n");
                    break;
                default:
                    printf("Invalid choice. Try again.\n");
            }
            break;
        default:
            printf("Invalid choice. Try again.\n");
    }
    
    return 0;
}