//Code Llama-13B DATASET v1.0 Category: Temperature monitor ; Style: mathematical
// Temperature Monitor Program
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MIN_TEMP 0
#define MAX_TEMP 100

// Function to check if the temperature is within the acceptable range
int is_valid_temperature(float temp) {
    return (temp >= MIN_TEMP && temp <= MAX_TEMP);
}

// Function to calculate the current temperature
float get_current_temperature() {
    float temp;
    printf("Enter the current temperature: ");
    scanf("%f", &temp);
    return temp;
}

// Function to calculate the average temperature
float get_average_temperature(float temp1, float temp2) {
    return (temp1 + temp2) / 2;
}

// Function to calculate the range of temperature
float get_temperature_range(float temp1, float temp2) {
    return fabs(temp1 - temp2);
}

int main() {
    float temp1, temp2, temp_avg, temp_range;

    // Get the current temperature
    temp1 = get_current_temperature();

    // Get the average temperature
    temp2 = get_current_temperature();
    temp_avg = get_average_temperature(temp1, temp2);

    // Get the range of temperature
    temp_range = get_temperature_range(temp1, temp2);

    // Check if the temperature is within the acceptable range
    if (is_valid_temperature(temp_avg)) {
        printf("The average temperature is: %f\n", temp_avg);
        printf("The range of temperature is: %f\n", temp_range);
    } else {
        printf("The temperature is not within the acceptable range.\n");
    }

    return 0;
}