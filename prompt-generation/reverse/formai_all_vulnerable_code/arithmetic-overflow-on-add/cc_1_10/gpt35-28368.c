//FormAI DATASET v1.0 Category: Weather simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    //setting up random seed
    srand(time(NULL));
   
    //array of weather conditions
    char* conditions[5] = {"Sunny", "Cloudy", "Rainy", "Windy", "Stormy"};
    
    //variables for temperature and humidity
    int temperature, humidity;
    
    //get user input for the temperature and humidity
    printf("Enter the current temperature: ");
    scanf("%d", &temperature);
    printf("Enter the current humidity: ");
    scanf("%d", &humidity);
    
    //generate a random number between 0 and 4 to determine weather condition
    int weatherIndex = rand() % 5;
    char* currentCondition = conditions[weatherIndex];
    
    //display the weather information to the user
    printf("\n\nCurrent Weather\n");
    printf("Temperature: %d degrees\n", temperature);
    printf("Humidity: %d%%\n", humidity);
    printf("Condition: %s\n\n", currentCondition);
    
    //simulate weather changes for the next 5 days
    printf("5-Day Weather Forecast\n");
    for (int i = 1; i <= 5; i++) {
        printf("Day %d: ", i);
        
        //generate a random temperature change between -5 and 5 degrees
        int tempChange = (rand() % 11) - 5;
        int newTemp = temperature + tempChange;
        
        //generate a random humidity change between -10% and 10%
        int humidityChange = (rand() % 21) - 10;
        int newHumidity = humidity + humidityChange;
        
        //generate a random weather condition
        weatherIndex = rand() % 5;
        char* newCondition = conditions[weatherIndex];
        
        //display the new weather information to the user
        printf("Temperature: %d degrees, Humidity: %d%%, Condition: %s\n", newTemp, newHumidity, newCondition);
        
        //update the temperature and humidity for the next iteration
        temperature = newTemp;
        humidity = newHumidity;
    }

    return 0;
}