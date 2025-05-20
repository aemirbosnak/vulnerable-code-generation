//Falcon-180B DATASET v1.0 Category: File handling ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1000

typedef struct {
    char filename[MAX_LINE_SIZE];
    FILE *file;
    char line[MAX_LINE_SIZE];
} File;

void open_file(File *file, const char *filename) {
    strcpy(file->filename, filename);
    file->file = fopen(filename, "r");
    if (file->file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
}

void close_file(File *file) {
    fclose(file->file);
}

int read_line(File *file) {
    char c;
    int i = 0;
    while ((c = fgetc(file->file))!= EOF) {
        if (c == '\n') {
            file->line[i] = '\0';
            return i;
        }
        file->line[i++] = c;
    }
    file->line[i] = '\0';
    return i;
}

int main() {
    File file;
    char command[MAX_LINE_SIZE];
    int line_number = 0;

    printf("Enter filename: ");
    scanf("%s", file.filename);

    open_file(&file, file.filename);

    while (1) {
        printf("Enter command (type 'q' to quit): ");
        scanf("%s", command);

        if (strcmp(command, "q") == 0) {
            break;
        }

        line_number = 0;
        while ((line_number = read_line(&file)) > 0) {
            printf("%d: %s\n", line_number, file.line);
        }
    }

    close_file(&file);

    return 0;
}