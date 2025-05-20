#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compress(char *data) {
    char *compressed = (char *)malloc(strlen(data));
    strcpy(compressed, data);
    printf("Compressed: %s\n", compressed);
    free(compressed);
}

int main() {
    char *data = "This is a test string.";
    compress(data);
    printf("Original: %s\n", data); // Use-after-free vulnerability here
    return 0;
}
