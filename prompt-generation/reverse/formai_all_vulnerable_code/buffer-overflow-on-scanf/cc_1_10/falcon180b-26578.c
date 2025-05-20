//Falcon-180B DATASET v1.0 Category: File handling ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_FILE_NAME_LENGTH 50
#define MAX_NUM_LINES 1000

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    FILE* file_ptr;
    char* lines[MAX_NUM_LINES];
    int num_lines;
} File;

int open_file(File* file) {
    char mode[10];
    printf("Enter the mode (r/w/a): ");
    scanf("%s", mode);

    if (strcmp(mode, "r") == 0) {
        file->file_ptr = fopen(file->file_name, "r");
    } else if (strcmp(mode, "w") == 0) {
        file->file_ptr = fopen(file->file_name, "w");
    } else if (strcmp(mode, "a") == 0) {
        file->file_ptr = fopen(file->file_name, "a");
    } else {
        printf("Invalid mode\n");
        exit(1);
    }

    if (file->file_ptr == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    return 0;
}

int close_file(File* file) {
    fclose(file->file_ptr);
    return 0;
}

int read_file(File* file) {
    char line[MAX_LINE_SIZE];
    int i = 0;

    while (fgets(line, MAX_LINE_SIZE, file->file_ptr)!= NULL) {
        file->lines[i] = strdup(line);
        i++;

        if (i >= MAX_NUM_LINES) {
            printf("Maximum number of lines reached\n");
            break;
        }
    }

    file->num_lines = i;
    return 0;
}

int write_file(File* file) {
    printf("Enter the line to write: ");
    scanf("%s", file->lines[file->num_lines]);

    fprintf(file->file_ptr, "%s", file->lines[file->num_lines]);
    file->num_lines++;

    return 0;
}

int append_file(File* file) {
    printf("Enter the line to append: ");
    scanf("%s", file->lines[file->num_lines]);

    fprintf(file->file_ptr, "%s", file->lines[file->num_lines]);
    file->num_lines++;

    return 0;
}

int main() {
    File file;
    int choice;

    printf("Enter the file name: ");
    scanf("%s", file.file_name);

    open_file(&file);

    while (1) {
        printf("\n1. Read file\n2. Write file\n3. Append file\n4. Close file\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                read_file(&file);
                break;
            case 2:
                write_file(&file);
                break;
            case 3:
                append_file(&file);
                break;
            case 4:
                close_file(&file);
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}