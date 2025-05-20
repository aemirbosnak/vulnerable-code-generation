//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_RECORDS 100

// Function prototypes
void displayMenu();
void addTemperature(float temperatures[], int *count);
void displayTemperatures(float temperatures[], int count);
void calculateAverage(float temperatures[], int count);
void findMaxTemperature(float temperatures[], int count);
void findMinTemperature(float temperatures[], int count);

int main() {
    float temperatures[MAX_RECORDS];
    int count = 0;
    int choice;

    printf("Welcome to the Temperature Monitor!\n");
    printf("Let's get ready to monitor some awesome temperatures!\n");

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addTemperature(temperatures, &count);
                break;
            case 2:
                displayTemperatures(temperatures, count);
                break;
            case 3:
                calculateAverage(temperatures, count);
                break;
            case 4:
                findMaxTemperature(temperatures, count);
                break;
            case 5:
                findMinTemperature(temperatures, count);
                break;
            case 6:
                printf("Exiting Temperature Monitor. Stay cool!\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 6.\n");
                break;
        }
        printf("\n");

    } while (choice != 6);

    return 0;
}

void displayMenu() {
    printf("-------- Temperature Monitor Menu --------\n");
    printf("1. Add Temperature\n");
    printf("2. Display Recorded Temperatures\n");
    printf("3. Calculate Average Temperature\n");
    printf("4. Find Maximum Temperature\n");
    printf("5. Find Minimum Temperature\n");
    printf("6. Exit\n");
    printf("------------------------------------------\n");
}

void addTemperature(float temperatures[], int *count) {
    if (*count >= MAX_RECORDS) {
        printf("Temperature record is full! Cannot add more temperatures.\n");
        return;
    }

    float temp;
    printf("Enter the temperature to record (in Celsius): ");
    scanf("%f", &temp);
    
    temperatures[*count] = temp;
    (*count)++;

    printf("Temperature %.2f °C has been recorded successfully!\n", temp);
}

void displayTemperatures(float temperatures[], int count) {
    if (count == 0) {
        printf("No temperatures recorded yet!\n");
        return;
    }

    printf("Recorded Temperatures:\n");
    for (int i = 0; i < count; i++) {
        printf("%.2f °C\n", temperatures[i]);
    }
}

void calculateAverage(float temperatures[], int count) {
    if (count == 0) {
        printf("No temperatures recorded to calculate average!\n");
        return;
    }

    float sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += temperatures[i];
    }

    printf("Average Temperature: %.2f °C\n", sum / count);
}

void findMaxTemperature(float temperatures[], int count) {
    if (count == 0) {
        printf("No temperatures recorded to find the maximum!\n");
        return;
    }

    float max = temperatures[0];
    for (int i = 1; i < count; i++) {
        if (temperatures[i] > max) {
            max = temperatures[i];
        }
    }

    printf("Maximum Temperature: %.2f °C\n", max);
}

void findMinTemperature(float temperatures[], int count) {
    if (count == 0) {
        printf("No temperatures recorded to find the minimum!\n");
        return;
    }

    float min = temperatures[0];
    for (int i = 1; i < count; i++) {
        if (temperatures[i] < min) {
            min = temperatures[i];
        }
    }

    printf("Minimum Temperature: %.2f °C\n", min);
}