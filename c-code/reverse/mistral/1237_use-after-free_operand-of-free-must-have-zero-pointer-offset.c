#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void process_data(int *data, int size) {
    int i;
    for (i = 0; i < size; ++i) {
        if (data[i] % 2 == 0) {
            void *temp = realloc(data, (size - i) * sizeof(int));
            if (!temp) {
                fprintf(stderr, "Memory allocation failed.\n");
                exit(1);
            }
            data = temp;
            data[i] = data[size - 1];
            data[size - 1] = 0;
            --size;
        }
    }
}

int main() {
    int *data = malloc(10 * sizeof(int));
    int i;
    for (i = 0; i < 10; ++i) {
        data[i] = i;
    }
    process_data(data, 10);
    free(data); // Use-after-free vulnerability here
    return 0;
}
