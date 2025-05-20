//FormAI DATASET v1.0 Category: Digital signal processing ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

int main()
{
    int n, k;
    double input[5], output_real[5], output_imag[5], frequency[5];

    // Taking input from the user
    printf("Enter the input signal:\n");
    for(int i=0; i<5; i++){
        printf("Input[%d]: ", i);
        scanf("%lf", &input[i]);
    }

    // Calculating the output using DFT Algorithm
    for(k=0; k<5; k++){
        output_real[k] = 0;
        output_imag[k] = 0;
        frequency[k] = k;
        for(n=0; n<5; n++){
            output_real[k] += input[n] * cos(2 * PI * k * n / 5);
            output_imag[k] -= input[n] * sin(2 * PI * k * n / 5);
        }
    }

    // Displaying the DFT output
    printf("\nDFT Output:\n");
    printf("Frequency\tReal Part\tImaginary Part\n");
    for(int i=0; i<5; i++){
        printf("%.2lf\t\t%.2lf\t\t%.2lf\n", frequency[i], output_real[i], output_imag[i]);
    }

    // Calculating the output using IDFT Algorithm
    for(n=0; n<5; n++){
        input[n] = 0;
        for(k=0; k<5; k++){
            input[n] += (output_real[k] * cos(2 * PI * k * n / 5)) + (output_imag[k] * sin(2 * PI * k * n / 5));
        }
        input[n] /= 5;
    }

    // Displaying the IDFT output
    printf("\nIDFT Output:\n");
    printf("Sample\t\tReal Part\n");
    for(int i=0; i<5; i++){
        printf("%d\t\t%.2lf\n", i, input[i]);
    }

    return 0;
}