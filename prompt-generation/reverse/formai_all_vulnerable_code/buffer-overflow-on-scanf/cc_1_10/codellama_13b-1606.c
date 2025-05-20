//Code Llama-13B DATASET v1.0 Category: Temperature monitor ; Style: high level of detail
// Temperature monitor program
#include <stdio.h>
#include <stdlib.h>

// Define the temperature range
#define MIN_TEMP 0
#define MAX_TEMP 100

// Define the temperature status codes
#define NORMAL 0
#define WARNING 1
#define CRITICAL 2

// Define the temperature threshold values
#define WARNING_THRESHOLD 25
#define CRITICAL_THRESHOLD 50

// Function to check the temperature status
int check_temp_status(int temperature) {
    if (temperature >= CRITICAL_THRESHOLD) {
        return CRITICAL;
    } else if (temperature >= WARNING_THRESHOLD) {
        return WARNING;
    } else {
        return NORMAL;
    }
}

// Function to print the temperature status
void print_temp_status(int temperature) {
    int status = check_temp_status(temperature);
    switch (status) {
        case NORMAL:
            printf("Temperature is normal (%d)\n", temperature);
            break;
        case WARNING:
            printf("Temperature is in warning range (%d)\n", temperature);
            break;
        case CRITICAL:
            printf("Temperature is critical (%d)\n", temperature);
            break;
        default:
            printf("Unknown temperature status (%d)\n", temperature);
    }
}

int main() {
    // Get the temperature from the user
    int temperature;
    printf("Enter the temperature: ");
    scanf("%d", &temperature);

    // Check the temperature status
    print_temp_status(temperature);

    return 0;
}