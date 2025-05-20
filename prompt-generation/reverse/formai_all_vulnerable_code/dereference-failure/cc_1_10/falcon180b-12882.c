//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SYSTEM_SIZE 10000
#define MAX_FILE_NAME_LENGTH 50
#define MAX_FILE_CONTENT_LENGTH 1000

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    char file_content[MAX_FILE_CONTENT_LENGTH];
    int file_size;
} File;

File* file_system = NULL;
int num_files = 0;

void init_file_system() {
    file_system = (File*)malloc(MAX_FILE_SYSTEM_SIZE * sizeof(File));
    num_files = 0;
}

void add_file(char* file_name, char* file_content) {
    if (num_files >= MAX_FILE_SYSTEM_SIZE) {
        printf("File system full.\n");
        return;
    }

    File* new_file = &file_system[num_files];
    strcpy(new_file->file_name, file_name);
    strcpy(new_file->file_content, file_content);
    new_file->file_size = strlen(file_content);

    num_files++;
}

void remove_file(char* file_name) {
    for (int i = 0; i < num_files; i++) {
        if (strcmp(file_system[i].file_name, file_name) == 0) {
            free(file_system[i].file_content);
            strcpy(file_system[i].file_name, "");
            file_system[i].file_size = 0;
            break;
        }
    }
}

void print_file_system() {
    printf("File name\t\tFile content\tFile size\n");
    for (int i = 0; i < num_files; i++) {
        printf("%s\t\t%s\t\t%d\n", file_system[i].file_name, file_system[i].file_content, file_system[i].file_size);
    }
}

int main() {
    init_file_system();

    add_file("test.txt", "This is a test file.");
    print_file_system();

    remove_file("test.txt");
    print_file_system();

    add_file("test2.txt", "This is another test file.");
    print_file_system();

    return 0;
}