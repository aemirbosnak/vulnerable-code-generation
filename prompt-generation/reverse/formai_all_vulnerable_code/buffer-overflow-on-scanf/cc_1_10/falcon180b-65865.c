//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NUM 1000000

/* function to check if a number is prime */
int is_prime(int num)
{
    if (num <= 1)
        return 0;

    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0)
            return 0;
    }

    return 1;
}

/* function to generate prime numbers */
void generate_primes(int start, int end)
{
    printf("Generating prime numbers between %d and %d\n", start, end);

    FILE *fp = fopen("primes.txt", "w");

    if (fp == NULL) {
        printf("Error: could not open file\n");
        exit(1);
    }

    for (int i = start; i <= end; i++) {
        if (is_prime(i)) {
            fprintf(fp, "%d\n", i);
            printf("%d ", i);
        }
    }

    fclose(fp);
}

int main()
{
    int start, end;

    printf("Enter start number: ");
    scanf("%d", &start);

    printf("Enter end number: ");
    scanf("%d", &end);

    if (start < 2 || end < 2 || start > end) {
        printf("Error: invalid input\n");
        exit(1);
    }

    generate_primes(start, end);

    return 0;
}