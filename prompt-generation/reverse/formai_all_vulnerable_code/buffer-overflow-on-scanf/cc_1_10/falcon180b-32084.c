//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n, i, j, k;
    int a[100], b[100];
    int sum = 0;
    int c[100];
    int r, q;

    // Input the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Input the elements
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Input the elements to be added
    printf("Enter the elements to be added:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }

    // Add the two arrays
    for (i = 0; i < n; i++) {
        sum += a[i] + b[i];
        c[i] = a[i] + b[i];
    }

    // Calculate the sum of the elements in the array
    for (i = 0; i < n; i++) {
        sum += c[i];
    }

    // Calculate the average of the elements in the array
    float avg = (float)sum / n;

    // Calculate the product of the elements in the array
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            for (k = j + 1; k < n; k++) {
                r = a[i] * a[j] * a[k];
                q = b[i] * b[j] * b[k];
                c[i] += r - q;
            }
        }
    }

    // Print the results
    printf("The sum of the elements is: %d\n", sum);
    printf("The average of the elements is: %.2f\n", avg);
    printf("The product of the elements is: %d\n", c[0]);

    return 0;
}