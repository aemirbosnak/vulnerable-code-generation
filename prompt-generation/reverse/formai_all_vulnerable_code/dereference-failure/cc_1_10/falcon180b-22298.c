//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_LINE_LENGTH 1000

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    int file_size;
    int num_lines;
    char *lines[MAX_LINE_LENGTH];
} File;

File *read_file(char *file_name) {
    FILE *fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Error: could not open file '%s'\n", file_name);
        exit(1);
    }

    File *file = (File *) malloc(sizeof(File));
    strcpy(file->file_name, file_name);

    char c;
    int line_num = 0;
    int file_size = 0;
    while ((c = fgetc(fp))!= EOF) {
        if (c == '\n') {
            line_num++;
        }
        file_size++;
    }

    file->file_size = file_size;
    file->num_lines = line_num;

    rewind(fp);
    while ((c = fgetc(fp))!= EOF) {
        if (c == '\n') {
            line_num++;
        }

        char *line = (char *) malloc(MAX_LINE_LENGTH);
        memset(line, 0, MAX_LINE_LENGTH);
        while (c!= '\n' && (file_size - file->num_lines) < MAX_LINE_LENGTH - 1) {
            strcat(line, &c);
            file_size++;
            c = fgetc(fp);
        }
        strcat(line, "\n");
        file->lines[line_num - 1] = line;
    }

    fclose(fp);
    return file;
}

void write_file(File *file) {
    FILE *fp = fopen(file->file_name, "w");
    if (fp == NULL) {
        printf("Error: could not open file '%s'\n", file->file_name);
        exit(1);
    }

    for (int i = 0; i < file->num_lines; i++) {
        fprintf(fp, "%s", file->lines[i]);
    }

    fclose(fp);
}

int main() {
    char file_name[MAX_FILE_NAME_LENGTH];
    printf("Enter file name: ");
    scanf("%s", file_name);

    File *file = read_file(file_name);
    write_file(file);

    printf("File backup completed.\n");

    return 0;
}