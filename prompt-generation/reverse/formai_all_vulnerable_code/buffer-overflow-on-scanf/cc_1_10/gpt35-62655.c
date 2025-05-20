//FormAI DATASET v1.0 Category: File system simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_FILENAME 10
#define MAX_SIZE 1024

typedef struct {
    char name[MAX_FILENAME];
    int size;
    char *data;
} File;

typedef struct {
    File files[MAX_FILES];
    int num_files;
} FileSystem;

void create_file(FileSystem *fs, char *filename, int size) {
    if (fs->num_files >= MAX_FILES) {
        printf("Maximum number of files exceeded.\n");
        return;
    }
    for (int i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i].name, filename) == 0) {
            printf("File with that name already exists.\n");
            return;
        }
    }
    File file = { .name = "", .size = 0, .data = NULL };
    strncpy(file.name, filename, MAX_FILENAME);
    file.size = size;
    file.data = (char *) malloc(size * sizeof(char));
    for (int i = 0; i < size; i++) {
        file.data[i] = '\0';
    }
    fs->files[fs->num_files] = file;
    fs->num_files++;
    printf("File created successfully.\n");
}

void delete_file(FileSystem *fs, char *filename) {
    for (int i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i].name, filename) == 0) {
            free(fs->files[i].data);
            for (int j = i; j < fs->num_files - 1; j++) {
                fs->files[j] = fs->files[j + 1];
            }
            fs->num_files--;
            printf("File deleted successfully.\n");
            return;
        }
    }
    printf("File not found.\n");
}

void read_file(FileSystem *fs, char *filename) {
    for (int i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i].name, filename) == 0) {
            printf("Contents of file '%s':\n", filename);
            printf("%s", fs->files[i].data);
            return;
        }
    }
    printf("File not found.\n");
}

void write_file(FileSystem *fs, char *filename, char *data) {
    for (int i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i].name, filename) == 0) {
            int data_len = strlen(data);
            if (data_len > fs->files[i].size) {
                printf("Data too large to fit in file.\n");
                return;
            }
            strncpy(fs->files[i].data, data, data_len);
            printf("Data written to file successfully.\n");
            return;
        }
    }
    printf("File not found.\n");
}

int main() {
    FileSystem fs = { .files = {}, .num_files = 0 };
    char cmd[10];
    char filename[MAX_FILENAME];
    int size;
    char data[MAX_SIZE];
    while (1) {
        printf("> ");
        scanf("%s", cmd);
        if (strcmp(cmd, "create") == 0) {
            scanf("%s %d", filename, &size);
            create_file(&fs, filename, size);
        } else if (strcmp(cmd, "delete") == 0) {
            scanf("%s", filename);
            delete_file(&fs, filename);
        } else if (strcmp(cmd, "read") == 0) {
            scanf("%s", filename);
            read_file(&fs, filename);
        } else if (strcmp(cmd, "write") == 0) {
            scanf("%s %s", filename, data);
            write_file(&fs, filename, data);
        } else if (strcmp(cmd, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }
    return 0;
}