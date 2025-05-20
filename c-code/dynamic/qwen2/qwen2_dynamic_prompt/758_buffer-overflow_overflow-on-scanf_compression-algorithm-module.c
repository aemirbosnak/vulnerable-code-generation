#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void compress_data(char *data, int size) {
    char buffer[10];
    printf("Enter data to compress: ");
    scanf("%s", buffer);
    // Buffer overflow vulnerability here
    for (int i = 0; i <= size; i++) {
        data[i] = buffer[i % 10];
    }
}

int main() {
    char *large_data;
    int size = 20;

    large_data = (char *)malloc(size * sizeof(char));
    if (large_data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    compress_data(large_data, size);

    free(large_data);
    return 0;
}
