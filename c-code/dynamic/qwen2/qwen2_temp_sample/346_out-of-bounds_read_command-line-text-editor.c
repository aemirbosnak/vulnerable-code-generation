#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

void readFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    int lineNumber = 1;
    char line[MAX_LINE_LENGTH];

    while (fgets(line, sizeof(line), file)) {
        printf("%d: %s", lineNumber, line);
        lineNumber++;
    }

    fclose(file);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    readFile(argv[1]);

    return 0;
}
