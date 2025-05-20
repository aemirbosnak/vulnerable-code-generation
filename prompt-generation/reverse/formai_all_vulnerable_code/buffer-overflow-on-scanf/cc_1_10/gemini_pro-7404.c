//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILES 100
#define MAX_FILE_SIZE 1024

typedef struct {
    char name[32];
    char contents[MAX_FILE_SIZE];
    size_t size;
} file_t;

file_t files[MAX_FILES];
int num_files = 0;

void add_file(char *name, char *contents, size_t size) {
    if (num_files >= MAX_FILES) {
        fprintf(stderr, "Error: Too many files.\n");
        return;
    }

    strcpy(files[num_files].name, name);
    strcpy(files[num_files].contents, contents);
    files[num_files].size = size;

    num_files++;
}

void save_files(char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        fprintf(stderr, "Error: Could not open file %s.\n", filename);
        return;
    }

    for (int i = 0; i < num_files; i++) {
        fwrite(&files[i], sizeof(file_t), 1, fp);
    }

    fclose(fp);
}

void load_files(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: Could not open file %s.\n", filename);
        return;
    }

    while (!feof(fp)) {
        file_t file;
        fread(&file, sizeof(file_t), 1, fp);

        add_file(file.name, file.contents, file.size);
    }

    fclose(fp);
}

void list_files() {
    for (int i = 0; i < num_files; i++) {
        printf("%s\n", files[i].name);
    }
}

void print_file(char *name) {
    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            printf("%s", files[i].contents);
            return;
        }
    }

    fprintf(stderr, "Error: File not found.\n");
}

int main() {
    char command[32];
    char filename[32];
    char name[32];
    char contents[MAX_FILE_SIZE];
    size_t size;

    while (1) {
        printf("> ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            scanf("%s %s", name, contents);
            size = strlen(contents);
            add_file(name, contents, size);
        } else if (strcmp(command, "save") == 0) {
            scanf("%s", filename);
            save_files(filename);
        } else if (strcmp(command, "load") == 0) {
            scanf("%s", filename);
            load_files(filename);
        } else if (strcmp(command, "list") == 0) {
            list_files();
        } else if (strcmp(command, "print") == 0) {
            scanf("%s", name);
            print_file(name);
        } else if (strcmp(command, "quit") == 0) {
            break;
        }
    }

    return 0;
}