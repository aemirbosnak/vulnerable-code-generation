//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int x1, y1, x2, y2, choice, direction;
    printf("Welcome to GPS Navigation Simulation!\n");
    printf("Enter the starting coordinates (x y): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter the destination coordinates (x y): ");
    scanf("%d %d", &x2, &y2);

    srand(time(NULL)); // to generate random direction
    direction = rand() % 4 + 1; // 1 - North, 2 - East, 3 - South, 4 - West

    printf("\nCalculating the best route...\n");
    printf("Press 1 to see the route or 2 to display the simulation: ");
    scanf("%d", &choice);

    if(choice == 1)
    {
        printf("\nRoute:\n");
        printf("(%d, %d) -> ", x1, y1);
        if(y2 > y1)
        {
            printf("(%d, %d) -> ", x1, y2);
            if(x2 > x1)
                printf("(%d, %d)\n", x2, y2);
            else
                printf("(%d, %d)\n", x1, y2);
        }
        else if(y1 > y2)
        {
            printf("(%d, %d) -> ", x1, y2);
            if(x2 > x1)
                printf("(%d, %d)\n", x2, y2);
            else
                printf("(%d, %d)\n", x1, y2);
        }
        else
        {
            if(x2 > x1)
                printf("(%d, %d)\n", x2, y2);
            else
                printf("(%d, %d)\n", x1, y2);
        }
    }
    else if(choice == 2)
    {
        printf("\nSimulation:\n");
        printf("(%d, %d) -> ", x1, y1);
        while(x1 != x2 || y1 != y2)
        {
            if(direction == 1)
            {
                y1 += 1;
                printf("(%d, %d) -> ", x1, y1);
                if(y1 == y2)
                {
                    if(x2 > x1)
                    {
                        x1 += 1;
                        printf("(%d, %d) -> ", x1, y1);
                    }
                    else if(x1 > x2)
                    {
                        x1 -= 1;
                        printf("(%d, %d) -> ", x1, y1);
                    }
                    else
                        printf("(%d, %d)\n", x1, y2);
                }
            }
            else if(direction == 2)
            {
                x1 += 1;
                printf("(%d, %d) -> ", x1, y1);
                if(x1 == x2)
                {
                    if(y2 > y1)
                    {
                        y1 += 1;
                        printf("(%d, %d) -> ", x1, y1);
                    }
                    else if(y1 > y2)
                    {
                        y1 -= 1;
                        printf("(%d, %d) -> ", x1, y1);
                    }
                    else
                        printf("(%d, %d)\n", x2, y1);
                }
            }
            else if(direction == 3)
            {
                y1 -= 1;
                printf("(%d, %d) -> ", x1, y1);
                if(y1 == y2)
                {
                    if(x2 > x1)
                    {
                        x1 += 1;
                        printf("(%d, %d) -> ", x1, y1);
                    }
                    else if(x1 > x2)
                    {
                        x1 -= 1;
                        printf("(%d, %d) -> ", x1, y1);
                    }
                    else
                        printf("(%d, %d)\n", x1, y2);
                }
            }
            else
            {
                x1 -= 1;
                printf("(%d, %d) -> ", x1, y1);
                if(x1 == x2)
                {
                    if(y2 > y1)
                    {
                        y1 += 1;
                        printf("(%d, %d) -> ", x1, y1);
                    }
                    else if(y1 > y2)
                    {
                        y1 -= 1;
                        printf("(%d, %d) -> ", x1, y1);
                    }
                    else
                        printf("(%d, %d)\n", x2, y1);
                }
            }
            direction = rand() % 4 + 1; // update direction
        }
    }
    else
        printf("\nInvalid choice!\n");

    return 0;
}