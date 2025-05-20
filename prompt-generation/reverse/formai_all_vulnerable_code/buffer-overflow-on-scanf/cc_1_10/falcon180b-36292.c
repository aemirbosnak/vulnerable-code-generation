//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Defining structure for weather
struct Weather {
    char temperature[50];
    char humidity[50];
    char wind[50];
    char precipitation[50];
};

//Function to generate random weather conditions
void generateWeather(struct Weather* weather) {
    int temp = rand()%30 + 1; //Temperature between 1-30 degree Celsius
    sprintf(weather->temperature, "%.2f", (float)temp/10.0); //Converting temperature to float and storing in string
    int humidity = rand()%100; //Humidity between 0-100%
    sprintf(weather->humidity, "%d%%", humidity); //Converting humidity to string
    int windSpeed = rand()%20 + 1; //Wind speed between 1-20 km/hr
    sprintf(weather->wind, "%d km/hr", windSpeed); //Converting wind speed to string
    int precipitation = rand()%3; //Precipitation 0-2, 0-no precipitation, 1-rain, 2-snow
    if(precipitation == 0)
        strcpy(weather->precipitation, "No precipitation");
    else if(precipitation == 1)
        strcpy(weather->precipitation, "Rain");
    else
        strcpy(weather->precipitation, "Snow");
}

//Function to display weather information
void displayWeather(struct Weather* weather) {
    printf("Current weather conditions:\n");
    printf("Temperature: %s degrees Celsius\n", weather->temperature);
    printf("Humidity: %s%%\n", weather->humidity);
    printf("Wind: %s\n", weather->wind);
    printf("Precipitation: %s\n\n", weather->precipitation);
}

//Function to simulate weather changes every 5 minutes
void simulateWeather(struct Weather* weather) {
    int i = 0;
    while(i<12) {
        generateWeather(weather);
        displayWeather(weather);
        sleep(300); //Sleep for 5 minutes
        i++;
    }
}

int main() {
    struct Weather weather;
    int choice = 0;
    while(choice == 0) {
        printf("Do you want to simulate weather changes? (1-Yes, 0-No)\n");
        scanf("%d", &choice);
        if(choice == 1) {
            simulateWeather(&weather);
        }
        else {
            printf("Exiting program...\n");
        }
    }
    return 0;
}