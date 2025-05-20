//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: scientific
#include <stdio.h>

#define MAX_READINGS 100

// Function declarations
void inputTemperatures(float temps[], int count);
void inputReactionRates(float rates[], int count);
float calculateAverage(float rates[], int count);
void displayResults(float temps[], float rates[], int count, float averageRate);

int main() {
    int n;
    float temperatures[MAX_READINGS];
    float reactionRates[MAX_READINGS];

    // Get the number of readings from user
    printf("Enter the number of temperature readings (max %d): ", MAX_READINGS);
    scanf("%d", &n);

    // Input validation
    if (n <= 0 || n > MAX_READINGS) {
        printf("Invalid number of readings. Please run the program again with a valid number.\n");
        return 1;
    }

    // Input temperatures
    inputTemperatures(temperatures, n);

    // Input corresponding reaction rates
    inputReactionRates(reactionRates, n);

    // Calculate average reaction rate
    float averageRate = calculateAverage(reactionRates, n);

    // Display results
    displayResults(temperatures, reactionRates, n, averageRate);

    return 0;
}

// Function to input temperatures from the user
void inputTemperatures(float temps[], int count) {
    printf("Enter the temperatures (in Celsius):\n");
    for (int i = 0; i < count; i++) {
        printf("Temperature %d: ", i + 1);
        scanf("%f", &temps[i]);
    }
}

// Function to input reaction rates
void inputReactionRates(float rates[], int count) {
    printf("Enter the corresponding reaction rates:\n");
    for (int i = 0; i < count; i++) {
        printf("Reaction rate for temperature %.2f: ", rates[i]);
        scanf("%f", &rates[i]);
    }
}

// Function to calculate the average of reaction rates
float calculateAverage(float rates[], int count) {
    float sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += rates[i];
    }
    return sum / count;
}

// Function to display the results
void displayResults(float temps[], float rates[], int count, float averageRate) {
    printf("\n---- Experiment Results ----\n");
    printf("Temperature (Celsius)\tReaction Rate\n");
    printf("------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%.2f\t\t\t%.2f\n", temps[i], rates[i]);
    }
    printf("------------------------------------\n");
    printf("Average Reaction Rate: %.2f\n", averageRate);
}