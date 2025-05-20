//FormAI DATASET v1.0 Category: Digital signal processing ; Style: enthusiastic
//Welcome to my exciting Digital Signal Processing program!
//This program takes in a series of noisy signals and filters out the noise to give us a clear signal output.
//Let's get started!

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define pi 3.14159265358979323846

//Function that generates noisy signals
float Generate_Noise(int n);

int main(void)
{
    int n, i;
    float x[100], y[100], noise[100], sum = 0, sum2 = 0, filtered_signal;

    printf("Enter the number of samples: ");
    scanf("%d", &n);

    //Generating input signal with random noise
    for(i = 0; i < n; i++)
    {
        x[i] = ((float)rand()/(float)(RAND_MAX))*10;
        noise[i] = Generate_Noise(i);

        y[i] = x[i] + noise[i];
    }

    //Filtering out the noise
    for(i = 0; i < n-1; i++)
    {
        filtered_signal = (y[i] + y[i+1])/2;
        y[i] = filtered_signal;
    }

    //Calculating the mean and standard deviation of the filtered signal
    for(i = 0; i < n; i++)
    {
        sum += y[i];
        sum2 += pow(y[i],2);
    }

    float mean = sum/n;
    float std_dev = sqrt((sum2/n) - pow(mean,2));

    //Outputting the results
    printf("The input signal with noisy added:\n");
    for(i = 0; i < n; i++)
    {
        printf("%0.2f\t", x[i]);
    }
    printf("\n");
    for(i = 0; i < n; i++)
    {
        printf("%0.2f\t", y[i]);
    }
    printf("\n");
    printf("The filtered signal:\n");
    for(i = 0; i < n; i++)
    {
        printf("%0.2f\t", y[i]);
    }
    printf("\n");
    printf("The mean of the filtered signal is: %0.2f\n", mean);
    printf("The standard deviation of the filtered signal is: %0.2f\n", std_dev);

    return 0;
}

//Function to generate noise
float Generate_Noise(int n)
{
    float noise = sin(2*pi*n/100) + sin(4*pi*n/100) + sin(6*pi*n/100);  
    return noise;
}