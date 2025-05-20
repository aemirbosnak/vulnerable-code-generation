//Falcon-180B DATASET v1.0 Category: File handling ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_FILE_NAME_LENGTH 100
#define MAX_NUM_LINES 1000

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    char *lines[MAX_NUM_LINES];
    int num_lines;
} File;

void read_file(File *file) {
    FILE *fptr;
    char line[MAX_LINE_LENGTH];
    int i = 0;

    fptr = fopen(file->file_name, "r");

    if (fptr == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, fptr)!= NULL) {
        file->lines[i] = malloc(strlen(line) + 1);
        strcpy(file->lines[i], line);
        i++;
    }

    file->num_lines = i;

    fclose(fptr);
}

void print_file(File *file) {
    int i;

    for (i = 0; i < file->num_lines; i++) {
        printf("%s", file->lines[i]);
    }
}

void write_file(File *file) {
    FILE *fptr;
    int i;

    fptr = fopen(file->file_name, "w");

    if (fptr == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    for (i = 0; i < file->num_lines; i++) {
        fprintf(fptr, "%s", file->lines[i]);
    }

    fclose(fptr);
}

int main() {
    File file;

    printf("Enter file name: ");
    scanf("%s", file.file_name);

    read_file(&file);
    print_file(&file);

    printf("Do you want to write the file? (y/n): ");
    char choice;
    scanf("%c", &choice);

    if (choice == 'y' || choice == 'Y') {
        write_file(&file);
        printf("File written successfully.\n");
    }

    return 0;
}