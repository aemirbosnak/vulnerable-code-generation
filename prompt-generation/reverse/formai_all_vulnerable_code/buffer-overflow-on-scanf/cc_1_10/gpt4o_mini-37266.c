//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_TEMPERATURES 100
#define WARNING_THRESHOLD 75
#define CRITICAL_THRESHOLD 90

typedef struct {
    time_t timestamp;
    float temperature;
} TemperatureRecord;

TemperatureRecord temperatureLog[MAX_TEMPERATURES];
int logIndex = 0;

void recordTemperature(float temp) {
    if (logIndex < MAX_TEMPERATURES) {
        temperatureLog[logIndex].timestamp = time(NULL);
        temperatureLog[logIndex].temperature = temp;
        logIndex++;
    } else {
        printf("Temperature log is full.\n");
    }
}

void displayTemperatures() {
    printf("\nTemperature Log:\n");
    printf("Time                   Temperature (°C)\n");
    for (int i = 0; i < logIndex; i++) {
        char buffer[26];
        struct tm* tm_info;

        tm_info = localtime(&temperatureLog[i].timestamp);
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tm_info);
        printf("%s   %.2f\n", buffer, temperatureLog[i].temperature);
    }
    printf("\n");
}

void checkTemperature(float temp) {
    if (temp >= CRITICAL_THRESHOLD) {
        printf("CRITICAL ALERT! Temperature reached %.2f°C\n", temp);
    } else if (temp >= WARNING_THRESHOLD) {
        printf("Warning! High temperature detected: %.2f°C\n", temp);
    } else {
        printf("Temperature is normal: %.2f°C\n", temp);
    }
}

float generateRandomTemperature() {
    return (float)(rand() % 101); // Generates a temperature between 0-100
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    char userInput;

    printf("Welcome to the Temperature Monitor System!\n");
    
    do {
        float currentTemperature = generateRandomTemperature();
        printf("Current generated temperature: %.2f°C\n", currentTemperature);
        
        recordTemperature(currentTemperature);
        checkTemperature(currentTemperature);

        displayTemperatures();

        printf("Do you want to check again? (y/n): ");
        scanf(" %c", &userInput);
    } while (userInput == 'y' || userInput == 'Y');

    printf("Exiting Temperature Monitor System. Goodbye!\n");
    return 0;
}