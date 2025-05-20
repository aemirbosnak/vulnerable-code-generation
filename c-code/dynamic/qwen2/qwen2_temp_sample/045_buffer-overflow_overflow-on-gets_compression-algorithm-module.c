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
    char input[200];
    printf("Enter file name to compress: ");
    gets(input); // Vulnerable to buffer overflow
    FILE *file = fopen(input, "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }
    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);
    char *data = malloc(length + 1);
    fread(data, 1, length, file);
    fclose(file);
    data[length] = '\0';
    compress_data(data);
    free(data);
    return EXIT_SUCCESS;
}
