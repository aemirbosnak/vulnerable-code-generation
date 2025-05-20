#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void compress_data(const char *input) {
    char buffer[10];
    int data;

    // Vulnerability: Buffer overflow due to insufficient check on input length
    if (sscanf(input, "%d", &data) == 1) {
        snprintf(buffer, sizeof(buffer), "Compressed: %d", data);
        printf("%s\n", buffer);
    } else {
        printf("Invalid input\n");
    }
}

int main() {
    char input[20];

    printf("Enter data to compress: ");
    fgets(input, sizeof(input), stdin);

    // Remove newline character from input
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    compress_data(input);

    return 0;
}
