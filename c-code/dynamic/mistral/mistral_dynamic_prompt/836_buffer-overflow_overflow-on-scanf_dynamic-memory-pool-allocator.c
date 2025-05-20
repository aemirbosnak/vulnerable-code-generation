#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Block {
    char *data;
    size_t size;
    struct Block *next;
} Block;

Block *pool = NULL;

void init_pool(size_t initial_size) {
    pool = malloc(initial_size * sizeof(Block));
    for (size_t i = 0; i < initial_size; ++i) {
        (pool + i)->data = NULL;
        (pool + i)->size = 0;
        (pool + i)->next = (pool + i + 1);
    }
    (pool + initial_size - 1)->next = pool;
}

Block *alloc(size_t size) {
    if (!pool) {
        fprintf(stderr, "No memory pool allocated.\n");
        return NULL;
    }

    Block *current = pool;
    do {
        if (!current->data || current->size >= size) {
            if (current->data) free(current->data);
            current->data = malloc(size);
            current->size = size;
            return current;
        }
        current = current->next;
    } while (1);
}

int main() {
    init_pool(10);

    printf("Enter the number of elements to allocate: ");
    int n;
    scanf("%d", &n);

    char *arr;
    arr = alloc(sizeof(char) * n);

    printf("Enter the values: ");
    for (size_t i = 0; i < n; ++i)
        scanf("%c", arr + i);

    // Intentionally overflow the buffer
    char c;
    scanf("%c", &c);

    printf("Your array is:\n");
    for (size_t i = 0; i < n; ++i)
        printf("%c ", arr[i]);

    free(arr);

    return 0;
}
