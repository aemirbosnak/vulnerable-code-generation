//FormAI DATASET v1.0 Category: Weather simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to our weather simulation program!\n");
    printf("Enter a number between 1 and 12 to simulate the month: ");

    int month;
    scanf("%d", &month);

    // only allow valid input for month
    while (month < 1 || month > 12)
    {
        printf("Invalid input, please enter a number between 1 and 12: ");
        scanf("%d", &month);
    }

    // initialize random seed
    srand(time(NULL));

    // calculate random temperature and precipitation
    int temperature = rand() % 61 - 30;
    int precipitation = rand() % 101;

    // display weather information based on month and random data
    printf("For the month of ");

    switch (month)
    {
        case 1:
            printf("January");
            printf(", expect an average temperature of %d degrees Celsius", temperature);
            if (precipitation < 20)
            {
                printf(", with mostly clear skies.\n");
            }
            else if (precipitation < 70)
            {
                printf(", with a chance of light rain or snow showers.\n");
            }
            else
            {
                printf(", with heavy snow or rain expected.\n");
            }
            break;
        case 2:
            printf("February");
            printf(", expect an average temperature of %d degrees Celsius", temperature);
            if (precipitation < 20)
            {
                printf(", with mostly clear skies.\n");
            }
            else if (precipitation < 70)
            {
                printf(", with a chance of light rain or snow showers.\n");
            }
            else
            {
                printf(", with heavy snow or rain expected.\n");
            }
            break;
        case 3:
            printf("March");
            printf(", expect an average temperature of %d degrees Celsius", temperature);
            if (precipitation < 20)
            {
                printf(", with mostly clear skies.\n");
            }
            else if (precipitation < 70)
            {
                printf(", with a chance of light rain or snow showers.\n");
            }
            else
            {
                printf(", with heavy snow or rain expected.\n");
            }
            break;
        case 4:
            printf("April");
            printf(", expect an average temperature of %d degrees Celsius", temperature);
            if (precipitation < 20)
            {
                printf(", with mostly clear skies.\n");
            }
            else if (precipitation < 70)
            {
                printf(", with a chance of light rain or snow showers.\n");
            }
            else
            {
                printf(", with heavy rain or thunderstorms expected.\n");
            }
            break;
        case 5:
            printf("May");
            printf(", expect an average temperature of %d degrees Celsius", temperature);
            if (precipitation < 20)
            {
                printf(", with mostly clear skies.\n");
            }
            else if (precipitation < 70)
            {
                printf(", with a chance of light rain or thunderstorms.\n");
            }
            else
            {
                printf(", with heavy rain or thunderstorms expected.\n");
            }
            break;
        case 6:
            printf("June");
            printf(", expect an average temperature of %d degrees Celsius", temperature);
            if (precipitation < 50)
            {
                printf(", with mostly clear skies.\n");
            }
            else
            {
                printf(", with occasional rain or thunderstorms.\n");
            }
            break;
        case 7:
            printf("July");
            printf(", expect an average temperature of %d degrees Celsius", temperature);
            if (precipitation < 50)
            {
                printf(", with mostly clear skies.\n");
            }
            else
            {
                printf(", with occasional rain or thunderstorms.\n");
            }
            break;
        case 8:
            printf("August");
            printf(", expect an average temperature of %d degrees Celsius", temperature);
            if (precipitation < 50)
            {
                printf(", with mostly clear skies.\n");
            }
            else
            {
                printf(", with occasional rain or thunderstorms.\n");
            }
            break;
        case 9:
            printf("September");
            printf(", expect an average temperature of %d degrees Celsius", temperature);
            if (precipitation < 20)
            {
                printf(", with mostly clear skies.\n");
            }
            else if (precipitation < 70)
            {
                printf(", with a chance of light rain or thunderstorms.\n");
            }
            else
            {
                printf(", with heavy rain or thunderstorms expected.\n");
            }
            break;
        case 10:
            printf("October");
            printf(", expect an average temperature of %d degrees Celsius", temperature);
            if (precipitation < 20)
            {
                printf(", with mostly clear skies.\n");
            }
            else if (precipitation < 70)
            {
                printf(", with a chance of light rain or snow showers.\n");
            }
            else
            {
                printf(", with heavy rain or snow expected.\n");
            }
            break;
        case 11:
            printf("November");
            printf(", expect an average temperature of %d degrees Celsius", temperature);
            if (precipitation < 20)
            {
                printf(", with mostly clear skies.\n");
            }
            else if (precipitation < 70)
            {
                printf(", with a chance of light rain or snow showers.\n");
            }
            else
            {
                printf(", with heavy snow or rain expected.\n");
            }
            break;
        case 12:
            printf("December");
            printf(", expect an average temperature of %d degrees Celsius", temperature);
            if (precipitation < 20)
            {
                printf(", with mostly clear skies.\n");
            }
            else if (precipitation < 70)
            {
                printf(", with a chance of light rain or snow showers.\n");
            }
            else
            {
                printf(", with heavy snow or rain expected.\n");
            }
            break;
    }

    return 0;
}