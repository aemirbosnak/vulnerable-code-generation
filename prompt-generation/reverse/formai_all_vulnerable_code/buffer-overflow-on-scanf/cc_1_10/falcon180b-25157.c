//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: high level of detail
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define MAX_N 1000
#define MAX_DIGITS 1000

int main() {
    int n, d;
    double x, y, z;
    int count = 0, max_count = 0;
    int max_index = 0;
    int *digits;
    int i;
    struct tm *timeinfo;
    time_t now;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Enter the number of digits: ");
    scanf("%d", &d);

    srand(time(NULL));
    for (i = 0; i < n; i++) {
        x = rand() % 1000;
        y = rand() % 1000;
        z = rand() % 1000;
        printf("%d %d %d\n", x, y, z);
    }

    digits = (int *)malloc(MAX_N * sizeof(int));
    if (digits == NULL) {
        printf("Memory error\n");
        exit(1);
    }

    for (i = 0; i < n; i++) {
        x = rand() % 1000;
        y = rand() % 1000;
        z = rand() % 1000;

        if (x == y && y == z) {
            count++;
            if (count > max_count) {
                max_count = count;
                max_index = i;
            }
        } else {
            count = 0;
        }
    }

    printf("The number of times %d appears consecutively is %d\n", max_count, max_index + 1);

    free(digits);
    return 0;
}