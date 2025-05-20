#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void process_file(char* filename) {
    FILE *file;
    char buffer[10];
    int size;

    file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return;
    }

    fgets(buffer, sizeof(buffer), file);
    sscanf(buffer, "%n", &size);

    char *data = malloc(size);
    fread(data, size, 1, file);

    fclose(file);

    // Process the uploaded file data (for the sake of example)
    for (int i = 0; i < size; ++i) {
        data[i] ^= 0x31; // XOR operation for "1" (ascending ASCII)
    }

    printf("Processed data:\n");
    fwrite(data, 1, size, stdout);
    free(data);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    process_file(argv[1]);

    return 0;
}
