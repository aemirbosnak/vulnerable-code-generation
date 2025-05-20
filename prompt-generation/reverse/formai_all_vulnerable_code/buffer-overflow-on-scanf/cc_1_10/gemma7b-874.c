//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void haunted_house(int floor_num)
{
    int i, j, k;
    time_t t;

    t = time(NULL);
    srand(t);

    // Create a spooky atmosphere
    for (i = 0; i < floor_num; i++)
    {
        for (j = 0; j < 10; j++)
        {
            for (k = 0; k < 10; k++)
            {
                printf("%c", rand() % 32 + 65);
            }
            printf("\n");
        }
    }

    // Make the ghosts appear
    for (i = 0; i < floor_num; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("Ghostly figure appears!\n");
            sleep(rand() % 2);
        }
    }

    // Leave the haunted house
    printf("You have escaped the haunted house!\n");
}

int main()
{
    int floor_num;

    printf("Enter the number of floors you want to explore: ");
    scanf("%d", &floor_num);

    haunted_house(floor_num);

    return 0;
}