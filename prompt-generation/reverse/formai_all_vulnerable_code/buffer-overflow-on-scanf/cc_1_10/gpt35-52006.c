//FormAI DATASET v1.0 Category: Unit converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// This program will convert temperatures from Celsius to Fahrenheit and vice versa using multi-threading.

// Global variables
pthread_mutex_t mutex;
double tempValue;
char tempUnit;
int isCelsius; // 1 for Celsius, 0 for Fahrenheit

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    double fahrenheit = (celsius * 9 / 5) + 32;
    return fahrenheit;
}

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    double celsius = (fahrenheit - 32) * 5 / 9;
    return celsius;
}

// Thread function to handle temperature conversion
void *converter(void *arg) {
    double value = *(double*) arg;
    
    // Locking the mutex before updating the global variables
    pthread_mutex_lock(&mutex);
    
    if (isCelsius) {
        tempUnit = 'C';
        tempValue = value;
        printf("%.2f degrees Celsius = %.2f degrees Fahrenheit\n", value, celsiusToFahrenheit(value));
    } else {
        tempUnit = 'F';
        tempValue = value;
        printf("%.2f degrees Fahrenheit = %.2f degrees Celsius\n", value, fahrenheitToCelsius(value));
    }
    
    // Unlocking the mutex after updating the global variables
    pthread_mutex_unlock(&mutex);
    
    pthread_exit(NULL);
}

int main() {
    double temp;
    char unit;
    
    // Getting user input for temperature value and unit
    printf("Enter temperature value: ");
    scanf("%lf", &temp);
    printf("Enter unit (C/F): ");
    scanf(" %c", &unit);
    
    // Setting isCelsius flag based on user input for unit
    if (unit == 'C' || unit == 'c') {
        isCelsius = 1;
    } else if (unit == 'F' || unit == 'f') {
        isCelsius = 0;
    } else {
        printf("Invalid unit. Please enter either C or F.\n");
        exit(1);
    }
    
    // Initialize the mutex
    pthread_mutex_init(&mutex, NULL);
    
    // Create the thread for temperature conversion
    pthread_t tid;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_create(&tid, &attr, converter, &temp);
    
    // Wait for the thread to finish before printing the global variables
    pthread_join(tid, NULL);
    
    printf("%.2f degrees %c is stored in the global variables.\n", tempValue, tempUnit);
    
    // Destroy the mutex before exiting
    pthread_mutex_destroy(&mutex);
    
    return 0;
}