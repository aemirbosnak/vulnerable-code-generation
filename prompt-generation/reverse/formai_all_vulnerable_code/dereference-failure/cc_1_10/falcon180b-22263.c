//Falcon-180B DATASET v1.0 Category: File handling ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_FILE_NAME 100
#define MAX_LINE_NUM 1000

typedef struct {
    char file_name[MAX_FILE_NAME];
    char *lines[MAX_LINE_NUM];
    int line_count;
} File;

char *read_line(FILE *file) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    if ((read = getline(&line, &len, file)) == -1) {
        perror("Error reading line");
        exit(1);
    }

    if (line[strlen(line) - 1] == '\n') {
        line[strlen(line) - 1] = '\0';
    }

    return line;
}

void write_file(const char *file_name, File *file) {
    FILE *fp = fopen(file_name, "w");

    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    for (int i = 0; i < file->line_count; i++) {
        fprintf(fp, "%s", file->lines[i]);
    }

    fclose(fp);
}

int main() {
    File file = {0};

    printf("Enter file name: ");
    scanf("%s", file.file_name);

    FILE *fp = fopen(file.file_name, "r");

    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    char *line = NULL;
    int line_num = 0;

    while ((line = read_line(fp))!= NULL) {
        if (file.line_count == MAX_LINE_NUM) {
            printf("Error: Maximum number of lines reached\n");
            exit(1);
        }

        file.lines[file.line_count++] = line;
        line_num++;
    }

    fclose(fp);

    printf("Enter new file name: ");
    scanf("%s", file.file_name);

    write_file(file.file_name, &file);

    printf("File saved successfully!\n");

    return 0;
}