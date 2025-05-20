//Falcon-180B DATASET v1.0 Category: Memory management ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 1000

// Function to dynamically allocate memory for a string
char* my_strdup(const char* str) {
    char* dup = malloc(strlen(str) + 1);
    if (dup == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    strcpy(dup, str);
    return dup;
}

// Function to concatenate two strings, dynamically allocating memory for the result
char* my_strcat(const char* str1, const char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    char* res = malloc(len1 + len2 + 1);
    if (res == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    strcpy(res, str1);
    strcat(res, str2);
    return res;
}

// Function to reverse a string, dynamically allocating memory for the result
char* my_strreverse(const char* str) {
    int len = strlen(str);
    char* res = malloc(len + 1);
    if (res == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    char* start = res;
    char* end = res + len - 1;
    while (start < end) {
        *start = *end;
        *end = '\0';
        start++;
        end--;
    }
    return res;
}

int main() {
    // Example usage
    char* str1 = my_strdup("Hello");
    char* str2 = my_strdup("World");
    char* res1 = my_strcat(str1, " ");
    res1 = my_strcat(res1, str2);
    printf("%s\n", res1);
    char* res2 = my_strreverse(res1);
    printf("%s\n", res2);
    free(str1);
    free(str2);
    free(res1);
    free(res2);
    return 0;
}