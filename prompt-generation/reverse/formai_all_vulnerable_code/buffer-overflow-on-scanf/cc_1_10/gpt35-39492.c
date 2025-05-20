//FormAI DATASET v1.0 Category: Digital signal processing ; Style: grateful
// Thankful Digital Signal Processing Example Program
// By [Your Name]

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

int main()
{
    printf("Thank you for using our Digital Signal Processing Example Program!\n");

    // User input for number of data points
    int numDataPoints;
    printf("Please enter the number of data points: ");
    scanf("%d", &numDataPoints);

    // Allocate memory for data array
    double* data = malloc(numDataPoints * sizeof(double));

    // User input for data values
    printf("Please enter the data values:\n");
    for (int i = 0; i < numDataPoints; i++)
    {
        printf("Data Point %d: ", i);
        scanf("%lf", &data[i]);
    }

    // Discrete Fourier Transform
    double real, imag;

    printf("\nResults of Discrete Fourier Transform:\n");
    for (int i = 0; i < numDataPoints; i++)
    {
        real = 0;
        imag = 0;
        for (int j = 0; j < numDataPoints; j++)
        {
            real += data[j] * cos(2 * PI * i * j / numDataPoints);
            imag -= data[j] * sin(2 * PI * i * j / numDataPoints);
        }

        printf("Frequency %d: Real %.2f, Imaginary %.2f\n", i, real, imag);
    }

    free(data);

    printf("\nThank you for using our Digital Signal Processing Example Program!\n");

    return 0;
}