#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 256

void process_file(FILE *file) {
    char buffer[MAX_SIZE];
    int len;

    printf("Uploading file...\n");

    while ((len = fscanf(file, "%s", buffer)) != EOF) {
        printf("Received: %s\n", buffer);
        // Assume buffer processing logic here...
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    char *filename;

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    filename = argv[1];
    file = fopen(filename, "r");

    if (!file) {
        perror("Error opening file");
        return 2;
    }

    process_file(file);
    fclose(file);

    return 0;
}
