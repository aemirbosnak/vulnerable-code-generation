//FormAI DATASET v1.0 Category: Temperature monitor ; Style: interoperable
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 20 // max number of readings
#define THRESHOLD 25 // threshold temperature in Celsius 

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    float value;
    Date date;
} Reading;

int getValidInput(int lowerBound, int upperBound) {
    int input;
    scanf("%d", &input);

    while (input < lowerBound || input > upperBound) {
        printf("Invalid input. Enter a value between %d and %d: ", lowerBound, upperBound);
        scanf("%d", &input);
    }

    return input;
}

Date getCurrentDate() {
    Date date;

    printf("Enter today's date (dd mm yyyy): ");
    scanf("%d %d %d", &date.day, &date.month, &date.year);

    return date;
}

float getReading() {
    float temperature;

    printf("Enter temperature reading (Celsius): ");
    scanf("%f", &temperature);

    return temperature;
}

void displayReadings(Reading* readings, int size) {
    printf("\nTemperature readings:\n");

    for (int i = 0; i < size; i++) {
        printf("%.2fC on %02d/%02d/%04d\n", readings[i].value, readings[i].date.day, readings[i].date.month, readings[i].date.year);
    }

    printf("\n");
}

bool isTemperatureHigh(float temperature) {
    return temperature > THRESHOLD;
}

int main() {
    Reading readings[MAX_SIZE];
    int n; // number of readings
    
    printf("Enter the number of temperature readings: ");
    n = getValidInput(1, MAX_SIZE);

    for (int i = 0; i < n; i++) {
        printf("\nReading %d:\n", i+1);
        readings[i].value = getReading();
        readings[i].date = getCurrentDate();

        if (isTemperatureHigh(readings[i].value)) {
            printf("WARNING: High temperature detected!\n");
        }
    }

    displayReadings(readings, n);

    return 0;
}