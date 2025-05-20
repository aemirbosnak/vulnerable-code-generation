//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_STR_LEN 1000
#define MAX_NUM_VALS 1000

// Function prototypes
int count_words(char *str);
int count_numbers(char *str);
int is_palindrome(char *str);
int is_prime(int num);

int main() {
    char str[MAX_STR_LEN];
    int num_vals;
    int i;

    printf("Enter a string: ");
    fgets(str, MAX_STR_LEN, stdin);
    num_vals = count_words(str);

    printf("Number of words: %d\n", num_vals);

    for (i = 0; i < num_vals; i++) {
        printf("Word %d: %s\n", i+1, strtok(str, " "));
    }

    printf("Enter a number of values to check for prime: ");
    scanf("%d", &num_vals);

    int vals[MAX_NUM_VALS];
    for (i = 0; i < num_vals; i++) {
        scanf("%d", &vals[i]);
        if (is_prime(vals[i])) {
            printf("%d is prime\n", vals[i]);
        } else {
            printf("%d is not prime\n", vals[i]);
        }
    }

    return 0;
}

int count_words(char *str) {
    int count = 0;
    char *token;

    token = strtok(str, " ");
    while (token!= NULL) {
        count++;
        token = strtok(NULL, " ");
    }

    return count;
}

int count_numbers(char *str) {
    int count = 0;
    char *token;

    token = strtok(str, " ");
    while (token!= NULL) {
        if (isdigit(token[0])) {
            count++;
        }
        token = strtok(NULL, " ");
    }

    return count;
}

int is_palindrome(char *str) {
    int len = strlen(str);
    int i;

    for (i = 0; i < len/2; i++) {
        if (str[i]!= str[len-i-1]) {
            return 0;
        }
    }

    return 1;
}

int is_prime(int num) {
    int i;

    for (i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return 0;
        }
    }

    return 1;
}