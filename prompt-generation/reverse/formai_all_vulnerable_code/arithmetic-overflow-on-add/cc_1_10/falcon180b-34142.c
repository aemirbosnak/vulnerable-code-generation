//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Function to convert Celsius to Fahrenheit
double celsius_to_fahrenheit(double celsius) {
    return (celsius * 1.8) + 32;
}

// Function to convert Fahrenheit to Celsius
double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32) / 1.8;
}

// Function to get the current date and time
void get_current_datetime(struct tm *datetime) {
    time_t now = time(NULL);
    localtime_r(&now, datetime);
}

int main() {
    double temperature;
    char unit;
    struct tm datetime;
    FILE *log_file;

    // Open the log file
    log_file = fopen("temperature_log.txt", "a");
    if (log_file == NULL) {
        printf("Error: Failed to open log file.\n");
        exit(1);
    }

    // Get the current date and time
    get_current_datetime(&datetime);

    // Prompt the user to enter the temperature and unit
    printf("Enter the temperature (e.g. 25.5): ");
    scanf("%lf", &temperature);
    printf("Enter the unit (C or F): ");
    scanf(" %c", &unit);

    // Convert the temperature if necessary
    if (unit == 'F') {
        temperature = fahrenheit_to_celsius(temperature);
        unit = 'C';
    }

    // Write the temperature to the log file
    fprintf(log_file, "%.2lf %c - %04d-%02d-%02d %02d:%02d:%02d\n", temperature, unit,
            datetime.tm_year + 1900, datetime.tm_mon + 1, datetime.tm_mday, datetime.tm_hour, datetime.tm_min, datetime.tm_sec);

    // Close the log file
    fclose(log_file);

    printf("Temperature logged successfully.\n");

    return 0;
}