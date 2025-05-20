//Falcon-180B DATASET v1.0 Category: File handling ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_LINES 10000

typedef struct {
    char *filename;
    FILE *file;
    char *lines[MAX_NUM_LINES];
    int num_lines;
} FileData;

void init_filedata(FileData *filedata) {
    filedata->filename = NULL;
    filedata->file = NULL;
    filedata->num_lines = 0;
}

void free_filedata(FileData *filedata) {
    if (filedata->filename!= NULL) {
        free(filedata->filename);
        filedata->filename = NULL;
    }

    if (filedata->file!= NULL) {
        fclose(filedata->file);
        filedata->file = NULL;
    }

    for (int i = 0; i < filedata->num_lines; i++) {
        if (filedata->lines[i]!= NULL) {
            free(filedata->lines[i]);
            filedata->lines[i] = NULL;
        }
    }
}

int read_file(FileData *filedata) {
    char line[MAX_LINE_LENGTH];
    int num_lines = 0;

    if (filedata->file == NULL) {
        filedata->file = fopen(filedata->filename, "r");
        if (filedata->file == NULL) {
            printf("Error: Could not open file %s\n", filedata->filename);
            return 1;
        }
    }

    while (fgets(line, MAX_LINE_LENGTH, filedata->file)!= NULL) {
        if (num_lines >= MAX_NUM_LINES) {
            printf("Error: Maximum number of lines (%d) reached\n", MAX_NUM_LINES);
            return 1;
        }

        filedata->lines[num_lines] = strdup(line);
        num_lines++;
    }

    filedata->num_lines = num_lines;
    return 0;
}

void print_file(FileData *filedata) {
    for (int i = 0; i < filedata->num_lines; i++) {
        printf("%s\n", filedata->lines[i]);
    }
}

int main() {
    FileData filedata;
    init_filedata(&filedata);

    printf("Enter filename: ");
    scanf("%s", filedata.filename);

    if (read_file(&filedata)!= 0) {
        return 1;
    }

    print_file(&filedata);

    free_filedata(&filedata);

    return 0;
}