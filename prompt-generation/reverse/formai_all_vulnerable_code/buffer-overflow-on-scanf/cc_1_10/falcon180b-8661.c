//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    double temperature = 0.0;
    double min_temp = 0.0;
    double max_temp = 0.0;
    double avg_temp = 0.0;
    int count = 0;
    int num_readings = 10;
    time_t start_time, end_time;
    struct tm *time_info;
    char temp_string[20];

    printf("Starting temperature monitor...\n");
    printf("Enter the number of readings to take: ");
    scanf("%d", &num_readings);
    printf("Enter the time interval in seconds: ");
    scanf("%d", &num_readings);

    // Set the start time
    time(&start_time);
    time_info = localtime(&start_time);
    strftime(temp_string, 20, "%Y-%m-%d %H:%M:%S", time_info);
    printf("Start time: %s\n", temp_string);

    // Take the readings
    for (int i = 0; i < num_readings; i++) {
        double temp_reading = rand() % 100;
        temperature += temp_reading;
        count++;
        if (i == 0) {
            min_temp = temp_reading;
            max_temp = temp_reading;
        }
        else {
            if (temp_reading < min_temp) {
                min_temp = temp_reading;
            }
            if (temp_reading > max_temp) {
                max_temp = temp_reading;
            }
        }
    }

    // Calculate the average temperature
    avg_temp = temperature / count;

    // Set the end time
    time(&end_time);
    time_info = localtime(&end_time);
    strftime(temp_string, 20, "%Y-%m-%d %H:%M:%S", time_info);
    printf("End time: %s\n", temp_string);

    // Print the results
    printf("Minimum temperature: %.2f\n", min_temp);
    printf("Maximum temperature: %.2f\n", max_temp);
    printf("Average temperature: %.2f\n", avg_temp);

    return 0;
}