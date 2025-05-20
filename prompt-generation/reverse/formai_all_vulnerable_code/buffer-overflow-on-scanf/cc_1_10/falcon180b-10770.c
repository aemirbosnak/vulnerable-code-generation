//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 1000000

/* Function to generate a random number within the given range */
int rand_num(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

/* Function to check if a number is prime */
int is_prime(int num)
{
    int i;
    if (num <= 1)
        return 0;

    for (i = 2; i <= sqrt(num); i++) {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

/* Function to generate prime numbers within the given range */
void generate_primes(int start, int end)
{
    int i, count = 0;
    srand(time(NULL));

    printf("Generating prime numbers between %d and %d:\n", start, end);

    for (i = start; i <= end; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
            count++;
        }
        if (count >= MAX_NUM)
            break;
    }
}

int main()
{
    int start, end;

    printf("Enter the starting number: ");
    scanf("%d", &start);

    printf("Enter the ending number: ");
    scanf("%d", &end);

    generate_primes(start, end);

    return 0;
}