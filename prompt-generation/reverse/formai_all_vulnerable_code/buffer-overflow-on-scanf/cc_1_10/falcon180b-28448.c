//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

// Function prototypes
void get_temperature(double *temp);
void display_temperature(double temp);

int main() {
    double temperature;
    char choice;

    do {
        printf("Welcome to the Temperature Monitor!\n");
        printf("Please select an option:\n");
        printf("1. Get current temperature\n");
        printf("2. Convert temperature units\n");
        printf("3. Exit\n");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                printf("Getting temperature...\n");
                get_temperature(&temperature);
                display_temperature(temperature);
                break;
            case '2':
                printf("Converting temperature units...\n");
                break;
            case '3':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid option selected.\n");
        }
    } while(choice!= '3');

    return 0;
}

void get_temperature(double *temp) {
    // Get current temperature from a sensor or API
    *temp = rand() % 100;
}

void display_temperature(double temp) {
    printf("Current temperature: %.2f\n", temp);
}