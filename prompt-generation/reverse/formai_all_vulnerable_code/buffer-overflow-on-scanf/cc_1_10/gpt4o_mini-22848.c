//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_READINGS 100
#define TEMP_THRESHOLD 30.0 // Define a threshold temperature 

typedef struct {
    int id;
    float temperature;
    time_t timestamp;
} Reading;

void log_readings(Reading readings[], int count) {
    FILE *file = fopen("temperature_log.txt", "a");
    if (file == NULL) {
        perror("Unable to open log file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "ID: %d, Temp: %.2f°C, Time: %s", 
                readings[i].id, readings[i].temperature, 
                ctime(&(readings[i].timestamp)));
    }

    fclose(file);
}

void display_readings(Reading readings[], int count) {
    printf("\n--- Temperature Readings ---\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Temperature: %.2f°C, Time: %s", 
                readings[i].id, readings[i].temperature, 
                ctime(&(readings[i].timestamp)));
    }
    printf("----------------------------\n");
}

float get_temperature() {
    // Simulate a temperature reading between 20°C and 40°C
    return (float)(rand() % 210) / 5 + 20; // ranges from 20 to 40
}

void check_temperature(float temperature) {
    if (temperature > TEMP_THRESHOLD) {
        printf("** Alert! Temperature exceeded threshold: %.2f°C **\n", temperature);
    }
}

int main() {
    srand(time(NULL)); // Seed for random temperature generation
    Reading readings[MAX_READINGS];
    int reading_count = 0;
    char choice;

    printf("Welcome to the Curious Temperature Monitor!\n");
    printf("In this mystical place, we shall observe the temperatures...\n");

    do {
        if (reading_count < MAX_READINGS) {
            float current_temp = get_temperature();
            time_t now = time(NULL);
            readings[reading_count].id = reading_count + 1;
            readings[reading_count].temperature = current_temp;
            readings[reading_count].timestamp = now;

            printf("Current temperature is: %.2f°C\n", current_temp);
            check_temperature(current_temp);
            reading_count++;
        } else {
            printf("Maximum reading limit reached! Processing...\n");
            log_readings(readings, reading_count);
            display_readings(readings, reading_count);
            reading_count = 0; // Reset after logging
        }

        printf("Would you like to record another temperature? (y/n): ");
        scanf(" %c", &choice); // Space before %c to consume newline

        if (choice == 'y' || choice == 'Y') {
            printf("Let the observations continue...\n");
        } else if (choice == 'n' || choice == 'N') {
            printf("Farewell, brave observer! Until we meet again...\n");
        } else {
            printf("Ah, the language of choice is unknown. Please choose wisely!\n");
        }

        sleep(1); // Simulate a wait before the next reading

    } while (choice == 'y' || choice == 'Y');

    if (reading_count > 0) {
        log_readings(readings, reading_count);
        display_readings(readings, reading_count);
    }

    return 0;
}