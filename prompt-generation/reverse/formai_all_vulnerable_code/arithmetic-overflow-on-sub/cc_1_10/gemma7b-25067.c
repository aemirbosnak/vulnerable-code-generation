//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
    int i, j, k, l, r, t, n;
    time_t start, end;
    char str[100];

    printf("Enter the number of ghosts: ");
    scanf("%d", &n);

    start = time(NULL);
    for (t = 0; t < n; t++)
    {
        printf("Ghost %d is awakening...\n", t + 1);
        sleep(rand() % 3);

        printf("Ghost %d is roaming...\n", t + 1);
        l = rand() % 10;
        r = rand() % 10;
        for (i = l; i <= r; i++)
        {
            printf("Ghost %d is moving towards room %d...\n", t + 1, i);
            sleep(rand() % 2);
        }

        printf("Ghost %d has disappeared...\n", t + 1);
        sleep(rand() % 2);
    }

    end = time(NULL);
    printf("Total time elapsed: %ld seconds\n", end - start);

    printf("Would you like to hear the stories of the ghosts? (Y/N): ");
    scanf("%s", str);

    if (str[0] == 'Y')
    {
        for (t = 0; t < n; t++)
        {
            printf("Story of Ghost %d:\n", t + 1);
            printf("Once upon a time...\n");
            sleep(rand() % 3);
            printf("The end.\n");
            sleep(rand() % 3);
        }
    }

    return;
}