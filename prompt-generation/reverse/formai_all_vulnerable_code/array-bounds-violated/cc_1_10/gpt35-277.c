//FormAI DATASET v1.0 Category: File Backup System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
    // Check if at least one argument is provided
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file_path> [backup_path]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *file_path = argv[1];
    char *backup_path;
    
    // If a backup path isn't provided, generate a default backup path
    if (argc < 3) {
        backup_path = malloc(strlen(file_path) + 5);
        strcpy(backup_path, file_path);
        strcat(backup_path, ".bak");
    } else {
        backup_path = argv[2];
    }

    FILE* file = fopen(file_path, "r");
    FILE* backup_file = fopen(backup_path, "w");

    if (!file) {
        fprintf(stderr, "Error: Unable to open file '%s'\n", file_path);
        exit(EXIT_FAILURE);
    }

    if (!backup_file) {
        fprintf(stderr, "Error: Unable to create backup file '%s'\n", backup_path);
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    size_t line_length;
    while (fgets(line, sizeof(line), file)) {
        line_length = strlen(line);

        // Remove newline character if present
        if (line[line_length - 1] == '\n') {
            line[line_length - 1] = '\0';
        }

        // Write line to backup file
        fprintf(backup_file, "%s\n", line);
    }

    fclose(file);
    fclose(backup_file);

    printf("Backup created successfully!\n");

    return 0;
}