//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

// Constants 
#define THRESHOLD_HIGH 75       // 75 degrees Fahrenheit
#define THRESHOLD_LOW 32        // 32 degrees Fahrenheit
#define MAX_HISTORY 10          // To track maximum 10 readings

// Function prototypes
void display_help();
float read_temperature();
void log_temperature(float *history, int *index, float temp);
void display_history(float *history, int index);
void check_threshold(float temp);

int main() {
    printf("Welcome to the Enigmatic Temperature Monitor!\n");
    printf("Your quest: To triumphantly track the temperature of your surroundings!\n");
    
    float temperature_history[MAX_HISTORY];
    int history_index = 0;
    char command;
    int running = 1;

    while (running) {
        printf("\nEnter 'r' to read temperature, 'd' to display history, 'h' for help, 'q' to quit: ");
        scanf(" %c", &command);
        
        switch (command) {
            case 'r':
                // Read the temperature
                {
                    float temp = read_temperature();
                    printf("Current Temperature: %.2f F\n", temp);
                    check_threshold(temp);
                    log_temperature(temperature_history, &history_index, temp);
                }
                break;

            case 'd':
                // Display temperature history
                printf("Displaying last readings:\n");
                display_history(temperature_history, history_index);
                break;

            case 'h':
                // Display help
                display_help();
                break;

            case 'q':
                // Quit the program
                running = 0;
                printf("Exiting Temperature Monitor. Thank you for participating in this adventure!\n");
                break;

            default:
                printf("Unknown command! Enter 'h' for help.\n");
                break;
        }
        
        // Simulate some delay to avoid burn-out
        sleep(1);
    }

    return 0;
}

// Simulate reading temperature from a sensor
float read_temperature() {
    // Generate a random temperature between 20 and 100 degrees Fahrenheit
    return (rand() % 81) + 20; // 20 + [0, 80]
}

// Log temperature to history
void log_temperature(float *history, int *index, float temp) {
    if (*index < MAX_HISTORY) {
        history[*index] = temp;
        *index += 1;
    } else {
        for (int i = 1; i < MAX_HISTORY; i++) {
            history[i - 1] = history[i]; // Shift left
        }
        history[MAX_HISTORY - 1] = temp; // Add new temperature to the end
    }
}

// Display logged temperatures
void display_history(float *history, int index) {
    for (int i = 0; i < index; i++) {
        printf("Reading %d: %.2f F\n", i + 1, history[i]);
    }
}

// Check if temperature is within the thresholds
void check_threshold(float temp) {
    if (temp > THRESHOLD_HIGH) {
        printf("Warning: Temperature too high! (%.2f F)\n", temp);
    } else if (temp < THRESHOLD_LOW) {
        printf("Warning: Temperature too low! (%.2f F)\n", temp);
    } else {
        printf("Temperature is within the safe range. (%.2f F)\n", temp);
    }
}

// Display help information
void display_help() {
    printf("Help Menu:\n");
    printf("'r' - Read the current temperature\n");
    printf("'d' - Display the history of temperature readings\n");
    printf("'h' - Display this help menu\n");
    printf("'q' - Quit the program\n");
}