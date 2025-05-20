//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX 1000000
#define PI 3.14159265358979323846

int main() {
    int i, j, k, n, m, sum = 0;
    float x, y, z, a, b, c, d, e, f, g, h, u, v, w, t, s, r;
    char ch;
    struct tm *tm;
    time_t now;

    srand(time(0));

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        x = rand() % MAX;
        y = rand() % MAX;
        z = rand() % MAX;

        a = x / (float)MAX;
        b = y / (float)MAX;
        c = z / (float)MAX;

        d = a * a;
        e = b * b;
        f = c * c;

        g = d + e + f;
        h = sqrt(g);

        if (h == 0) {
            printf("Error: Division by zero!\n");
            exit(0);
        }

        u = a * b * c;
        v = a * e + b * d + c * f;
        w = a * f + b * c + d * e;

        t = (u + v + w) / (2.0 * h);
        s = (u - v - w) / (6.0 * h * h);
        r = (v - u) / (6.0 * h);

        m = (int)t;
        printf("Term %d: x = %d, y = %d, z = %d, a = %f, b = %f, c = %f\n", i + 1, x, y, z, a, b, c);
        printf("a = %f, b = %f, c = %f, d = %f, e = %f, f = %f\n", a, b, c, d, e, f);
        printf("g = %f, h = %f, u = %f, v = %f, w = %f\n", g, h, u, v, w);
        printf("t = %f, s = %f, r = %f\n", t, s, r);
        printf("Approximation: %d\n", m);
        printf("\n");
    }

    return 0;
}