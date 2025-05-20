//FormAI DATASET v1.0 Category: Weather simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to check if user input is valid */
int isValidInput(int num){
    if(num >= 0 && num <= 100)
        return 1;
    else
        return 0; 
}

int main()
{
    /* Get user input for temperature, wind speed and humidity */
    int temperature, windSpeed, humidity;
    
    printf("Welcome to the Weather Simulation!\n");
    printf("Please enter the current temperature (in Celsius): ");
    scanf("%d", &temperature);
    
    if(!isValidInput(temperature)){
        printf("Invalid input! Temperature should be between 0 and 100 Celsius. Try again.\n");
        return 1;
    }
    
    printf("Please enter the current wind speed (in km/h): ");
    scanf("%d", &windSpeed);
    
    if(!isValidInput(windSpeed)){
        printf("Invalid input! Wind speed should be between 0 and 100 km/h. Try again.\n");
        return 1;
    }
    
    printf("Please enter the current humidity (in %%): ");
    scanf("%d", &humidity);
    
    if(!isValidInput(humidity)){
        printf("Invalid input! Humidity should be between 0 and 100%%. Try again.\n");
        return 1;
    }
    
    /* Generate random values for temperature, wind speed and humidity for next 5 days */
    srand(time(NULL));
    
    int temperatureArr[5], windSpeedArr[5], humidityArr[5];
    
    printf("\nGenerating weather simulation for the next 5 days...\n");
    
    for(int i = 0; i < 5; i++){
        temperatureArr[i] = (rand() % 31) - 10; /* Temperature range from -10 to 20 Celsius */
        windSpeedArr[i] = rand() % 101; /* Wind speed range from 0 to 100 km/h */
        humidityArr[i] = rand() % 101; /* Humidity range from 0 to 100% */
    }
    
    /* Print the simulation */
    printf("\n\nDay\tTemperature\tWind Speed\tHumidity\n");
    
    for(int i = 0; i < 5; i++){
        printf("%d\t%dC\t\t%d km/h\t\t%d%%\n", (i+1), temperatureArr[i], windSpeedArr[i], humidityArr[i]);
    }
    
    /* Calculate average temperature, wind speed and humidity for the next 5 days */
    int avgTemperature = 0, avgWindSpeed = 0, avgHumidity = 0;
    
    for(int i = 0; i < 5; i++){
        avgTemperature += temperatureArr[i];
        avgWindSpeed += windSpeedArr[i];
        avgHumidity += humidityArr[i];
    }
    
    avgTemperature /= 5;
    avgWindSpeed /= 5;
    avgHumidity /= 5;
    
    /* Print the average values */
    printf("\n\nAverage temperature for the next 5 days: %dC\n", avgTemperature);
    printf("Average wind speed for the next 5 days: %d km/h\n", avgWindSpeed);
    printf("Average humidity for the next 5 days: %d%%\n", avgHumidity);
    
    return 0;
}