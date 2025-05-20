//FormAI DATASET v1.0 Category: Digital signal processing ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

/* Define a struct for holding complex numbers */
typedef struct {
    double real;
    double imag;
} Complex;

/* Function to perform the Discrete Fourier Transform */
void DFT(Complex *data, int n) {
    int k, j;
    Complex sum, temp;

    /* Perform the DFT */
    for(k=0; k<n; k++) {
        sum.real = 0.0;
        sum.imag = 0.0;

        for(j=0; j<n; j++) {
            temp.real = cos(2*PI*k*j/n);
            temp.imag = -sin(2*PI*k*j/n);
            sum.real += (data[j].real * temp.real) - (data[j].imag * temp.imag);
            sum.imag += (data[j].real * temp.imag) + (data[j].imag * temp.real);
        }

        data[k].real = sum.real;
        data[k].imag = sum.imag;
    }
}

int main() {
    int i, n;
    Complex *data;

    /* Get the size of the input vector */
    printf("Enter the size of the vector: ");
    scanf("%d", &n);

    /* Allocate space for the input vector */
    data = (Complex *) malloc(sizeof(Complex) * n);

    /* Get the elements of the input vector */
    printf("Enter the elements of the vector:\n");
    for(i=0; i<n; i++) {
        printf("data[%d].real = ", i);
        scanf("%lf", &data[i].real);
        printf("data[%d].imag = ", i);
        scanf("%lf", &data[i].imag);
    }

    /* Perform the DFT */
    DFT(data, n);

    /* Print the results */
    printf("The result of the DFT is:\n");
    for(i=0; i<n; i++) {
        printf("data[%d].real = %lf\tdata[%d].imag = %lf\n", i, data[i].real, i, data[i].imag);
    }

    /* Free the memory used by the input vector */
    free(data);

    return 0;
}