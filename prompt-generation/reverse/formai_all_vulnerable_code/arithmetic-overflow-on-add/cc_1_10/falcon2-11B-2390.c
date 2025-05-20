//Falcon2-11B DATASET v1.0 Category: Digital signal processing ; Style: intelligent
#include <stdio.h>
#include <math.h>

// Function to perform FFT on an array of integers
void fft(int* data, int n, int start) {
    // Initialize FFT coefficients
    int* fft_coeffs = malloc(sizeof(int) * n);
    
    // Perform FFT
    for (int i = 0; i < n; i++) {
        int temp = fft_coeffs[i];
        for (int j = i; j < n; j += 2*start) {
            temp = temp + fft_coeffs[j];
            fft_coeffs[j] = fft_coeffs[j] - temp;
        }
        fft_coeffs[i] = fft_coeffs[i] + temp;
    }
    
    // Output FFT coefficients
    printf("FFT coefficients: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", fft_coeffs[i]);
    }
    printf("\n");
    
    // Free memory
    free(fft_coeffs);
}

// Function to perform IFFT on an array of integers
void ifft(int* data, int n, int start) {
    // Initialize IFFT coefficients
    int* ifft_coeffs = malloc(sizeof(int) * n);
    
    // Perform IFFT
    for (int i = 0; i < n; i++) {
        int temp = ifft_coeffs[i];
        for (int j = i; j < n; j += 2*start) {
            temp = temp + ifft_coeffs[j];
            ifft_coeffs[j] = ifft_coeffs[j] - temp;
        }
        ifft_coeffs[i] = ifft_coeffs[i] + temp;
    }
    
    // Output IFFT coefficients
    printf("IFFT coefficients: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", ifft_coeffs[i]);
    }
    printf("\n");
    
    // Free memory
    free(ifft_coeffs);
}

int main() {
    int data[] = {1, 2, 3, 4, 5};
    int n = sizeof(data) / sizeof(data[0]);
    
    printf("Original array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
    
    // Perform FFT
    fft(data, n, 2);
    
    // Perform IFFT
    ifft(data, n, 2);
    
    printf("Transformed array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
    
    return 0;
}