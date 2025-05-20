//FormAI DATASET v1.0 Category: Weather simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printWeather(int temperature, int humidity) {
    printf("Current weather conditions:\n");
    printf("Temperature: %d C\n", temperature);
    printf("Humidity: %d%%\n", humidity);
    printf("\n");
}

int main() {
    int temperature = 20;
    int humidity = 50;
    int userChoice;
    
    srand(time(0));
    
    printf("Welcome to the Weather Simulator!\n");
    
    do {
        printf("1. Increase temperature\n");
        printf("2. Decrease temperature\n");
        printf("3. Increase humidity\n");
        printf("4. Decrease humidity\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &userChoice);
        printf("\n");
        
        switch (userChoice) {
            case 1:
                temperature++;
                break;
            case 2:
                temperature--;
                break;
            case 3:
                humidity++;
                break;
            case 4:
                humidity--;
                break;
            case 5:
                printf("Thank you for using the Weather Simulator!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        
        // Simulate random weather changes
        if (rand() % 10 == 0) {
            temperature += (rand() % 3) - 1;
            humidity += (rand() % 5) - 2;
        }
        
        // Ensure temperature and humidity values are within valid ranges
        if (temperature < -20) {
            temperature = -20;
        } else if (temperature > 50) {
            temperature = 50;
        }
        if (humidity < 0) {
            humidity = 0;
        } else if (humidity > 100) {
            humidity = 100;
        }
        
        printWeather(temperature, humidity);
    } while (userChoice != 5);
    
    return 0;
}