//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_RECORDS 100
#define THRESHOLD_COLD 0
#define THRESHOLD_HOT 30

typedef struct {
    time_t timestamp;
    float temperature;
} TemperatureRecord;

TemperatureRecord records[MAX_RECORDS];
int record_count = 0;

void record_temperature(float temp) {
    if (record_count < MAX_RECORDS) {
        records[record_count].timestamp = time(NULL);
        records[record_count].temperature = temp;
        record_count++;
    } else {
        printf("Record limit reached! Cannot save more temperatures.\n");
    }
}

void print_temperature_records() {
    printf("Temperature Records:\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < record_count; i++) {
        char buffer[26];
        struct tm* tm_info;

        tm_info = localtime(&records[i].timestamp);
        strftime(buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);
        printf("Record %d: Time: %s | Temperature: %.2f°C\n", 
               i + 1, buffer, records[i].temperature);
    }
    printf("--------------------------------------------------\n");
}

void check_temperature(float temp) {
    if (temp < THRESHOLD_COLD) {
        printf("Warning: Temperature is too cold at %.2f°C!\n", temp);
    } else if (temp > THRESHOLD_HOT) {
        printf("Warning: Temperature is too hot at %.2f°C!\n", temp);
    } else {
        printf("Temperature is normal at %.2f°C.\n", temp);
    }
}

float generate_random_temperature() {
    return (rand() % 501) / 10.0; // Generate temperature between 0.0 and 50.0
}

int main() {
    srand(time(NULL)); // Seed random number generator

    char command[10];

    printf("Welcome to the C Temperature Monitor.\n");
    printf("Commands available:\n");
    printf("1. record - Record a new temperature reading\n");
    printf("2. display - Display all recorded temperatures\n");
    printf("3. exit - Exit the program\n");

    while (1) {
        printf("\nEnter command: ");
        scanf("%s", command);

        if (strcmp(command, "record") == 0) {
            float temp = generate_random_temperature();
            printf("Randomly generated temperature: %.2f°C\n", temp);
            record_temperature(temp);
            check_temperature(temp);
        } else if (strcmp(command, "display") == 0) {
            print_temperature_records();
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting the program. Goodbye!\n");
            break;
        } else {
            printf("Unknown command! Please try again.\n");
        }
    }

    return 0;
}