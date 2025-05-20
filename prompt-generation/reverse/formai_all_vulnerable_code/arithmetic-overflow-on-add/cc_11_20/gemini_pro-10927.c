//GEMINI-pro DATASET v1.0 Category: Arithmetic ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    // Declare variables
    int a, b, c, d, e, f, g, h, i, j;

    // Get input from user
    printf("Enter 10 numbers: ");
    scanf("%d %d %d %d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &g, &h, &i, &j);

    // Calculate the sum of the numbers
    int sum = a + b + c + d + e + f + g + h + i + j;

    // Calculate the average of the numbers
    float average = (float)sum / 10;

    // Calculate the maximum of the numbers
    int max = a;
    if (b > max) max = b;
    if (c > max) max = c;
    if (d > max) max = d;
    if (e > max) max = e;
    if (f > max) max = f;
    if (g > max) max = g;
    if (h > max) max = h;
    if (i > max) max = i;
    if (j > max) max = j;

    // Calculate the minimum of the numbers
    int min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    if (d < min) min = d;
    if (e < min) min = e;
    if (f < min) min = f;
    if (g < min) min = g;
    if (h < min) min = h;
    if (i < min) min = i;
    if (j < min) min = j;

    // Print the results
    printf("The sum of the numbers is: %d\n", sum);
    printf("The average of the numbers is: %.2f\n", average);
    printf("The maximum of the numbers is: %d\n", max);
    printf("The minimum of the numbers is: %d\n", min);

    return 0;
}