//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 1024
#define PI 3.14159265358979323846

int main() {
    int i;
    float x[N], y[N], amp, freq, t;
    float sum = 0;

    printf("Enter amplitude: ");
    scanf("%f", &amp);

    printf("Enter frequency: ");
    scanf("%f", &freq);

    t = 0.0;
    for(i=0; i<N; i++) {
        x[i] = amp*cos(2*PI*freq*t);
        y[i] = amp*sin(2*PI*freq*t);
        t += 1.0/44100.0;
    }

    printf("Enter window function (0 for none, 1 for rectangular, 2 for Hamming): ");
    scanf("%d", &i);

    switch(i) {
        case 0:
            for(i=0; i<N; i++) {
                sum += x[i]*y[i];
            }
            break;
        case 1:
            for(i=0; i<N; i++) {
                if(i<N/2) {
                    x[i] *= 0.5;
                    y[i] *= 0.5;
                }
            }
            for(i=0; i<N; i++) {
                sum += x[i]*y[i];
            }
            break;
        case 2:
            for(i=0; i<N; i++) {
                if(i<N/2) {
                    x[i] *= 0.54 - 0.46*cos(2*PI*i/(N/2));
                    y[i] *= 0.54 - 0.46*cos(2*PI*i/(N/2));
                } else {
                    x[i] *= 0.46 - 0.54*cos(2*PI*i/(N/2));
                    y[i] *= 0.46 - 0.54*cos(2*PI*i/(N/2));
                }
            }
            for(i=0; i<N; i++) {
                sum += x[i]*y[i];
            }
            break;
        default:
            printf("Invalid window function\n");
            return 0;
    }

    printf("Sum: %f\n", sum);

    return 0;
}