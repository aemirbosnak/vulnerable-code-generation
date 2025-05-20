//Falcon-180B DATASET v1.0 Category: File handling ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_FILE_NAME_LENGTH 256

typedef struct {
    char *filename;
    FILE *file;
    int line_number;
    char line[MAX_LINE_LENGTH];
} file_t;

int open_file(file_t *file, const char *filename) {
    file->filename = (char *)malloc(MAX_FILE_NAME_LENGTH);
    strcpy(file->filename, filename);
    file->file = fopen(filename, "r");

    if (file->file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    file->line_number = 0;
    return 0;
}

int read_line(file_t *file) {
    if (fgets(file->line, MAX_LINE_LENGTH, file->file) == NULL) {
        printf("Error reading line from file %s\n", file->filename);
        exit(1);
    }

    file->line_number++;
    return 0;
}

int print_line(file_t *file) {
    printf("%s:%d: %s", file->filename, file->line_number, file->line);
    return 0;
}

int main() {
    file_t file;
    int choice;

    do {
        printf("Enter the filename: ");
        scanf("%s", file.filename);
        open_file(&file, file.filename);

        do {
            printf("Enter your choice:\n1. Read line\n2. Print line\n3. Exit\n");
            scanf("%d", &choice);

            switch(choice) {
                case 1:
                    read_line(&file);
                    break;
                case 2:
                    print_line(&file);
                    break;
                case 3:
                    exit(0);
                default:
                    printf("Invalid choice!\n");
            }
        } while(choice!= 3);

    } while(1);

    return 0;
}