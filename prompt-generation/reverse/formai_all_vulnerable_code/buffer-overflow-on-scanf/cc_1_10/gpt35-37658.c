//FormAI DATASET v1.0 Category: Weather simulation ; Style: standalone
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Function to generate random number between given range
int getRandomNumber(int min, int max){
    return (rand() % (max - min + 1)) + min;
}

int main(){

    //Seed the random number generator
    srand(time(NULL));

    //Initialize the variables
    int temp, humidity, windSpeed, weatherCondition;
    float windDirection;

    //Prompt user for input
    printf("Enter the temperature (in Celsius): ");
    scanf("%d", &temp);

    printf("Enter the humidity (in percentage): ");
    scanf("%d", &humidity);

    printf("Enter the wind speed (in km/h): ");
    scanf("%d", &windSpeed);

    //Simulate the weather condition
    weatherCondition = getRandomNumber(1,5); //1-Sunny, 2-Cloudy, 3-Rainy, 4-Snowy, 5-Stormy

    //Simulate the wind direction (only if wind speed > 0)
    if(windSpeed > 0){
        windDirection = getRandomNumber(0, 360);
    }
    else{
        windDirection = -1;
    }

    //Print the weather report
    printf("\n");
    printf("=========================================\n");
    printf("   WEATHER REPORT FOR TODAY\n");
    printf("=========================================\n");
    printf("Temperature           : %d C\n", temp);
    printf("Humidity              : %d %%\n", humidity);
    printf("Wind Speed            : %d km/h\n", windSpeed);

    switch(weatherCondition){
        case 1:
            printf("Weather Condition     : Sunny\n");
            break;
        case 2:
            printf("Weather Condition     : Cloudy\n");
            break;
        case 3:
            printf("Weather Condition     : Rainy\n");
            break;
        case 4:
            printf("Weather Condition     : Snowy\n");
            break;
        case 5:
            printf("Weather Condition     : Stormy\n");
            break;
        default:
            printf("Weather Condition     : Unknown\n");
    }

    printf("Wind Direction        : ");
    if(windDirection == -1){
        printf("N/A\n");
    }
    else{
        printf("%.2f degrees (Clockwise from North)\n", windDirection);
    }

    printf("=========================================\n");

    return 0;
}