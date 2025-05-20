//Falcon2-11B DATASET v1.0 Category: Weather simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Global variables
int wind_speed = 0;
int temperature = 0;
int humidity = 0;

// Function prototypes
void read_weather_data();
void display_weather_data();
void update_weather();

int main()
{
    srand(time(NULL));

    while(1)
    {
        read_weather_data();
        display_weather_data();
        update_weather();
    }
}

void read_weather_data()
{
    printf("Enter the wind speed: ");
    scanf("%d", &wind_speed);

    printf("Enter the temperature: ");
    scanf("%d", &temperature);

    printf("Enter the humidity: ");
    scanf("%d", &humidity);
}

void display_weather_data()
{
    printf("Wind speed: %d\n", wind_speed);
    printf("Temperature: %d\n", temperature);
    printf("Humidity: %d\n", humidity);
}

void update_weather()
{
    wind_speed += (rand() % 5) - 2;

    if(wind_speed < 0)
        wind_speed = 0;

    if(temperature < 0)
        temperature = 0;

    if(temperature > 100)
        temperature = 100;

    if(humidity > 100)
        humidity = 100;
}