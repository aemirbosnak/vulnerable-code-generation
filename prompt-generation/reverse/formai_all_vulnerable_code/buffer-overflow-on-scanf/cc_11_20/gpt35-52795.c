//FormAI DATASET v1.0 Category: Temperature Converter ; Style: configurable
#include <stdio.h>

int main() {
    int inputScale, outputScale, numTemps, i;
    float inputTemp, outputTemp;

    printf("Select input scale: \n");
    printf("1. Fahrenheit\n");
    printf("2. Celsius\n");
    printf("3. Kelvin\n");
    scanf("%d", &inputScale);

    printf("Select output scale: \n");
    printf("1. Fahrenheit\n");
    printf("2. Celsius\n");
    printf("3. Kelvin\n");
    scanf("%d", &outputScale);

    printf("Enter the number of temperatures to convert: ");
    scanf("%d", &numTemps);

    for (i = 0; i < numTemps; i++) {
        printf("Enter the temperature in the input scale: ");
        scanf("%f", &inputTemp);

        if (inputScale == 1) {
            // Fahrenheit to Celsius
            if (outputScale == 2) {
                outputTemp = (inputTemp - 32) * 5/9;
            }
            // Fahrenheit to Kelvin
            else if (outputScale == 3) {
                outputTemp = (inputTemp - 32) * 5/9 + 273.15;
            }
        }

        else if (inputScale == 2) {
            // Celsius to Fahrenheit
            if (outputScale == 1) {
                outputTemp = (inputTemp * 9/5) + 32;
            }
            // Celsius to Kelvin
            else if (outputScale == 3) {
                outputTemp = inputTemp + 273.15;
            }
        }

        else if (inputScale == 3) {
            // Kelvin to Fahrenheit
            if (outputScale == 1) {
                outputTemp = ((inputTemp - 273.15) * 9/5) + 32;
            }
            // Kelvin to Celsius
            else if (outputScale == 2) {
                outputTemp = inputTemp - 273.15;
            }
        }

        printf("The temperature in the output scale is: %.2f\n", outputTemp);
    }

    return 0;
}