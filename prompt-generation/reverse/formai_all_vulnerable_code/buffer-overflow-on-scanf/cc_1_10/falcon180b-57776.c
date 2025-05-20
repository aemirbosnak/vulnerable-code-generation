//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DAYS 365
#define MAX_HOURS 24
#define MAX_MINUTES 60
#define MAX_SECONDS 60

// Function to generate random weather conditions
void generate_weather(int *temperature, char *conditions) {
    int temp_range = 30; // Temperature range in degrees Celsius

    // Generate temperature
    *temperature = rand() % (MAX_DAYS * temp_range) + 1;

    // Generate weather conditions
    switch (*temperature / temp_range) {
        case 1:
            strcpy(conditions, "Freezing");
            break;
        case 2:
            strcpy(conditions, "Very cold");
            break;
        case 3:
            strcpy(conditions, "Cold");
            break;
        case 4:
            strcpy(conditions, "Cool");
            break;
        case 5:
            strcpy(conditions, "Mild");
            break;
        case 6:
            strcpy(conditions, "Warm");
            break;
        case 7:
            strcpy(conditions, "Very warm");
            break;
        case 8:
            strcpy(conditions, "Hot");
            break;
        case 9:
            strcpy(conditions, "Very hot");
            break;
        default:
            strcpy(conditions, "Unknown");
            break;
    }
}

// Function to print weather information
void print_weather(int temperature, char *conditions) {
    printf("Current weather: %s, %d degrees Celsius\n", conditions, temperature);
}

// Function to simulate weather for a given number of days
void simulate_weather(int num_days) {
    printf("Simulating weather for %d days...\n", num_days);

    int temperature;
    char conditions[20];

    for (int i = 0; i < num_days; i++) {
        generate_weather(&temperature, conditions);
        print_weather(temperature, conditions);
        sleep(60); // Sleep for 1 minute to simulate real-time weather changes
    }
}

int main() {
    int num_days;

    // Prompt user for number of days to simulate weather
    printf("How many days do you want to simulate the weather for? ");
    scanf("%d", &num_days);

    // Simulate weather
    simulate_weather(num_days);

    return 0;
}