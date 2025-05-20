//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_TEMPERATURE 100
#define MIN_TEMPERATURE -20

void display_warning(float temperature) {
    if (temperature > 75) {
        printf("🚨 WARNING: High temperature detected! 🚨\n");
    } else if (temperature < 0) {
        printf("💧 WARNING: Temperature is freezing! 💧\n");
    } else {
        printf("Temperature is within the safe range.\n");
    }
}

float get_random_temperature() {
    // Generate a random float in the range of MIN_TEMPERATURE to MAX_TEMPERATURE
    float temp = ((float)rand() / RAND_MAX) * (MAX_TEMPERATURE - MIN_TEMPERATURE) + MIN_TEMPERATURE;
    return temp;
}

void check_temperature() {
    float temperature = get_random_temperature();
    printf("🕒 Checking temperature...\n");
    sleep(1);  // Simulating a delay for realism

    printf("🌡️ Current Temperature: %.2f°C\n", temperature);
    display_warning(temperature);
}

void show_temperature_logging() {
    printf("📜 Temperature Log:\n");
    printf("===================================\n");
    for (int i = 1; i <= 10; ++i) {
        float temp = get_random_temperature();
        printf("Log %d: %.2f°C\n", i, temp);
        sleep(1);
    }
    printf("===================================\n");
}

void display_menu() {
    printf("\n📊 Temperature Monitor Menu 📊\n");
    printf("1. Check Current Temperature\n");
    printf("2. View Temperature Log\n");
    printf("3. Exit\n");
    printf("===================================\n");
}

int main() {
    srand(time(NULL));  // Seed for random number generation
    int choice;

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                check_temperature();
                break;
            case 2:
                show_temperature_logging();
                break;
            case 3:
                printf("🚪 Exiting Temperature Monitor. Stay safe! 🚪\n");
                exit(0);
            default:
                printf("❌ Invalid choice! Please choose again.\n");
                break;
        }
    }

    return 0;
}