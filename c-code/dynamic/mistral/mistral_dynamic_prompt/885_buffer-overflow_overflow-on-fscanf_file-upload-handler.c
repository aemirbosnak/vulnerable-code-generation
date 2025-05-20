#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void process_file(FILE *file) {
    char buffer[BUFFER_SIZE];
    int ch;

    printf("Uploading file...\n");
    fseek(file, 0, SEEK_SET); // Reset the file pointer to the beginning of the file

    while ((ch = fscanf(file, "%s", buffer)) != EOF) {
        if (ch == 1) {
            // Process the read line
            printf("Received line: %s\n", buffer);
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *file;

    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");

    if (file == NULL) {
        perror("Error opening file");
        return 2;
    }

    process_file(file);

    fclose(file);
    return 0;
}
