//FormAI DATASET v1.0 Category: Weather simulation ; Style: medieval
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    srand((unsigned)time(NULL)); // seed random number generator
    
    int month, day, temperature;
    char weather[10];
    
    printf("Welcome to the Medieval Weather Simulation!\n");
    printf("Enter the month (1-12): ");
    scanf("%d", &month);
    printf("Enter the day (1-31): ");
    scanf("%d", &day);
    
    // determine temperature based on month
    if (month == 12 || month <= 2) {
        temperature = (rand() % 21) - 10; // -10 to 10 degrees
    } else if (month >= 3 && month <= 5) {
        temperature = (rand() % 16) + 10; // 10 to 25 degrees
    } else if (month >= 6 && month <= 8) {
        temperature = (rand() % 16) + 20; // 20 to 35 degrees
    } else {
        temperature = (rand() % 16) + 5; // 5 to 20 degrees
    }
    
    // determine weather based on temperature and chance of precipitation
    int chance_of_precipitation = rand() % 101;
    if (temperature < 0) {
        sprintf(weather, "snowy");
    } else if (temperature >= 0 && temperature <= 10) {
        if (chance_of_precipitation > 50) {
            sprintf(weather, "rainy");
        } else {
            sprintf(weather, "cloudy");
        }
    } else if (temperature > 10 && temperature <= 20) {
        if (chance_of_precipitation > 75) {
            sprintf(weather, "thunderstorm");
        } else if (chance_of_precipitation > 50 && chance_of_precipitation <= 75) {
            sprintf(weather, "rainy");
        } else {
            sprintf(weather, "partly cloudy");
        }
    } else if (temperature > 20 && temperature <= 30) {
        if (chance_of_precipitation > 75) {
            sprintf(weather, "thunderstorm");
        } else if (chance_of_precipitation > 50 && chance_of_precipitation <= 75) {
            sprintf(weather, "rainy");
        } else {
            sprintf(weather, "sunny");
        }
    } else if (temperature > 30) {
        if (chance_of_precipitation > 75) {
            sprintf(weather, "thunderstorm");
        } else if (chance_of_precipitation > 50 && chance_of_precipitation <= 75) {
            sprintf(weather, "rainy");
        } else {
            sprintf(weather, "hot and sunny");
        }
    }
    
    printf("\nOn %d/%d the temperature is %d degrees Celsius and the weather is %s.\n", month, day, temperature, weather);
    
    return 0;
}