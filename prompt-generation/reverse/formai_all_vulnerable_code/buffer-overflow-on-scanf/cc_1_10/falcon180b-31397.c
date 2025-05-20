//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_LINE_LENGTH 1024

typedef struct {
    char* filename;
    char* backup_filename;
    int backup_count;
} FileBackup;

void create_backup_filename(char* filename, char* backup_filename) {
    int length = strlen(filename);
    int i = length - 1;
    while (i >= 0 && filename[i]!= '.') {
        backup_filename[i] = filename[i];
        i--;
    }
    backup_filename[i+1] = '\0';
    strcat(backup_filename, ".bak");
}

int backup_file(char* filename, char* backup_filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return 1;
    }
    FILE* backup_file = fopen(backup_filename, "w");
    if (backup_file == NULL) {
        printf("Error: Could not create backup file %s\n", backup_filename);
        fclose(file);
        return 1;
    }
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        fputs(line, backup_file);
    }
    fclose(file);
    fclose(backup_file);
    printf("Backup created: %s\n", backup_filename);
    return 0;
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <filename> <backup_filename>\n", argv[0]);
        return 1;
    }
    char* filename = argv[1];
    char* backup_filename = argv[2];
    create_backup_filename(filename, backup_filename);
    int backup_count = 0;
    while (1) {
        int choice;
        printf("\nChoose an option:\n");
        printf("1. Backup file\n");
        printf("2. View backup history\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                backup_file(filename, backup_filename);
                backup_count++;
                break;
            case 2:
                printf("\nBackup history:\n");
                printf("-----------------\n");
                printf("Backup count: %d\n", backup_count);
                break;
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}