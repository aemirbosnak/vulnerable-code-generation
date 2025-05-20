//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

// Define constants for unit types
#define UNIT_LENGTH 1
#define UNIT_WEIGHT 2
#define UNIT_TEMPERATURE 3

// Structure to hold conversion task details
typedef struct {
    int unitType;
    double value;
    double result;
} ConversionTask;

// Function declarations
void* lengthConverter(void* task);
void* weightConverter(void* task);
void* temperatureConverter(void* task);
void convertUnits(ConversionTask* task);

// Main function
int main() {
    pthread_t threads[3];
    ConversionTask tasks[3];
    
    // Get input from user
    printf("Unit Conversion Program\n");
    printf("Choose conversion type:\n");
    printf("1. Length (meters to feet)\n");
    printf("2. Weight (kilograms to pounds)\n");
    printf("3. Temperature (Celsius to Fahrenheit)\n");
    
    for (int i = 0; i < 3; i++) {
        printf("Enter value for type %d: ", i + 1);
        scanf("%lf", &tasks[i].value);
        tasks[i].unitType = i + 1;
    }
    
    // Create threads for each conversion
    pthread_create(&threads[0], NULL, lengthConverter, &tasks[0]);
    pthread_create(&threads[1], NULL, weightConverter, &tasks[1]);
    pthread_create(&threads[2], NULL, temperatureConverter, &tasks[2]);
    
    // Wait for all threads to finish
    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }
    
    // Display results
    for (int i = 0; i < 3; i++) {
        printf("Converted value for type %d: %lf\n", i + 1, tasks[i].result);
    }
    
    return 0;
}

// Length conversion from meters to feet
void* lengthConverter(void* task) {
    ConversionTask* convTask = (ConversionTask*)task;
    convTask->result = convTask->value * 3.28084; // 1 meter = 3.28084 feet
    return NULL;
}

// Weight conversion from kilograms to pounds
void* weightConverter(void* task) {
    ConversionTask* convTask = (ConversionTask*)task;
    convTask->result = convTask->value * 2.20462; // 1 kilogram = 2.20462 pounds
    return NULL;
}

// Temperature conversion from Celsius to Fahrenheit
void* temperatureConverter(void* task) {
    ConversionTask* convTask = (ConversionTask*)task;
    convTask->result = (convTask->value * 9.0 / 5.0) + 32.0; // Celsius to Fahrenheit
    return NULL;
}