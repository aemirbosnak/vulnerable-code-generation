//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.1415926535897932384626
#define MAX_TEMP 1000

// Function prototypes
double get_temperature(void);
void display_menu(void);
int get_choice(void);

int main(void) {
    int choice;
    double temperature;

    do {
        display_menu();
        choice = get_choice();

        switch(choice) {
            case 1:
                temperature = get_temperature();
                printf("The current temperature is %.2f degrees Celsius.\n", temperature);
                break;
            case 2:
                printf("Converting %.2f degrees Celsius to Fahrenheit: %.2f degrees Fahrenheit\n", temperature, (temperature * 1.8) + 32);
                break;
            case 3:
                printf("Converting %.2f degrees Fahrenheit to Celsius: %.2f degrees Celsius\n", temperature, (temperature - 32) / 1.8);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(1);

    return 0;
}

double get_temperature(void) {
    double temperature;
    FILE *fp;

    fp = fopen("/sys/class/thermal/thermal_zone0/temp", "r");

    if(fp == NULL) {
        printf("Error: Could not open temperature file.\n");
        exit(1);
    }

    fscanf(fp, "%lf", &temperature);

    fclose(fp);

    return temperature / 1000;
}

void display_menu(void) {
    printf("Temperature Monitor Menu:\n");
    printf("1. Get current temperature\n");
    printf("2. Convert Celsius to Fahrenheit\n");
    printf("3. Convert Fahrenheit to Celsius\n");
    printf("4. Exit\n");
}

int get_choice(void) {
    int choice;

    printf("Enter your choice: ");
    scanf("%d", &choice);

    return choice;
}