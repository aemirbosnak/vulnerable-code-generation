//Falcon-180B DATASET v1.0 Category: Memory management ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

// Function to allocate memory dynamically
void* safe_malloc(size_t num, size_t size) {
    void* ptr = malloc(num * size);
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    return ptr;
}

// Function to free memory
void safe_free(void* ptr) {
    free(ptr);
}

// Function to copy a string
char* strcpy(char* dest, const char* src) {
    char* result = dest;
    while ((*dest++ = *src++)!= '\0')
        ;
    return result;
}

// Function to concatenate two strings
char* strcat(char* dest, const char* src) {
    char* result = dest;
    while (*dest)
        dest++;
    while ((*dest++ = *src++)!= '\0')
        ;
    return result;
}

// Function to compare two strings
int strcmp(const char* str1, const char* str2) {
    while (*str1 && *str2 && *str1 == *str2) {
        str1++;
        str2++;
    }
    return *str1 - *str2;
}

// Function to reverse a string
char* strrev(char* str) {
    char* start = str;
    char* end = str + strlen(str) - 1;
    while (start < end) {
        char temp = *start;
        *start++ = *end;
        *end-- = temp;
    }
    return str;
}

int main() {
    // Allocate memory for a string
    char* str1 = safe_malloc(1, sizeof(char));
    *str1 = 'H';

    // Allocate memory for another string
    char* str2 = safe_malloc(1, sizeof(char));
    *str2 = 'e';

    // Concatenate the strings
    char* result = safe_malloc(3, sizeof(char));
    strcat(result, str1);
    strcat(result, str2);

    // Reverse the concatenated string
    char* reversed_result = safe_malloc(3, sizeof(char));
    strrev(reversed_result);

    // Print the strings
    printf("Original string: %s\n", result);
    printf("Reversed string: %s\n", reversed_result);

    // Free the allocated memory
    safe_free(str1);
    safe_free(str2);
    safe_free(result);
    safe_free(reversed_result);

    return 0;
}