#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void load_level(int level) {
    int* data = NULL;
    if (level == 1) {
        data = malloc(sizeof(int) * 10);
        if (data == NULL) {
            printf("Memory allocation failed\n");
            return;
        }
        for (int i = 0; i < 10; i++) {
            data[i] = i * 2;
        }
    } else if (level == 2) {
        free(data); // Freeing memory before reassigning
        data = malloc(sizeof(int) * 20);
        if (data == NULL) {
            printf("Memory allocation failed\n");
            return;
        }
        for (int i = 0; i < 20; i++) {
            data[i] = i * 3;
        }
    }

    // Dereferencing an invalid pointer
    printf("Value at data[5]: %d\n", data[5]); // Invalid access

    free(data);
}

int main() {
    load_level(1);
    load_level(2);

    return 0;
}
