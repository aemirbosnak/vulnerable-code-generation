//FormAI DATASET v1.0 Category: Temperature monitor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TEMP 100

int main()
{
    int temp, temp_history[MAX_TEMP] = {0}, temp_sum = 0, temp_count = 0;
    float temp_avg;
    char time_str[100];
    time_t t;

    printf("Welcome to Temperature Monitor!\n\n");

    while(1) {

        // Get current time
        time(&t);
        strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", localtime(&t));

        // Get temperature input from user
        printf("Enter temperature (between -30 and 50 degrees Celsius): ");
        scanf("%d", &temp);

        // Check if temperature is within valid range
        if(temp >= -30 && temp <= 50) {

            // Store temperature in history array
            temp_history[temp_count % MAX_TEMP] = temp;
            temp_count++;

            // Calculate average temperature
            temp_sum += temp;
            if(temp_count > MAX_TEMP) {
                temp_sum -= temp_history[(temp_count - MAX_TEMP - 1) % MAX_TEMP];
            }
            temp_avg = (float)temp_sum / ((temp_count < MAX_TEMP) ? temp_count : MAX_TEMP);

            // Print temperature details
            printf("\n\nTemperature: %d C\n", temp);
            printf("Time: %s\n", time_str);
            printf("Average Temperature (last %d readings): %.2f C\n\n", ((temp_count < MAX_TEMP) ? temp_count : MAX_TEMP), temp_avg);

        } else {

            // Display error message if input is not within valid range
            printf("Error: Temperature must be between -30 and 50 degrees Celsius. Try again.\n\n");

        }
    }

    return 0;
}