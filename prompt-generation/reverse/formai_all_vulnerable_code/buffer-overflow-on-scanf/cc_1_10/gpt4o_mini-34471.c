//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void display_welcome_message() {
    printf("*********************************************\n");
    printf("*        Welcome to the Temperature        *\n");
    printf("*               Monitor Program             *\n");
    printf("*       We are grateful for your interest!  *\n");
    printf("*********************************************\n\n");
}

void get_temperature_reading(float *temperature) {
    *temperature = (float)(rand() % 401) / 10.0;  // Simulating temperature between 0.0 and 40.0
}

void display_temperature(float temperature) {
    printf("Current Temperature: %.1f °C\n", temperature);
}

void ask_user_for_threshold(float *threshold) {
    printf("Please set your temperature threshold (°C) for warnings: ");
    scanf("%f", threshold);
}

void check_temperature(float temperature, float threshold) {
    if (temperature > threshold) {
        printf("Warning: The temperature %.1f°C exceeds your threshold of %.1f°C!\n", temperature, threshold);
    } else {
        printf("All is well! Temperature is within acceptable limits.\n");
    }
}

void thank_user() {
    printf("\nThank you for using our Temperature Monitor!\n");
    printf("Your feedback is invaluable to us and we appreciate your trust.\n");
    printf("Stay safe and take care!\n");
}

int main() {
    srand(time(NULL));  // Seed for random number generation
    float temperature;
    float threshold;

    display_welcome_message();

    while (1) {
        get_temperature_reading(&temperature);
        display_temperature(temperature);
        ask_user_for_threshold(&threshold);
        check_temperature(temperature, threshold);

        char choice;
        printf("\nWould you like to take another reading? (y/n): ");
        scanf(" %c", &choice);
        
        if (choice == 'n' || choice == 'N') {
            break;
        }
    }

    thank_user();
    
    return 0;
}