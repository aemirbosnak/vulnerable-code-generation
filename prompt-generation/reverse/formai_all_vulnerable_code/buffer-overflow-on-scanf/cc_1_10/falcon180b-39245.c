//Falcon-180B DATASET v1.0 Category: File handling ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_FILE_NAME_LENGTH 50

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    FILE *fp;
    int line_count;
} file_t;

void open_file(file_t *f, char *filename) {
    strcpy(f->name, filename);
    f->fp = fopen(filename, "r");
    if (f->fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    f->line_count = 0;
}

int read_line(file_t *f, char *line) {
    char c;
    int i = 0;
    while ((c = fgetc(f->fp))!= EOF && i < MAX_LINE_LENGTH - 1) {
        line[i++] = c;
        if (c == '\n') {
            f->line_count++;
            break;
        }
    }
    line[i] = '\0';
    return i;
}

void close_file(file_t *f) {
    fclose(f->fp);
}

int main() {
    int choice, i, j;
    char filename[MAX_FILE_NAME_LENGTH];
    char line[MAX_LINE_LENGTH];
    file_t file;

    printf("Enter the name of the file to be read: ");
    scanf("%s", filename);

    open_file(&file, filename);

    while (1) {
        printf("\nEnter your choice:\n");
        printf("1. Read file line by line\n");
        printf("2. Print file content\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the line number to read: ");
                scanf("%d", &i);
                if (i < 1 || i > file.line_count) {
                    printf("Invalid line number\n");
                } else {
                    rewind(file.fp);
                    for (j = 0; j < i - 1; j++) {
                        read_line(&file, line);
                    }
                    read_line(&file, line);
                    printf("Line %d: %s\n", i, line);
                }
                break;
            case 2:
                rewind(file.fp);
                while (read_line(&file, line)!= 0) {
                    printf("%s", line);
                }
                break;
            case 3:
                close_file(&file);
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}