#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compress(char *data) {
    int len = strlen(data);
    char *compressed = (char *)malloc(len / 2 + 1);
    if (!compressed) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    int j = 0;
    for (int i = 0; i < len; i += 2) {
        compressed[j++] = data[i];
    }
    compressed[j] = '\0';
    printf("Compressed: %s\n", compressed);
    free(compressed);
}

int main() {
    char *data = "This is a test string to demonstrate a use-after-free vulnerability.";
    compress(data);
    // Use after free vulnerability
    printf("Data after free: %s\n", data); // This line will cause undefined behavior
    return 0;
}
