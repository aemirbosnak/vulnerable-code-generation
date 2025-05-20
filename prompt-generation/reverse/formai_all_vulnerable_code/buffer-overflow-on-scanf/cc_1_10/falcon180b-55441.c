//Falcon-180B DATASET v1.0 Category: File handling ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 80
#define MAX_FILE_NAME_LENGTH 20

typedef struct {
    char *name;
    FILE *fp;
    int line_number;
} File;

void open_file(File *file, char *filename) {
    file->fp = fopen(filename, "r");
    if (file->fp == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }
    file->name = strdup(filename);
    file->line_number = 0;
}

void close_file(File *file) {
    if (file->fp!= NULL) {
        fclose(file->fp);
    }
    free(file->name);
}

int read_line(File *file, char *buffer) {
    char c;
    int i = 0;
    while ((c = fgetc(file->fp))!= EOF) {
        if (i >= MAX_LINE_LENGTH) {
            printf("Error: line too long\n");
            exit(1);
        }
        if (c == '\n') {
            buffer[i] = '\0';
            file->line_number++;
            return i;
        }
        buffer[i++] = c;
    }
    if (i == 0) {
        file->line_number++;
    }
    return i;
}

int main() {
    int choice;
    char filename[MAX_FILE_NAME_LENGTH];
    char buffer[MAX_LINE_LENGTH];
    File file;

    do {
        printf("1. Open file\n");
        printf("2. Read line\n");
        printf("3. Close file\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter filename: ");
            scanf("%s", filename);
            open_file(&file, filename);
            break;
        case 2:
            read_line(&file, buffer);
            printf("Line: %s\n", buffer);
            break;
        case 3:
            close_file(&file);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    } while (1);

    return 0;
}