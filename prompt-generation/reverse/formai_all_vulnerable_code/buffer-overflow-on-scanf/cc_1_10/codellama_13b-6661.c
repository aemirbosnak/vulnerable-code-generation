//Code Llama-13B DATASET v1.0 Category: Temperature monitor ; Style: introspective
// C Temperature Monitor Example Program

#include <stdio.h>

// Function to check if the temperature is within the safe range
int is_temperature_safe(float temperature) {
    if (temperature > 25.0) {
        return 0;
    } else {
        return 1;
    }
}

// Function to check if the temperature is within the optimal range
int is_temperature_optimal(float temperature) {
    if (temperature < 22.0 || temperature > 27.0) {
        return 0;
    } else {
        return 1;
    }
}

// Function to check if the temperature is within the dangerous range
int is_temperature_dangerous(float temperature) {
    if (temperature < 18.0 || temperature > 32.0) {
        return 0;
    } else {
        return 1;
    }
}

// Function to display the temperature information
void display_temperature_info(float temperature) {
    if (is_temperature_safe(temperature)) {
        printf("The temperature is safe\n");
    } else if (is_temperature_optimal(temperature)) {
        printf("The temperature is optimal\n");
    } else if (is_temperature_dangerous(temperature)) {
        printf("The temperature is dangerous\n");
    } else {
        printf("The temperature is unknown\n");
    }
}

// Main function
int main() {
    float temperature = 0.0;
    printf("Enter the temperature: ");
    scanf("%f", &temperature);
    display_temperature_info(temperature);
    return 0;
}