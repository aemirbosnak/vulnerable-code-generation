//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct {
    int temp;
    int humidity;
} Weather;

int main() {
    Weather currentWeather;
    int choice;
    do {
        printf("Current weather:\n");
        printf("Temperature: %d\n", currentWeather.temp);
        printf("Humidity: %d\n", currentWeather.humidity);
        printf("\n");
        printf("What would you like to do?\n");
        printf("1. Update weather\n");
        printf("2. View weather history\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\n");
                printf("Enter new temperature: ");
                scanf("%d", &currentWeather.temp);
                printf("Enter new humidity: ");
                scanf("%d", &currentWeather.humidity);
                printf("\n");
                printf("Weather updated!\n");
                break;
            case 2:
                printf("\n");
                printf("Weather history:\n");
                printf("Temperature: %d\n", currentWeather.temp);
                printf("Humidity: %d\n", currentWeather.humidity);
                printf("\n");
                break;
            case 3:
                printf("\n");
                printf("Exiting program...\n");
                break;
            default:
                printf("\n");
                printf("Invalid choice!\n");
        }
    } while (choice!= 3);
    return 0;
}