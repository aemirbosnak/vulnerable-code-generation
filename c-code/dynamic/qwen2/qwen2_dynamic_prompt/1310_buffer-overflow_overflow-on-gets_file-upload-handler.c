#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 16

void handle_file_upload(char *filename) {
    char buffer[BUFFER_SIZE];
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open file\n");
        return;
    }
    while (!feof(file)) {
        fgets(buffer, sizeof(buffer), file);
        // No bounds checking here
        printf("%s", buffer);
    }
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    handle_file_upload(argv[1]);
    return 0;
}
