//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 100

struct Weather{
    int temperature;
    int humidity;
    int windSpeed;
};

void generateRandomWeather(struct Weather* weather){
    weather->temperature = rand()%MAX;
    weather->humidity = rand()%MAX;
    weather->windSpeed = rand()%MAX;
}

void printWeather(struct Weather weather){
    printf("Temperature: %d\n", weather.temperature);
    printf("Humidity: %d\n", weather.humidity);
    printf("Wind Speed: %d\n", weather.windSpeed);
}

int main(){
    srand(time(NULL));

    struct Weather weather;

    int choice;
    while(1){
        printf("\nWeather Simulation\n");
        printf("1. Generate Random Weather\n");
        printf("2. Print Current Weather\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                generateRandomWeather(&weather);
                break;
            case 2:
                printWeather(weather);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}