//Falcon-180B DATASET v1.0 Category: Memory management ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to allocate memory dynamically
void *my_malloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        printf("Error: Out of memory!\n");
        exit(1);
    }
    return ptr;
}

// Function to free memory dynamically
void my_free(void *ptr) {
    free(ptr);
}

// Function to copy a string using dynamic memory allocation
char *my_strcpy(const char *src) {
    size_t len = strlen(src) + 1;
    char *dest = my_malloc(len);
    if (dest == NULL) {
        return NULL;
    }
    strcpy(dest, src);
    return dest;
}

// Function to concatenate two strings using dynamic memory allocation
char *my_strcat(const char *src1, const char *src2) {
    size_t len1 = strlen(src1);
    size_t len2 = strlen(src2);
    size_t len = len1 + len2 + 1;
    char *dest = my_malloc(len);
    if (dest == NULL) {
        return NULL;
    }
    strcpy(dest, src1);
    strcat(dest, src2);
    return dest;
}

int main() {
    char *str1 = my_strcpy("Hello");
    printf("str1 = %s\n", str1);

    char *str2 = my_strcpy("World");
    printf("str2 = %s\n", str2);

    char *str3 = my_strcat(str1, str2);
    printf("str3 = %s\n", str3);

    my_free(str1);
    my_free(str2);
    my_free(str3);

    return 0;
}