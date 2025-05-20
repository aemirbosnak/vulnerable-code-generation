//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define N 1024

int main()
{
    float x[N], y[N], w[N];
    int n, m, k, i, j;
    float sum, twopi;
    
    printf("Enter the type of window:\n");
    printf("1. Rectangular window\n");
    printf("2. Hamming window\n");
    printf("3. Hanning window\n");
    printf("4. Blackman window\n");
    scanf("%d", &m);
    
    twopi = 2.0*PI;
    
    switch(m)
    {
        case 1: // Rectangular window
            for(i=0; i<N; i++)
            {
                x[i] = sin(i*twopi/N);
                y[i] = 1.0;
            }
            break;
            
        case 2: // Hamming window
            for(i=0; i<N; i++)
            {
                x[i] = sin(i*twopi/N);
                y[i] = 0.54 - 0.46*cos(2.0*PI*i/N);
            }
            break;
            
        case 3: // Hanning window
            for(i=0; i<N; i++)
            {
                x[i] = sin(i*twopi/N);
                y[i] = 0.5 - 0.5*cos(2.0*PI*i/N);
            }
            break;
            
        case 4: // Blackman window
            for(i=0; i<N; i++)
            {
                x[i] = sin(i*twopi/N);
                y[i] = 0.42 - 0.5*cos(2.0*PI*i/N) + 0.08*cos(4.0*PI*i/N);
            }
            break;
            
        default:
            printf("Invalid window type\n");
            exit(0);
    }
    
    for(i=0; i<N; i++)
    {
        sum = 0.0;
        for(j=0; j<N; j++)
        {
            sum += x[j]*y[j]*cos(2.0*PI*i*j/N);
        }
        w[i] = sum;
    }
    
    printf("The window coefficients are:\n");
    for(i=0; i<N; i++)
    {
        printf("%f ", w[i]);
    }
    
    return 0;
}