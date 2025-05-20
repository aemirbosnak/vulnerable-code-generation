//FormAI DATASET v1.0 Category: Digital signal processing ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BUFFER_SIZE 100

int main()
{
    int i, j, num_samples;
    float sample_rate, frequency, phase, amplitude;
    float time, signal[BUFFER_SIZE], output_signal[BUFFER_SIZE];

    printf("Enter the number of samples: ");
    scanf("%d", &num_samples);

    printf("Enter the sample rate: ");
    scanf("%f", &sample_rate);

    printf("Enter the frequency: ");
    scanf("%f", &frequency);

    printf("Enter the phase: ");
    scanf("%f", &phase);

    printf("Enter the amplitude: ");
    scanf("%f", &amplitude);

    /* Generate the input signal and add some noise */
    for (i = 0; i < num_samples; i++)
    {
        time = (float)i / sample_rate;
        signal[i] = amplitude * sin(2 * M_PI * frequency * time + phase) + 0.1 * ((float)rand() / RAND_MAX - 0.5);
    }

    /* Apply a low-pass filter to the input signal */
    float cutoff_frequency = 500.0;
    float filter_gain = 1.0 / (1.0 + 2.0 * M_PI * cutoff_frequency / sample_rate);

    for (i = 0; i < num_samples; i++)
    {
        output_signal[i] = 0.0;
        for (j = 0; j <= i; j++)
        {
            output_signal[i] += signal[j] * pow(filter_gain, i - j);
        }
    }

    /* Display the input and output signals */
    printf("\nInput Signal\n");
    for (i = 0; i < num_samples; i++)
    {
        printf("%f\n", signal[i]);
    }

    printf("\nOutput Signal\n");
    for (i = 0; i < num_samples; i++)
    {
        printf("%f\n", output_signal[i]);
    }

    return 0;
}