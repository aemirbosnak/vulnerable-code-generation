//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_READING_SIZE 10

int main()
{
    char readings[MAX_READING_SIZE];
    int i, reading_size = 0, total_calories = 0;
    char environment_type;

    printf("Please select the environment type (A/C/R): ");
    scanf("%c", &environment_type);

    switch (environment_type)
    {
        case 'A':
            printf("Enter the number of readings: ");
            scanf("%d", &reading_size);

            for (i = 0; i < reading_size; i++)
            {
                printf("Enter the reading: ");
                scanf("%s", readings);

                total_calories += atoi(readings) * 2;
            }
            break;

        case 'C':
            printf("Enter the number of readings: ");
            scanf("%d", &reading_size);

            for (i = 0; i < reading_size; i++)
            {
                printf("Enter the reading: ");
                scanf("%s", readings);

                total_calories += atoi(readings) * 1.5;
            }
            break;

        case 'R':
            printf("Enter the number of readings: ");
            scanf("%d", &reading_size);

            for (i = 0; i < reading_size; i++)
            {
                printf("Enter the reading: ");
                scanf("%s", readings);

                total_calories += atoi(readings) * 1.2;
            }
            break;

        default:
            printf("Invalid environment type.");
    }

    printf("Total calories burned: %d", total_calories);

    return 0;
}