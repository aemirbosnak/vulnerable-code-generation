//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX 1000000

int is_prime(int n)
{
    int i;
    if (n <= 1)
        return 0;
    for (i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

void generate_primes(int start, int end)
{
    FILE *fp;
    int i, j, count = 0;
    fp = fopen("primes.txt", "w");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(0);
    }
    fprintf(fp, "Prime numbers between %d and %d:\n", start, end);
    for (i = start; i <= end; i++) {
        if (is_prime(i)) {
            fprintf(fp, "%d ", i);
            count++;
        }
    }
    fprintf(fp, "\nTotal prime numbers: %d\n", count);
    fclose(fp);
}

int main()
{
    int start, end;
    printf("Enter the starting number: ");
    scanf("%d", &start);
    printf("Enter the ending number: ");
    scanf("%d", &end);
    if (start <= 0 || end <= 0 || start > end) {
        printf("Invalid input\n");
        exit(0);
    }
    srand(time(NULL));
    generate_primes(start, end);
    return 0;
}