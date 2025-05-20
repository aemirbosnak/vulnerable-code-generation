//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

int main() {
    int i, nfft, n, is;
    double f, fs, t, x[100000], y[100000], window[100000];
    FILE *fp;

    printf("Enter the sampling frequency: ");
    scanf("%lf", &fs);

    printf("Enter the number of samples: ");
    scanf("%d", &n);

    printf("Enter the type of window (0 for rectangular, 1 for Hanning): ");
    scanf("%d", &is);

    nfft = 2*n;
    f = fs/n;
    t = 0;

    for(i=0; i<n; i++) {
        x[i] = sin(2*PI*f*t);
        t += 1.0/fs;
    }

    if(is == 0) {
        for(i=0; i<nfft; i++) {
            window[i] = 1.0;
        }
    } else {
        for(i=0; i<nfft; i++) {
            window[i] = 0.5*(1.0 - cos(2*PI*i/(nfft-1)));
        }
    }

    for(i=0; i<n; i++) {
        y[i] = 0.0;
        for(n=0; n<nfft; n++) {
            y[i] += x[n]*window[n];
        }
    }

    fp = fopen("output.txt", "w");

    for(i=0; i<n; i++) {
        fprintf(fp, "%.6lf\n", y[i]);
    }

    fclose(fp);

    return 0;
}