//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to get current temperature
double get_temperature() {
    FILE *fp;
    char line[100];
    double temp = 0.0;

    // Open the temperature sensor file
    fp = fopen("/sys/class/thermal/thermal_zone0/temp", "r");

    // Read the temperature from the file
    if (fp!= NULL) {
        fgets(line, sizeof(line), fp);
        sscanf(line, "%lf", &temp);
        fclose(fp);
    }

    return temp;
}

// Function to print temperature in a fancy way
void print_temperature(double temp) {
    char *unit;

    if (temp >= 0 && temp <= 15) {
        unit = "°C";
    } else if (temp >= 15 && temp <= 30) {
        unit = "°C";
    } else if (temp >= 30 && temp <= 45) {
        unit = "°C";
    } else if (temp >= 45 && temp <= 60) {
        unit = "°C";
    } else {
        unit = "°C";
    }

    printf("Current temperature: %.2lf%s\n", temp, unit);
}

// Main function
int main() {
    double temperature;

    while (1) {
        // Get current temperature
        temperature = get_temperature();

        // Print temperature in a fancy way
        print_temperature(temperature);

        // Wait for 5 seconds before checking temperature again
        sleep(5);
    }

    return 0;
}