//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int current_temperature = 0;
    int previous_temperature = 0;
    int temperature_change = 0;
    char temperature_unit = 'C';
    char *temperature_units[] = {"C", "F"};
    int temperature_unit_index = 0;
    time_t start_time, end_time;
    double elapsed_time;

    printf("Welcome to the Retro Temperature Monitor!\n");
    printf("Please select a temperature unit: ");
    scanf("%c", &temperature_unit);

    printf("Enter the initial temperature (in %c): ", temperature_unit);
    scanf("%d", &current_temperature);

    previous_temperature = current_temperature;
    temperature_unit_index = (temperature_unit == 'C')? 0 : 1;

    while (1) {
        time(&start_time);
        fflush(stdout);
        fflush(stdin);

        while (1) {
            time(&end_time);
            elapsed_time = difftime(end_time, start_time);

            if (elapsed_time >= 1.0) {
                break;
            }

            fflush(stdout);
            fflush(stdin);
        }

        temperature_change = current_temperature - previous_temperature;
        previous_temperature = current_temperature;

        printf("\r%s Temperature: %d %c (%+d)", temperature_units[temperature_unit_index], current_temperature, temperature_unit, temperature_change);
        fflush(stdout);

        usleep(100000);
    }

    return 0;
}