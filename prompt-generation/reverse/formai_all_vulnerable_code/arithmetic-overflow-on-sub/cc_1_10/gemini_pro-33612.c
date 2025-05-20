//GEMINI-pro DATASET v1.0 Category: Temperature monitor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

typedef struct {
    float temperature;
    char unit;
} Temperature;

Temperature get_temperature() {
    Temperature temp;
    printf("Enter temperature: ");
    scanf("%f", &temp.temperature);
    printf("Enter unit (C/F): ");
    scanf(" %c", &temp.unit);
    return temp;
}

void print_temperature(Temperature temp) {
    printf("Temperature: %f %c\n", temp.temperature, temp.unit);
}

int main() {

    // Initial temperature settings
    Temperature current_temp = get_temperature();

    // Temperature monitoring loop
    while (1) {

        // Get new temperature reading
        Temperature new_temp = get_temperature();

        // Check for unit change
        if (new_temp.unit != current_temp.unit) {
            if (new_temp.unit == 'C') {
                current_temp.temperature = (current_temp.temperature - 32) / 1.8;
            } else if (new_temp.unit == 'F') {
                current_temp.temperature = current_temp.temperature * 1.8 + 32;
            }
            current_temp.unit = new_temp.unit;
        }

        // Update current temperature
        current_temp.temperature = new_temp.temperature;

        // Print temperature every second
        time_t start_time = time(NULL);
        while (time(NULL) - start_time < 1);
        print_temperature(current_temp);

    }

    return 0;
}