//FormAI DATASET v1.0 Category: File Backup System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct backup_file {
    char name[50];
    size_t size;
    char content[5000];
};

/* Function to create a backup of a file */
void backup_file(char *file_name) {
    FILE *fp, *fp_backup;
    char backup_name[60];

    /* Open the file in read mode */
    fp = fopen(file_name, "r");
    if(fp == NULL) {
        printf("Error opening file\n");
        return;
    }

    /* Create backup file name */
    strcpy(backup_name, file_name);
    strcat(backup_name, ".bak");

    /* Open the backup file in write mode */
    fp_backup = fopen(backup_name, "w");
    if(fp_backup == NULL) {
        fclose(fp);
        printf("Error creating backup file\n");
        return;
    }

    /* Read the contents of the original file */
    char c;
    size_t size = 0;
    char content[5000] = "";
    while((c = fgetc(fp)) != EOF) {
        size++;
        strncat(content, &c, 1);
    }

    /* Write the contents to the backup file */
    fwrite(content, 1, size, fp_backup);

    /* Close the files */
    fclose(fp);
    fclose(fp_backup);

    /* Create backup_file struct */
    struct backup_file bf;
    strcpy(bf.name, file_name);
    bf.size = size;
    strcpy(bf.content, content);

    printf("\nBackup created successfully!\n");

    /* Print the details of the backup */
    printf("\nDetails of the backup:\n");
    printf("File name: %s\n", bf.name);
    printf("File size: %lu bytes\n", bf.size);
    printf("File content: %s\n", bf.content);
}

/* Function to restore a backup of a file */
void restore_backup(char *file_name) {
    FILE *fp, *fp_backup;
    char backup_name[60];

    /* Create backup file name */
    strcpy(backup_name, file_name);
    strcat(backup_name, ".bak");

    /* Open the backup file in read mode */
    fp_backup = fopen(backup_name, "r");
    if(fp_backup == NULL) {
        printf("Error opening backup file\n");
        return;
    }

    /* Open the original file in write mode */
    fp = fopen(file_name, "w");
    if(fp == NULL) {
        fclose(fp_backup);
        printf("Error opening file to restore backup\n");
        return;
    }

    /* Read the contents of the backup file */
    char c;
    size_t size = 0;
    char content[5000] = "";
    while((c = fgetc(fp_backup)) != EOF) {
        size++;
        strncat(content, &c, 1);
    }

    /* Write the contents to the original file */
    fwrite(content, 1, size, fp);

    /* Close the files */
    fclose(fp);
    fclose(fp_backup);

    printf("\nBackup restored successfully!\n");
}

int main() {
    char file_name[50];
    int choice;

    printf("Welcome to C File Backup System!\n");

    while(1) {
        printf("\nChoose an option:\n");
        printf("1. Backup a file\n");
        printf("2. Restore a backup\n");
        printf("3. Exit\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the name of the file to backup: ");
                scanf("%s", file_name);
                backup_file(file_name);
                break;

            case 2:
                printf("Enter the name of the file to restore: ");
                scanf("%s", file_name);
                restore_backup(file_name);
                break;

            case 3:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}