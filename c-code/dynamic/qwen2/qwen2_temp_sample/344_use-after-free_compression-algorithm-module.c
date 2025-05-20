#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void compressData(char* data, int length) {
    // Simulate compression logic
}

int main() {
    char* buffer = (char*)malloc(100 * sizeof(char));
    if (!buffer) return -1;

    strcpy(buffer, "Sample data to compress");
    printf("Original: %s\n", buffer);

    compressData(buffer, 26);

    printf("Compressed: ");
    for (int i = 0; i < 26; ++i) {
        putchar(buffer[i]);
    }
    putchar('\n');

    // Use-after-free vulnerability
    free(buffer);
    printf("%s\n", buffer); // Use freed memory

    return 0;
}
