//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define MAX_N 1000000
#define MAX_TRIALS 1000

int main(int argc, char *argv[]) {
    int n = 0;
    int sum = 0;
    int trials = 0;
    int max_trial = 0;
    int i;
    int *arr = NULL;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    arr = (int *) malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    srand(time(NULL));

    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    start = clock();

    do {
        sum = 0;
        max_trial = 0;

        for (i = 0; i < n; i++) {
            sum += arr[i];
        }

        for (i = 0; i < MAX_TRIALS; i++) {
            int j = rand() % n;
            int k = rand() % n;
            int temp = arr[j];
            arr[j] = arr[k];
            arr[k] = temp;
        }

        for (i = 0; i < n; i++) {
            sum -= arr[i];
            if (arr[i] > max_trial) {
                max_trial = arr[i];
            }
        }

        trials++;

    } while (trials < MAX_TRIALS || max_trial > 0);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("The sum of the array is: %d\n", sum);
    printf("The maximum number of trials is: %d\n", max_trial);
    printf("The number of trials is: %d\n", trials);
    printf("CPU time used: %lf seconds\n", cpu_time_used);

    free(arr);
    return 0;
}