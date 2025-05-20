//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1000

int main() {
    int n, i, j, k, count = 0;
    double x1, y1, x2, y2, x3, y3, a, b, c, area, s;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    double *x = (double*)malloc(n*sizeof(double));
    double *y = (double*)malloc(n*sizeof(double));

    for(i=0; i<n; i++) {
        printf("Enter vertex %d coordinates: ", i+1);
        scanf("%lf %lf", &x[i], &y[i]);
    }

    for(i=0; i<n; i++) {
        for(j=i+1; j<n; j++) {
            for(k=j+1; k<n; k++) {
                x1 = x[i];
                y1 = y[i];
                x2 = x[j];
                y2 = y[j];
                x3 = x[k];
                y3 = y[k];

                a = x2 - x1;
                b = x3 - x1;
                c = y3 - y1;

                area = 0.5*abs(a*(y2-y3) + b*(y3-y1) + c*(y1-y2));

                s = (a + b + c)/2;

                if(area > 0 && area < s*s/4) {
                    count++;
                }
            }
        }
    }

    printf("Total number of triangles formed: %d", count);

    free(x);
    free(y);

    return 0;
}