//FormAI DATASET v1.0 Category: Digital signal processing ; Style: mind-bending
#include <stdio.h>

// Function to perform the Fast Fourier Transform
void fft(int input[], int output[], int n){
    // Base case of recursion
    if(n == 1){
        output[0] = input[0];
        return;
    }
    
    // Divide and conquer approach
    int fe[n/2], fo[n/2], ffe[n/2], ffo[n/2];
    for(int i=0; i<n; i++){
        if(i%2 == 0) fe[i/2] = input[i];
        else fo[i/2] = input[i];
    }
    fft(fe, ffe, n/2);
    fft(fo, ffo, n/2);
    
    // Combine the results of subproblems
    for(int i=0; i<n/2; i++){
        double ang = 2*3.14159265359*i/n; // Angle term
        double w_real = cos(ang);
        double w_img = sin(ang);
        output[i] = ffe[i] + w_real * ffo[i] - w_img * ffo[i];
        output[i+n/2] = ffe[i] - w_real * ffo[i] + w_img * ffo[i];
    }
}

int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    // Input the signal
    int signal[n];
    printf("Enter the signal:\n");
    for(int i=0; i<n; i++){
        scanf("%d", &signal[i]);
    }
    
    // Perform the Discrete Fourier Transform
    int spectrum[n];
    fft(signal, spectrum, n);
    
    // Output the spectrum
    printf("The spectrum is:\n");
    for(int i=0; i<n; i++){
        printf("%d ", spectrum[i]);
    }
    
    return 0;
}