//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DAYS_IN_WEEK 7
#define HOURS_IN_DAY 24
#define MINUTES_IN_HOUR 60
#define SECONDS_IN_MINUTE 60
#define MILLISECONDS_IN_SECOND 1000

// Function Prototypes
void generateWeather(int *weather);
void printWeather(int weather);

int main()
{
    int weather[DAYS_IN_WEEK];
    int i, j;
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);

    for (i = 0; i < DAYS_IN_WEEK; i++)
    {
        generateWeather(&weather[i]);
    }

    for (i = 0; i < DAYS_IN_WEEK; i++)
    {
        printf("Day %d:\n", i + 1);
        for (j = 0; j < HOURS_IN_DAY; j++)
        {
            printf("%02d:%02d:%02d - ", tm_info->tm_hour, tm_info->tm_min, tm_info->tm_sec);
            printWeather(weather[i]);
            printf("\n");
            tm_info->tm_hour++;
            if (tm_info->tm_hour >= HOURS_IN_DAY)
            {
                tm_info->tm_hour = 0;
            }
        }
        printf("\n\n");
    }

    return 0;
}

void generateWeather(int *weather)
{
    int temperature;
    int humidity;
    int precipitation;
    int windSpeed;

    temperature = rand() % 101;
    humidity = rand() % 101;
    precipitation = rand() % 101;
    windSpeed = rand() % 101;

    *weather = (temperature << 24) | (humidity << 16) | (precipitation << 8) | windSpeed;
}

void printWeather(int weather)
{
    int temperature;
    int humidity;
    int precipitation;
    int windSpeed;

    temperature = (weather >> 24) & 0xFF;
    humidity = (weather >> 16) & 0xFF;
    precipitation = (weather >> 8) & 0xFF;
    windSpeed = weather & 0xFF;

    printf("Temperature: %d°C\n", temperature);
    printf("Humidity: %d%%\n", humidity);
    printf("Precipitation: %d%%\n", precipitation);
    printf("Wind Speed: %d km/h\n", windSpeed);
}