#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_ENTRY_SIZE 1024

void readEntry(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }

    char entry[MAX_ENTRY_SIZE];
    while (fscanf(file, "%1023s", entry) != EOF) { // Vulnerability: Buffer overflow due to lack of bounds checking
        printf("%s\n", entry);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    readEntry(argv[1]);

    return 0;
}
