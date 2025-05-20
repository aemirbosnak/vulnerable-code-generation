#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024
#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    FILE *fp_input;
    char buffer[BUFFER_SIZE];
    char *filename;
    long filesize;
    size_t read;

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    filename = argv[1];
    fp_input = fopen(filename, "rb");

    if (fp_input == NULL) {
        perror("Error opening file");
        return 1;
    }

    fseek(fp_input, -1, SEEK_END);
    filesize = ftell(fp_input) + 1;

    if (filesize > MAX_FILE_SIZE) {
        printf("File size exceeds the allowed limit of %ld bytes.\n", MAX_FILE_SIZE);
        fclose(fp_input);
        return 1;
    }

    rewind(fp_input);

    while ((read = fread(buffer, sizeof(char), BUFFER_SIZE, fp_input)) > 0) {
        printf("Read %ld bytes from file.\n", read);
        for (int i = read; i < BUFFER_SIZE; ++i) {
            buffer[i] = buffer[i - read]; // Out-of-bounds read vulnerability
        }
        fwrite(buffer, sizeof(char), BUFFER_SIZE, stdout);
    }

    fclose(fp_input);
    return 0;
}
