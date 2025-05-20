//FormAI DATASET v1.0 Category: File system simulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct file {
    char name[20];
    int size;
    struct file *next;
};

typedef struct file File;

int add_file(File **root, char *name, int size) {
    File *temp, *current;
    temp = (File*)malloc(sizeof(File));
    strcpy(temp->name, name);
    temp->size = size;
    temp->next = NULL;
    if (*root == NULL) {
        *root = temp;
    } else {
        current = *root;
        while(current->next != NULL) {
            current = current->next;
        }
        current->next = temp;
    }
    return 1;
}

int delete_file(File **root, char *name) {
    File *current, *previous;
    if (*root == NULL) {
        return 0;
    }
    current = *root;
    previous = current;
    if(strcmp(current->name, name) == 0) {
        *root = current->next;
        free(current);
        return 1;
    }
    while(current != NULL && strcmp(current->name, name) != 0) {
        previous = current;
        current = current->next;
    }
    if (current == NULL) {
        return 0;
    }
    previous->next = current->next;
    free(current);
    return 1;
}

int main() {
    int choice, size, result;
    char name[20];
    File *root = NULL;
    do {
        printf("\nWelcome to the Surreal File System Simulation\n");
        printf("1. Add File\n");
        printf("2. Delete File\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter the file name: ");
                scanf("%s", name);
                printf("Enter the file size: ");
                scanf("%d", &size);
                result = add_file(&root, name, size);
                if(result == 1) {
                    printf("File added successfully\n");
                } else {
                    printf("Unable to add file\n");
                }
                break;

            case 2:
                printf("Enter the file name: ");
                scanf("%s", name);
                result = delete_file(&root, name);
                if(result == 1) {
                    printf("File deleted successfully\n");
                } else {
                    printf("File not found\n");
                }
                break;

            case 3:
                printf("Goodbye, see you in the matrix..\n");
                break;

            default:
                printf("Invalid choice, please try again\n");
                break;
        }
    } while(choice != 3);
    return 0;
}