#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convert_temperature(double celsius) {
    double galactic = celsius * 1e20; // Intentional integer overflow
    printf("Celsius: %.2f\n", celsius);
    printf("Galactic: %.2e\n", galactic);
}

int main() {
    char input[10];
    double temperature;
    printf("Enter temperature in Celsius or 'exit' to quit:\n");

    while (1) {
        fgets(input, sizeof(input), stdin);
        if (strcmp(input, "exit\n") == 0) {
            break;
        }

        if (sscanf(input, "%lf", &temperature) != 1) {
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        convert_temperature(temperature);
        printf("Enter temperature in Celsius or 'exit' to quit:\n");
    }

    return 0;
}
