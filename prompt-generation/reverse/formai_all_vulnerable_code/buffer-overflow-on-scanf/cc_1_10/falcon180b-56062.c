//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_FILE_CONTENTS_LENGTH 1000

typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    char file_contents[MAX_FILE_CONTENTS_LENGTH];
    int file_size;
} File;

void create_file(File* file, char* filename) {
    strcpy(file->filename, filename);
    file->file_size = 0;
    file->file_contents[0] = '\0';
}

void write_to_file(File* file, char* data) {
    int new_file_size = file->file_size + strlen(data);
    if (new_file_size > MAX_FILE_CONTENTS_LENGTH) {
        printf("Error: File is full.\n");
        return;
    }

    strcat(file->file_contents, data);
    file->file_size = new_file_size;
}

void read_from_file(File* file) {
    printf("File contents: %s\n", file->file_contents);
}

int main() {
    File my_file;
    char filename[MAX_FILENAME_LENGTH];

    printf("Enter a filename: ");
    scanf("%s", filename);

    create_file(&my_file, filename);

    char choice;
    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Write to file\n");
        printf("2. Read from file\n");
        printf("3. Exit\n");
        scanf("%c", &choice);

        switch (choice) {
            case '1': {
                char data[MAX_FILE_CONTENTS_LENGTH];
                printf("Enter data to write: ");
                scanf("%s", data);
                write_to_file(&my_file, data);
                break;
            }
            case '2': {
                read_from_file(&my_file);
                break;
            }
            case '3': {
                exit(0);
            }
            default: {
                printf("Invalid option.\n");
            }
        }
    }

    return 0;
}