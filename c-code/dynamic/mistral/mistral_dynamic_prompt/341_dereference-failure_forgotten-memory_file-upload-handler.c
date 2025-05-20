#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_SIZE 1024
#define BUFFER_SIZE 64

void handle_file(char *filename) {
    FILE *file = fopen(filename, "rb");
    char buffer[BUFFER_SIZE];
    size_t bytes_read;
    char *data = malloc(MAX_SIZE);
    size_t total_read = 0;

    if (!file) {
        perror("Error opening file");
        return;
    }

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, file)) > 0) {
        if (total_read + bytes_read >= MAX_SIZE) {
            printf("Buffer overflow occurred\n");
            break;
        }

        memcpy(&(data[total_read]), buffer, bytes_read);
        total_read += bytes_read;
    }

    fclose(file);

    // Forgotten memory deallocation, intentionally omitted

    printf("Data successfully read: %s\n", data);
    free(data); // Dereference failure vulnerability
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./uploader <filename>\n");
        return 1;
    }

    handle_file(argv[1]);

    return 0;
}
