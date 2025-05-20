//FormAI DATASET v1.0 Category: Digital signal processing ; Style: Dennis Ritchie
#include<stdio.h>
#include<math.h>

#define PI 3.14159265358979323846

void FFT(float *real, float *imag, int n, int inverse){
    int i, j, k, m, step;
    float theta, wr, wi, temp, treal, timag;
   
    for(i = 0; i < n; i++){
        j = i;
        k = 0;
        m = n;
        while(m > 1){
            m = m/2;
            j = j % m + m*k;
            k = k*2;
        }
        if(j < i){
            temp = real[i];
            real[i] = real[j];
            real[j] = temp;
            temp = imag[i];
            imag[i] = imag[j];
            imag[j] = temp;
        }
    }
    
    for(step = 1; step < n; step = 2*step){
        for(i = 0; i < n; i = i + 2*step){
            theta = 2*PI*i/n;
            if(inverse){
                theta = -theta;
            }
            wr = cos(theta);
            wi = sin(theta);
            for(j = i; j < i + step; j++){
                treal = wr*real[j + step] - wi*imag[j + step];
                timag = wr*imag[j + step] + wi*real[j + step];
                real[j + step] = real[j] - treal;
                imag[j + step] = imag[j] - timag;
                real[j] = real[j] + treal;
                imag[j] = imag[j] + timag;
            }
        }
    }
    if(inverse){
        for(i = 0; i < n; i++){
            real[i] = real[i]/n;
            imag[i] = imag[i]/n; 
        }
    }
}

int main(){
    int n, i, inverse;
    float real[100], imag[100];
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("Enter the values of real and imaginary parts: \n");
    for(i = 0; i < n; i++){
        scanf("%f %f", &real[i], &imag[i]);
    }
    printf("Enter 1 for FFT and 0 for IFFT: ");
    scanf("%d", &inverse);
    FFT(real, imag, n, inverse);
    if(inverse){
        printf("Inverse FFT: \n");
    }else{
        printf("FFT: \n");
    }
    for(i = 0; i < n; i++){
        printf("%f + i%f\n", real[i], imag[i]);
    }
    return 0;
}