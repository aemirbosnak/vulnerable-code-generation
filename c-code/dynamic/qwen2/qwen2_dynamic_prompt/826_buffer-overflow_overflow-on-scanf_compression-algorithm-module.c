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
    char *data;
    int size;

    printf("Enter the size of the data: ");
    scanf("%d", &size);

    data = (char *)malloc(size * sizeof(char));
    if (data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    compress_data(data, size);

    printf("Compressed data: %s\n", data);

    free(data);
    return 0;
}
