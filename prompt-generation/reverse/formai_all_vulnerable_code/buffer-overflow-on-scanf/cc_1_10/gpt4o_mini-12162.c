//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_READINGS 100
#define THRESHOLD 75.0
#define LOG_FILE "temperature_log.txt"

// Structure to hold temperature readings
typedef struct {
    time_t timestamp;
    float temperature;
} TemperatureReading;

// Function to generate a random temperature
float generate_random_temperature() {
    return ((float)(rand() % 10000) / 100.0);
}

// Function to log temperature readings to a file
void log_temperature_reading(TemperatureReading reading) {
    FILE *file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        perror("Error opening log file");
        return;
    }
    fprintf(file, "Time: %sTemperature: %.2f\n",
            ctime(&reading.timestamp), reading.temperature);
    fclose(file);
}

// Function to alert the user if temperature exceeds threshold
void check_temperature(TemperatureReading reading) {
    if (reading.temperature > THRESHOLD) {
        printf("Alert! High temperature detected: %.2f\n", reading.temperature);
    } else {
        printf("Temperature is normal: %.2f\n", reading.temperature);
    }
}

// Function to display the temperature history
void display_temperature_history(TemperatureReading readings[], int count) {
    printf("\n--- Temperature History ---\n");
    for (int i = 0; i < count; i++) {
        printf("Reading %d: Time: %sTemperature: %.2f\n", 
               i + 1,
               ctime(&readings[i].timestamp),
               readings[i].temperature);
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    TemperatureReading readings[MAX_READINGS]; // Array to store temperature readings
    int reading_count = 0;
    char command[10];
    
    printf("Welcome to the Temperature Monitor System!\n");
    
    while (1) {
        printf("\nEnter 'reading' to get a new temperature reading, "
               "'history' to view past readings, or 'exit' to quit: ");
        scanf("%s", command);
        
        if (strcmp(command, "reading") == 0) {
            if (reading_count < MAX_READINGS) {
                TemperatureReading new_reading;
                new_reading.temperature = generate_random_temperature();
                new_reading.timestamp = time(NULL);
                
                readings[reading_count] = new_reading; // Store the new reading
                log_temperature_reading(new_reading); // Log to file

                check_temperature(new_reading); // Check against threshold
                reading_count++; // Increment reading count
            } else {
                printf("Maximum reading limit reached.\n");
            }
        } else if (strcmp(command, "history") == 0) {
            display_temperature_history(readings, reading_count);
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting Temperature Monitor System. Goodbye!\n");
            break;
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }

    return 0;
}