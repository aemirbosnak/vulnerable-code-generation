//FormAI DATASET v1.0 Category: File Backup System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct file {
    char name[50];
    char date[20];
    unsigned int size;
    struct file *next;
} File;

File *head = NULL;

void add_file() {
    File *new_file = (File*) malloc(sizeof(File));
    printf("Enter file name: ");
    scanf("%s", new_file->name);
    printf("Enter file size: ");
    scanf("%d", &new_file->size);
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    sprintf(new_file->date, "%d-%02d-%02d %02d:%02d:%02d",
            tm->tm_year+1900, tm->tm_mon+1, tm->tm_mday,
            tm->tm_hour, tm->tm_min, tm->tm_sec);
    new_file->next = NULL;
    if (head == NULL) {
        head = new_file;
    } else {
        File *curr = head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = new_file;
    }
    printf("File added successfully!\n");
}

void view_files() {
    if (head == NULL) {
        printf("No files found.\n");
    } else {
        printf("Total number of files: %d\n", get_file_count());
        printf("----------------------------------------\n");
        printf("| %-30s | %-10s | %-20s |\n", "Name", "Size", "Date");
        printf("----------------------------------------\n");
        File *curr = head;
        while (curr != NULL) {
            printf("| %-30s | %-10u | %-20s |\n", curr->name, curr->size, curr->date);
            curr = curr->next;
        }
        printf("----------------------------------------\n");
    }
}

void delete_file() {
    if (head == NULL) {
        printf("No files found.\n");
    } else {
        printf("Enter file name to delete: ");
        char name[50];
        scanf("%s", name);
        File *curr = head;
        if (strcmp(curr->name, name) == 0) {
            head = curr->next;
            free(curr);
            printf("File deleted successfully!\n");
            return;
        }
        while (curr->next != NULL) {
            if (strcmp(curr->next->name, name) == 0) {
                File *temp = curr->next;
                curr->next = temp->next;
                free(temp);
                printf("File deleted successfully!\n");
                return;
            }
            curr = curr->next;
        }
        printf("File not found.\n");
    }
}

int get_file_count() {
    int count = 0;
    File *curr = head;
    while (curr != NULL) {
        count++;
        curr = curr->next;
    }
    return count;
}

void write_to_file() {
    FILE *fp = fopen("backup.txt", "w");
    if (fp == NULL) {
        printf("Failed to create file!\n");
        return;
    }
    File *curr = head;
    while (curr != NULL) {
        fprintf(fp, "%s %d %s\n", curr->name, curr->size, curr->date);
        curr = curr->next;
    }
    fclose(fp);
    printf("Data saved successfully to backup.txt!\n");
}

void read_from_file() {
    FILE *fp = fopen("backup.txt", "r");
    if (fp == NULL) {
        printf("No existing backup found.\n");
        return;
    }
    char name[50], date[20];
    unsigned int size;
    while (fscanf(fp, "%s %u %s", name, &size, date) != EOF) {
        File *new_file = (File*) malloc(sizeof(File));
        strcpy(new_file->name, name);
        new_file->size = size;
        strcpy(new_file->date, date);
        new_file->next = NULL;
        if (head == NULL) {
            head = new_file;
        } else {
            File *curr = head;
            while (curr->next != NULL) {
                curr = curr->next;
            }
            curr->next = new_file;
        }
    }
    fclose(fp);
    printf("Data loaded successfully from backup.txt!\n");
}

void clear_data() {
    File *curr = head;
    while (curr != NULL) {
        File *temp = curr;
        curr = curr->next;
        free(temp);
    }
    head = NULL;
    printf("All data cleared!\n");
}

int main() {
    int choice;
    do {
        printf("1. Add file\n");
        printf("2. View files\n");
        printf("3. Delete file\n");
        printf("4. Backup to file\n");
        printf("5. Load from backup\n");
        printf("6. Clear data\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("----------------------------------------\n");
        switch (choice) {
            case 1:
                add_file();
                break;
            case 2:
                view_files();
                break;
            case 3:
                delete_file();
                break;
            case 4:
                write_to_file();
                break;
            case 5:
                clear_data();
                read_from_file();
                break;
            case 6:
                clear_data();
                break;
            case 0:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
        printf("----------------------------------------\n");
    } while (choice != 0);

    return 0;
}