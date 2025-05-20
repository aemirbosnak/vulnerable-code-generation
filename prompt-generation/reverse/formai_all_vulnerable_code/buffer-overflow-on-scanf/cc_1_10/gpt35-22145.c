//FormAI DATASET v1.0 Category: File Backup System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILENAME_LENGTH 50

/* Function declaration */
void create_backup(char* file_name);
void display_backup_files();
void delete_backup(char* file_name);
void select_backup(char* file_name);

int main() {
    int choice;
    char file_name[MAX_FILENAME_LENGTH];

    while(1) {
        printf("\n**********C FILE BACKUP SYSTEM**********\n\n");
        printf("1. Create backup\n");
        printf("2. Display backup files\n");
        printf("3. Delete backup\n");
        printf("4. Select backup\n");
        printf("5. Exit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter file name to backup: ");
                scanf("%s", file_name);
                create_backup(file_name);
                break;

            case 2:
                display_backup_files();
                break;

            case 3:
                printf("Enter backup file name to delete: ");
                scanf("%s", file_name);
                delete_backup(file_name);
                break;

            case 4:
                printf("Enter backup file name to select: ");
                scanf("%s", file_name);
                select_backup(file_name);
                break;

            case 5:
                printf("\nThank you for using the C File Backup System.\n");
                exit(0);

            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}

/* Function to create backup of a file */
void create_backup(char* file_name) {
    FILE *fptr1, *fptr2;
    char backup_file_name[MAX_FILENAME_LENGTH];
    time_t current_time;
    struct tm *time_info;
    char time_string[20];

    /* Get current time */
    time(&current_time);
    time_info = localtime(&current_time);
    strftime(time_string, 20, "_%Y-%m-%d_%H-%M-%S", time_info);

    /* Create backup file name */
    strcpy(backup_file_name, file_name);
    strcat(backup_file_name, time_string);

    /* Open original file */
    fptr1 = fopen(file_name, "r");
    if(fptr1 == NULL) {
        printf("Unable to open file. Please check if the file name is correct and the file exists in the specified directory.\n");
        return;
    }

    /* Open backup file */
    fptr2 = fopen(backup_file_name, "w");
    if(fptr2 == NULL) {
        printf("Unable to create backup file. Please check if you have write permission in the specified directory.\n");
        return;
    }

    /* Copy file data to backup file */
    char ch;
    while((ch = fgetc(fptr1)) != EOF) {
        fputc(ch, fptr2);
    }

    printf("File backup created successfully. Backup file name: %s\n", backup_file_name);

    fclose(fptr1);
    fclose(fptr2);
}

/* Function to display list of backup files */
void display_backup_files() {
    system("ls *_*-*-*_*-*-* > backup_files.txt");
    printf("\nList of backup files:\n\n");

    FILE *fptr = fopen("backup_files.txt", "r");
    if(fptr == NULL) {
        printf("Unable to find backup files. No backup files exist in the specified directory.\n");
        return;
    }

    char file_name[MAX_FILENAME_LENGTH];
    while(fscanf(fptr, "%s", file_name) != EOF) {
        printf("%s\n", file_name);
    }

    fclose(fptr);
    system("rm backup_files.txt");
}

/* Function to delete a backup file */
void delete_backup(char* file_name) {
    char command[MAX_FILENAME_LENGTH + 10];
    sprintf(command, "rm %s", file_name);

    if(system(command) == 0) {
        printf("\nBackup file deleted successfully.\n");
    } else {
        printf("\nUnable to delete backup file. Please check if the file name exists in the specified directory.\n");
    }
}

/* Function to select and open a backup file */
void select_backup(char* file_name) {
    FILE *fptr = fopen(file_name, "r");
    if(fptr == NULL) {
        printf("Unable to open file. Please check if the file name is correct and the file exists in the specified directory.\n");
        return;
    }

    printf("Backup file opened successfully. You can now view and edit the file.\n");

    fclose(fptr);
}