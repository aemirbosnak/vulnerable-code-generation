//Falcon-180B DATASET v1.0 Category: Recursive ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_RECURSION_LEVEL 1000

void print_array(char *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%c", arr[i]);
    }
    printf("\n");
}

int count_palindromes(char *str, int start, int end) {
    int count = 0;
    for (int i = start; i <= end; i++) {
        for (int j = i; j <= end; j++) {
            if (i == j) {
                continue;
            }
            if (str[i] == str[j]) {
                count++;
            }
        }
    }
    return count;
}

void find_palindromes(char *str, int start, int end, int level, char *result) {
    if (level == MAX_RECURSION_LEVEL) {
        printf("Error: Maximum recursion level reached.\n");
        exit(1);
    }
    if (start >= end) {
        if (level == 1) {
            printf("Palindrome found: %s\n", result);
        }
        return;
    }
    for (int i = start; i <= end; i++) {
        result[level] = str[i];
        find_palindromes(str, start, end, level + 1, result);
    }
}

int main() {
    char input[1000];
    printf("Enter a string: ");
    scanf("%s", input);
    find_palindromes(input, 0, strlen(input) - 1, 0, "");
    return 0;
}