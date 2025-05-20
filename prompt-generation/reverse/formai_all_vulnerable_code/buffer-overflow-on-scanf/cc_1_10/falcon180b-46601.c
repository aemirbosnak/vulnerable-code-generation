//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBERS 1000000

int isPrime(int number);
int generatePrime(int start, int end);

int main() {
    int start, end;
    printf("Enter the start and end range: ");
    scanf("%d %d", &start, &end);
    if (start < 2) {
        start = 2;
    }
    if (end < start) {
        end = start;
    }
    generatePrime(start, end);
    return 0;
}

int isPrime(int number) {
    if (number <= 1) {
        return 0;
    }
    for (int i = 2; i <= number / 2; i++) {
        if (number % i == 0) {
            return 0;
        }
    }
    return 1;
}

int generatePrime(int start, int end) {
    int count = 0;
    int numbers[MAX_NUMBERS];
    int index = 0;
    for (int i = start; i <= end; i++) {
        if (isPrime(i)) {
            numbers[index] = i;
            index++;
            count++;
            if (count == MAX_NUMBERS) {
                break;
            }
        }
    }
    printf("Total prime numbers generated: %d\n", count);
    printf("Prime numbers in range %d to %d:\n", start, end);
    for (int i = 0; i < count; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
}