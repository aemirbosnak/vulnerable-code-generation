//Falcon-180B DATASET v1.0 Category: File handling ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILE_NAME 100
#define MAX_LINE_SIZE 1000

typedef struct {
    char filename[MAX_FILE_NAME];
    FILE *file;
    int linenumber;
} File;

int openfile(File *file, char *filename) {
    file->filename[0] = '\0';
    strcat(file->filename, filename);
    file->file = fopen(file->filename, "r");
    if (file->file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }
    file->linenumber = 1;
    return 0;
}

int closefile(File *file) {
    fclose(file->file);
    file->file = NULL;
    return 0;
}

int readline(File *file, char *line) {
    char ch;
    int i = 0;
    while ((ch = fgetc(file->file))!= EOF && ch!= '\n') {
        if (i >= MAX_LINE_SIZE - 1) {
            printf("Error: Line too long\n");
            exit(1);
        }
        line[i++] = ch;
    }
    if (ch == '\n') {
        line[i++] = '\0';
        file->linenumber++;
    } else {
        line[i] = '\0';
    }
    return 0;
}

int writeline(File *file, char *line) {
    fprintf(file->file, "%d: %s", file->linenumber, line);
    return 0;
}

int main() {
    char filename[MAX_FILE_NAME];
    char line[MAX_LINE_SIZE];
    printf("Enter file name: ");
    scanf("%s", filename);
    File file;
    openfile(&file, filename);
    while (readline(&file, line) == 0) {
        writeline(&file, line);
    }
    closefile(&file);
    return 0;
}