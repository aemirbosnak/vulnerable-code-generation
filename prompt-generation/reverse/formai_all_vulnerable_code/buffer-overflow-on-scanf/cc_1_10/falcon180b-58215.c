//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_NUM 1000000

int is_prime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void generate_primes(int start_num, int end_num) {
    printf("Generating prime numbers between %d and %d...\n", start_num, end_num);
    FILE *file = fopen("primes.txt", "w");
    if (file == NULL) {
        printf("Error: Could not create file.\n");
        exit(1);
    }
    for (int i = start_num; i <= end_num; i++) {
        if (is_prime(i)) {
            fprintf(file, "%d\n", i);
        }
    }
    fclose(file);
    printf("Done.\n");
}

int main() {
    int start_num, end_num;
    printf("Enter the starting number: ");
    scanf("%d", &start_num);
    printf("Enter the ending number: ");
    scanf("%d", &end_num);
    if (start_num > end_num) {
        printf("Error: Starting number cannot be greater than ending number.\n");
        return 1;
    }
    if (start_num < 2 || end_num > MAX_NUM) {
        printf("Error: Invalid range.\n");
        return 1;
    }
    generate_primes(start_num, end_num);
    return 0;
}