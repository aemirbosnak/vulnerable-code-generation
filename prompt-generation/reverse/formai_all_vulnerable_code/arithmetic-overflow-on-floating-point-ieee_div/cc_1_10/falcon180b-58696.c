//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159265358979323846

int main(void)
{
    double current_temperature;
    double average_temperature;
    double temperature_change;
    double temperature_range;
    double temperature_variance;
    int num_readings = 0;
    int i;
    time_t start_time;
    time_t end_time;
    double elapsed_time;
    char *temperature_unit = "Celsius";
    char *temperature_scale = "Metric";
    char *date_format = "%Y-%m-%d %H:%M:%S";
    char *timezone = "UTC";

    printf("Welcome to the Medieval Temperature Monitor!\n");
    printf("Please enter the number of readings you wish to take: ");
    scanf("%d", &num_readings);

    struct tm *start_tm = localtime(&start_time);
    strftime(date_format, 80, date_format, start_tm);

    printf("Starting temperature readings at %s UTC...\n", date_format);

    for (i = 0; i < num_readings; i++)
    {
        printf("Please enter the temperature (in %s) for reading %d: ", temperature_unit, i+1);
        scanf("%lf", &current_temperature);

        if (i == 0)
        {
            average_temperature = current_temperature;
        }
        else
        {
            average_temperature += current_temperature;
        }

        if (current_temperature > average_temperature)
        {
            temperature_change = current_temperature - average_temperature;
        }
        else
        {
            temperature_change = average_temperature - current_temperature;
        }

        temperature_range += temperature_change;
    }

    average_temperature /= num_readings;

    temperature_variance = temperature_range / num_readings;

    printf("Average temperature: %.2lf %s\n", average_temperature, temperature_unit);
    printf("Temperature variance: %.2lf %s\n", temperature_variance, temperature_unit);

    elapsed_time = difftime(end_time, start_time);
    printf("Elapsed time: %ld seconds\n", elapsed_time);

    return 0;
}