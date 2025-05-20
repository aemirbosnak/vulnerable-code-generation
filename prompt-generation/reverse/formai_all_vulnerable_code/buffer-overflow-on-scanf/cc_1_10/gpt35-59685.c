//FormAI DATASET v1.0 Category: Weather simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DAYS 7
#define MAX_TEMP 100    // maximum temperature in Fahrenheit
#define MIN_TEMP 20     // minimum temperature in Fahrenheit

void print_weather(int day, int temp);

int main() {
    srand(time(NULL));  // seeding random number generator
    
    int temp;
    printf("Enter the temperature of today in Fahrenheit: ");
    scanf("%d", &temp);
    
    if (temp < MIN_TEMP || temp > MAX_TEMP) {   // checking if temperature is within valid range
        printf("Invalid temperature.\n");
        return 1;
    }
    
    printf("Weather forecast for next 7 days:\n");
    
    for (int i = 1; i <= MAX_DAYS; i++) {   // simulating weather for next 7 days
        int deviation = rand() % 10 - 5;    // random deviation from previous day's temperature
        temp += deviation;
        
        if (temp < MIN_TEMP) {
            temp = MIN_TEMP;
        } else if (temp > MAX_TEMP) {
            temp = MAX_TEMP;
        }
        
        print_weather(i, temp);
    }
    
    return 0;
}

void print_weather(int day, int temp) {
    printf("Day %d: Temperature %d°F, ", day, temp);
    
    if (temp < 32) {
        printf("Freezing\n");
    } else if (temp >= 32 && temp < 50) {
        printf("Cold\n");
    } else if (temp >= 50 && temp < 70) {
        printf("Mild\n");
    } else if (temp >= 70 && temp < 90) {
        printf("Warm\n");
    } else {
        printf("Hot\n");
    }
}