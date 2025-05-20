//Falcon-180B DATASET v1.0 Category: Memory management ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
} Person;

void *my_malloc(size_t size) {
    printf("Malloc called with size %d\n", size);
    void *ptr = malloc(size);
    if (ptr == NULL) {
        printf("Malloc failed\n");
        exit(1);
    }
    return ptr;
}

void *my_calloc(size_t count, size_t size) {
    printf("Calloc called with count %d and size %d\n", count, size);
    void *ptr = calloc(count, size);
    if (ptr == NULL) {
        printf("Calloc failed\n");
        exit(1);
    }
    return ptr;
}

void *my_realloc(void *ptr, size_t size) {
    printf("Realloc called with pointer %p and size %d\n", ptr, size);
    void *new_ptr = realloc(ptr, size);
    if (new_ptr == NULL) {
        printf("Realloc failed\n");
        exit(1);
    }
    return new_ptr;
}

void my_free(void *ptr) {
    printf("Free called with pointer %p\n", ptr);
    free(ptr);
}

int main() {
    char *str1 = my_malloc(10);
    strcpy(str1, "Hello");

    char *str2 = my_calloc(10, sizeof(char));
    strcpy(str2, "World");

    char *str3 = my_realloc(str1, 15);
    strcat(str3, " ");
    strcat(str3, str2);

    printf("%s\n", str3);

    my_free(str1);
    my_free(str2);
    my_free(str3);

    return 0;
}