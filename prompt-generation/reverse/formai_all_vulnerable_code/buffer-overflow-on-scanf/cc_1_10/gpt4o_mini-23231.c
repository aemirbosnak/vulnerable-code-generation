//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: complex
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX_TERMS 100
#define PI 3.14159265358979323846

typedef struct {
    double angle;
    double sine;
    double cosine;
    double tangent;
    double secant;
    double cosecant;
    double cotangent;
} TrigValues;

void calculate_trigonometric_values(TrigValues *values) {
    values->sine = sin(values->angle);
    values->cosine = cos(values->angle);
    if (values->cosine != 0) {
        values->secant = 1 / values->cosine;
    } else {
        values->secant = INFINITY; // Handle division by zero
    }
    if (values->sine != 0) {
        values->cosecant = 1 / values->sine;
    } else {
        values->cosecant = INFINITY; // Handle division by zero
    }
    if (values->sine != 0 && values->cosine != 0) {
        values->tangent = values->sine / values->cosine;
        values->cotangent = values->cosine / values->sine;
    } else {
        values->tangent = INFINITY; // Handle undefined case
        values->cotangent = INFINITY; // Handle undefined case
    }
}

void display_results(TrigValues *values) {
    printf("Angle: %.2f radians\n", values->angle);
    printf("Sine: %.4f\n", values->sine);
    printf("Cosine: %.4f\n", values->cosine);
    printf("Tangent: %.4f\n", values->tangent);
    printf("Secant: %.4f\n", values->secant);
    printf("Cosecant: %.4f\n", values->cosecant);
    printf("Cotangent: %.4f\n", values->cotangent);
    printf("\n");
}

void process_angle_input() {
    double angle_degrees;
    printf("Enter angle in degrees (or type -1 to exit): ");
    scanf("%lf", &angle_degrees);
    
    while (angle_degrees != -1) {
        TrigValues values;
        // Convert degrees to radians.
        values.angle = angle_degrees * (PI / 180.0);

        calculate_trigonometric_values(&values);
        display_results(&values);
        
        printf("Enter angle in degrees (or type -1 to exit): ");
        scanf("%lf", &angle_degrees);
    }
}

int main() {
    printf("Welcome to the Trigonometric Value Calculator!\n");
    process_angle_input();
    printf("Thank you for using the calculator. Goodbye!\n");
    return 0;
}