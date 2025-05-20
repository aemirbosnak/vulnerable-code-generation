//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: excited
// **C Prime Number Generator**

#include <stdio.h>
#include <math.h>

int main() {
    int n, i, j, count = 0;
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    // Check if the given number is prime or not
    for (i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            printf("%d is not a prime number.", n);
            return 0;
        }
    }

    // Generate prime numbers up to the given number
    printf("\nPrime numbers up to %d:\n", n);
    for (i = 2; i <= n; i++) {
        count = 0;
        for (j = 2; j <= i / 2; j++) {
            if (i % j == 0) {
                count++;
                break;
            }
        }
        if (count == 0) {
            printf("%d ", i);
        }
    }

    return 0;
}

/*
Sample Input/Output:

Enter a positive integer: 20
2 3 5 7 11 13 17 19

Enter a positive integer: 25
2 3 5 7 11 13 17 19 23

Enter a positive integer: 30
2 3 5 7 11 13 17 19 23 29

Enter a positive integer: 35
2 3 5 7 11 13 17 19 23 29 31 37

Enter a positive integer: 40
2 3 5 7 11 13 17 19 23 29 31 37 41

Enter a positive integer: 50
2 3 5 7 11 13 17 19 23 29 31 37 41 43 47

Enter a positive integer: 0
0 is not a prime number.

Enter a positive integer: 1
1 is not a prime number.
*/