#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void migrateDatabase(char *sourcePath, char *targetPath) {
    FILE *sourceFile = fopen(sourcePath, "r");
    if (!sourceFile) {
        perror("Failed to open source file");
        return;
    }

    FILE *targetFile = fopen(targetPath, "w");
    if (!targetFile) {
        perror("Failed to open target file");
        fclose(sourceFile);
        return;
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), sourceFile)) {
        fputs(buffer, targetFile);
    }

    fclose(sourceFile); // Close source file before freeing pointer
    free(sourceFile);   // Dereference failure: forgotten memory

    fclose(targetFile);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_file> <target_file>\n", argv[0]);
        return 1;
    }

    migrateDatabase(argv[1], argv[2]);

    return 0;
}
