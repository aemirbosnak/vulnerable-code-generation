//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <limits.h>

#define MAX_SIZE 1000
#define MAX_CHARS 10

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void reverse(char s[]) {
    int i, j;
    char c;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void itoa(int n, char s[]) {
    int i, sign;
    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);

    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

int isPalindrome(char s[]) {
    int i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        if (s[i]!= s[j])
            return 0;
    }
    return 1;
}

int main() {
    char s[MAX_SIZE];
    int i, j, k, n, count = 0;

    printf("Enter a string: ");
    scanf("%s", s);

    for (i = 0; i < strlen(s); i++) {
        s[i] = toupper(s[i]);
    }

    for (i = 0; i < strlen(s); i++) {
        for (j = i + 1; j < strlen(s); j++) {
            for (k = j + 1; k < strlen(s); k++) {
                if (isPalindrome(s + i)) {
                    strncpy(s + i + 1, s + j, strlen(s) - j);
                    s[i] = s[k];
                    strncpy(s + k, s + j + 1, strlen(s) - j - 1);
                    count++;
                }
            }
        }
    }

    printf("The number of palindromes in the given string is %d\n", count);

    return 0;
}