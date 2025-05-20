//Falcon-180B DATASET v1.0 Category: File handling ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char *filename;
    FILE *fp;
} File;

int create_file(const char *filename) {
    File *file = malloc(sizeof(File));

    if (file == NULL) {
        printf("Failed to allocate memory for file.\n");
        return 1;
    }

    file->filename = strdup(filename);
    file->fp = fopen(filename, "w");

    if (file->fp == NULL) {
        printf("Failed to create file '%s'.\n", filename);
        free(file->filename);
        free(file);
        return 1;
    }

    return 0;
}

int read_line(char *buffer, int max_length, FILE *fp) {
    char c;
    int length = 0;

    while ((c = fgetc(fp))!= EOF && length < max_length - 1) {
        buffer[length++] = c;
        if (c == '\n') {
            break;
        }
    }

    buffer[length] = '\0';
    return length;
}

int write_line(const char *buffer, FILE *fp) {
    return fputs(buffer, fp);
}

int append_line(const char *buffer, FILE *fp) {
    return fputs(buffer, fp);
}

int close_file(File *file) {
    if (fclose(file->fp)!= 0) {
        printf("Failed to close file '%s'.\n", file->filename);
        free(file->filename);
        free(file);
        return 1;
    }

    free(file->filename);
    free(file);
    return 0;
}

int main() {
    File file;
    char buffer[MAX_LINE_LENGTH];
    int choice;

    printf("Enter the filename: ");
    scanf("%s", buffer);

    if (create_file(buffer)) {
        return 1;
    }

    do {
        printf("\n1. Append line\n2. Read file\n3. Close file\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the line to append: ");
                scanf("%[^\n]", buffer);
                append_line(buffer, file.fp);
                break;
            case 2:
                rewind(file.fp);
                while (fgets(buffer, MAX_LINE_LENGTH, file.fp)!= NULL) {
                    printf("%s", buffer);
                }
                break;
            case 3:
                close_file(&file);
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 3);

    return 0;
}