//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_FILE_NAME_LENGTH 256
#define MAX_LINE_LENGTH 1024

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    FILE *file;
    char line[MAX_LINE_LENGTH];
} File;

void open_file(File *file, const char *file_name) {
    file->file = fopen(file_name, "r");
    if (file->file == NULL) {
        printf("Error: could not open file '%s'\n", file_name);
        exit(1);
    }
}

bool read_line(File *file, char *line) {
    return fgets(file->line, MAX_LINE_LENGTH, file->file)!= NULL;
}

void close_file(File *file) {
    fclose(file->file);
}

int main() {
    int num_files;
    char file_names[MAX_FILE_NAME_LENGTH];
    File files[10];

    printf("Enter the number of files to synchronize: ");
    scanf("%d", &num_files);

    printf("Enter the file names:\n");
    for (int i = 0; i < num_files; i++) {
        scanf("%s", file_names + i * MAX_FILE_NAME_LENGTH);
    }

    for (int i = 0; i < num_files; i++) {
        strcpy(files[i].file_name, file_names + i * MAX_FILE_NAME_LENGTH);
        open_file(&files[i], files[i].file_name);
    }

    bool end_of_file = false;
    while (!end_of_file) {
        for (int i = 0; i < num_files; i++) {
            if (!read_line(&files[i], files[i].line)) {
                close_file(&files[i]);
                end_of_file = true;
                break;
            }
        }

        for (int i = 0; i < num_files - 1; i++) {
            if (strcmp(files[i].line, files[i + 1].line)!= 0) {
                printf("Files are not synchronized!\n");
                close_file(&files[i]);
                close_file(&files[i + 1]);
                end_of_file = true;
                break;
            }
        }
    }

    printf("Files are synchronized!\n");

    return 0;
}