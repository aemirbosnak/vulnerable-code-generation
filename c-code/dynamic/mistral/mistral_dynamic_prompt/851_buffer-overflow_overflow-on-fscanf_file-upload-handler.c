#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void handle_file_upload(FILE *file) {
    char buffer[BUFFER_SIZE];
    fscanf(file, "%s", buffer);
    // Deliberate buffer overflow
    printf("Received: %s\n", buffer);
}

int main(int argc, char *argv[]) {
    FILE *file;

    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    if ((file = fopen(argv[1], "r")) == NULL) {
        perror("Error opening file");
        return 2;
    }

    handle_file_upload(file);
    fclose(file);

    return 0;
}
