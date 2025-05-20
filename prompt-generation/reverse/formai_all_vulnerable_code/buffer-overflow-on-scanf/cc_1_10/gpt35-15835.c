//FormAI DATASET v1.0 Category: Temperature monitor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MIN_TEMP 0
#define MAX_TEMP 100

int main(void) {
    int temp = 0;
    bool is_celsius = true;

    printf("Welcome to the temperature monitoring system\n\n");

    while(true) {
        printf("Enter temperature value (0-100): ");
        scanf("%d", &temp);

        if(temp >= MIN_TEMP && temp <= MAX_TEMP) {
            if(is_celsius) {
                printf("Temperature in Celsius: %d\n", temp);
                printf("Temperature in Fahrenheit: %d\n\n", (temp * 9/5) + 32);
            } else {
                printf("Temperature in Fahrenheit: %d\n", temp);
                printf("Temperature in Celsius: %d\n\n", (temp - 32) * 5/9);
            }
        } else {
            printf("Invalid temperature value\n");
            continue;
        }

        printf("Toggle display to Celsius or Fahrenheit? (0 for C, 1 for F, 2 to exit): ");
        int choice = 0;
        scanf("%d", &choice);

        switch(choice) {
            case 0:
                is_celsius = true;
                printf("\nDisplay set to Celsius\n\n");
                break;
            case 1:
                is_celsius = false;
                printf("\nDisplay set to Fahrenheit\n\n");
                break;
            case 2:
                printf("\nExiting the temperature monitoring system\n");
                exit(0);
                break;
            default:
                printf("\nInvalid choice\n\n");
                break;
        }
    }

    return 0;
}