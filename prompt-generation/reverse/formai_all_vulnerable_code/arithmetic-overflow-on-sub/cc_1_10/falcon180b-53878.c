//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate random numbers within a range
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
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

int main() {
    srand(time(NULL)); // seed the random number generator with the current time

    // prompt the user for the range of numbers to generate
    int min_num, max_num;
    printf("Enter the minimum number: ");
    scanf("%d", &min_num);
    printf("Enter the maximum number: ");
    scanf("%d", &max_num);

    // generate a list of random numbers within the given range
    int num_list[10];
    for (int i = 0; i < 10; i++) {
        num_list[i] = rand_num(min_num, max_num);
        printf("%d ", num_list[i]);
    }

    // print the sum of all the numbers in the list
    int sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += num_list[i];
    }
    printf("\nSum of the numbers: %d\n", sum);

    // print the average of all the numbers in the list
    double avg = (double)sum / 10;
    printf("Average of the numbers: %.2f\n", avg);

    // print the number of prime numbers in the list
    int prime_count = 0;
    for (int i = 0; i < 10; i++) {
        if (is_prime(num_list[i])) {
            prime_count++;
        }
    }
    printf("Number of prime numbers in the list: %d\n", prime_count);

    return 0;
}