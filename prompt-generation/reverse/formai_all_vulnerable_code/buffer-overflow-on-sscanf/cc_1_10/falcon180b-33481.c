//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define TEMP_SENSOR_PIN 0
#define TEMP_SENSOR_READ_INTERVAL 5 // in seconds
#define TEMP_SENSOR_ERROR -1

int main() {
    int temp_sensor_value = 0;
    int temp_celsius = 0;
    int temp_fahrenheit = 0;
    float temp_kelvin = 0.0;
    time_t last_read_time = 0;
    int temp_sensor_read_count = 0;
    int temp_sensor_error_count = 0;

    printf("Temperature Monitor Example Program\n");
    printf("Press any key to start...\n");
    getchar(); // wait for user to press any key to start program

    while (1) {
        if (temp_sensor_read_count >= TEMP_SENSOR_READ_INTERVAL) {
            temp_sensor_read_count = 0;

            if (read_temp_sensor(&temp_sensor_value) == TEMP_SENSOR_ERROR) {
                temp_sensor_error_count++;
            } else {
                temp_sensor_error_count = 0;
            }

            temp_celsius = temp_sensor_value - 32;
            temp_fahrenheit = temp_sensor_value;
            temp_kelvin = temp_sensor_value + 273.15;

            printf("Temperature: %d degrees Celsius / %d degrees Fahrenheit / %.2f degrees Kelvin\n", temp_celsius, temp_fahrenheit, temp_kelvin);

            last_read_time = time(NULL);
        } else {
            temp_sensor_read_count++;
        }

        if (temp_sensor_error_count >= 10) {
            printf("Error: Temperature sensor read error count exceeded 10. Exiting program.\n");
            exit(1);
        }
    }

    return 0;
}

int read_temp_sensor(int *value) {
    FILE *fp;
    char line[100];
    int temp_value = 0;

    fp = fopen("/sys/devices/platform/soc/2100000.i2c/i2c-0/0-0060/temp1_input", "r");

    if (fp == NULL) {
        printf("Error: Failed to open temperature sensor file.\n");
        return TEMP_SENSOR_ERROR;
    }

    fgets(line, sizeof(line), fp);
    fclose(fp);

    sscanf(line, "%d", &temp_value);

    *value = temp_value / 1000; // convert to Celsius

    return 0;
}