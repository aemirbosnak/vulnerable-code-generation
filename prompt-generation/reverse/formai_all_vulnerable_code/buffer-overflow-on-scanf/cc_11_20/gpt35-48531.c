//FormAI DATASET v1.0 Category: Weather simulation ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    int temp, humidity, windSpeed;
    srand(time(0)); // Seed the random number generator with current time

    printf("Welcome to the Weather Simulation Program\n\n");

    while(1) {  // Infinite loop
        printf("Enter the temperature: ");
        scanf("%d", &temp);

        printf("Enter the humidity: ");
        scanf("%d", &humidity);

        printf("Enter the wind speed: ");
        scanf("%d", &windSpeed);

        // Calculate the chance of precipitation
        float precipChance = (float)(humidity * windSpeed) / temp;

        printf("The chance of precipitation is %.2f%%\n", precipChance);

        // Generate a random temperature fluctuation between -5 to 5 degrees
        int tempFluctuation = (rand() % 11) - 5;

        // Add the fluctuation to the current temperature
        int newTemp = temp + tempFluctuation;

        printf("The new temperature is %d degrees Celsius\n", newTemp);

        // Check temperature range and advise user accordingly
        if(newTemp < 0) {
            printf("It is freezing cold outside, stay indoors if possible!\n");
        } else if(newTemp >= 0 && newTemp <= 20) {
            printf("It is quite cold outside, make sure to wear multiple layers!\n");
        } else if(newTemp > 20 && newTemp <= 30) {
            printf("The temperature is pleasant, enjoy the weather outside!\n");
        } else if(newTemp > 30 && newTemp <= 40) {
            printf("It is quite hot outside, stay hydrated and avoid staying outdoors for long!\n");
        } else if(newTemp > 40) {
            printf("It is scorching hot outside, avoid going outside if possible!\n");
        }

        // Check wind speed range and advise user accordingly
        if(windSpeed < 10) {
            printf("The wind is calm, perfect weather for outdoor activities!\n");
        } else if(windSpeed >= 10 && windSpeed <= 20) {
            printf("The wind is moderate, be cautious of flying objects!\n");
        } else if(windSpeed > 20 && windSpeed <= 30) {
            printf("The wind is strong, avoid outdoor activities involving flying objects!\n");
        } else if(windSpeed > 30) {
            printf("The wind is very strong, stay indoors and avoid going outside if possible!\n");
        }

        printf("\n"); // Break line for readability
    }

    return 0;
}