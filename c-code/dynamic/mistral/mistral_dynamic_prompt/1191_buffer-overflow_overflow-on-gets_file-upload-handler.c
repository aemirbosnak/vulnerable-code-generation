#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

void handle_file(char* filename) {
    FILE *file = fopen(filename, "r");
    char buffer[MAX_SIZE];
    if (!file) {
        printf("Error: Could not open file.\n");
        return;
    }

    printf("File %s opened successfully.\n", filename);

    while (fgets(buffer, sizeof(buffer), file)) {
        printf("Received line: %s", buffer);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    handle_file(argv[1]);

    return 0;
}
