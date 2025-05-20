//FormAI DATASET v1.0 Category: Digital signal processing ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define PI 3.14159265358979323846

int main(){

    int n, i;
    float xn[10], hn[10], yn[10], real[10], imag[10];
    float mag[10], phase[10];
    
    // Taking input for number of samples of xn and hn
    printf("Enter number of samples of xn and hn: ");
    scanf("%d", &n);
    
    // Taking input for samples of xn
    printf("Enter samples of xn: ");
    for(i=0; i<n; i++){
        scanf("%f", &xn[i]);
    }
    
    // Taking input for samples of hn
    printf("Enter samples of hn: ");
    for(i=0; i<n; i++){
        scanf("%f", &hn[i]);
    }

    // Performing Circular Convolution (Discrete Fourier Transform)
    for(i=0; i<n; i++){
        real[i] = xn[i];
        imag[i] = 0;
    }
    for(i=n; i<2*n; i++){
        real[i] = 0;
        imag[i] = 0;
    }
    for(i=0; i<n; i++){
        real[i+n] = hn[i];
        imag[i+n] = 0;
    }
    for(i=n; i<2*n; i++){
        real[i] = 0;
        imag[i] = 0;
    }

    for(i=0; i<2*n; i++){
        mag[i] = sqrt(real[i]*real[i] + imag[i]*imag[i]);
        phase[i] = atan2(imag[i], real[i]) * 180/PI;
    }
    
    // Printing output
    printf("\n*** Output of Circular Convolution (Discrete Fourier Transform) ***\n\n");
    printf("  n \t\t xn \t\t hn \t\t yn \t\t Magnitude \t Phase\n");
    for(i=0; i<n; i++){
        yn[i] = mag[i];
        printf("%3d \t %9.4f \t %9.4f \t %9.4f \t %9.4f \t %6.2f\n", i, xn[i], hn[i], yn[i], mag[i], phase[i]);
    }
    printf("\n");
    
    return 0;
}