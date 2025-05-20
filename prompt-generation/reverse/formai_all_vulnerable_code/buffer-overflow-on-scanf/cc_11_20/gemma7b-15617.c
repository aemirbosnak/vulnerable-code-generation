//Gemma-7B DATASET v1.0 Category: Weather simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, j, n, t, r, c, f;
    char ch;

    printf("Press 's' to start the storm, 'a' for a gentle breeze, or 'h' for a hurricane:\n");
    scanf("%c", &ch);

    switch (ch)
    {
        case 's':
            n = 50;
            break;
        case 'a':
            n = 20;
            break;
        case 'h':
            n = 80;
            break;
        default:
            printf("Invalid input.\n");
            return 1;
    }

    printf("Creating the storm...\n");
    for (t = 0; t < n; t++)
    {
        r = rand() % 3;
        c = rand() % 2;
        f = rand() % 4;

        switch (r)
        {
            case 0:
                printf("Thunderstorm!\n");
                break;
            case 1:
                printf("Rain!\n");
                break;
            case 2:
                printf("Snow!\n");
                break;
        }

        switch (c)
        {
            case 0:
                printf("Gentle wind.\n");
                break;
            case 1:
                printf("Strong wind.\n");
                break;
        }

        switch (f)
        {
            case 0:
                printf("Clear sky.\n");
                break;
            case 1:
                printf("Clouds.\n");
                break;
            case 2:
                printf("Fog.\n");
                break;
        }
    }

    printf("The storm has passed.\n");

    return 0;
}