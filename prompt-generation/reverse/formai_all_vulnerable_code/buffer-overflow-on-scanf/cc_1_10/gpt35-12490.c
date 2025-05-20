//FormAI DATASET v1.0 Category: Weather simulation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int temperature, humidity, pressure, wind_speed, num_samples, i, j;
    srand(time(NULL));

    printf("Enter the temperature: ");
    scanf("%d", &temperature);
    printf("Enter the humidity: ");
    scanf("%d", &humidity);
    printf("Enter the pressure: ");
    scanf("%d", &pressure);
    printf("Enter the wind speed: ");
    scanf("%d", &wind_speed);
    printf("Enter the number of samples: ");
    scanf("%d", &num_samples);

    printf("The weather simulation for the city is as follows:\n");

    for(i = 1; i <= num_samples; i++) {
        printf("\nSample no. %d\n", i);
        temperature += rand() % 10 - 5;
        humidity += rand() % 10 - 5;
        pressure += rand() % 10 - 5;
        wind_speed += rand() % 10 - 5;

        printf("Temperature: %d\n", temperature);
        printf("Humidity: %d\n", humidity);
        printf("Pressure: %d\n", pressure);
        printf("Wind speed: %d\n", wind_speed);

        if(temperature > 30) {
            printf("It's pretty hot out there. Don't forget to stay hydrated.\n");
        }
        else if(temperature < 10) {
            printf("It's quite cold outside. Make sure you wear warm clothes.\n");
        }

        if(humidity > 70) {
            printf("It's quite humid outside. Be sure to bring an umbrella.\n");
        }

        if(pressure < 980) {
            printf("Low pressure alert. Possible rainfall.\n");
        }
        else if(pressure > 1030) {
            printf("High pressure alert. Clear and sunny skies expected.\n");
        }

        if(wind_speed > 20) {
            printf("Windy day. Hang on to your hats!\n");
        }
    }

    return 0;
}