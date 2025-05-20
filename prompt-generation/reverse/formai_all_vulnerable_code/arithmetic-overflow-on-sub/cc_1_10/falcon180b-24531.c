//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_NUM 1000000

int is_prime(int num);

int main() {
    int num, i, count = 0;
    time_t start_time, end_time;
    double elapsed_time;

    srand(time(NULL));
    num = rand() % MAX_NUM + 1;

    printf("Generating prime numbers up to %d...\n", num);

    start_time = clock();

    for (i = 2; i <= num; i++) {
        if (is_prime(i)) {
            printf("%d\n", i);
            count++;
        }
    }

    end_time = clock();
    elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("\n%d prime numbers found.\n", count);
    printf("Execution time: %.2f seconds.\n", elapsed_time);

    return 0;
}

int is_prime(int num) {
    int i;

    if (num <= 1)
        return 0;

    for (i = 2; i <= sqrt(num); i++) {
        if (num % i == 0)
            return 0;
    }

    return 1;
}