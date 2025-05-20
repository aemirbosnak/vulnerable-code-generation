//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX 1000
#define PI 3.14159265358979323846

int main() {
    int i, j, n, k, l;
    double x, y, z, sum = 0;
    struct timespec start, end;
    double elapsed_time;

    // Prompt user to enter number of terms
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    // Initialize random number generator
    srand(time(NULL));

    // Generate random numbers
    for (i = 0; i < n; i++) {
        x = rand() % MAX;
        y = rand() % MAX;
        z = rand() % MAX;

        // Calculate sum of squares
        sum += x*x + y*y + z*z;
    }

    // Calculate elapsed time
    clock_gettime(CLOCK_REALTIME, &start);
    for (i = 0; i < n; i++) {
        x = rand() % MAX;
        y = rand() % MAX;
        z = rand() % MAX;

        // Calculate sum of squares
        sum += x*x + y*y + z*z;
    }
    clock_gettime(CLOCK_REALTIME, &end);
    elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) * 1e-9;

    // Print results
    printf("The sum of the squares of %d random numbers is %.2f\n", n, sum);
    printf("The elapsed time is %.2f seconds\n", elapsed_time);

    return 0;
}