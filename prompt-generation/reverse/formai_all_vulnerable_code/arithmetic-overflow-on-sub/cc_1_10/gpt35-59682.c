//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct prime_args {
    int start, end;
    int *primes;
    int *count;
};

void *find_primes(void *args) {
    struct prime_args *p = (struct prime_args *) args;

    for (int i = p->start; i <= p->end; i++) {
        int is_prime = 1;
        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                is_prime = 0;
                break;
            }
        }
        if (is_prime) {
            p->primes[(*p->count)++] = i;
        }
    }

    pthread_exit(NULL);
}

int main(void) {
    int min, max, count = 0;
    printf("Please enter the minimum number: ");
    scanf("%d", &min);
    printf("Please enter the maximum number: ");
    scanf("%d", &max);

    int *primes = (int *) malloc(sizeof(int) * (max - min + 1));

    pthread_t thread1, thread2;
    struct prime_args args1 = {min, (min + max) / 2, primes, &count};
    struct prime_args args2 = {(min + max) / 2 + 1, max, primes, &count};

    pthread_create(&thread1, NULL, find_primes, &args1);
    pthread_create(&thread2, NULL, find_primes, &args2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Generated prime numbers within range [%d, %d]:", min, max);
    for (int i = 0; i < count; i++) {
        printf(" %d", primes[i]);
    }
    printf("\n");

    free(primes);

    return 0;
}