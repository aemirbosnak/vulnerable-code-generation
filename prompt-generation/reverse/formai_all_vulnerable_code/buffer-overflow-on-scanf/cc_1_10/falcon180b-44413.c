//Falcon-180B DATASET v1.0 Category: File handling ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 256
#define MAX_FILE_NAME_SIZE 256
#define MAX_NUM_LINES 10000

typedef struct {
    char file_name[MAX_FILE_NAME_SIZE];
    FILE *fp;
    char *lines[MAX_NUM_LINES];
    int num_lines;
} File;

int read_file(File *file) {
    char line[MAX_LINE_SIZE];
    int i = 0;

    while (fgets(line, MAX_LINE_SIZE, file->fp)!= NULL) {
        file->lines[i] = strdup(line);
        i++;
    }

    file->num_lines = i;

    return i;
}

int write_file(File *file) {
    int i;

    for (i = 0; i < file->num_lines; i++) {
        fprintf(file->fp, "%s", file->lines[i]);
    }

    return i;
}

int main() {
    File my_file;

    printf("Enter the name of the file you want to read/write: ");
    scanf("%s", my_file.file_name);

    my_file.fp = fopen(my_file.file_name, "r");

    if (my_file.fp == NULL) {
        printf("File not found.\n");
        exit(1);
    }

    read_file(&my_file);

    printf("Enter the text you want to write to the file:\n");
    scanf("%s", my_file.lines[my_file.num_lines]);

    my_file.num_lines++;

    write_file(&my_file);

    printf("File successfully written.\n");

    fclose(my_file.fp);

    return 0;
}