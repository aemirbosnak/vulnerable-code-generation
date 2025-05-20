#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 10

void handle_file(FILE *file) {
    char buffer[BUFFER_SIZE];
    if (fscanf(file, "%s", buffer) != 1) {
        fprintf(stderr, "Error reading from file\n");
        return;
    }
    printf("Read: %s\n", buffer);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Failed to open file");
        return 1;
    }

    handle_file(file);

    fclose(file);
    return 0;
}
