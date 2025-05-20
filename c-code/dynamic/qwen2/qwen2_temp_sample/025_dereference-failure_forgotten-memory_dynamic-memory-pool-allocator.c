#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define POOL_SIZE 1024

char pool[POOL_SIZE];
int free_index = 0;

void* my_malloc(size_t size) {
    if (free_index + size > POOL_SIZE) return NULL;
    void* ptr = &pool[free_index];
    free_index += size;
    return ptr;
}

void my_free(void* ptr) {}

int main() {
    char* str1 = (char*)my_malloc(10);
    strcpy(str1, "Hello");

    char* str2 = (char*)my_malloc(20);
    strcpy(str2, "World");

    printf("%s %s\n", str1, str2);

    // Dereference failure: using str1 after it has been freed implicitly
    printf("%s\n", str1); // This will likely crash due to accessing freed memory

    return 0;
}
