//FormAI DATASET v1.0 Category: Temperature monitor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define MAX_TEMPS 100
#define TEMP_WARNING 25.0

int read_temperatures(float temps[]) {
    int count = 0;
    float temp;
    printf("Enter temperature values (Q to quit):\n");
    while (count < MAX_TEMPS && scanf("%f", &temp) == 1) {
        temps[count++] = temp;
    }
    return count;
}

void print_temperatures(float temps[], int count) {
    printf("Temperature values:\n");
    for (int i = 0; i < count; i++) {
        printf("%.1f ", temps[i]);
    }
    printf("\n");
}

float find_max_temp(float temps[], int count) {
    float max = temps[0];
    for (int i = 1; i < count; i++) {
        if (temps[i] > max) {
            max = temps[i];
        }
    }
    return max;
}

float find_min_temp(float temps[], int count) {
    float min = temps[0];
    for (int i = 1; i < count; i++) {
        if (temps[i] < min) {
            min = temps[i];
        }
    }
    return min;
}

float find_avg_temp(float temps[], int count) {
    float sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += temps[i];
    }
    return sum / (float) count;
}

void print_temp_warnings(float temps[], int count) {
    printf("Temperature warnings:\n");
    for (int i = 0; i < count; i++) {
        if (temps[i] > TEMP_WARNING) {
            printf("Warning: temperature %.1f exceeds warning threshold of %.1f\n", temps[i], TEMP_WARNING);
        }
    }
}

int main(void) {
    float temps[MAX_TEMPS];
    int count = read_temperatures(temps);

    if (count == 0) {
        printf("No temperatures entered.\n");
        return 0;
    }

    print_temperatures(temps, count);

    float max_temp = find_max_temp(temps, count);
    printf("Maximum temperature: %.1f\n", max_temp);

    float min_temp = find_min_temp(temps, count);
    printf("Minimum temperature: %.1f\n", min_temp);

    float avg_temp = find_avg_temp(temps, count);
    printf("Average temperature: %.1f\n", avg_temp);

    print_temp_warnings(temps, count);

    return 0;
}