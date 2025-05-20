//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Defining the structure of weather data
struct Weather{
    float temperature;
    float humidity;
    float pressure;
    float windSpeed;
};

//Function to generate random weather data
struct Weather generateWeather(){
    struct Weather weather;
    weather.temperature = rand()%50+10;
    weather.humidity = rand()%70+30;
    weather.pressure = rand()%1010+950;
    weather.windSpeed = rand()%20+5;
    return weather;
}

//Function to display the weather data
void displayWeather(struct Weather weather){
    printf("Temperature: %.2f\n", weather.temperature);
    printf("Humidity: %.2f\n", weather.humidity);
    printf("Pressure: %.2f\n", weather.pressure);
    printf("Wind Speed: %.2f\n\n", weather.windSpeed);
}

int main(){
    srand(time(NULL));
    int choice, i;
    struct Weather weather;
    float avgTemp, avgHum, avgPres, avgWind;

    do{
        printf("1. Generate Weather Data\n2. Display Weather Data\n3. Exit\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                weather = generateWeather();
                printf("Generated Weather Data:\n");
                displayWeather(weather);
                break;
            case 2:
                if(weather.temperature == 0){
                    printf("No weather data generated yet!\n");
                }else{
                    printf("Weather Data:\n");
                    displayWeather(weather);
                }
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }

    }while(1);

    return 0;
}