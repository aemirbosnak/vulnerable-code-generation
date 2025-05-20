//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

int main() {
    double radius, area, circumference;
    char choice;
    int validInput = 0;

    // Initialize variables
    radius = 0;
    area = 0;
    circumference = 0;

    // Loop until valid input is entered
    while(!validInput) {
        printf("Enter R for radius, A for area, or C for circumference: ");
        scanf("%c", &choice);

        // Check for valid input
        if(choice == 'R' || choice == 'r') {
            printf("Enter the radius: ");
            scanf("%lf", &radius);
            validInput = 1;
        } else if(choice == 'A' || choice == 'a') {
            printf("Enter the area: ");
            scanf("%lf", &area);
            radius = sqrt(area / PI);
            validInput = 1;
        } else if(choice == 'C' || choice == 'c') {
            printf("Enter the circumference: ");
            scanf("%lf", &circumference);
            radius = circumference / (2 * PI);
            validInput = 1;
        } else {
            printf("Invalid input! Please enter R, A, or C.\n");
        }
    }

    // Calculate area and circumference
    if(radius > 0) {
        area = PI * radius * radius;
        circumference = 2 * PI * radius;
    }

    // Output results
    printf("For a circle with radius %.2lf:\n", radius);
    printf("The area is %.2lf\n", area);
    printf("The circumference is %.2lf\n", circumference);

    return 0;
}