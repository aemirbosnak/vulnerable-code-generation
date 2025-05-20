//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void get_timestamp(char *timestamp_buffer) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(timestamp_buffer, 20, "%Y%m%d_%H%M%S", t);
}

void backup_file(const char *source_file) {
    char backup_file[256];
    char timestamp[20];
    
    get_timestamp(timestamp);
    snprintf(backup_file, sizeof(backup_file), "%s_backup_%s", source_file, timestamp);
    
    FILE *src = fopen(source_file, "rb");
    if (!src) {
        perror("Error opening source file");
        return;
    }

    FILE *dest = fopen(backup_file, "wb");
    if (!dest) {
        perror("Error creating backup file");
        fclose(src);
        return;
    }

    char buffer[BUFFER_SIZE];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, src)) > 0) {
        fwrite(buffer, 1, bytes_read, dest);
    }

    printf("🎉 Backup successful! File '%s' has been backed up as '%s'\n", source_file, backup_file);

    fclose(src);
    fclose(dest);
}

void list_backups(const char *source_file) {
    char command[256];
    snprintf(command, sizeof(command), "ls -1 | grep '%s_backup_'", source_file);
    
    printf("📦 Listing backups for '%s':\n", source_file);
    system(command);
}

void display_menu() {
    printf("\n🎈 Welcome to the Happy File Backup System! 🎈\n");
    printf("1. Backup a file\n");
    printf("2. List backups\n");
    printf("3. Exit\n");
    printf("Please enter your choice: ");
}

int main() {
    while (1) {
        display_menu();

        int choice;
        scanf("%d", &choice);
        
        if (choice == 1) {
            char source_file[256];
            printf("Enter the name of the file to backup: ");
            scanf("%s", source_file);
            backup_file(source_file);
        } else if (choice == 2) {
            char source_file[256];
            printf("Enter the name of the file to list backups: ");
            scanf("%s", source_file);
            list_backups(source_file);
        } else if (choice == 3) {
            printf("🌟 Thank you for using Happy File Backup System! Goodbye! 🌟\n");
            break;
        } else {
            printf("🚫 Invalid choice, please try again.\n");
        }
    }
    
    return 0;
}