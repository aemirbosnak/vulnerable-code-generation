#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void process_file(char *filename) {
    FILE *file = fopen(filename, "r");
    char buffer[BUFFER_SIZE];
    char buffer2[10];
    int size;

    if (!file) {
        printf("Error opening file.\n");
        return;
    }

    while ((size = fscanf(file, "%s", buffer)) != EOF) {
        if (size > 9) {
            strcpy(buffer2, buffer);
        }
    }

    fclose(file);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: ./uploader <filename>\n");
        return 1;
    }

    process_file(argv[1]);

    printf("Processed file: %s\n", argv[1]);

    return 0;
}
