//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

int main() {
    char str1[MAX_LENGTH];
    char str2[MAX_LENGTH];
    char str3[MAX_LENGTH];

    printf("Enter first string: ");
    fgets(str1, MAX_LENGTH, stdin);
    printf("Enter second string: ");
    fgets(str2, MAX_LENGTH, stdin);

    // Concatenate two strings
    char* result = malloc(strlen(str1) + strlen(str2) + 1);
    strcat(result, str1);
    strcat(result, str2);
    printf("Concatenated string: %s\n", result);
    free(result);

    // Compare two strings
    int result_compare = strcmp(str1, str2);
    if(result_compare == 0) {
        printf("The two strings are equal.\n");
    } else if(result_compare < 0) {
        printf("The first string is less than the second string.\n");
    } else {
        printf("The first string is greater than the second string.\n");
    }

    // Copy one string to another
    strcpy(str3, str1);
    printf("Copied string: %s\n", str3);

    // Reverse a string
    char* reversed_str = malloc(strlen(str1) + 1);
    strcpy(reversed_str, str1);
    char* end = reversed_str + strlen(reversed_str) - 1;
    char* start = reversed_str;
    while(start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
    printf("Reversed string: %s\n", reversed_str);
    free(reversed_str);

    return 0;
}