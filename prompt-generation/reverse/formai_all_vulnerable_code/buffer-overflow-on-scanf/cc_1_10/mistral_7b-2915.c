//MISTRAL-7B DATASET v1.0 Category: File system simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_FILES 100
#define MAX_FILE_NAME 50
#define MAX_CHARS_PER_FILE 1024

typedef struct File {
    char name[MAX_FILE_NAME];
    char content[MAX_CHARS_PER_FILE];
    struct File *next;
} File;

File *head = NULL;

void create_file(char *name) {
    File *new_file = (File *)malloc(sizeof(File));
    strcpy(new_file->name, name);
    new_file->next = head;
    head = new_file;
}

void write_to_file(char *name, char *data) {
    File *current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            strcpy(current->content, data);
            printf("Data written to file %s successfully!\n", name);
            return;
        }
        current = current->next;
    }
    printf("File not found. Please create it first using 'create_file' function.\n");
}

void read_from_file(char *name) {
    File *current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("Content of file %s:\n", name);
            printf("%s\n", current->content);
            return;
        }
        current = current->next;
    }
    printf("File not found.\n");
}

void delete_file(char *name) {
    File *current = head, *prev = NULL;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("File %s deleted successfully!\n", name);
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("File not found.\n");
}

int main() {
    int choice, i;
    char name[MAX_FILE_NAME], data[MAX_CHARS_PER_FILE];

    printf("Welcome to Simple File System Simulator!\n");

    while (1) {
        printf("\n1. Create File\n2. Write to File\n3. Read from File\n4. Delete File\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter file name: ");
                scanf("%s", name);
                create_file(name);
                break;
            case 2:
                printf("Enter file name: ");
                scanf("%s", name);
                printf("Enter data to write: ");
                scanf("%s", data);
                write_to_file(name, data);
                break;
            case 3:
                printf("Enter file name: ");
                scanf("%s", name);
                read_from_file(name);
                break;
            case 4:
                printf("Enter file name: ");
                scanf("%s", name);
                delete_file(name);
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}