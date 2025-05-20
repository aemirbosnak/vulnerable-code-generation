//Gemma-7B DATASET v1.0 Category: Time Travel Simulator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

#define MAX_CHAR 100

int main()
{
    char history[MAX_CHAR];
    int i, j, k, l, n, m;
    char name[MAX_CHAR];

    printf("Enter the name of the person you want to time travel to:");
    scanf("%s", name);

    printf("Enter the year of the event you want to travel to:");
    scanf("%d", &n);

    printf("Enter the month of the event you want to travel to:");
    scanf("%d", &m);

    printf("Enter the day of the event you want to travel to:");
    scanf("%d", &k);

    printf("Enter a brief description of the event you want to travel to:");
    scanf("%[^\n]%*c", history);

    l = 0;
    for (i = 0; history[i] != '\0'; i++)
    {
        history[l] = history[i];
        l++;
    }

    for (j = 0; name[j] != '\0'; j++)
    {
        for (i = 0; history[i] != '\0'; i++)
        {
            if (name[j] == history[i])
            {
                printf("Sorry, but that person does not exist in that time period.\n");
                return 0;
            }
        }
    }

    printf("Here is the timeline of events for %s in %d %d %d:\n", name, n, m, k);
    printf("%s\n", history);

    return 0;
}