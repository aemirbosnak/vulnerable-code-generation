//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NUM 100
#define MAX_STR 100

// Function to calculate the arithmetic mean of two integers
int mean(int a, int b) {
    return (a + b) / 2;
}

// Function to calculate the arithmetic mean of two floating point numbers
float mean_fp(float a, float b) {
    return (a + b) / 2;
}

// Function to calculate the arithmetic mean of two strings
char *mean_str(char *a, char *b) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    int total_len = len_a + len_b;
    char *result = (char *)malloc(total_len + 1);
    int i = 0;

    for (i = 0; i < len_a; i++) {
        result[i] = a[i];
    }
    for (i = 0; i < len_b; i++) {
        result[i + len_a] = b[i];
    }
    result[total_len] = '\0';
    return result;
}

int main() {
    int num1, num2, res;
    char str1[MAX_STR], str2[MAX_STR];
    char *result_str;

    // Example 1: Calculate the arithmetic mean of two integers
    printf("Enter two integers: ");
    scanf("%d%d", &num1, &num2);
    res = mean(num1, num2);
    printf("The arithmetic mean of %d and %d is %d\n", num1, num2, res);

    // Example 2: Calculate the arithmetic mean of two floating point numbers
    printf("Enter two floating point numbers: ");
    scanf("%f%f", &num1, &num2);
    res = mean_fp(num1, num2);
    printf("The arithmetic mean of %f and %f is %f\n", num1, num2, res);

    // Example 3: Calculate the arithmetic mean of two strings
    printf("Enter two strings: ");
    scanf("%s%s", str1, str2);
    result_str = mean_str(str1, str2);
    printf("The arithmetic mean of %s and %s is %s\n", str1, str2, result_str);

    return 0;
}