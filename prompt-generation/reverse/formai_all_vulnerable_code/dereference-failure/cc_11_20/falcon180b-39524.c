//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 1024 //Number of samples
#define Fs 44100 //Sampling frequency
#define PI 3.14159265358979323846
#define TWO_PI (2*PI)
#define BLOCK_SIZE 32 //Number of samples per block
#define OVERLAP 16 //Number of samples of overlap between adjacent blocks
#define WINDOW_SIZE (BLOCK_SIZE-OVERLAP) //Size of the window function
#define WINDOW_TYPE 0 //Type of window function (0: Rectangular, 1: Hamming, 2: Hanning)

int main() {
    FILE *fp;
    float *data, *window, *output;
    int i, j, k, n, m, l, index, window_size, overlap, block_size, window_type;
    float sum, max_value, threshold;

    fp = fopen("input.txt", "rb");
    if(fp == NULL) {
        printf("Error: Unable to open input file.\n");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    n = ftell(fp)/sizeof(float);
    fseek(fp, 0, SEEK_SET);

    data = (float*)malloc(n*sizeof(float));
    fread(data, sizeof(float), n, fp);
    fclose(fp);

    printf("Enter the window type (0: Rectangular, 1: Hamming, 2: Hanning): ");
    scanf("%d", &window_type);

    switch(window_type) {
        case 0:
            window_size = BLOCK_SIZE;
            break;
        case 1:
            window_size = BLOCK_SIZE;
            break;
        case 2:
            window_size = BLOCK_SIZE;
            break;
        default:
            printf("Error: Invalid window type.\n");
            exit(1);
    }

    overlap = OVERLAP;
    block_size = BLOCK_SIZE;

    window = (float*)malloc(window_size*sizeof(float));
    output = (float*)malloc(n*sizeof(float));

    for(i=0; i<window_size; i++) {
        window[i] = 1.0;
    }

    for(i=0; i<n; i+=block_size-overlap) {
        for(j=0; j<window_size; j++) {
            index = i+j;
            if(index >= n) {
                break;
            }
            output[index] += data[i]*window[j];
        }

        for(k=0; k<window_size; k++) {
            output[i+k] /= window_size;
        }
    }

    max_value = output[0];
    for(i=1; i<n; i++) {
        if(output[i] > max_value) {
            max_value = output[i];
        }
    }

    threshold = max_value*0.1;

    for(i=0; i<n; i++) {
        if(output[i] > threshold) {
            output[i] = max_value;
        } else {
            output[i] = 0.0;
        }
    }

    fp = fopen("output.txt", "wb");
    if(fp == NULL) {
        printf("Error: Unable to open output file.\n");
        exit(1);
    }

    fwrite(output, sizeof(float), n, fp);
    fclose(fp);

    printf("Digital signal processing completed successfully.\n");

    return 0;
}