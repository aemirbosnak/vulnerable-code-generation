//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: recursive
#include <stdio.h>

void getTemperatures(float *sum, float *max, float *min, int *count) {
    float temp;
    printf("Enter temperature (Celsius) or type '999' to finish: ");
    
    if (scanf("%f", &temp) != 1) {
        // Clear invalid input
        while(getchar() != '\n');
        printf("Invalid input. Please enter a valid temperature.\n");
        getTemperatures(sum, max, min, count);
        return;
    }

    if (temp == 999.0) { // Sentinel value to stop input
        return;
    }

    // Update sum
    *sum += temp;
    // Count number of readings
    (*count)++;
    
    // Update max and min
    if (*count == 1) {
        *max = temp;
        *min = temp;
    } else {
        if (temp > *max) {
            *max = temp;
        }
        if (temp < *min) {
            *min = temp;
        }
    }
    
    // Recursive call to get another temperature
    getTemperatures(sum, max, min, count);
}

void displayResults(float sum, float min, float max, int count) {
    if (count == 0) {
        printf("No temperature readings were entered.\n");
        return;
    }
    
    printf("Results:\n");
    printf("Total Readings: %d\n", count);
    printf("Sum of Temperatures: %.2f\n", sum);
    printf("Average Temperature: %.2f\n", sum / count);
    printf("Maximum Temperature: %.2f\n", max);
    printf("Minimum Temperature: %.2f\n", min);
}

int main() {
    float sum = 0.0, max = 0.0, min = 0.0;
    int count = 0;
    
    printf("Welcome to the Temperature Monitor!\n");
    printf("You can enter multiple temperature readings.\n");
    printf("Type '999' when you are finished entering temperatures.\n");

    // Start the recursive function to input temperatures
    getTemperatures(&sum, &max, &min, &count);

    // Display the results
    displayResults(sum, min, max, count);
    
    return 0;
}