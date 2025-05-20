//Falcon2-11B DATASET v1.0 Category: Temperature monitor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMPERATURE 100
#define MIN_TEMPERATURE -100

int main() {
    int temperature;
    char input;
    double average_temperature;
    FILE* file;
    int temperature_data[10];
    int i;

    srand(time(NULL));

    file = fopen("temperature_data.txt", "w");
    if (file == NULL) {
        printf("Error opening file");
        return 1;
    }

    for (i = 0; i < 10; i++) {
        temperature = rand() % (MAX_TEMPERATURE - MIN_TEMPERATURE + 1) + MIN_TEMPERATURE;
        fprintf(file, "%d\n", temperature);
    }

    fclose(file);

    file = fopen("temperature_data.txt", "r");
    if (file == NULL) {
        printf("Error opening file");
        return 1;
    }

    while ((input = fgetc(file))!= EOF) {
        temperature_data[i] = input;
        i++;
    }

    fclose(file);

    for (i = 0; i < 10; i++) {
        temperature = temperature_data[i];
        average_temperature += temperature;
    }

    average_temperature = average_temperature / 10;

    printf("Average temperature: %.2f\n", average_temperature);

    return 0;
}