#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 256

void handle_file(char *filename) {
    char buffer[MAX_BUFFER];
    FILE *file;

    printf("Uploading file: %s\n", filename);
    file = fopen(filename, "r");

    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    fgets(buffer, sizeof(buffer), file);
    fclose(file);

    printf("File contents:\n%s\n", buffer);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    handle_file(argv[1]);

    return 0;
}
