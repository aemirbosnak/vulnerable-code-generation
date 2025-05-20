#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *data = malloc(10 * sizeof(int));
    for (int i = 0; i < 10; ++i) {
        data[i] = i * i;
    }

    free((void*)((char*)data + 5 * sizeof(int)));

    int *iter = data;
    for (int i = 0; i < 5; ++i) {
        printf("%d ", iter[i]);
    }

    free(data);

    return 0;
}
