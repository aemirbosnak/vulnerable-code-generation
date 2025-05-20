//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

struct sensor {
    char name[50];
    int value;
};

int main() {
    int num_sensors;
    struct sensor sensors[100];
    double temp_avg;

    // Get number of sensors from user
    printf("Enter the number of temperature sensors: ");
    scanf("%d", &num_sensors);

    // Get sensor names and initial temperatures
    for (int i = 0; i < num_sensors; i++) {
        printf("Enter sensor %d name: ", i+1);
        scanf("%s", sensors[i].name);
        printf("Enter initial temperature for %s: ", sensors[i].name);
        scanf("%d", &sensors[i].value);
    }

    // Main loop
    while (1) {
        // Get current time
        time_t now = time(NULL);
        struct tm *t = localtime(&now);

        // Calculate average temperature
        temp_avg = 0;
        for (int i = 0; i < num_sensors; i++) {
            temp_avg += sensors[i].value;
        }
        temp_avg /= num_sensors;

        // Print current date and time along with average temperature
        printf("%s: Average temperature: %.2f\n", asctime(t), temp_avg);

        // Wait for 1 second before next iteration
        sleep(1);
    }

    return 0;
}