//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMPERATURES 1000
#define MIN_TEMPERATURE -1000

struct Temperature {
    time_t timestamp;
    int value;
};

int main() {
    char input[100];
    int temperature;
    time_t start_time = time(NULL);

    struct Temperature temperatures[MAX_TEMPERATURES];
    int temperature_count = 0;

    while (1) {
        printf("Enter temperature (or 'q' to quit): ");
        fgets(input, sizeof(input), stdin);

        if (strcmp(input, "q") == 0) {
            break;
        }

        if (sscanf(input, "%d", &temperature)!= 1) {
            printf("Invalid temperature\n");
            continue;
        }

        if (temperature_count >= MAX_TEMPERATURES) {
            printf("Maximum temperature count reached\n");
            continue;
        }

        temperatures[temperature_count].timestamp = start_time;
        temperatures[temperature_count].value = temperature;
        temperature_count++;
    }

    printf("Temperature log:\n");
    for (int i = 0; i < temperature_count; i++) {
        printf("%ld: %d\n", temperatures[i].timestamp, temperatures[i].value);
    }

    return 0;
}