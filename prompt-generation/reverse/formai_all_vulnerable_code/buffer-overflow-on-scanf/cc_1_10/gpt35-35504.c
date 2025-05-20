//FormAI DATASET v1.0 Category: Weather simulation ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Function to generate a random number
int random_number(int min_num, int max_num)
{
    srand(time(NULL));
    int result = (rand() % (max_num - min_num)) + min_num;
    return result;
}

// Function to get a weather condition
char* get_weather()
{
    int num = random_number(1, 5);
    char* weather;
    switch(num)
    {
        case 1:
            weather = "Sunny";
            break;
        case 2:
            weather = "Cloudy";
            break;
        case 3:
            weather = "Rainy";
            break;
        case 4:
            weather = "Snowy";
            break;
        case 5:
            weather = "Windy";
            break;
        default:
            weather = "Unknown";
            break;
    }
    return weather;
}

// Function to get the temperature
float get_temperature()
{
    float min_temp = -5.0;
    float max_temp = 40.0;
    float temperature = (rand() / (float)RAND_MAX) * (max_temp - min_temp) + min_temp;
    return temperature;
}

int main()
{
    char* weather_condition;
    float temperature;
    int num_of_days;
    printf("Enter number of days: ");
    scanf("%d", &num_of_days);
    printf("\n");
    printf("Weather Report for the next %d days:\n", num_of_days);
    printf("======================================\n\n");
    for(int i = 1; i <= num_of_days; i++)
    {
        weather_condition = get_weather();
        temperature = get_temperature();
        printf("Day %d: %s, %.1f °C\n", i, weather_condition, temperature);
    }
    return 0;
}