//LLAMA2-13B DATASET v1.0 Category: Game ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_LENGTH 1024
#define MAGIC_NUMBER 42

void print_rainbow(void);
int is_prime(int);
int find_first_prime(int);

int main(void) {
    int n;
    char magic_word[MAX_LENGTH];

    srand(time(NULL));

    printf("Welcome to the Genius C Program! Please enter a number: ");
    scanf("%d", &n);

    if (n == 42) {
        printf("Congratulations! You have entered the magic number!\n");
        print_rainbow();
    } else {
        printf("Too bad, that's not the magic number. Try again!\n");
        n = find_first_prime(n);
        if (n == 0) {
            printf("You have entered a non-prime number. Better luck next time!\n");
        } else {
            printf("You have entered a prime number! The first prime greater than or equal to %d is %d.\n", n, find_first_prime(n));
        }
    }

    return 0;
}

void print_rainbow(void) {
    int i, j;
    char c;

    for (i = 0; i < 7; i++) {
        for (j = 0; j < 7; j++) {
            c = i * 7 + j;
            if (c < 91) {
                printf("%c", c);
            } else {
                printf("%c", 97 + (c - 91));
            }
        }
        printf("\n");
    }
}

int is_prime(int n) {
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int find_first_prime(int n) {
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i <= n; i++) {
        if (is_prime(i)) {
            return i;
        }
    }
    return 0;
}