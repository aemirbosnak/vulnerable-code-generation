//FormAI DATASET v1.0 Category: Temperature monitor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Temperature {
    float value;
    char timestamp[20];
} Temperature;

void display_history(Temperature temps[], int length) {
    printf("\nTemperature History:\n");
    for (int i = 0; i < length; i++) {
        printf("Temperature: %.2f C, Timestamp: %s\n", temps[i].value, temps[i].timestamp);
    }
    printf("\n");
}

int main() {
    Temperature temps[10];
    int num_temps = 0;

    while (1) {
        printf("Enter the current temperature in Celsius (or 'exit' to quit): ");
        char input[10];
        scanf("%s", input);

        if (strcmp(input, "exit") == 0) {
            break;
        }

        float temp = strtof(input, NULL);

        if (temp < -273.15) {
            printf("Invalid temperature entered: temperature cannot be less than -273.15 C.\n");
            continue;
        }

        time_t current_time = time(NULL);
        char timestamp[20];
        strftime(timestamp, 20, "%Y-%m-%d %H:%M:%S", localtime(&current_time));

        Temperature new_temp = {temp, timestamp};
        temps[num_temps++] = new_temp;

        if (num_temps >= 10) {
            printf("Temperature limit reached. Showing history.\n");
            display_history(temps, num_temps);
            break;
        }

        printf("Temperature added successfully.\n");
    }

    return 0;
}