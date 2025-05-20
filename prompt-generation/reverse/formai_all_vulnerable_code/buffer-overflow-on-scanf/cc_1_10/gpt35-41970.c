//FormAI DATASET v1.0 Category: File system simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LEN 20
#define MAX_FILE_SIZE 1024

typedef struct file {
    char filename[MAX_FILE_NAME_LEN];
    int size;
    char data[MAX_FILE_SIZE];
    struct file *next;
} file_t;

file_t *head = NULL;
int num_files = 0;

int add_file(char *filename, int size, char *data) {
    if(num_files == 0) {
        head = (file_t*)malloc(sizeof(file_t));
        if(head == NULL) {
            printf("Error: Unable to allocate memory\n");
            return -1;
        }
        strcpy(head->filename, filename);
        head->size = size;
        memcpy(head->data, data, size);
        head->next = NULL;
    } else {
        file_t *current = head;
        while(current->next != NULL) {
            current = current->next;
        }
        current->next = (file_t*)malloc(sizeof(file_t));
        if(current->next == NULL) {
            printf("Error: Unable to allocate memory\n");
            return -1;
        }
        strcpy(current->next->filename, filename);
        current->next->size = size;
        memcpy(current->next->data, data, size);
        current->next->next = NULL;
    }
    num_files++;
    return 0;
}

int delete_file(char *filename) {
    if(num_files == 0) {
        printf("Error: No files exist in the file system\n");
        return -1;
    } else if(strcmp(head->filename, filename) == 0) {
        file_t *temp = head;
        head = head->next;
        free(temp);
    } else {
        file_t *current = head;
        while(current->next != NULL && strcmp(current->next->filename, filename) != 0) {
            current = current->next;
        }
        if(current->next == NULL) {
            printf("Error: File does not exist in the file system\n");
            return -1;
        } else {
            file_t *temp = current->next;
            current->next = current->next->next;
            free(temp);
        }
    }
    num_files--;
    return 0;
}

void print_files() {
    printf("Number of files: %d\n", num_files);
    if(num_files == 0) {
        printf("No files exist in the file system\n");
    } else {
        file_t *current = head;
        while(current != NULL) {
            printf("Filename: %s, Size: %d bytes\n", current->filename, current->size);
            printf("Data: %s\n", current->data);
            printf("\n");
            current = current->next;
        }
    }
}

int main() {
    char filename[MAX_FILE_NAME_LEN];
    int size;
    char data[MAX_FILE_SIZE];
    int choice;

    while(1) {
        printf("1. Add File\n");
        printf("2. Delete File\n");
        printf("3. View Files\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter filename: ");
                scanf("%s", filename);
                printf("Enter file size (in bytes): ");
                scanf("%d", &size);
                printf("Enter file data: ");
                scanf("%s", data);
                if(add_file(filename, size, data) == -1) {
                    printf("Unable to add file to file system\n");
                } else {
                    printf("File added to file system\n");
                }
                break;
            case 2:
                printf("Enter filename: ");
                scanf("%s", filename);
                if(delete_file(filename) == -1) {
                    printf("Unable to delete file from file system\n");
                } else {
                    printf("File deleted from file system\n");
                }
                break;
            case 3:
                print_files();
                break;
            case 4:
                printf("Exiting File System Simulation...\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
        }
    }
}