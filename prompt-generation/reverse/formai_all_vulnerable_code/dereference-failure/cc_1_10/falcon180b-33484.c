//Falcon-180B DATASET v1.0 Category: Memory management ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to allocate memory dynamically
void* safeMalloc(size_t size) {
    void* ptr = malloc(size);
    if (ptr == NULL) {
        printf("Error: Memory allocation failed!\n");
        exit(1);
    }
    return ptr;
}

// Function to free memory dynamically
void safeFree(void* ptr) {
    if (ptr!= NULL) {
        free(ptr);
        ptr = NULL;
    }
}

// Function to copy a string
char* strcpy_s(char* destination, const char* source) {
    size_t len = strlen(source) + 1;
    destination = (char*) safeMalloc(len * sizeof(char));
    strcpy(destination, source);
    return destination;
}

// Function to concatenate two strings
char* strcat_s(char* destination, const char* source) {
    size_t destLen = strlen(destination);
    size_t srcLen = strlen(source);
    destination = (char*) realloc(destination, destLen + srcLen + 1);
    strcat(destination, source);
    return destination;
}

// Function to reverse a string
char* strrev_s(char* str) {
    size_t len = strlen(str);
    char* reversed = (char*) safeMalloc(len * sizeof(char));
    for (int i = 0; i < len; i++) {
        reversed[i] = str[len - 1 - i];
    }
    reversed[len] = '\0';
    safeFree(str);
    return reversed;
}

int main() {
    // Test safeMalloc and safeFree
    void* ptr1 = safeMalloc(10 * sizeof(int));
    void* ptr2 = safeMalloc(20 * sizeof(char));
    safeFree(ptr1);
    safeFree(ptr2);

    // Test strcpy_s
    char* str1 = strcpy_s(NULL, "Hello, World!");
    printf("str1 = %s\n", str1);
    safeFree(str1);

    // Test strcat_s
    char* str2 = strcpy_s(NULL, "Hello");
    char* str3 = strcat_s(str2, ", World!");
    printf("str3 = %s\n", str3);
    safeFree(str2);
    safeFree(str3);

    // Test strrev_s
    char* str4 = strcpy_s(NULL, "Hello, World!");
    char* reversed = strrev_s(str4);
    printf("reversed = %s\n", reversed);
    safeFree(str4);
    safeFree(reversed);

    return 0;
}