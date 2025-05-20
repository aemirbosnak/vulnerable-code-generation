//FormAI DATASET v1.0 Category: File system simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_FILE_COUNT 100 // maximum files that can be created
#define MAX_FILE_NAME_LENGTH 20 // maximum length of file name
#define MAX_FILE_CONTENT_LENGTH 100 // maximum length of file content
#define BLOCK_SIZE 4 // block size of file system

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    char content[MAX_FILE_CONTENT_LENGTH];
    int size; // size of file in blocks
    int blocks[10]; // array to store block numbers of the file
} file;

int file_count = 0; // count of files in file system
int available_blocks = MAX_FILE_COUNT * BLOCK_SIZE; // number of available blocks
file files[MAX_FILE_COUNT]; // array to store file data
int file_system[BLOCK_SIZE * MAX_FILE_COUNT]; // file system as an array of blocks

void create_file(char* name, char* content);
void delete_file(char* name);
void write_file(char* name, char* content);
void read_file(char* name);

int main()
{
    printf("Welcome to File System Simulation\n");

    while (true) {
        int choice;
        printf("\nMenu:\n");
        printf("1. Create file\n");
        printf("2. Delete file\n");
        printf("3. Write to file\n");
        printf("4. Read from file\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char name[MAX_FILE_NAME_LENGTH];
                printf("\nEnter file name: ");
                scanf("%s", name);
                char content[MAX_FILE_CONTENT_LENGTH];
                printf("Enter file content: ");
                scanf("%s", content);
                create_file(name, content);
                break;
            }

            case 2: {
                char name[MAX_FILE_NAME_LENGTH];
                printf("\nEnter file name: ");
                scanf("%s", name);
                delete_file(name);
                break;
            }

            case 3: {
                char name[MAX_FILE_NAME_LENGTH];
                printf("\nEnter file name: ");
                scanf("%s", name);
                char content[MAX_FILE_CONTENT_LENGTH];
                printf("Enter file content: ");
                scanf("%s", content);
                write_file(name, content);
                break;
            }

            case 4: {
                char name[MAX_FILE_NAME_LENGTH];
                printf("\nEnter file name: ");
                scanf("%s", name);
                read_file(name);
                break;
            }

            case 5: {
                printf("\nExiting...\n");
                return 0;
            }

            default: {
                printf("\nInvalid choice. Please try again.\n");
                break;
            }
        }
    }

    return 0;
}

void create_file(char* name, char* content)
{
    if (file_count == MAX_FILE_COUNT) {
        printf("\nFile limit reached. Cannot create file.\n");
        return;
    }

    for (int i = 0; i < file_count; i++) {
        if (strcmp(files[i].name, name) == 0) {
            printf("\nFile with this name already exists. Cannot create file.\n");
            return;
        }
    }

    if (available_blocks < BLOCK_SIZE) {
        printf("\nNot enough space in file system. Cannot create file.\n");
        return;
    }

    file new_file;
    strcpy(new_file.name, name);
    strcpy(new_file.content, content);
    int content_length = strlen(content);
    new_file.size = (content_length / BLOCK_SIZE) + ((content_length % BLOCK_SIZE) != 0); // calculate file size in blocks

    int blocks_taken = 0;
    for (int i = 0; i < MAX_FILE_COUNT * BLOCK_SIZE; i++) {
        if (file_system[i] == 0) {
            new_file.blocks[blocks_taken++] = i;
            file_system[i] = 1;
            available_blocks--;
        }

        if (blocks_taken == new_file.size) {
            break;
        }
    }

    files[file_count++] = new_file;

    printf("\nFile created successfully.\n");
}

void delete_file(char* name)
{
    for (int i = 0; i < file_count; i++) {
        if (strcmp(files[i].name, name) == 0) {
            for (int j = 0; j < files[i].size; j++) {
                file_system[files[i].blocks[j]] = 0;
                available_blocks++;
            }

            for (int j = i; j < file_count; j++) {
                files[j] = files[j + 1];
            }

            file_count--;

            printf("\nFile deleted successfully.\n");
            return;
        }
    }

    printf("\nFile not found. Cannot delete file.\n");
}

void write_file(char* name, char* content)
{
    for (int i = 0; i < file_count; i++) {
        if (strcmp(files[i].name, name) == 0) {
            int content_length = strlen(content);
            int old_size = files[i].size;
            files[i].size = (content_length / BLOCK_SIZE) + ((content_length % BLOCK_SIZE) != 0); // calculate new file size in blocks

            if (files[i].size > old_size && files[i].size * BLOCK_SIZE > available_blocks) {
                printf("\nNot enough space in file system. Cannot write to file.\n");
                files[i].size = old_size;
                return;
            }

            int blocks_taken = 0;
            for (int j = 0; j < MAX_FILE_COUNT * BLOCK_SIZE; j++) {
                if (file_system[j] == 0) {
                    files[i].blocks[blocks_taken++] = j;
                    file_system[j] = 1;
                    available_blocks--;
                }

                if (blocks_taken == files[i].size) {
                    break;
                }

                if (j == MAX_FILE_COUNT * BLOCK_SIZE - 1) {
                    printf("\nNot enough space in file system. Cannot write to file.\n");
                    files[i].size = old_size;
                    for (int k = old_size; k < files[i].size; k++) {
                        file_system[files[i].blocks[k]] = 0;
                        available_blocks++;
                    }
                    return;
                }
            }

            strcpy(files[i].content, content);

            printf("\nFile written successfully.\n");
            return;
        }
    }

    printf("\nFile not found. Cannot write to file.\n");
}

void read_file(char* name)
{
    for (int i = 0; i < file_count; i++) {
        if (strcmp(files[i].name, name) == 0) {
            printf("\nFile content: %s\n", files[i].content);
            return;
        }
    }

    printf("\nFile not found. Cannot read file.\n");
}