//FormAI DATASET v1.0 Category: File Backup System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_BACKUPS 10
#define MAX_LENGTH 100

typedef struct Backup {
    char filename[MAX_LENGTH];
    char content[MAX_LENGTH];
    bool is_saved;
} Backup;

 Backup backups[MAX_BACKUPS];
 int num_backups = 0;

void print_menu() {
    printf("Welcome to the C File Backup System\n"
           "1. Create backup\n"
           "2. Load backup\n"
           "3. Display backups\n"
           "4. Exit\n");
}

void create_backup() {
    if (num_backups >= MAX_BACKUPS) {
        printf("Error: Maximum number of backups reached\n");
        return;
    }

    Backup new_backup;
    printf("Enter filename: ");
    scanf("%s", new_backup.filename);
    printf("Enter file content: ");
    scanf("%s", new_backup.content);
    new_backup.is_saved = true;

    backups[num_backups] = new_backup;
    num_backups++;

    printf("Backup created successfully\n");
}

void load_backup() {
    printf("Enter filename to load: ");
    char filename[MAX_LENGTH];
    scanf("%s", filename);

    for (int i = 0; i < num_backups; i++) {
        Backup backup = backups[i];
        if (strcmp(backup.filename, filename) == 0) {
            if (backup.is_saved) {
                printf("Backup already loaded\n");
            } else {
                printf("Loading backup...\n");
                printf("File content: %s\n", backup.content);
                backup.is_saved = true;
                backups[i] = backup;
            }
            return;
        }
    }

    printf("Backup not found\n");
}

void display_backups() {
    printf("List of backups:\n");
    for (int i = 0; i < num_backups; i++) {
        printf("Backup %d: %s\n", i+1, backups[i].filename);
    }
}

int main() {
    int choice = 0;
    while (choice != 4) {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_backup();
                break;
            case 2:
                load_backup();
                break;
            case 3:
                display_backups();
                break;
            case 4:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice. Please try again\n");
                break;
        }

        printf("\n");
    }

    return 0;
}