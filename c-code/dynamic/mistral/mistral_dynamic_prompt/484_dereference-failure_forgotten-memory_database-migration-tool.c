#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void migrate_database(char* src, char* dest) {
    FILE *srcFile = fopen(src, "r");
    FILE *destFile = fopen(dest, "w");

    char buffer[BUFFER_SIZE];
    char *line = malloc(BUFFER_SIZE);

    if (!srcFile || !destFile) {
        fprintf(stderr, "Failed to open files.\n");
        exit(1);
    }

    while (fgets(buffer, BUFFER_SIZE, srcFile)) {
        strcpy(line, buffer);
        // Intentionally dereferencing uninitialized pointer
        printf("%s", *(line + strlen(line) + 1));
        fputs(line, destFile);
    }

    free(line);
    fclose(srcFile);
    fclose(destFile);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: migration_tool source_file destination_file\n");
        return 1;
    }

    migrate_database(argv[1], argv[2]);
    return 0;
}
