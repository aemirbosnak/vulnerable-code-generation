//FormAI DATASET v1.0 Category: File system simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_COUNT 10
#define MAX_FILE_SIZE 1024

struct file {
    char* filename;
    char* content;
    int size;
};

struct file_system {
    struct file* files[MAX_FILE_COUNT];
    int file_count;
};

struct file* create_file(char* filename, char* content, int size) {
    struct file* new_file = (struct file*) malloc(sizeof(struct file));
    new_file->filename = filename;
    new_file->content = content;
    new_file->size = size;
    return new_file;
}

void destroy_file(struct file* f) {
    if (f) {
        free(f->filename);
        free(f->content);
        free(f);
    }
}

void add_file_to_system(struct file_system* fs, struct file* f) {
    if (fs->file_count < MAX_FILE_COUNT) {
        fs->files[fs->file_count++] = f;
    }
}

void list_files(struct file_system* fs) {
    for (int i = 0; i < fs->file_count; ++i) {
        printf("%s (%d bytes)\n", fs->files[i]->filename, fs->files[i]->size);
    }
}

void print_file(struct file* f) {
    printf("%s:\n%s\n", f->filename, f->content);
}

void run_file_system_simulation() {
    struct file_system fs;
    fs.file_count = 0;

    char input[128];
    while (1) {
        printf("> ");
        scanf("%s", input);
        if (strcmp(input, "quit") == 0) {
            break;
        } else if (strcmp(input, "ls") == 0) {
            list_files(&fs);
        } else if (strcmp(input, "cat") == 0) {
            scanf("%s", input);
            int found = 0;
            for (int i = 0; i < fs.file_count; ++i) {
                if (strcmp(input, fs.files[i]->filename) == 0) {
                    found = 1;
                    print_file(fs.files[i]);
                    break;
                }
            }
            if (!found) {
                printf("File not found\n");
            }
        } else if (strcmp(input, "create") == 0) {
            char filename[128];
            scanf("%s", filename);
            char content[MAX_FILE_SIZE];
            scanf(" %[^\n]s", content);
            struct file* new_file = create_file(strdup(filename), strdup(content), strlen(content));
            add_file_to_system(&fs, new_file);
        } else {
            printf("Unknown command\n");
        }
    }

    for (int i = 0; i < fs.file_count; ++i) {
        destroy_file(fs.files[i]);
    }
}

int main() {
    printf("Welcome to the file system simulation\n");
    printf("Type 'quit' to exit the program\n");
    run_file_system_simulation();
    printf("Exiting program\n");
    return 0;
}