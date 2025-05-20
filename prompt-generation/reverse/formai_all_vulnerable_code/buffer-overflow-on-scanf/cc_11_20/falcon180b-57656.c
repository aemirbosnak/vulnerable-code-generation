//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_TEMP_SENSORS 10
#define MAX_TEMP_DATA 500

struct temp_data {
    int sensor_num;
    double temp;
    time_t timestamp;
};

int main() {
    int num_sensors;
    double temp;
    struct temp_data temp_data[MAX_TEMP_DATA];
    int temp_data_count = 0;
    int i;

    // Get number of temperature sensors
    printf("Enter number of temperature sensors: ");
    scanf("%d", &num_sensors);

    // Initialize temperature sensor data
    for (i = 0; i < num_sensors; i++) {
        temp_data[i].sensor_num = i + 1;
        temp_data[i].temp = 0;
        temp_data[i].timestamp = 0;
    }

    // Main loop for temperature monitoring
    while (1) {
        printf("\n");
        printf("Temperature Sensor Data:\n");
        printf("---------------------------------\n");
        printf("Sensor # | Temperature (C) | Timestamp\n");
        printf("---------------------------------\n");

        // Get temperature data from sensors
        for (i = 0; i < num_sensors; i++) {
            printf("Sensor %d: ", i + 1);
            scanf("%lf", &temp);
            temp_data[i].temp = temp;
            temp_data[i].timestamp = time(NULL);
            printf("%lf | %ld\n", temp, temp_data[i].timestamp);
        }

        // Print average temperature
        double avg_temp = 0;
        int num_sensors_with_data = 0;
        for (i = 0; i < num_sensors; i++) {
            if (temp_data[i].temp!= 0) {
                avg_temp += temp_data[i].temp;
                num_sensors_with_data++;
            }
        }
        if (num_sensors_with_data > 0) {
            avg_temp /= num_sensors_with_data;
            printf("\nAverage Temperature: %lf\n", avg_temp);
        }

        // Check for temperature threshold violations
        printf("\nChecking for temperature threshold violations:\n");
        for (i = 0; i < num_sensors; i++) {
            if (temp_data[i].temp > 30) {
                printf("Sensor %d is above 30C threshold!\n", i + 1);
            }
        }

        // Print temperature data to file
        FILE *temp_file = fopen("temp_data.txt", "a");
        if (temp_file!= NULL) {
            fprintf(temp_file, "Time: %s\n", ctime(&temp_data[temp_data_count].timestamp));
            fprintf(temp_file, "Sensor %d: %lf\n", temp_data[temp_data_count].sensor_num, temp_data[temp_data_count].temp);
            fprintf(temp_file, "\n");
            fclose(temp_file);
        }

        // Check if maximum temperature data has been reached
        if (temp_data_count >= MAX_TEMP_DATA - 1) {
            temp_data_count = 0;
        } else {
            temp_data_count++;
        }

        // Wait for 5 seconds before next temperature reading
        sleep(5);
    }

    return 0;
}