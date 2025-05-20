//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define CPU_TEMP_FILE "/sys/class/thermal/thermal_zone0/temp"
#define TEMP_SENSOR_COUNT 4

// Function to read temperature from the file
float read_cpu_temperature() {
    FILE *file = fopen(CPU_TEMP_FILE, "r");
    if (!file) {
        fprintf(stderr, "Error: Unable to open temperature file!\n");
        return -1.0;
    }

    float temperature;
    fscanf(file, "%f", &temperature);
    fclose(file);

    // Convert from millidegree Celsius to degree Celsius
    return temperature / 1000.0;
}

// Function to display the temperature with fun ASCII art
void display_temperature(float temp) {
    system("clear");
    printf("🔥🔥🔥 Welcome to the Temperature Monitor! 🔥🔥🔥\n");
    printf("===============================================\n");
    printf("Current CPU Temperature: %.2f °C\n", temp);
    printf("===============================================\n");
    
    // Create a fun thermometer display
    int barLength = (int)(temp / 2); // Scaling factor for display
    if(barLength > 50) barLength = 50; // Limit max length

    printf("Thermometer: |");
    for (int i = 0; i < barLength; i++) {
        printf("█");
    }
    for (int i = barLength; i < 50; i++) {
        printf(" ");
    }
    printf("| %d°C\n", (int)temp);
    printf("===============================================\n");
    printf("Note: Keep an eye on your CPU temperature! 🌡️\n");
}

void monitor_temperature() {
    while (1) {
        float cpu_temp = read_cpu_temperature();
        if(cpu_temp < 0) {
            printf("Failed to read temperature data.\n");
            break;
        }

        display_temperature(cpu_temp);
        
        // Sleep for 1 second before reading again
        sleep(1);
    }
}

int main() {
    printf("Starting the CPU Temperature Monitor...\n");
    sleep(1);
    printf("Monitoring in progress. Press Ctrl+C to stop.\n\n");

    monitor_temperature();

    return 0;
}