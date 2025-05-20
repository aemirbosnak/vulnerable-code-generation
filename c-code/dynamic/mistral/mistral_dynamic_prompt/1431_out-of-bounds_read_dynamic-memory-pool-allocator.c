#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define POOL_SIZE 0x1000
char pool[POOL_SIZE];
size_t free_list[POOL_SIZE / sizeof(size_t)];
size_t free_count = POOL_SIZE / sizeof(size_t);

void *allocate(size_t size) {
    if (free_count == 0 || size > POOL_SIZE) {
        fprintf(stderr, "Out of memory\n");
        return NULL;
    }

    size_t idx = free_count--;
    void *ptr = &pool[free_list[idx]];
    free_list[idx] += size;

    return ptr;
}

int main() {
    char *buf1 = allocate(10);
    strcpy(buf1, "Attacker's Input");
    char *buf2 = allocate(5);
    strcpy(buf2, "Expected Output");

    // Intentionally reading beyond the allocated buffer
    for (int i = 0; i < 10; i++)
        printf("%c", buf1[10 + i]);

    return 0;
}
