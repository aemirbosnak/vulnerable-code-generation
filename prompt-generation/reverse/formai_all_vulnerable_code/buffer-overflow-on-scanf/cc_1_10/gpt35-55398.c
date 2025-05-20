//FormAI DATASET v1.0 Category: Math exercise ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

// A function to check if a number is prime
int is_prime(int num) {
    int i;
    for(i = 2; i <= num/2; i++) {
        if(num % i == 0) {
            return 0;
        }
    }
    return 1;
}

// A function to reverse a given number
int reverse_number(int num) {
    int rev = 0;
    while(num != 0) {
        int digit = num % 10;
        rev = rev * 10 + digit;
        num /= 10;
    }
    return rev;
}

// The main function
int main() {
    printf("Welcome to the Math Exercise Program\n");
    printf("Please enter a positive integer: ");
    int num;
    scanf("%d", &num);
    int rev_num = reverse_number(num);
    int sum_of_digits = 0, num_of_primes = 0;
    while(num != 0) {
        int digit = num % 10;
        sum_of_digits += digit;
        if(is_prime(digit)) {
            num_of_primes++;
        }
        num /= 10;
    }
    printf("The reverse of %d is %d\n", num, rev_num);
    printf("The sum of digits in %d is %d\n", num, sum_of_digits);
    printf("The number of prime digits in %d is %d\n", num, num_of_primes);
    if(num == rev_num) {
        printf("%d is a palindrome number\n", num);
    }
    else {
        printf("%d is not a palindrome number\n", num);
    }
    printf("Thank you for using the Math Exercise Program\n");
    return 0;
}