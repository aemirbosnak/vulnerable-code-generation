#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_FILE_SIZE 1024
#define BUFFER_SIZE 256

void handle_file(FILE *fp) {
    char buffer[BUFFER_SIZE];
    size_t bytes_read;
    size_t file_size = 0;

    while ((bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, fp)) > 0) {
        if (file_size + bytes_read > MAX_FILE_SIZE) {
            printf("File is too large. Max size is %lu bytes.\n", MAX_FILE_SIZE);
            return;
        }

        // Vulnerable section, write to destination without checking buffer size
        char *dest = malloc(file_size + bytes_read);
        memcpy(dest, &buffer, bytes_read);
        dest[file_size + bytes_read] = '\0';
        file_size += bytes_read;

        write(STDOUT_FILENO, dest, file_size);
    }

    if (fp != stdin) fclose(fp);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "rb");
    if (!fp) {
        perror("Error opening file");
        return 1;
    }

    handle_file(fp);

    return 0;
}
