//Falcon-180B DATASET v1.0 Category: File handling ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char *filename;
    FILE *file;
} File;

int create_file(const char *filename) {
    File *new_file = malloc(sizeof(File));
    if (new_file == NULL) {
        printf("Error: Could not allocate memory for new file.\n");
        return 1;
    }
    new_file->filename = strdup(filename);
    new_file->file = fopen(filename, "w");
    if (new_file->file == NULL) {
        printf("Error: Could not open file '%s' for writing.\n", filename);
        free(new_file->filename);
        free(new_file);
        return 1;
    }
    return 0;
}

int append_line(File *file, const char *line) {
    char buffer[MAX_LINE_LENGTH];
    strncpy(buffer, line, MAX_LINE_LENGTH - 1);
    buffer[MAX_LINE_LENGTH - 1] = '\0';
    return fprintf(file->file, "%s\n", buffer) < 0;
}

int read_file(File *file) {
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file->file)!= NULL) {
        printf("%s", line);
    }
    return 0;
}

int main() {
    File *my_file = NULL;
    char filename[MAX_LINE_LENGTH];
    printf("Enter filename: ");
    scanf("%s", filename);
    int error = create_file(filename);
    if (error!= 0) {
        return error;
    }
    my_file = malloc(sizeof(File));
    if (my_file == NULL) {
        printf("Error: Could not allocate memory for file struct.\n");
        return 1;
    }
    my_file->filename = strdup(filename);
    my_file->file = fopen(filename, "a");
    if (my_file->file == NULL) {
        printf("Error: Could not open file '%s' for appending.\n", filename);
        free(my_file->filename);
        free(my_file);
        return 1;
    }
    char input[MAX_LINE_LENGTH];
    while (fgets(input, MAX_LINE_LENGTH, stdin)!= NULL) {
        if (append_line(my_file, input)) {
            printf("Error: Could not write line to file.\n");
            return 1;
        }
    }
    fclose(my_file->file);
    free(my_file->filename);
    free(my_file);
    printf("File saved successfully.\n");
    return 0;
}