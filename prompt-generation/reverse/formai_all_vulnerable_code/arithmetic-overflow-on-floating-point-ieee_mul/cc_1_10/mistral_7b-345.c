//MISTRAL-7B DATASET v1.0 Category: Arithmetic ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define PI 3.14159265358979323846
#define MIN(x,y) ((x<y)?x:y)
#define MAX(x,y) ((x>y)?x:y)
#define ABS(x) ((x<0)?-x:x)

typedef struct {
    int length;
    int width;
    int height;
    float diagonal;
} Box;

void calculateBoxDimensions(Box *box, int length, int width, int height) {
    box->length = length;
    box->width = width;
    box->height = height;

    box->diagonal = sqrt(pow(length, 2) + pow(width, 2) + pow(height, 2));
}

int main() {
    int a = 10, b = 20, c, d, e, f;
    float x = 5.5, y = 2.5, z;
    Box myBox;

    printf("Arithmetic Operations Enthusiast\n\n");

    // Addition
    c = a + b;
    printf("Addition: a + b = %d\n", c);

    // Subtraction
    d = a - b;
    printf("Subtraction: a - b = %d\n", d);

    // Multiplication
    e = a * b;
    printf("Multiplication: a * b = %d\n", e);

    // Division
    z = (float) a / b;
    printf("Division: a / b = %.2f\n", z);

    // Modulus
    f = a % b;
    printf("Modulus: a %% b = %d\n", f);

    // Increment and Decrement
    a++;
    printf("Increment: a++ = %d\n", a);

    --a;
    printf("Decrement: --a = %d\n", a);

    // Arithmetic with floats
    x += y;
    printf("Addition with floats: x += y = %.2f\n", x);

    y -= x;
    printf("Subtraction with floats: y -= x = %.2f\n", y);

    x *= 2.5;
    printf("Multiplication with floats: x *= 2.5 = %.2f\n", x);

    x /= 2.5;
    printf("Division with floats: x /= 2.5 = %.2f\n", x);

    // Arithmetic with Boxes
    calculateBoxDimensions(&myBox, 5, 6, 7);
    printf("Length: %d\n", myBox.length);
    printf("Width: %d\n", myBox.width);
    printf("Height: %d\n", myBox.height);
    printf("Diagonal: %.2f\n", myBox.diagonal);

    // Arithmetic with macros
    int h = 5, w = 10, minLength = MIN(h, w);
    printf("Minimum of h and w: %d\n", minLength);

    int l = 2, m = 8, maxLength = MAX(l, m);
    printf("Maximum of l and m: %d\n", maxLength);

    int n = -3;
    int absValue = ABS(n);
    printf("Absolute value of n: %d\n", absValue);

    return 0;
}