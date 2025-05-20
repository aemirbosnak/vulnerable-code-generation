//Falcon-180B DATASET v1.0 Category: File handling ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char filename[MAX_LINE_LENGTH];
    FILE *file;
} File;

File *openFile(const char *filename) {
    File *file = (File *)malloc(sizeof(File));
    strcpy(file->filename, filename);
    file->file = fopen(filename, "r");
    if (file->file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }
    return file;
}

void closeFile(File *file) {
    if (file->file!= NULL) {
        fclose(file->file);
        file->file = NULL;
    }
}

int readLine(File *file, char *buffer) {
    int length = 0;
    char c;
    while ((c = fgetc(file->file))!= EOF && length < MAX_LINE_LENGTH) {
        buffer[length++] = c;
    }
    buffer[length] = '\0';
    return length;
}

void printLine(const char *buffer) {
    printf("%s", buffer);
}

int countLines(File *file) {
    int count = 0;
    char buffer[MAX_LINE_LENGTH];
    while (readLine(file, buffer) > 0) {
        count++;
    }
    return count;
}

int main() {
    File *file = openFile("example.txt");
    int lineCount = countLines(file);
    printf("File contains %d lines\n", lineCount);
    for (int i = 1; i <= lineCount; i++) {
        char buffer[MAX_LINE_LENGTH];
        sprintf(buffer, "Line %d: ", i);
        printf("%s", buffer);
        readLine(file, buffer);
        printLine(buffer);
    }
    closeFile(file);
    return 0;
}