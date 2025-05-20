//GPT-4o-mini DATASET v1.0 Category: Performance-Critical Component ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846
#define MAX_TERMS 10000

// Function to calculate the sine of an angle using Taylor series
double sine_taylor_series(double angle) {
    double result = 0.0;
    double term = angle; // First term is the angle itself
    int sign = 1; // Used to alternate the signs in the series

    for (int n = 1; n < MAX_TERMS; n++) {
        result += term; // Add the current term to the result
        term *= (-1) * angle * angle / ((2 * n) * (2 * n + 1)); // Calculate the next term
    }

    return result;
}

// Function to calculate the cosine of an angle using Taylor series
double cosine_taylor_series(double angle) {
    double result = 1.0; // First term is 1
    double term = 1.0; // For cosine, the first term is 1
    int sign = -1; // Used to alternate the signs in the series

    for (int n = 1; n < MAX_TERMS; n++) {
        term *= (-1) * angle * angle / ((2 * n - 1) * (2 * n)); // Calculate the next term 
        result += term; // Add the current term to the result
    }

    return result;
}

// Function to calculate the tangent of an angle using sine and cosine
double tangent(double angle) {
    double sine_value = sine_taylor_series(angle);
    double cosine_value = cosine_taylor_series(angle);

    if (fabs(cosine_value) < 1e-10) { // Check for division by zero
        printf("Tangent undefined at angle: %f (cosine is near zero)\n", angle);
        return NAN;
    }

    return sine_value / cosine_value; // Return the tangent value
}

// Main function to test the trigonometric functions
int main() {
    double angle_degrees;
    printf("Enter an angle in degrees: ");
    scanf("%lf", &angle_degrees);

    // Convert degrees to radians
    double angle_radians = angle_degrees * PI / 180.0;

    // Measure execution time for sine calculation
    clock_t start_time = clock();
    double sine_value = sine_taylor_series(angle_radians);
    clock_t end_time = clock();
    double sine_execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // Measure execution time for cosine calculation
    start_time = clock();
    double cosine_value = cosine_taylor_series(angle_radians);
    end_time = clock();
    double cosine_execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // Measure execution time for tangent calculation
    start_time = clock();
    double tangent_value = tangent(angle_radians);
    end_time = clock();
    double tangent_execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // Output results
    printf("Sine(%lf°) = %lf (computed in %lf seconds)\n", angle_degrees, sine_value, sine_execution_time);
    printf("Cosine(%lf°) = %lf (computed in %lf seconds)\n", angle_degrees, cosine_value, cosine_execution_time);
    
    if (!isnan(tangent_value)) {
        printf("Tangent(%lf°) = %lf (computed in %lf seconds)\n", angle_degrees, tangent_value, tangent_execution_time);
    }

    return 0;
}