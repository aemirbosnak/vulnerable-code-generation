#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

void recoverData(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        return;
    }

    char line[MAX_LINE_LENGTH];
    int lineNumber = 1;

    while (fgets(line, sizeof(line), file)) {
        // Simulate medieval fantasy theme
        printf("Line %d of the ancient tome:\n%s", lineNumber, line);

        // Check for non-ASCII characters
        for (int i = 0; line[i] != '\0'; i++) {
            if ((unsigned char)line[i] > 127) {
                printf("Warning: Non-ASCII character detected on line %d.\n", lineNumber);
                break;
            }
        }

        lineNumber++;
    }

    fclose(file);
}

int main() {
    char filename[256];

    printf("Enter the name of the ancient tome to recover data from: ");
    fgets(filename, sizeof(filename), stdin);

    // Remove newline character if present
    size_t len = strlen(filename);
    if (len > 0 && filename[len - 1] == '\n') {
        filename[len - 1] = '\0';
    }

    recoverData(filename);

    return 0;
}
