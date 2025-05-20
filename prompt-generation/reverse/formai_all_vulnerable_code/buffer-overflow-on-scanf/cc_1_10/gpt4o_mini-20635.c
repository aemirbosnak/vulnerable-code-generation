//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define CAUTION_THRESHOLD 30.0
#define DANGER_THRESHOLD 10.0
#define MAX_TEMPERATURE 40.0
#define MIN_TEMPERATURE -10.0

void displayTemperature(float temperature) {
    printf("Current Temperature: %.2f°C\n", temperature);
}

void checkTemperature(float temperature, float caution, float danger) {
    if (temperature > caution) {
        printf("Warning: High temperature alert! (%.2f°C)\n", temperature);
    } else if (temperature < danger) {
        printf("Warning: Low temperature alert! (%.2f°C)\n", temperature);
    } else {
        printf("Temperature is within safe limits.\n");
    }
}

float generateRandomTemperature() {
    return (rand() % (int)(MAX_TEMPERATURE - MIN_TEMPERATURE + 1) + MIN_TEMPERATURE);
}

void runTemperatureMonitor(float cautionThreshold, float dangerThreshold) {
    srand(time(0)); // Seed for random number generation
    while (1) {
        float currentTemperature = generateRandomTemperature();

        displayTemperature(currentTemperature);
        checkTemperature(currentTemperature, cautionThreshold, dangerThreshold);

        sleep(2); // Delay for 2 seconds before generating next temperature reading
    }
}

int main() {
    float cautionThreshold, dangerThreshold;

    printf("Set the high caution temperature threshold (°C): ");
    scanf("%f", &cautionThreshold);
    printf("Set the low danger temperature threshold (°C): ");
    scanf("%f", &dangerThreshold);

    if (cautionThreshold < dangerThreshold) {
        printf("Caution threshold must be higher than danger threshold!\n");
        exit(EXIT_FAILURE);
    }
    if (cautionThreshold > MAX_TEMPERATURE || dangerThreshold < MIN_TEMPERATURE) {
        printf("Thresholds must be within the range of %.2f°C to %.2f°C\n", MIN_TEMPERATURE, MAX_TEMPERATURE);
        exit(EXIT_FAILURE);
    }

    printf("Starting Temperature Monitor...\n");
    runTemperatureMonitor(cautionThreshold, dangerThreshold);

    return 0;
}