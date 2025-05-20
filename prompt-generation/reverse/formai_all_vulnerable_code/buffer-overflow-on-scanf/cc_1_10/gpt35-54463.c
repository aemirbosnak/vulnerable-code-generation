//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

// Function to calculate the equivalent resistance of two resistors in series
float series_resistance(float r1, float r2)
{
    return r1 + r2;
}

// Function to calculate the equivalent resistance of two resistors in parallel
float parallel_resistance(float r1, float r2)
{
    return (r1 * r2) / (r1 + r2);
}

// Main function
int main()
{
    // Initialization
    float resistors[SIZE];
    char connection_type[SIZE];
    int i, num_resistors;

    // Get user input
    printf("Enter the number of resistors: ");
    scanf("%d", &num_resistors);

    for(i = 0; i < num_resistors; i++) {
        printf("Enter the value of resistor %d: ", i+1);
        scanf("%f", &resistors[i]);

        printf("Enter the connection type (S for series, P for parallel): ");
        scanf("%s", &connection_type[i]);
    }

    // Calculate the equivalent resistance
    float total_resistance;

    for(i = 0; i < num_resistors; i++) {
        if(connection_type[i] == 'S') {
            total_resistance = series_resistance(total_resistance, resistors[i]);
        } else if(connection_type[i] == 'P') {
            total_resistance = parallel_resistance(total_resistance, resistors[i]);
        }
    }

    // Print the results
    printf("The total resistance is %.2f ohms", total_resistance);

    return 0;
}