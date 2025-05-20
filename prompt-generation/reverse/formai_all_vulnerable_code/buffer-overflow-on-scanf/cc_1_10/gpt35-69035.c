//FormAI DATASET v1.0 Category: File Backup System ; Style: complex
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_FILE 20

typedef struct {
    char name[50];
    char content[100];
} file_t;

typedef struct {
    file_t files[MAX_FILE];
    int count;
} backup_t;

void save_files(backup_t* backup) {
    FILE* fp = fopen("backup.dat", "wb");
    fwrite(&backup->count, sizeof(int), 1, fp);
    for (int i = 0; i < backup->count; i++) {
        fwrite(&backup->files[i], sizeof(file_t), 1, fp);
    }
    fclose(fp);
}

void load_files(backup_t* backup) {
    FILE* fp = fopen("backup.dat", "rb");
    fread(&backup->count, sizeof(int), 1, fp);
    for (int i = 0; i < backup->count; i++) {
        fread(&backup->files[i], sizeof(file_t), 1, fp);
    }
    fclose(fp);
}

void display_files(backup_t* backup) {
    printf("==== BACKUP FILES ====\n");
    for (int i = 0; i < backup->count; i++) {
        printf("%d. %s\n", i+1, backup->files[i].name);
    }
}

void add_file(backup_t* backup, char* name, char* content) {
    if (backup->count >= MAX_FILE) {
        printf("Backup is full!\n");
        return;
    }
    int index = backup->count++;
    strcpy(backup->files[index].name, name);
    strcpy(backup->files[index].content, content);
    printf("%s added to the backup!\n", name);
}

void extract_file(backup_t* backup, int index) {
    if (index < 1 || index > backup->count) {
        printf("Invalid index!\n");
        return;
    }
    int i = index - 1;
    char filename[100];
    strcpy(filename, backup->files[i].name);
    strcat(filename, ".txt");
    FILE* fp = fopen(filename, "w");
    fprintf(fp, "%s", backup->files[i].content);
    fclose(fp);
    printf("%s extracted from the backup!\n", backup->files[i].name);
}

int main() {
    backup_t backup;
    backup.count = 0;

    // load backup from file
    load_files(&backup);

    // menu loop
    int choice;
    char name[50], content[100];
    do {
        printf("\n==== BACKUP SYSTEM ====\n");
        printf("1. Add file to backup\n");
        printf("2. Extract file from backup\n");
        printf("3. Display backup files\n");
        printf("4. Save and exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter file name: ");
                scanf("%s", name);
                printf("Enter file content: ");
                scanf(" %[^\n]", content);
                add_file(&backup, name, content);
                break;
            case 2:
                printf("Enter file index: ");
                scanf("%d", &choice);
                extract_file(&backup, choice);
                break;
            case 3:
                display_files(&backup);
                break;
            case 4:
                save_files(&backup);
                printf("Backup saved!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}