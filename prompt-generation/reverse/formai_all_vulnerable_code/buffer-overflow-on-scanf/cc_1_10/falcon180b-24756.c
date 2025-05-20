//Falcon-180B DATASET v1.0 Category: File handling ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FILENAME_LENGTH 256

typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    FILE *file;
    int line_number;
} File;

void read_file(File *file) {
    char line[MAX_LINE_LENGTH];
    char *token;
    int i = 0;

    while (fgets(line, MAX_LINE_LENGTH, file->file)!= NULL) {
        i++;
        printf("%d: %s", i, line);
        token = strtok(line, " ");
        while (token!= NULL) {
            printf(" %s", token);
            token = strtok(NULL, " ");
        }
        printf("\n");
    }
}

int main() {
    File file;
    char filename[MAX_FILENAME_LENGTH];

    printf("Enter filename: ");
    scanf("%s", filename);

    strcpy(file.filename, filename);
    file.file = fopen(filename, "r");

    if (file.file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    read_file(&file);

    fclose(file.file);

    return 0;
}