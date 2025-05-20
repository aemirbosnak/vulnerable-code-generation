//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FILE_SIZE (10 * 1024 * 1024) // 10MB

typedef struct {
    char *filename;
    FILE *fp;
    size_t filesize;
    char *buffer;
} backup_file_t;

void backup_file(backup_file_t *bf) {
    char line[MAX_LINE_LENGTH];
    size_t bytes_read = 0;

    while ((bytes_read = fread(line, sizeof(char), MAX_LINE_LENGTH, bf->fp)) > 0) {
        size_t line_len = strlen(line);
        if (line_len > 0 && line[line_len - 1] == '\n') {
            line[--line_len] = '\0';
        }
        printf("%s", line);
    }

    if (ferror(bf->fp)) {
        fprintf(stderr, "Error reading file: %s\n", bf->filename);
    }
}

int main() {
    backup_file_t bf;

    printf("Enter filename to backup: ");
    scanf("%s", bf.filename);

    bf.fp = fopen(bf.filename, "r");
    if (bf.fp == NULL) {
        fprintf(stderr, "Error opening file: %s\n", bf.filename);
        return 1;
    }

    fseek(bf.fp, 0, SEEK_END);
    bf.filesize = ftell(bf.fp);
    rewind(bf.fp);

    if (bf.filesize > MAX_FILE_SIZE) {
        fprintf(stderr, "File is too large to backup.\n");
        return 1;
    }

    bf.buffer = malloc(bf.filesize + 1);
    if (bf.buffer == NULL) {
        fprintf(stderr, "Out of memory.\n");
        return 1;
    }

    backup_file(&bf);

    fclose(bf.fp);
    free(bf.buffer);

    return 0;
}