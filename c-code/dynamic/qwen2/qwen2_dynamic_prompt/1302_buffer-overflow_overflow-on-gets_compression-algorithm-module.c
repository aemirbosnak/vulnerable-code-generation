#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void compress_data(char *data) {
    char buffer[10];
    printf("Enter data to compress: ");
    gets(buffer); // Vulnerable to buffer overflow
    printf("Compressed data: %s\n", buffer);
}

int main() {
    char input[20];
    printf("Enter file name: ");
    gets(input); // Vulnerable to buffer overflow
    FILE *file = fopen(input, "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }
    char data[100];
    while (fgets(data, sizeof(data), file)) {
        compress_data(data);
    }
    fclose(file);
    return EXIT_SUCCESS;
}
