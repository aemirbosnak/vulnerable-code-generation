//FormAI DATASET v1.0 Category: File system simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_FILENAME 20
#define MAX_FILESIZE 1024

typedef struct file {
    char *filename;
    char *content;
    int size;
    int blocks;
} file_t;

file_t file_system[MAX_FILES];
int used_blocks = 0;

void create_file(char *filename) {
    if (used_blocks == MAX_FILES) {
        printf("Error: File system is full\n");
        return;
    }

    file_t new_file;
    new_file.filename = malloc(MAX_FILENAME * sizeof(char));
    new_file.content = malloc(MAX_FILESIZE * sizeof(char));

    strcpy(new_file.filename, filename);
    new_file.size = 0;
    new_file.blocks = 0;
    file_system[used_blocks] = new_file;
    used_blocks++;

    printf("File \"%s\" created successfully\n", filename);
}

void delete_file(char *filename) {
    for (int i=0; i<MAX_FILES; i++) {
        if (file_system[i].filename != NULL && strcmp(file_system[i].filename, filename) == 0) {
            free(file_system[i].filename);
            free(file_system[i].content);
            file_system[i].filename = NULL;
            file_system[i].content = NULL;
            used_blocks--;
            printf("File \"%s\" deleted successfully\n", filename);
            return;
        }
    }

    printf("Error: File \"%s\" not found\n", filename);
}

void read_file(char *filename) {
    for (int i=0; i<MAX_FILES; i++) {
        if (file_system[i].filename != NULL && strcmp(file_system[i].filename, filename) == 0) {
            printf("=== %s ===\n", filename);
            printf("%s", file_system[i].content);
            printf("=== End of file ===\n");
            return;
        }
    }

    printf("Error: File \"%s\" not found\n", filename);
}

void write_file(char *filename, char *content) {
    for (int i=0; i<MAX_FILES; i++) {
        if (file_system[i].filename != NULL && strcmp(file_system[i].filename, filename) == 0) {
            int new_size = strlen(content);
            int new_blocks = new_size / MAX_FILESIZE + 1;

            if (used_blocks + new_blocks - file_system[i].blocks > MAX_FILES) {
                printf("Error: File system is full\n");
                return;
            }

            used_blocks += new_blocks - file_system[i].blocks;
            file_system[i].size = new_size;
            file_system[i].blocks = new_blocks;
            strcpy(file_system[i].content, content);

            printf("File \"%s\" written successfully\n", filename);
            return;
        }
    }

    printf("Error: File \"%s\" not found\n", filename);
}

void list_files() {
    printf("List of files:\n");

    for (int i=0; i<MAX_FILES; i++) {
        if (file_system[i].filename != NULL) {
            printf("%s (%d bytes, %d blocks)\n", file_system[i].filename, file_system[i].size, file_system[i].blocks);
        }
    }
}

int main() {
    int choice;
    char filename[MAX_FILENAME];
    char content[MAX_FILESIZE];

    while (1) {
        printf("\nFile system simulation\n");
        printf("1. Create file\n");
        printf("2. Delete file\n");
        printf("3. Read file\n");
        printf("4. Write to file\n");
        printf("5. List files\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter file name: ");
                scanf("%s", filename);
                create_file(filename);
                break;
            case 2:
                printf("Enter file name: ");
                scanf("%s", filename);
                delete_file(filename);
                break;
            case 3:
                printf("Enter file name: ");
                scanf("%s", filename);
                read_file(filename);
                break;
            case 4:
                printf("Enter file name: ");
                scanf("%s", filename);
                printf("Enter file content: ");
                getchar(); // Clear input buffer
                fgets(content, sizeof(content), stdin);
                write_file(filename, content);
                break;
            case 5:
                list_files();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}