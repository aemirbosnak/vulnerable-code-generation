//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TEMP_THRESHOLD_HIGH 80
#define TEMP_THRESHOLD_LOW 60

void display_menu() {
    printf("=== Temperature Monitor ===\n");
    printf("1. Read Current Temperature\n");
    printf("2. Set High Temperature Threshold\n");
    printf("3. Set Low Temperature Threshold\n");
    printf("4. Exit\n");
    printf("===========================\n");
    printf("Select an option: ");
}

float read_temperature() {
    // Simulate reading a temperature value
    return (rand() % 100) + (rand() % 100) / 100.0;
}

void check_temperature(float temperature) {
    if (temperature > TEMP_THRESHOLD_HIGH) {
        printf("Warning: High temperature detected (%.2f°F)!\n", temperature);
    } else if (temperature < TEMP_THRESHOLD_LOW) {
        printf("Warning: Low temperature detected (%.2f°F)!\n", temperature);
    } else {
        printf("Temperature is normal (%.2f°F).\n", temperature);
    }
}

int main() {
    srand(time(NULL)); // Seed random number generator
    int choice;
    float high_threshold = TEMP_THRESHOLD_HIGH;
    float low_threshold = TEMP_THRESHOLD_LOW;

    while (1) {
        display_menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                float current_temp = read_temperature();
                check_temperature(current_temp);
                break;
            }
            case 2: {
                printf("Enter new high temperature threshold: ");
                scanf("%f", &high_threshold);
                printf("High temperature threshold set to %.2f°F.\n", high_threshold);
                break;
            }
            case 3: {
                printf("Enter new low temperature threshold: ");
                scanf("%f", &low_threshold);
                printf("Low temperature threshold set to %.2f°F.\n", low_threshold);
                break;
            }
            case 4: {
                printf("Exiting temperature monitor. Goodbye!\n");
                exit(0);
            }
            default: {
                printf("Invalid option! Please try again.\n");
            }
        }
    }

    return 0;
}