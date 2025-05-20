//Falcon-180B DATASET v1.0 Category: Memory management ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10000

// function to dynamically allocate memory
void* paranoid_malloc(size_t size) {
    void* ptr = malloc(size);
    if (ptr == NULL) {
        fprintf(stderr, "Error: failed to allocate %zu bytes of memory.\n", size);
        exit(EXIT_FAILURE);
    }
    return ptr;
}

// function to free memory
void paranoid_free(void* ptr) {
    if (ptr == NULL) {
        fprintf(stderr, "Error: trying to free a NULL pointer.\n");
        exit(EXIT_FAILURE);
    }
    free(ptr);
}

// function to copy a string
char* paranoid_strdup(const char* str) {
    size_t len = strlen(str);
    char* dup = paranoid_malloc(len + 1);
    if (dup == NULL) {
        fprintf(stderr, "Error: failed to allocate %zu bytes of memory for string duplication.\n", len + 1);
        exit(EXIT_FAILURE);
    }
    strcpy(dup, str);
    return dup;
}

// function to concatenate two strings
char* paranoid_strcat(const char* str1, const char* str2) {
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    char* cat = paranoid_malloc(len1 + len2 + 1);
    if (cat == NULL) {
        fprintf(stderr, "Error: failed to allocate %zu bytes of memory for string concatenation.\n", len1 + len2 + 1);
        exit(EXIT_FAILURE);
    }
    strcpy(cat, str1);
    strcpy(cat + len1, str2);
    return cat;
}

int main() {
    char* str1 = paranoid_strdup("Hello");
    char* str2 = paranoid_strdup("world");
    char* str3 = paranoid_strcat(str1, str2);
    printf("String 1: %s\n", str1);
    printf("String 2: %s\n", str2);
    printf("Concatenated string: %s\n", str3);
    paranoid_free(str1);
    paranoid_free(str2);
    paranoid_free(str3);
    return 0;
}