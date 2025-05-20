//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_READINGS 100 // Maximum number of temperature readings
#define LOG_FILE "temperature_log.txt"

// Function to simulate reading temperature from a sensor
float read_temperature() {
    // Simulate a temperature between -10 and 40 degrees Celsius
    return (rand() % 500) / 10.0 - 10.0;
}

// Function to log temperature to a file
void log_temperature(float temp) {
    FILE *file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        perror("Unable to open log file");
        return;
    }
    time_t now;
    time(&now);
    fprintf(file, "%s: %.2f°C\n", ctime(&now), temp);
    fclose(file);
}

// Function to read all logged temperatures
void read_logged_data() {
    FILE *file = fopen(LOG_FILE, "r");
    if (file == NULL) {
        perror("Unable to open log file");
        return;
    }
    char line[256];
    printf("Logged Temperature Data:\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}

// Function to calculate average temperature from the log
void calculate_average_temperature() {
    FILE *file = fopen(LOG_FILE, "r");
    if (file == NULL) {
        perror("Unable to open log file");
        return;
    }
    float temp;
    float sum = 0.0;
    int count = 0;
    while (fscanf(file, "%*[^:]: %f", &temp) != EOF) {
        sum += temp;
        count++;
    }
    fclose(file);
    if (count == 0) {
        printf("No temperature data available to calculate average.\n");
    } else {
        printf("Average Temperature: %.2f°C\n", sum / count);
    }
}

// Function to display the menu options
void display_menu() {
    printf("Temperature Monitor Menu:\n");
    printf("1. Read Temperature and Log\n");
    printf("2. Read Logged Data\n");
    printf("3. Calculate Average Temperature\n");
    printf("4. Exit\n");
    printf("Select an option: ");
}

int main() {
    srand(time(0)); // Seed random number generator
    int choice;
    float temperature;
    
    do {
        display_menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                temperature = read_temperature();
                printf("Current Temperature: %.2f°C\n", temperature);
                log_temperature(temperature);
                break;
            case 2:
                read_logged_data();
                break;
            case 3:
                calculate_average_temperature();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}