#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void process_file(char *filename) {
    FILE *fp = fopen(filename, "rb");
    char buffer[BUFFER_SIZE];

    if (!fp) {
        perror("Error opening file");
        return;
    }

    size_t bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, fp);

    // Deliberate out-of-bounds read, accessing one past the end of the buffer
    printf("First extra byte from the file: %c\n", buffer[BUFFER_SIZE]);

    fclose(fp);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    process_file(argv[1]);

    return 0;
}
