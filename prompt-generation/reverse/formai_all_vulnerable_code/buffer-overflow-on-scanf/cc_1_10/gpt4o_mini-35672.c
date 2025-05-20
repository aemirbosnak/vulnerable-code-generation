//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

// Function declarations
float read_sensor();
void log_temperature(float temperature);
void display_temperatures();
void print_menu();
void handle_user_selection(int choice);

#define LOG_FILE "temperature_log.txt"
#define MAX_LOG_ENTRIES 100

// Structure to hold temperature log data
typedef struct {
    time_t timestamp;
    float temperature;
} TemperatureLog;

// Global variables
TemperatureLog temperature_logs[MAX_LOG_ENTRIES];
int log_count = 0;

// Main function
int main() {
    int choice;
    srand(time(NULL));

    while(1) {
        print_menu();
        printf("Please enter your choice (1-3): ");
        scanf("%d", &choice);
        handle_user_selection(choice);
    }

    return 0;
}

// Function to read simulated temperature from sensor
float read_sensor() {
    // Simulating temperature between -10 and 40 degrees Celsius
    return ((rand() % 5000) / 100.0) - 10.0;
}

// Function to log temperature data to an array
void log_temperature(float temperature) {
    if (log_count < MAX_LOG_ENTRIES) {
        temperature_logs[log_count].timestamp = time(NULL);
        temperature_logs[log_count].temperature = temperature;
        log_count++;
    } else {
        printf("Log is full! Consider resetting the log.\n");
    }
}

// Function to display logged temperatures in a simple format
void display_temperatures() {
    printf("\nTemperature Log:\n");
    printf("---------------------------------------\n");
    for (int i = 0; i < log_count; i++) {
        printf("Entry %d: %s - %.2f°C\n", i + 1, ctime(&temperature_logs[i].timestamp), temperature_logs[i].temperature);
    }
    if (log_count == 0) {
        printf("No temperature readings logged yet.\n");
    }
    printf("---------------------------------------\n\n");
}

// Function to print the main menu
void print_menu() {
    printf("Temperature Monitor Menu:\n");
    printf("1. Read and Log Temperature\n");
    printf("2. Display Logged Temperatures\n");
    printf("3. Exit\n");
}

// Function to handle user selection and execute the corresponding action
void handle_user_selection(int choice) {
    switch (choice) {
        case 1: {
            float current_temp = read_sensor();
            printf("Current Temperature: %.2f°C\n", current_temp);
            log_temperature(current_temp);
            break;
        }
        case 2:
            display_temperatures();
            break;
        case 3:
            printf("Exiting the program...\n");
            exit(0);
        default:
            printf("Invalid choice! Please select a valid option.\n");
    }
}