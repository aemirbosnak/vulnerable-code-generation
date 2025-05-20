//FormAI DATASET v1.0 Category: Digital signal processing ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define CUTOFF_FREQ 2000
#define FILTER_ORDER 4

int main() {
    // Generate a test audio signal
    int num_samples = 10000;
    float* signal = (float*) malloc (num_samples * sizeof(float));
    for (int i = 0; i < num_samples; i++) {
        signal[i] = sin(2*M_PI*440*i/SAMPLE_RATE) + sin(2*M_PI*880*i/SAMPLE_RATE);
    }

    // Compute filter coefficients with Butterworth filter design
    float a[FILTER_ORDER+1], b[FILTER_ORDER+1];
    float wc = 2*M_PI*CUTOFF_FREQ/SAMPLE_RATE;
    float inv_sqrt2 = 1/sqrt(2);
    for (int i = 0; i <= FILTER_ORDER; i++) {
        float theta = (i % 2 == 0) ? M_PI/2 : 0;
        float alpha = sin(theta)*sinh(log(2)*wc/(FILTER_ORDER*sin(theta)));
        float beta = cos(theta)*cosh(log(2)*wc/(FILTER_ORDER*sin(theta)));
        float A = 1 + alpha/beta;
        a[i] = (i == 0) ? inv_sqrt2/beta : alpha/(beta*A);
        b[i] = (i == 0) ? inv_sqrt2 : (-1)*cos(theta)*A;
    }

    // Apply filter to the audio signal
    float* filtered_signal = (float*) malloc (num_samples * sizeof(float));
    for (int i = 0; i < num_samples; i++) {
        filtered_signal[i] = 0;
        for (int j = 0; j <= FILTER_ORDER; j++) {
            if (i-j >= 0) {
                filtered_signal[i] += b[j]*signal[i-j];
            }
            if (j > 0 && i-j >= 0) {
                filtered_signal[i] -= a[j]*filtered_signal[i-j];
            }
        }
    }

    // Write filtered signal to a file
    FILE* output_file = fopen("filtered_audio.raw", "wb");
    for (int i = 0; i < num_samples; i++) {
        fwrite(&filtered_signal[i], sizeof(float), 1, output_file);
    }
    fclose(output_file);

    // Free memory
    free(signal);
    free(filtered_signal);

    return 0;
}