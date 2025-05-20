//FormAI DATASET v1.0 Category: File Backup System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME 20
#define MAX_FILE_SIZE 100

typedef struct file {
    char filename[MAX_FILENAME];
    char content[MAX_FILE_SIZE];
    int size;
    struct file *next;
} File;

void print_menu() {
    printf("\nMenu:\n");
    printf("1. Add a file\n");
    printf("2. Delete a file\n");
    printf("3. Backup files\n");
    printf("4. Exit\n");
}

void add_file(File **head) {
    char filename[MAX_FILENAME];
    char content[MAX_FILE_SIZE];
    int size;

    printf("Enter filename (max 20 characters): ");
    scanf("%s", filename);
    printf("Enter file content (max 100 characters): ");
    scanf("%s", content);
    size = strlen(content);

    File *new_file = (File *) malloc(sizeof(File));
    if (!new_file) {
        printf("Error: Out of memory.\n");
        return;
    }
    strcpy(new_file->filename, filename);
    strcpy(new_file->content, content);
    new_file->size = size;
    new_file->next = *head;

    *head = new_file;
}

void delete_file(File **head, char filename[]) {
    File *prev = NULL;
    File *current = *head;

    while (current != NULL) {
        if (strcmp(current->filename, filename) == 0) {
            if (prev == NULL) {
                *head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("Error: File not found.\n");
}

void backup_files(File *head) {
    if (head == NULL) {
        printf("Error: No files to backup.\n");
        return;
    }

    printf("Backing up files...\n");
    while (head != NULL) {
        FILE *fp;
        char filename[MAX_FILENAME + 6];
        sprintf(filename, "%s.bak", head->filename);
        fp = fopen(filename, "w");
        if (!fp) {
            printf("Error: Cannot create backup file %s.\n", filename);
        } else {
            fprintf(fp, "%s", head->content);
            printf("Created backup file %s.\n", filename);
            fclose(fp);
        }
        head = head->next;
    }
}

int main() {
    File *head = NULL;
    int choice;
    char filename[MAX_FILENAME];

    do {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_file(&head);
                break;
            case 2:
                printf("Enter filename to delete: ");
                scanf("%s", filename);
                delete_file(&head, filename);
                break;
            case 3:
                backup_files(head);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Error: Invalid choice.\n");
        }
    } while (choice != 4);

    return 0;
}