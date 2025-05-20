#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 16

void handle_file_sync(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    char buffer[BUFFER_SIZE];
    printf("Enter data: ");
    // Vulnerability: Buffer overflow due to fscanf
    fscanf(file, "%s", buffer);
    fclose(file);

    printf("Data read: %s\n", buffer);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    handle_file_sync(argv[1]);

    return 0;
}
