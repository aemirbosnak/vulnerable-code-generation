//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SAMPLE_INTERVAL 1000 // Sample interval in milliseconds
#define SAMPLE_COUNT 10 // Number of samples to take
#define THERMISTOR_RESISTANCE 10000 // Resistance of thermistor at 25°C in Ohms
#define ADC_MAX_VALUE 1023 // Maximum value of ADC

// Function to read temperature from thermistor
float read_temperature(int adc_value) {
    float temperature = 0;
    temperature = (THERMISTOR_RESISTANCE / (float)adc_value) - 1;
    temperature = log(temperature);
    temperature /= log(2);
    temperature = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * temperature * temperature)) * temperature);
    temperature = temperature - 273.15;
    return temperature;
}

int main() {
    int i;
    float temperature_array[SAMPLE_COUNT];
    float average_temperature = 0;

    // Initialize ADC
    FILE *fp;
    fp = fopen("/sys/bus/iio/devices/iio:device0/in_voltage6_raw", "r");
    if (fp == NULL) {
        printf("Error opening ADC device\n");
        exit(1);
    }

    // Take samples
    for (i = 0; i < SAMPLE_COUNT; i++) {
        int adc_value;
        fscanf(fp, "%d", &adc_value);
        temperature_array[i] = read_temperature(adc_value);
        printf("Sample %d: Temperature = %.2f°C\n", i+1, temperature_array[i]);
        usleep(SAMPLE_INTERVAL);
    }

    // Calculate average temperature
    for (i = 0; i < SAMPLE_COUNT; i++) {
        average_temperature += temperature_array[i];
    }
    average_temperature /= SAMPLE_COUNT;

    printf("\nAverage temperature = %.2f°C\n", average_temperature);

    return 0;
}