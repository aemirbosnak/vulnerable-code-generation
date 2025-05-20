//Falcon-180B DATASET v1.0 Category: Memory management ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

void *my_malloc(size_t size) {
    void *ptr;
    if (size <= 0) {
        printf("Invalid size parameter\n");
        exit(1);
    }
    if (size > MAX_SIZE) {
        printf("Size is too large\n");
        exit(1);
    }
    ptr = malloc(size);
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    return ptr;
}

void my_free(void *ptr) {
    if (ptr == NULL) {
        printf("Invalid pointer\n");
        exit(1);
    }
    free(ptr);
}

void my_strcpy(char *dest, const char *src) {
    if (dest == NULL || src == NULL) {
        printf("Invalid parameter\n");
        exit(1);
    }
    strcpy(dest, src);
}

int main() {
    char *str1, *str2;
    str1 = my_malloc(MAX_SIZE);
    str2 = my_malloc(MAX_SIZE);
    if (str1 == NULL || str2 == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    printf("Enter a string: ");
    scanf("%s", str1);
    printf("Enter another string: ");
    scanf("%s", str2);
    if (strcmp(str1, str2) == 0) {
        printf("Strings are equal\n");
    } else {
        printf("Strings are not equal\n");
    }
    my_free(str1);
    my_free(str2);
    return 0;
}