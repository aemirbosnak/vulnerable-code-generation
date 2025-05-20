//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: all-encompassing
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX 1000000
#define TRUE 1
#define FALSE 0

int is_prime(int n)
{
    int i;
    if (n <= 1)
        return FALSE;

    for (i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return FALSE;
    }
    return TRUE;
}

void generate_primes(int start, int end)
{
    int i;
    for (i = start; i <= end; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }
}

int main()
{
    int start, end;

    printf("Enter the starting number: ");
    scanf("%d", &start);

    printf("Enter the ending number: ");
    scanf("%d", &end);

    if (start > end) {
        printf("Invalid input! Starting number should be less than or equal to ending number.\n");
        exit(0);
    }

    generate_primes(start, end);

    return 0;
}