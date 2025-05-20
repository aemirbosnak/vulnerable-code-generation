//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define TEMP_SENSOR_FILE "/sys/class/thermal/thermal_zone0/temp"
#define WARNING_TEMP 80000 // Temperature in millidegree Celsius (80.0°C)

// Function to read the current temperature from the sensor
float read_temperature() {
    FILE *fp = fopen(TEMP_SENSOR_FILE, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: Couldn't open temperature sensor file.\n");
        exit(EXIT_FAILURE);
    }

    int temp_millidegree;
    fscanf(fp, "%d", &temp_millidegree);
    fclose(fp);
    
    return temp_millidegree / 1000.0; // Convert millidegree to degree Celsius
}

// Function to display a stylized message based on temperature
void display_temperature(float temperature) {
    printf("\n-------------------------\n");
    printf("    Current Temperature   \n");
    printf("-------------------------\n");
    printf("          %.2f °C        \n", temperature);
    printf("-------------------------\n");

    if (temperature > WARNING_TEMP / 1000.0) {
        printf("ALERT! Temperature is above safe limits!\n");
        printf("Consider taking action immediately!\n");
    } else {
        printf("Temperature is within the safe range.\n");
    }

    printf("-------------------------\n");
}

// Main function to control the flow of the program
int main() {
    printf("Welcome to the C Temperature Monitor!\n");
    printf("Monitoring your system's temperature...\n");

    while (1) {
        float current_temp = read_temperature();
        display_temperature(current_temp);
        sleep(5); // Wait for 5 seconds before the next reading

        // Artistic touch: Create a little animation
        for (int i = 0; i < 3; i++) {
            printf("Scanning for temperature");
            for (int j = 0; j < 3; j++) {
                printf(".");
                fflush(stdout);
                sleep(1);
            }
            printf("\r                     \r"); // Clear line
        }
    }

    return 0;
}