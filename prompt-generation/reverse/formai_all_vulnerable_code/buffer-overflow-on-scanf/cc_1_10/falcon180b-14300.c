//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FILENAME_LENGTH 256

typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    int num_lines;
    char *lines[MAX_LINE_LENGTH];
} File;

int read_file(const char *filename, File *file) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file '%s'\n", filename);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    int num_lines = 0;

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        if (num_lines >= MAX_LINE_LENGTH) {
            printf("Error: file '%s' has too many lines\n", filename);
            fclose(fp);
            return 1;
        }

        int len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[--len] = '\0';
        }

        file->lines[num_lines++] = strdup(line);
    }

    file->num_lines = num_lines;
    fclose(fp);

    return 0;
}

int write_file(const char *filename, File *file) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file '%s' for writing\n", filename);
        return 1;
    }

    for (int i = 0; i < file->num_lines; i++) {
        fprintf(fp, "%s\n", file->lines[i]);
    }

    fclose(fp);

    return 0;
}

int main() {
    File file;
    char input_filename[MAX_FILENAME_LENGTH];
    char output_filename[MAX_FILENAME_LENGTH];

    printf("Enter the name of the input file: ");
    scanf("%s", input_filename);

    if (read_file(input_filename, &file)!= 0) {
        return 1;
    }

    printf("Enter the name of the output file: ");
    scanf("%s", output_filename);

    if (write_file(output_filename, &file)!= 0) {
        return 1;
    }

    printf("File recovery successful!\n");

    return 0;
}