//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    struct tm current_time;
    double current_temp;
    int choice;

    time_t now = time(NULL);
    localtime_r(&now, &current_time);

    do {
        printf("Current time: %02d:%02d:%02d\n", current_time.tm_hour, current_time.tm_min, current_time.tm_sec);
        printf("Current temperature: ");
        scanf("%lf", &current_temp);

        printf("\n");
        printf("1. Convert temperature to Celsius\n");
        printf("2. Convert temperature to Fahrenheit\n");
        printf("3. Convert temperature to Kelvin\n");
        printf("4. Exit\n");
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                current_temp -= 32;
                current_temp *= 5.0/9.0;
                printf("Temperature in Celsius: %.2lf\n", current_temp);
                break;
            case 2:
                current_temp = (current_temp - 32) * 5.0/9.0;
                printf("Temperature in Fahrenheit: %.2lf\n", current_temp);
                break;
            case 3:
                current_temp += 273.15;
                printf("Temperature in Kelvin: %.2lf\n", current_temp);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= 4);

    return 0;
}