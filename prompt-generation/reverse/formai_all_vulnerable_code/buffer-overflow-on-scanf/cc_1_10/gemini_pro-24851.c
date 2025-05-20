//GEMINI-pro DATASET v1.0 Category: Fractal Generation ; Style: Ken Thompson
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

    const int MAX_N = 2000;
    const int MAX_I = 2000;

    typedef struct {
        double r;
        double i;
    } complex_t;

    void cadd(complex_t *c1, complex_t *c2) {
        c1->r += c2->r;
        c1->i += c2->i;
    }

    void cmul(complex_t *c1, complex_t *c2) {
        double r = c1->r;
        double i = c1->i;
        c1->r = r*c2->r - i*c2->i;
        c1->i = r*c2->i + i*c2->r;
    }

    double cmag(complex_t *c1) {
        return sqrt(c1->r*c1->r + c1->i*c1->i);
    }

    int main() {
        int n, i;
        double x, y;
        complex_t c1, c2 = {0, 0};
        printf("Enter z0-x: ");
        scanf("%lf", &x);
        printf("Enter z0-y: ");
        scanf("%lf", &y);
        printf("Enter n: ");
        scanf("%d", &n);
        printf("Enter max iterations: ");
        scanf("%d", &i);
        c1.r = x;
        c1.i = y;
        printf("Iteration   Magnitude\n");
        for (; i >= 0; i--) {
            cmul(&c2, &c2);
            cadd(&c2, &c1);
            if (cmag(&c2) > MAX_N) {
                printf("%3d     %12.4lf  \n", i, cmag(&c2));
                break;
            }
            printf("%3d     %12.4lf  \r", i, cmag(&c2));
        }
        if (i < 0)
            puts("does not escape");
        return 0;
    }