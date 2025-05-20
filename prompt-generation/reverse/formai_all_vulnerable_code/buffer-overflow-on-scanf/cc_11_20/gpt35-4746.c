//FormAI DATASET v1.0 Category: Temperature monitor ; Style: minimalist
#include <stdio.h>
#include <stdbool.h>

#define MAX_TEMP 100
#define MIN_TEMP -273

int main()
{
    int temperature;

    printf("Welcome to the temperature monitor!\n");

    do{
        printf("Enter the current temperature: ");
        scanf("%d", &temperature);

        if (temperature < MIN_TEMP)
        {
            printf("Invalid temperature entered! The temperature cannot be lower than absolute zero (-273C).\n");
            continue;
        }
        else if (temperature > MAX_TEMP)
        {
            printf("Invalid temperature entered! The temperature cannot exceed 100C.\n");
            continue;
        }

        if (temperature <= 0)
        {
            printf("It's freezing cold!\n");
        }
        else if (temperature > 0 && temperature <= 20)
        {
            printf("It's cold today\n");
        }
        else if (temperature > 20 && temperature <= 30)
        {
            printf("The temperature is just right today\n");
        }
        else if (temperature > 30 && temperature <= 40)
        {
            printf("It's pretty warm today\n");
        }
        else if (temperature > 40 && temperature <= 100)
        {
            printf("It's scorching hot today!\n");
        }
    } while (true);

    return 0;
}