//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX_ENTRIES 100
#define TEMP_THRESHOLD 30.0

void display_menu();
void record_temperature(float temperatures[], int *count);
void display_temperatures(const float temperatures[], int count);
float calculate_average(const float temperatures[], int count);
float find_maximum(const float temperatures[], int count);

int main() {
    float temperatures[MAX_ENTRIES];
    int count = 0;
    int choice;

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');  // Clear invalid input
            continue;
        }

        switch (choice) {
            case 1:
                record_temperature(temperatures, &count);
                break;
            case 2:
                display_temperatures(temperatures, count);
                break;
            case 3: {
                float average = calculate_average(temperatures, count);
                printf("Average Temperature: %.2f°C\n", average);
                break;
            }
            case 4: {
                float maximum = find_maximum(temperatures, count);
                printf("Maximum Temperature: %.2f°C\n", maximum);
                break;
            }
            case 5:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please select a correct option.\n");
                break;
        }
    }
    return 0;
}

void display_menu() {
    printf("\nTemperature Monitor\n");
    printf("1. Record Temperature\n");
    printf("2. Display Temperatures\n");
    printf("3. Calculate Average Temperature\n");
    printf("4. Find Maximum Temperature\n");
    printf("5. Exit\n");
}

void record_temperature(float temperatures[], int *count) {
    if (*count >= MAX_ENTRIES) {
        printf("Temperature record is full. Cannot record more temperatures.\n");
        return;
    }

    float temp;
    printf("Enter temperature (in °C): ");
    if (scanf("%f", &temp) != 1) {
        printf("Invalid input. Please enter a valid temperature.\n");
        while (getchar() != '\n');  // Clear invalid input
        return;
    }

    temperatures[*count] = temp;
    (*count)++;

    if (temp > TEMP_THRESHOLD) {
        printf("Warning: Temperature exceeds threshold! (%.2f°C)\n", temp);
    }
    printf("Temperature recorded successfully!\n");
}

void display_temperatures(const float temperatures[], int count) {
    if (count == 0) {
        printf("No temperatures recorded yet.\n");
        return;
    }

    printf("Recorded Temperatures:\n");
    for (int i = 0; i < count; i++) {
        printf("%.2f°C\n", temperatures[i]);
    }
}

float calculate_average(const float temperatures[], int count) {
    if (count == 0) {
        return 0.0;  // No temperatures to average
    }

    float sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += temperatures[i];
    }
    return sum / count;
}

float find_maximum(const float temperatures[], int count) {
    if (count == 0) {
        return -1.0;  // Signal no temperatures recorded
    }

    float max = temperatures[0];
    for (int i = 1; i < count; i++) {
        if (temperatures[i] > max) {
            max = temperatures[i];
        }
    }
    return max;
}