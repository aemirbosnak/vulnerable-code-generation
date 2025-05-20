//Falcon-180B DATASET v1.0 Category: Educational ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Function to concatenate two strings
void concatenate(char* str1, char* str2, char* result) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int len = len1 + len2;

    strcpy(result, str1);
    strcat(result, str2);

    printf("Result: %s\n", result);
}

// Function to reverse a string
void reverse(char* str, char* result) {
    int len = strlen(str);
    int i, j;

    for (i = 0, j = len - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

    strcpy(result, str);
    printf("Result: %s\n", result);
}

// Function to convert a string to uppercase
void uppercase(char* str, char* result) {
    int len = strlen(str);
    int i;

    for (i = 0; i < len; i++) {
        str[i] = toupper(str[i]);
    }

    strcpy(result, str);
    printf("Result: %s\n", result);
}

// Function to convert a string to lowercase
void lowercase(char* str, char* result) {
    int len = strlen(str);
    int i;

    for (i = 0; i < len; i++) {
        str[i] = tolower(str[i]);
    }

    strcpy(result, str);
    printf("Result: %s\n", result);
}

int main() {
    char str1[MAX_SIZE], str2[MAX_SIZE], result[MAX_SIZE];

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    concatenate(str1, str2, result);
    reverse(str1, result);
    uppercase(str1, result);
    lowercase(str1, result);

    return 0;
}