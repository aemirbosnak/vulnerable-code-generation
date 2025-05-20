//FormAI DATASET v1.0 Category: Temperature monitor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_TEMP 100.0
#define MIN_TEMP 0.0

float read_temp(float temp)
{
    printf("Enter temperature reading: ");
    scanf("%f", &temp);

    if (temp < MIN_TEMP || temp > MAX_TEMP) {
        printf("Invalid reading. Temperature must be between %.1f and %.1f.\n", MIN_TEMP, MAX_TEMP);
        exit(EXIT_FAILURE);
    }

    return temp;
}

bool is_hot(float temp)
{
    return temp > 25.0 ? true : false;
}

bool is_cold(float temp)
{
    return temp < 10.0 ? true : false;
}

int main()
{
    float temp = 0.0;
    float max_temp = 0.0;
    float min_temp = MAX_TEMP;
    float sum_temp = 0.0;
    float avg_temp = 0.0;
    int count = 0;

    printf("Temperature Monitor\n\n");

    while (true) {
        temp = read_temp(temp);

        if (temp > max_temp) {
            max_temp = temp;
        }

        if (temp < min_temp) {
            min_temp = temp;
        }

        sum_temp += temp;
        count++;

        if (is_hot(temp)) {
            printf("Temperature is HOT.\n");
        }

        if (is_cold(temp)) {
            printf("Temperature is COLD.\n");
        }

        avg_temp = sum_temp / count;

        printf("Maximum temperature: %.1f\n", max_temp);
        printf("Minimum temperature: %.1f\n", min_temp);
        printf("Average temperature: %.1f\n\n", avg_temp);
    }

    return 0;
}