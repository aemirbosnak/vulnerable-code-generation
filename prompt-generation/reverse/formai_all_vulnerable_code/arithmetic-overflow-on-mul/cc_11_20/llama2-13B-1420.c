//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define INF 1000000
#define EPS 0.000001

int main() {
    int i, j, k, n, m;
    long long int a, b, c, d, e, f;
    double x, y, z, w;
    char str[100];

    // Initialize variables
    scanf("%d%d%d%d", &n, &m, &k, &i);
    a = (long long int)n * (long long int)m * (long long int)k;
    b = (long long int)i * (long long int)n * (long long int)m;
    c = (long long int)n * (long long int)m * (long long int)k + (long long int)i * (long long int)n * (long long int)m;
    d = (long long int)n * (long long int)m * (long long int)k - (long long int)i * (long long int)n * (long long int)m;
    e = (long long int)n * (long long int)m * (long long int)k + (long long int)i * (long long int)n * (long long int)m;
    f = (long long int)n * (long long int)m * (long long int)k - (long long int)i * (long long int)n * (long long int)m;

    // Calculate expressions
    x = (double)a / (double)b;
    y = (double)c / (double)d;
    z = (double)e / (double)f;
    w = (double)a / (double)c;

    // Check for overflow
    if (fabs(x) > INF || fabs(y) > INF || fabs(z) > INF || fabs(w) > INF) {
        printf("OVERFLOW\n");
        return 0;
    }

    // Check for underflow
    if (fabs(x) < -INF || fabs(y) < -INF || fabs(z) < -INF || fabs(w) < -INF) {
        printf("UNDERFLOW\n");
        return 0;
    }

    // Check for equality
    if (fabs(x - y) < EPS && fabs(x - z) < EPS && fabs(x - w) < EPS && fabs(y - z) < EPS && fabs(y - w) < EPS && fabs(z - w) < EPS) {
        printf("EQUAL\n");
    } else {
        printf("NOT EQUAL\n");
    }

    return 0;
}