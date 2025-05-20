//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: recursive
#include <stdio.h>

#define MAX_READINGS 100

// Function prototype for recursive temperature input
void inputTemperatures(float temperatures[], int count, int max_count);
float calculateAverage(float temperatures[], int count);
void printTemperatures(float temperatures[], int count);

int main() {
    float temperatures[MAX_READINGS];
    int count = 0;

    printf("Welcome to the Temperature Monitor!\n");
    inputTemperatures(temperatures, count, MAX_READINGS);
    
    printf("\nYou have entered the following temperatures:\n");
    printTemperatures(temperatures, count);
    
    float average = calculateAverage(temperatures, count);
    printf("The average temperature is: %.2f\n", average);

    return 0;
}

// Function to recursively input temperature readings
void inputTemperatures(float temperatures[], int count, int max_count) {
    if (count >= max_count) {
        printf("Maximum readings reached!\n");
        return;
    }

    float temp;
    printf("Enter temperature reading %d: ", count + 1);
    scanf("%f", &temp);
    
    temperatures[count] = temp;
    
    char choice;
    printf("Do you want to add another temperature reading? (y/n): ");
    scanf(" %c", &choice);
    
    if (choice == 'y' || choice == 'Y') {
        inputTemperatures(temperatures, count + 1, max_count);
    } else {
        printf("End of temperature input.\n");
    }
}

// Function to calculate the average temperature
float calculateAverage(float temperatures[], int count) {
    if (count == 0) {
        return 0; // Avoid division by zero
    }

    float sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += temperatures[i];
    }

    return sum / count;
}

// Function to print the recorded temperatures
void printTemperatures(float temperatures[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Temperature %d: %.2f\n", i + 1, temperatures[i]);
    }
}