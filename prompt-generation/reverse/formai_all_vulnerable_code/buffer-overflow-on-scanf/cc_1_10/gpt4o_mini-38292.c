//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define TEMP_THRESHOLD_HIGH 75.0
#define TEMP_THRESHOLD_LOW 60.0

void log_temperature(float temperature) {
    FILE *file = fopen("temperature_log.txt", "a");
    if (file == NULL) {
        perror("Error opening log file");
        return;
    }

    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    char timestamp[26];
    strftime(timestamp, 26, "%Y-%m-%d %H:%M:%S", tm_info);

    fprintf(file, "[%s] Temperature: %.2f\n", timestamp, temperature);
    fclose(file);
}

void check_temperature(float temperature) {
    if (temperature > TEMP_THRESHOLD_HIGH) {
        printf("Warning: Temperature %.2f exceeds the high threshold of %.2f!\n",
                temperature, TEMP_THRESHOLD_HIGH);
    } else if (temperature < TEMP_THRESHOLD_LOW) {
        printf("Warning: Temperature %.2f is below the low threshold of %.2f!\n",
                temperature, TEMP_THRESHOLD_LOW);
    } else {
        printf("Temperature %.2f is within the normal range.\n", temperature);
    }
}

float get_random_temperature() {
    return (rand() % 50) + 50.0;  // Generates a temperature between 50.0 and 100.0
}

void display_menu() {
    printf("\n=== Temperature Monitor ===\n");
    printf("1. Check current temperature\n");
    printf("2. View temperature log\n");
    printf("3. Exit\n");
    printf("===========================\n");
    printf("Select an option: ");
}

void display_log() {
    printf("\n=== Temperature Log ===\n");
    FILE *file = fopen("temperature_log.txt", "r");
    if (file == NULL) {
        perror("Error opening log file");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
    printf("=========================\n");
}

int main() {
    srand(time(NULL));
    int choice;
    float current_temperature;

    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                current_temperature = get_random_temperature();
                printf("Current Temperature: %.2f\n", current_temperature);
                log_temperature(current_temperature);
                check_temperature(current_temperature);
                break;
            case 2:
                display_log();
                break;
            case 3:
                printf("Exiting the Temperature Monitor. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }

        sleep(1);  // Simulate some delay for user experience
    }

    return 0;
}