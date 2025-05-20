//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>

#define TEMP_SENSOR "/sys/class/thermal/thermal_zone0/temp"
#define DELAY 5000 // 5 seconds delay

// Function to get current temperature in Celsius
float get_temperature() {
    FILE *fp;
    char buffer[10];
    float temp;

    fp = fopen(TEMP_SENSOR, "r");
    if (fp == NULL) {
        printf("Error: Cannot open temperature sensor.\n");
        exit(1);
    }

    fscanf(fp, "%f", &temp);
    fclose(fp);

    return temp / 1000.0; // Convert from milli Celsius to Celsius
}

// Function to print temperature and fan status
void print_status(float temperature) {
    if (temperature <= 50) {
        printf("Temperature: %.1f°C (Cool)\n", temperature);
    } else if (temperature <= 60) {
        printf("Temperature: %.1f°C (Normal)\n", temperature);
    } else {
        printf("Temperature: %.1f°C (Hot)\n", temperature);
    }

    if (temperature >= 70) {
        printf("Fan: On\n");
    } else {
        printf("Fan: Off\n");
    }
}

int main() {
    float temperature;

    while (1) {
        temperature = get_temperature();
        print_status(temperature);

        usleep(DELAY * 1000); // Delay for 5 seconds
    }

    return 0;
}