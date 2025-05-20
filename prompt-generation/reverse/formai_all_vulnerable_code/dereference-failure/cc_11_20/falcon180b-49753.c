//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *filename;
    FILE *file;
    char *buffer;
    int buf_size;
    int buf_len;
} FileSynchronizer;

int main(int argc, char **argv) {
    if (argc < 4) {
        printf("Usage: %s <file1> <file2> [output]\n", argv[0]);
        return 1;
    }

    FileSynchronizer file1 = {
       .filename = argv[1],
       .file = fopen(argv[1], "r"),
       .buffer = NULL,
       .buf_size = 0,
       .buf_len = 0
    };

    FileSynchronizer file2 = {
       .filename = argv[2],
       .file = fopen(argv[2], "r"),
       .buffer = NULL,
       .buf_size = 0,
       .buf_len = 0
    };

    if (file1.file == NULL || file2.file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    FILE *output_file = stdout;
    if (argc > 3) {
        output_file = fopen(argv[3], "w");
        if (output_file == NULL) {
            printf("Error opening output file.\n");
            return 1;
        }
    }

    char line1[MAX_LINE_LENGTH];
    char line2[MAX_LINE_LENGTH];
    char *line_ptr1 = line1;
    char *line_ptr2 = line2;

    while (fgets(line1, MAX_LINE_LENGTH, file1.file)!= NULL &&
           fgets(line2, MAX_LINE_LENGTH, file2.file)!= NULL) {
        if (strcmp(line1, line2)!= 0) {
            printf("Mismatch on line %d:\n", file1.buf_len + 1);
            printf("File 1: %s\n", line1);
            printf("File 2: %s\n", line2);
            if (output_file!= stdout) {
                fprintf(output_file, "Mismatch on line %d:\n", file1.buf_len + 1);
                fprintf(output_file, "File 1: %s\n", line1);
                fprintf(output_file, "File 2: %s\n", line2);
            }
        }
        file1.buf_len++;
        file2.buf_len++;
    }

    if (fclose(file1.file)!= 0 || fclose(file2.file)!= 0) {
        printf("Error closing file.\n");
        return 1;
    }

    if (output_file!= stdout) {
        fclose(output_file);
    }

    return 0;
}