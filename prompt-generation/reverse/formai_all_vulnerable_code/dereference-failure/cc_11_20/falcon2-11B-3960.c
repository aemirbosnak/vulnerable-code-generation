//Falcon2-11B DATASET v1.0 Category: Weather simulation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DAYS_PER_YEAR 365
#define DAYS_PER_WEEK 7

int main(int argc, char *argv[])
{
    if (argc!= 2)
    {
        printf("Usage: %s <number_of_years>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int years = atoi(argv[1]);
    int days = DAYS_PER_YEAR * years;
    int weeks = days / DAYS_PER_WEEK;
    days = days % DAYS_PER_WEEK;

    int i;
    for (i = 0; i < weeks; i++)
    {
        printf("Week %d:\n", i + 1);
        for (int j = 0; j < DAYS_PER_WEEK; j++)
        {
            int r = rand() % 100 + 50;
            if (j == 5) // Sunday
            {
                r += 5;
            }
            else if (j == 6) // Monday
            {
                r += 5;
            }
            else if (j == 7) // Tuesday
            {
                r += 5;
            }
            else if (j == 8) // Wednesday
            {
                r += 5;
            }
            else if (j == 9) // Thursday
            {
                r += 5;
            }
            else if (j == 0) // Friday
            {
                r += 5;
            }
            else if (j == 1) // Saturday
            {
                r += 5;
            }

            if (r < 10)
            {
                printf("It's a sunny day!\n");
            }
            else if (r >= 10 && r < 20)
            {
                printf("It's a cloudy day.\n");
            }
            else if (r >= 20 && r < 30)
            {
                printf("It's a rainy day.\n");
            }
            else if (r >= 30)
            {
                printf("It's a stormy day.\n");
            }
        }
        printf("\n");
    }
    printf("End of simulation.\n");

    return 0;
}