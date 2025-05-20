//Falcon-180B DATASET v1.0 Category: Error handling ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// function prototypes
int read_int(const char* prompt);
double read_double(const char* prompt);
char* read_string(const char* prompt);

int main() {
    int num1, num2, result;
    double num3, num4, result_double;
    char* str1, str2;

    // read two integers and perform addition
    printf("Enter first integer:\n");
    num1 = read_int("Integer 1: ");
    printf("Enter second integer:\n");
    num2 = read_int("Integer 2: ");
    result = num1 + num2;
    printf("Result: %d\n", result);

    // read two doubles and perform subtraction
    printf("\nEnter first double:\n");
    num3 = read_double("Double 1: ");
    printf("Enter second double:\n");
    num4 = read_double("Double 2: ");
    result_double = num3 - num4;
    printf("Result: %.2f\n", result_double);

    // read two strings and concatenate them
    printf("\nEnter first string:\n");
    str1 = read_string("String 1: ");
    printf("Enter second string:\n");
    str2 = read_string("String 2: ");
    char* result_string = malloc(strlen(str1) + strlen(str2) + 1);
    strcat(result_string, str1);
    strcat(result_string, str2);
    printf("Result: %s\n", result_string);

    return 0;
}

// function to read an integer from user input
int read_int(const char* prompt) {
    int num;
    printf("%s", prompt);
    if (scanf("%d", &num)!= 1) {
        printf("Invalid input. Please enter an integer.\n");
        exit(1);
    }
    return num;
}

// function to read a double from user input
double read_double(const char* prompt) {
    double num;
    printf("%s", prompt);
    if (scanf("%lf", &num)!= 1) {
        printf("Invalid input. Please enter a double.\n");
        exit(1);
    }
    return num;
}

// function to read a string from user input
char* read_string(const char* prompt) {
    char str[100];
    printf("%s", prompt);
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = '\0'; // remove newline character
    return strdup(str);
}