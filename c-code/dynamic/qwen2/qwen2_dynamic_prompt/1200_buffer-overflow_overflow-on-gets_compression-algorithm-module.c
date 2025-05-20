#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void compress_data(char *data) {
    char buffer[10];
    printf("Enter data to compress: ");
    gets(buffer); // Vulnerable function
    printf("Compressed data: %s\n", buffer);
}

int main() {
    char input[20];
    printf("Enter file name: ");
    gets(input); // Vulnerable function
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
