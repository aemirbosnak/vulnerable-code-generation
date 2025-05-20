//FormAI DATASET v1.0 Category: Weather simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int temperature, humidity;

    // get user input for temperature and humidity
    printf("Enter temperature (in Celsius): ");
    scanf("%d", &temperature);

    printf("Enter humidity (in percentage): ");
    scanf("%d", &humidity);

    // seed the random number generator with system time
    srand(time(NULL));

    // generate random wind speed and direction
    int wind_speed = rand() % 71;    // max wind speed is 70 km/h
    int wind_direction = rand() % 360;    // wind direction in degrees

    printf("\nWeather conditions:\n");
    printf("--------------------\n");

    // print temperature condition
    if (temperature >= 35)
        printf("It's extremely hot!\n");
    else if (temperature >= 30)
        printf("It's very hot!\n");
    else if (temperature >= 20)
        printf("It's warm\n");
    else if (temperature >= 10)
        printf("It's chilly\n");
    else
        printf("It's very cold!\n");

    // print humidity condition
    if (humidity >= 80)
        printf("It's very humid\n");
    else if (humidity >= 60)
        printf("It's moderately humid\n");
    else
        printf("It's dry\n");

    // print wind condition
    if (wind_speed >= 60)
        printf("There's a hurricane!\n");
    else if (wind_speed >= 30)
        printf("There's a gale\n");
    else if (wind_speed >= 10)
        printf("There's a breeze\n");
    else
        printf("There's calm\n");

    // print wind direction
    printf("Wind direction: %d degrees\n", wind_direction);

    return 0;
}