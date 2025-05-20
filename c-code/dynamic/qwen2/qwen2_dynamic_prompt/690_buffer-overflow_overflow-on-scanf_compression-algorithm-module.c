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
    if (strlen(buffer) > sizeof(buffer)) {
        printf("Buffer overflow detected!\n");
        exit(1);
    }
    // Simulate compression logic
    for (int i = 0; i < strlen(buffer); i++) {
        data[i] = buffer[i];
    }
}

int main() {
    char *data = malloc(20 * sizeof(char));
    if (data == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    compress_data(data, 20);

    free(data);
    return 0;
}
