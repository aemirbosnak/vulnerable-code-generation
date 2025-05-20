//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define MAX_NUM 1000000

void is_prime(int num) {
    if (num <= 1) {
        printf("%d is not a prime number\n", num);
        return;
    }
    int i;
    for (i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            printf("%d is not a prime number\n", num);
            return;
        }
    }
    printf("%d is a prime number\n", num);
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    if (num <= 0 || num > MAX_NUM) {
        printf("Invalid input\n");
        return 0;
    }
    int count = 0;
    int prime_numbers[MAX_NUM];
    prime_numbers[count++] = 2;
    int i;
    for (i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) {
            prime_numbers[count++] = i;
            num /= i;
            i--;
        }
    }
    if (num > 2) {
        prime_numbers[count++] = num;
    }
    printf("Prime numbers up to %d:\n", num);
    for (i = 0; i < count; i++) {
        is_prime(prime_numbers[i]);
    }
    return 0;
}