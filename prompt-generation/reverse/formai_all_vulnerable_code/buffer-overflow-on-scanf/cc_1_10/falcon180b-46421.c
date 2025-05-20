//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int isPrime(int n) {
    int i;
    for (i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int num, count = 0, nums[100];
    int i, j, k, l;
    int prime[100];
    int flag = 0;
    srand(time(NULL));
    printf("Enter the number of prime numbers to be generated: ");
    scanf("%d", &num);
    if (num < 1 || num > 100) {
        printf("Invalid input! Please enter a number between 1 and 100.\n");
        return 0;
    }
    for (i = 2; i <= num; i++) {
        if (isPrime(i) == 1) {
            prime[count] = i;
            count++;
        }
    }
    if (count == 0) {
        printf("No prime numbers found in the given range.\n");
        return 0;
    }
    for (i = 0; i < count; i++) {
        for (j = i + 1; j < count; j++) {
            for (k = j + 1; k < count; k++) {
                for (l = k + 1; l < count; l++) {
                    if ((prime[i] + prime[j] + prime[k] + prime[l]) % (prime[i] * prime[j] * prime[k] * prime[l]) == 0) {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 1) {
                    break;
                }
            }
            if (flag == 1) {
                break;
            }
        }
        if (flag == 0) {
            nums[i] = prime[i];
        }
        flag = 0;
    }
    printf("The %d prime numbers are:\n", num);
    for (i = 0; i < num; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    return 0;
}