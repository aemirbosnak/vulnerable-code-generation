//Falcon-180B DATASET v1.0 Category: File handling ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char *filename;
    FILE *fp;
    int linenumber;
} file_t;

void create_file(file_t *file, char *filename) {
    file->filename = filename;
    file->fp = fopen(filename, "w");
    if (file->fp == NULL) {
        printf("Error creating file: %s\n", filename);
        exit(1);
    }
    file->linenumber = 1;
}

void write_line(file_t *file, char *line) {
    fprintf(file->fp, "%d: %s\n", file->linenumber, line);
    file->linenumber++;
}

void read_file(file_t *file) {
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file->fp)!= NULL) {
        printf("%s", line);
    }
}

void append_line(file_t *file, char *line) {
    fprintf(file->fp, "%s", line);
    file->linenumber++;
}

void delete_file(file_t *file) {
    fclose(file->fp);
    remove(file->filename);
}

int main() {
    file_t file;
    char filename[100];
    int choice;

    printf("Enter filename: ");
    scanf("%s", filename);

    create_file(&file, filename);

    do {
        printf("\n1. Write a line\n2. Read file\n3. Append a line\n4. Delete file\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter line to write: ");
                scanf("%s", file.filename);
                write_line(&file, file.filename);
                break;
            case 2:
                read_file(&file);
                break;
            case 3:
                printf("Enter line to append: ");
                scanf("%s", file.filename);
                append_line(&file, file.filename);
                break;
            case 4:
                delete_file(&file);
                break;
            default:
                printf("Invalid choice\n");
        }

    } while(1);

    return 0;
}