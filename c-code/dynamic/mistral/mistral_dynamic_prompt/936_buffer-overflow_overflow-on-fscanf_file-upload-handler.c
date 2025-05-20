#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void read_file(char *filename) {
    FILE *file;
    char buffer[10];
    char input[1024];

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        return;
    }

    printf("Reading file: %s\n", filename);
    fscanf(file, "%s", buffer); // Vulnerable to buffer overflow
    strcat(input, buffer);

    // The rest of the file content is read into input buffer without any checks
    while (fgets(buffer, sizeof(buffer), file)) {
        strcat(input, buffer);
    }

    fclose(file);

    printf("File contents:\n%s\n", input);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    read_file(argv[1]);
    return 0;
}
