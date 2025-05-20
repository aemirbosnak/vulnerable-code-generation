#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void free_and_use(void *ptr) {
    free(ptr);
    if (ptr != NULL) {
        printf("%d\n", *(int *)ptr); // Use after free
    }
}

int main() {
    int *data = (int *)malloc(sizeof(int));
    if (data == NULL) {
        return 1;
    }
    *data = 42;
    free_and_use(data);
    return 0;
}
