//Falcon-180B DATASET v1.0 Category: Recursive ; Style: brave
#include <stdio.h>
#include <stdlib.h>

// function to calculate the sum of digits in a number
int sum_of_digits(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

// recursive function to find the nth prime number
int nth_prime(int n, int count) {
    if (count == n) {
        return 0;
    }
    int i = 2;
    while (i <= count) {
        if (is_prime(i)) {
            return i;
        }
        i++;
    }
    return nth_prime(n, count + 1);
}

// function to check if a number is prime
int is_prime(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

// function to find the sum of the digits of the nth prime number
int sum_of_digits_nth_prime(int n) {
    int count = 0;
    int num = nth_prime(n, count);
    return sum_of_digits(num);
}

int main() {
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    int result = sum_of_digits_nth_prime(n);
    printf("The sum of the digits of the %dth prime number is %d.\n", n, result);
    return 0;
}