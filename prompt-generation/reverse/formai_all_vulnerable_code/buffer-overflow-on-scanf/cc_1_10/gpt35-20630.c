//FormAI DATASET v1.0 Category: Digital signal processing ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

int main()
{
    int n,i;
    float x[1000],y[1000],mag[1000],phase[1000];

    printf("Enter the number of samples(1-1000): ");
    scanf("%d",&n);

    //Generating input signal
    for(i=0;i<n;i++)
    {
        x[i] = sin(2*PI*10*i/n) + sin(2*PI*30*i/n); //sum of two sine waves
    }

    printf("Input Signal: \n");
    for(i=0;i<n;i++)
    {
        printf("%f\n",x[i]);
    }

    //Discrete Fourier Transform
    for(i=0;i<n;i++)
    {
        float real = 0, imag = 0;

        for(int j=0;j<n;j++)
        {
            real += x[j] * cos(2*PI*i*j/n);
            imag -= x[j] * sin(2*PI*i*j/n);
        }

        y[i] = sqrt(real*real + imag*imag); //magnitude spectrum
        phase[i] = atan2(imag,real); //phase spectrum
    }

    printf("Magnitude Spectrum: \n");
    for(i=0;i<n;i++)
    {
        printf("%f\n",y[i]);
    }

    printf("Phase Spectrum: \n");
    for(i=0;i<n;i++)
    {
        printf("%f\n",phase[i]);
    }

    //Inverse Discrete Fourier Transform
    for(i=0;i<n;i++)
    {
        float real = 0, imag = 0;

        for(int j=0;j<n;j++)
        {
            real += y[j] * cos(2*PI*i*j/n);
            imag += y[j] * sin(2*PI*i*j/n);
        }

        x[i] = (real/n) + (imag/n); //reconstructed signal
    }

    printf("Reconstructed Signal: \n");
    for(i=0;i<n;i++)
    {
        printf("%f\n",x[i]);
    }

    return 0;
}