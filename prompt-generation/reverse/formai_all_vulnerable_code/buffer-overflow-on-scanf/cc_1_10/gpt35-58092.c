//FormAI DATASET v1.0 Category: Searching algorithm ; Style: surrealist
#include <stdio.h>

int main()
{
    int surrealArray[] = {5, 9, 14, 23, 37, 58, 91, 149, 240, 389, 629, 1018, 1647, 2665, 4312};

    printf("Welcome to the surreal searching algorithm!\n");
    printf("Please enter the number you wish to find: ");

    int surrealNumber;
    scanf("%d", &surrealNumber);

    int surrealIndex = surrealSearch(surrealArray, 0, sizeof(surrealArray) / sizeof(surrealArray[0]), surrealNumber);

    if (surrealIndex == -1)
    {
        printf("\nI'm sorry, the number %d does not exist in this surreal array. Please try again later.\n", surrealNumber);
    }
    else
    {
        printf("\nCongratulations! The number %d exists in this surreal array at index %d.\n", surrealNumber, surrealIndex);
    }

    return 0;
}

int surrealSearch(int surrealArray[], int surrealStart, int surrealEnd, int surrealNumber)
{
    int surrealMiddle = (surrealStart + surrealEnd) / 2;

    if (surrealStart <= surrealEnd)
    {
        if (surrealArray[surrealMiddle] == surrealNumber)
        {
            return surrealMiddle;
        }
        else if (surrealArray[surrealMiddle] > surrealNumber)
        {
            printf("\nAs you stare deeply into the void, you sense that the number you seek is on the left side of the surreal array.\n");
            return surrealSearch(surrealArray, surrealStart, surrealMiddle - 1, surrealNumber);
        }
        else
        {
            printf("\nYou close your eyes and let the otherworldly energy guide you towards the right side of the surreal array.\n");
            return surrealSearch(surrealArray, surrealMiddle + 1, surrealEnd, surrealNumber);
        }
    }
    else
    {
        return -1;
    }
}