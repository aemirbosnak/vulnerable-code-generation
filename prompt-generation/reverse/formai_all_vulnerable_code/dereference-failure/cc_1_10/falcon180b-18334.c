//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

int main() {
    int i, j;
    double temperature;
    char input[50];
    FILE *file;
    struct tm *timeinfo;
    time_t now;

    // Initialize the program
    printf("Welcome to the Temperature Monitor!\n");

    // Open the temperature file
    file = fopen("temperature.txt", "a");
    if (file == NULL) {
        printf("Error opening temperature file.\n");
        exit(1);
    }

    // Set the initial time
    time(&now);
    timeinfo = localtime(&now);
    printf("Program started at %s.\n", asctime(timeinfo));

    // Main loop
    while (TRUE) {
        // Get the current temperature
        printf("Enter the current temperature: ");
        fgets(input, sizeof(input), stdin);
        sscanf(input, "%lf", &temperature);

        // Convert to Celsius and Fahrenheit
        double celsius = (temperature - 32) * 5 / 9;
        double fahrenheit = temperature * 9 / 5 + 32;

        // Write the data to the file
        fprintf(file, "%s - Temperature: %.2lf C / %.2lf F\n", asctime(timeinfo), celsius, fahrenheit);

        // Check if it's time to exit
        now = time(NULL);
        timeinfo = localtime(&now);
        if (timeinfo->tm_hour == 23 && timeinfo->tm_min == 59) {
            printf("Program ended at %s.\n", asctime(timeinfo));
            fclose(file);
            exit(0);
        }

        // Wait for one minute
        for (i = 0; i < 60; i++) {
            for (j = 0; j < 1000000; j++) {
                ;
            }
            printf(".");
        }
        printf("\n");
    }

    return 0;
}