//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_TEMP 100
#define MIN_TEMP -30
#define ALERT_THRESHOLD 75

void generate_random_temperature(float *temperature) {
    *temperature = (rand() % (MAX_TEMP - MIN_TEMP + 1)) + MIN_TEMP + (rand() % 100) / 100.0; // Random float generation
}

void check_temperature(float temperature) {
    if (temperature > ALERT_THRESHOLD) {
        printf("\033[1;31mALERT! High Temperature: %.2f°C - Take action immediately!\033[0m\n", temperature);
    } else {
        printf("Current Temperature: %.2f°C - All systems normal.\n", temperature);
    }
}

void display_menu() {
    printf("\n=========================\n");
    printf("  Temperature Monitor\n");
    printf("=========================\n");
    printf("1. Start Monitoring\n");
    printf("2. Set New Alert Threshold\n");
    printf("3. Exit\n");
    printf("=========================\n");
}

void set_alert_threshold(int *threshold) {
    printf("Enter new alert threshold (current: %d°C): ", *threshold);
    int new_threshold;
    scanf("%d", &new_threshold);
    if (new_threshold > MAX_TEMP || new_threshold < MIN_TEMP) {
        printf("\033[1;33mInvalid threshold! Please enter a value between %d and %d.\033[0m\n", MIN_TEMP, MAX_TEMP);
    } else {
        *threshold = new_threshold;
        printf("\033[1;32mAlert threshold set to %d°C.\033[0m\n", *threshold);
    }
}

int main() {
    srand(time(0)); // Seed random number generator
    int alert_threshold = ALERT_THRESHOLD; // Default alert threshold
    int choice;

    printf("\033[1;34mWelcome to the Energetic Temperature Monitor!\033[0m\n");
    printf("\033[1;34mLet's keep it cool or raise the alarm if it gets too hot!\033[0m\n");

    while (1) {
        display_menu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\033[1;36mStarting temperature monitoring...\033[0m\n");
                while (1) {
                    float current_temp;
                    generate_random_temperature(&current_temp);
                    check_temperature(current_temp);
                    sleep(2); // Pause for 2 seconds for the next reading
                }
                break;
            case 2:
                set_alert_threshold(&alert_threshold);
                break;
            case 3:
                printf("\033[1;33mThanks for using the Energetic Temperature Monitor! Goodbye!\033[0m\n");
                exit(0);
            default:
                printf("\033[1;31mInvalid choice! Please select a valid option.\033[0m\n");
                break;
        }
    }
    
    return 0;
}