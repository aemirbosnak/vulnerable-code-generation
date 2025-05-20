//Code Llama-13B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <unistd.h>

#define WIDTH 80
#define HEIGHT 25

void draw_fibonacci(int n) {
    int x, y;
    int x1, y1;
    int x2, y2;
    int x3, y3;
    int x4, y4;
    int x5, y5;
    int x6, y6;
    int x7, y7;
    int x8, y8;
    int x9, y9;
    int x10, y10;
    int x11, y11;
    int x12, y12;
    int x13, y13;
    int x14, y14;
    int x15, y15;
    int x16, y16;
    int x17, y17;
    int x18, y18;
    int x19, y19;
    int x20, y20;

    x1 = 0;
    y1 = 0;
    x2 = 1;
    y2 = 0;
    x3 = 1;
    y3 = 1;
    x4 = 2;
    y4 = 1;
    x5 = 3;
    y5 = 2;
    x6 = 5;
    y6 = 3;
    x7 = 8;
    y7 = 5;
    x8 = 13;
    y8 = 8;
    x9 = 21;
    y9 = 13;
    x10 = 34;
    y10 = 21;
    x11 = 55;
    y11 = 34;
    x12 = 89;
    y12 = 55;
    x13 = 144;
    y13 = 89;
    x14 = 233;
    y14 = 144;
    x15 = 377;
    y15 = 233;
    x16 = 610;
    y16 = 377;
    x17 = 987;
    y17 = 610;
    x18 = 1597;
    y18 = 987;
    x19 = 2584;
    y19 = 1597;
    x20 = 4181;
    y20 = 2584;

    for (int i = 0; i < n; i++) {
        x = x1 + x2;
        y = y1 + y2;
        x2 = x1;
        y2 = y1;
        x1 = x;
        y1 = y;

        x3 = x2 + x1;
        y3 = y2 + y1;
        x4 = x3 + x2;
        y4 = y3 + y2;
        x5 = x4 + x3;
        y5 = y4 + y3;
        x6 = x5 + x4;
        y6 = y5 + y4;
        x7 = x6 + x5;
        y7 = y6 + y5;
        x8 = x7 + x6;
        y8 = y7 + y6;
        x9 = x8 + x7;
        y9 = y8 + y7;
        x10 = x9 + x8;
        y10 = y9 + y8;
        x11 = x10 + x9;
        y11 = y10 + y9;
        x12 = x11 + x10;
        y12 = y11 + y10;
        x13 = x12 + x11;
        y13 = y12 + y11;
        x14 = x13 + x12;
        y14 = y13 + y12;
        x15 = x14 + x13;
        y15 = y14 + y13;
        x16 = x15 + x14;
        y16 = y15 + y14;
        x17 = x16 + x15;
        y17 = y16 + y15;
        x18 = x17 + x16;
        y18 = y17 + y16;
        x19 = x18 + x17;
        y19 = y18 + y17;
        x20 = x19 + x18;
        y20 = y19 + y18;

        printf("%d\t%d\n", x, y);
    }
}

int main() {
    int n;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    draw_fibonacci(n);

    return 0;
}