#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 256

void process_file(char* fileName) {
    FILE *file;
    int fileContent[BUFFER_SIZE];
    int i;

    file = fopen(fileName, "r");
    if (file == NULL) {
        perror("Error opening file.");
        exit(1);
    }

    for (i = 0; fscanf(file, "%d", &fileContent[i]) != EOF; ++i) {
        if (i >= BUFFER_SIZE) {
            fprintf(stderr, "Buffer overflow detected!\n");
            exit(1);
        }
    }

    fclose(file);

    // Process the data here...

    for (i = 0; i < BUFFER_SIZE; ++i) {
        printf("Content[%d]: %d\n", i, fileContent[i]);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    process_file(argv[1]);

    return 0;
}
