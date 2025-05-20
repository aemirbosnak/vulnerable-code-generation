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
    char buffer[100];
    printf("Enter some data to compress: ");
    fgets(buffer, sizeof(buffer), stdin);

    // Compress the data
    compress(buffer);

    // Use after free vulnerability
    printf("Data after compression: %s\n", buffer); // Use after free

    return 0;
}
