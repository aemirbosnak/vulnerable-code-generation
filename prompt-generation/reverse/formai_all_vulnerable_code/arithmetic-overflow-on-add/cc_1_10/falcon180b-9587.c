//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

// Function prototypes
void init_sensors(void);
void read_sensors(float sensors_data[3]);
void convert_celsius_to_fahrenheit(float *celsius);
void display_temperature(float temperature, char unit);
void log_data(float temperature, char unit);

int main(void) {
    float sensors_data[3];
    char unit = 'C'; // Default temperature unit is Celsius

    init_sensors();

    while (TRUE) {
        read_sensors(sensors_data);

        display_temperature(sensors_data[0], unit);
        display_temperature(sensors_data[1], unit);
        display_temperature(sensors_data[2], unit);

        log_data(sensors_data[0], unit);
        log_data(sensors_data[1], unit);
        log_data(sensors_data[2], unit);

        sleep(1); // Sleep for 1 second before reading sensors again
    }

    return 0;
}

void init_sensors(void) {
    // Initialize sensors here
}

void read_sensors(float sensors_data[3]) {
    // Read temperature data from sensors and store in sensors_data array
}

void convert_celsius_to_fahrenheit(float *celsius) {
    *celsius = (*celsius * 9.0 / 5.0) + 32.0;
}

void display_temperature(float temperature, char unit) {
    printf("%.2f%c\n", temperature, unit);
}

void log_data(float temperature, char unit) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    FILE *log_file = fopen("temperature_log.txt", "a");

    fprintf(log_file, "%04d-%02d-%02d %02d:%02d:%02d - %.2f%c\n",
            t->tm_year + 1900, t->tm_mon + 1, t->tm_mday,
            t->tm_hour, t->tm_min, t->tm_sec, temperature, unit);

    fclose(log_file);
}