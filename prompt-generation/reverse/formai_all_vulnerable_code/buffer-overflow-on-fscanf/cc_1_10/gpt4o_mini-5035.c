//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_READINGS 100
#define FILE_NAME "temperature_readings.txt"

void log_temperature(float temp) {
    FILE *file = fopen(FILE_NAME, "a");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    fprintf(file, "%.2f\n", temp);
    fclose(file);
}

void read_temperatures(float *temp_array, int *count) {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        perror("Error reading file");
        return;
    }
    *count = 0;
    while (fscanf(file, "%f", &temp_array[*count]) != EOF && *count < MAX_READINGS) {
        (*count)++;
    }
    fclose(file);
}

float calculate_average(float *temps, int count) {
    float sum = 0;
    for (int i = 0; i < count; i++) {
        sum += temps[i];
    }
    return (count > 0) ? (sum / count) : 0;
}

float find_max_temperature(float *temps, int count) {
    float max_temp = temps[0];
    for (int i = 1; i < count; i++) {
        if (temps[i] > max_temp) {
            max_temp = temps[i];
        }
    }
    return max_temp;
}

float find_min_temperature(float *temps, int count) {
    float min_temp = temps[0];
    for (int i = 1; i < count; i++) {
        if (temps[i] < min_temp) {
            min_temp = temps[i];
        }
    }
    return min_temp;
}

void display_statistics(float *temps, int count) {
    if (count == 0) {
        printf("No temperature readings available.\n");
        return;
    }
    printf("Statistics:\n");
    printf("Average Temperature: %.2f\n", calculate_average(temps, count));
    printf("Maximum Temperature: %.2f\n", find_max_temperature(temps, count));
    printf("Minimum Temperature: %.2f\n", find_min_temperature(temps, count));
}

void generate_random_temperature(float *temp) {
    // Simulate a random temperature from -10 to 40 degrees Celsius
    *temp = ((float)(rand() % 500) / 10.0f) - 10.0f;
}

void fetch_temperature() {
    float temp;
    generate_random_temperature(&temp);
    printf("Current temperature: %.2f°C\n", temp);
    log_temperature(temp);
}

void print_menu() {
    printf("\nTemperature Monitor\n");
    printf("1. Fetch Temperature\n");
    printf("2. Show Statistics\n");
    printf("3. Exit\n");
    printf("Select an option: ");
}

int main() {
    srand(time(NULL));
    int running = 1;

    while (running) {
        print_menu();
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                fetch_temperature();
                break;
            case 2: {
                float temp_array[MAX_READINGS];
                int count;
                read_temperatures(temp_array, &count);
                display_statistics(temp_array, count);
                break;
            }
            case 3:
                running = 0;
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option, please try again.\n");
                break;
        }
    }

    return 0;
}