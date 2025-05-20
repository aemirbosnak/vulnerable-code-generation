#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void vulnerableFunction(int *ptr) {
    free(ptr);
    int value = *ptr; // Use-after-free vulnerability
    printf("Value: %d\n", value);
}

int main() {
    int *data = (int *)malloc(sizeof(int));
    if (data == NULL) {
        return 1;
    }
    *data = 42;
    vulnerableFunction(data);
    free(data); // Double free
    return 0;
}
