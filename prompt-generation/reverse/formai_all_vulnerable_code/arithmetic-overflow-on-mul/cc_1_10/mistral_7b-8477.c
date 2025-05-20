//MISTRAL-7B DATASET v1.0 Category: Arithmetic ; Style: thoughtful
#include <stdio.h>
#include <math.h>

void print_interesting_facts(int num) {
    int root, sum_of_digits;

    printf("\nNumber: %d", num);

    // Calculate sum of digits using recursive function
    sum_of_digits = sum_of_digits_recursive(num);
    printf("\nSum of digits: %d", sum_of_digits);

    // Calculate square root and check if it's a perfect square
    root = sqrt(num);
    if (root * root == num)
        printf("\n%d is a perfect square", num);

    // Check if number is a palindrome
    if (is_palindrome(num))
        printf("\n%d is a palindrome", num);

    // Calculate and display interesting facts
    if (num > 0) {
        int digit = num % 10;
        printf("\nInteresting facts about %d:\n", num);

        // Fact 1: Sum of digits of a number is always greater than or equal to the number itself.
        if (sum_of_digits >= num)
            printf("- The sum of its digits is greater than or equal to itself.\n");

        // Fact 2: Every number leaves a digit when divided by 10.
        printf("- When divided by 10, %d leaves a remainder of %d.\n", num, digit);

        // Fact 3: Every number is a multiple of a digit.
        if (num % digit == 0)
            printf("- %d is a multiple of its last digit.\n", num);

        // Fact 4: Every even number greater than 2 can be written as the sum of two prime numbers.
        if (num > 2 && num % 2 == 0) {
            int i = 3, is_prime, sum = 0;
            while (sum < num) {
                is_prime = 1;
                for (int j = 2; j <= sqrt(i); j++) {
                    if (i % j == 0) {
                        is_prime = 0;
                        break;
                    }
                }
                if (is_prime) {
                    sum += i;
                    if (sum == num) {
                        printf("- %d is the sum of two prime numbers: %d and %d.\n", num, i, num - i);
                        break;
                    }
                }
                i += 2;
            }
        }
    } else {
        printf("\nInvalid number. Please enter a positive integer.");
    }
}

int sum_of_digits_recursive(int num) {
    if (num >= 10)
        return num % 10 + sum_of_digits_recursive(num / 10);
    else
        return num;
}

int is_palindrome(int num) {
    int reversed_num = 0;
    int original_num = num;

    while (num != 0) {
        int digit = num % 10;
        reversed_num = reversed_num * 10 + digit;
        num /= 10;
    }

    return original_num == reversed_num;
}

int main() {
    int user_number;

    printf("Enter a positive integer: ");
    scanf("%d", &user_number);

    print_interesting_facts(user_number);

    return 0;
}