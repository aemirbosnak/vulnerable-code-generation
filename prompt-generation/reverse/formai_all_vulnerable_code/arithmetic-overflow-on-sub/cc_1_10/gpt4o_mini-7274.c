//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_FILES 100
#define BUFFER_SIZE 1024

typedef struct {
    char source_file[256];
    char backup_file[256];
    time_t timestamp;
} FileBackup;

FileBackup backups[MAX_FILES];
int backup_count = 0;

void create_backup(const char *source) {
    if (backup_count >= MAX_FILES) {
        printf("Backup limit reached. Cannot create more backups.\n");
        return;
    }

    struct stat buffer;
    if (stat(source, &buffer) == -1) {
        perror("Error accessing source file");
        return;
    }

    FILE *source_fp = fopen(source, "rb");
    if (!source_fp) {
        perror("Error opening source file");
        return;
    }

    char backup_name[256];
    snprintf(backup_name, sizeof(backup_name), "%s.bak", source);
    FILE *backup_fp = fopen(backup_name, "wb");
    if (!backup_fp) {
        perror("Error creating backup file");
        fclose(source_fp);
        return;
    }

    char data[BUFFER_SIZE];
    size_t bytes;
    while ((bytes = fread(data, 1, BUFFER_SIZE, source_fp)) > 0) {
        fwrite(data, 1, bytes, backup_fp);
    }

    fclose(source_fp);
    fclose(backup_fp);

    strcpy(backups[backup_count].source_file, source);
    strcpy(backups[backup_count].backup_file, backup_name);
    backups[backup_count].timestamp = time(NULL);
    backup_count++;

    printf("Backup created: %s --> %s\n", source, backup_name);
}

void list_backups() {
    if (backup_count == 0) {
        printf("No backups available.\n");
        return;
    }

    printf("List of Backups:\n");
    for (int i = 0; i < backup_count; i++) {
        printf(" %d. Source: %s | Backup: %s | Time: %s",
               i + 1,
               backups[i].source_file,
               backups[i].backup_file,
               ctime(&backups[i].timestamp));
    }
}

void restore_backup(int index) {
    if (index < 0 || index >= backup_count) {
        printf("Invalid backup index.\n");
        return;
    }

    FILE *backup_fp = fopen(backups[index].backup_file, "rb");
    if (!backup_fp) {
        perror("Error opening backup file");
        return;
    }

    FILE *restore_fp = fopen(backups[index].source_file, "wb");
    if (!restore_fp) {
        perror("Error restoring to source file");
        fclose(backup_fp);
        return;
    }

    char data[BUFFER_SIZE];
    size_t bytes;
    while ((bytes = fread(data, 1, BUFFER_SIZE, backup_fp)) > 0) {
        fwrite(data, 1, bytes, restore_fp);
    }

    fclose(backup_fp);
    fclose(restore_fp);

    printf("Restored from backup: %s to %s\n",
           backups[index].backup_file, backups[index].source_file);
}

void delete_backup(int index) {
    if (index < 0 || index >= backup_count) {
        printf("Invalid backup index.\n");
        return;
    }
    
    if (remove(backups[index].backup_file) == 0) {
        printf("Backup deleted: %s\n", backups[index].backup_file);
        
        for (int i = index; i < backup_count - 1; i++) {
            backups[i] = backups[i + 1];
        }
        
        backup_count--;
    } else {
        perror("Error deleting backup file");
    }
}

int main() {
    int option;
    char filename[256];

    while (1) {
        printf("\nFile Backup System\n");
        printf("1. Create Backup\n");
        printf("2. List Backups\n");
        printf("3. Restore Backup\n");
        printf("4. Delete Backup\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);
        getchar();  // consume newline

        switch (option) {
            case 1:
                printf("Enter the file to backup: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0;  // remove newline
                create_backup(filename);
                break;
            case 2:
                list_backups();
                break;
            case 3:
                printf("Enter backup index to restore: ");
                scanf("%d", &option);
                restore_backup(option - 1);
                break;
            case 4:
                printf("Enter backup index to delete: ");
                scanf("%d", &option);
                delete_backup(option - 1);
                break;
            case 5:
                printf("Exiting system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}