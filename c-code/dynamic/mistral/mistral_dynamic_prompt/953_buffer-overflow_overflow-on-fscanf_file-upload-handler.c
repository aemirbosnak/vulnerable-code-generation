#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

void handle_file(char *filename) {
    FILE *file = fopen(filename, "r");
    char buffer[BUFFER_SIZE];

    if (!file) {
        printf("Error: Could not open file.\n");
        return;
    }

    printf("Uploading file: %s\n", filename);
    fscanf(file, "%s", buffer);

    // Process the data here...
    // (In a real-world application, you would actually process the file data)

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file_to_upload>\n", argv[0]);
        return 1;
    }

    handle_file(argv[1]);

    return 0;
}
