//FormAI DATASET v1.0 Category: File Backup System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILENAME_LEN 50
#define MAX_BACKUP_NUM 10
#define MAX_LINE_LEN 100

void print_menu();
void do_backup(char* filename, char* backup_dir);
void list_backups(char* backup_dir);
int get_backup_num(char* backup_dir);

int main()
{
    char filename[MAX_FILENAME_LEN];
    char backup_dir[MAX_FILENAME_LEN];
    int choice;
    
    srand(time(0)); // Initialize random seed
    
    printf("Enter the filename to backup:\n");
    fgets(filename, MAX_FILENAME_LEN, stdin);
    filename[strcspn(filename, "\n")] = 0; // Remove newline character from input
    printf("Enter the directory to store backups:\n");
    fgets(backup_dir, MAX_FILENAME_LEN, stdin);
    backup_dir[strcspn(backup_dir, "\n")] = 0; // Remove newline character from input
    printf("\n");
    
    // Loop until user chooses to exit
    while (1) {
        print_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                do_backup(filename, backup_dir);
                break;
            case 2:
                list_backups(backup_dir);
                break;
            case 3:
                printf("Exiting program.\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }
    
    return 0;
}

void print_menu() {
    printf("Select an option:\n");
    printf("1. Backup file\n");
    printf("2. List backups\n");
    printf("3. Exit program\n");
    printf("Enter choice: ");
}

void do_backup(char* filename, char* backup_dir) {
    FILE* file;
    char backup_filename[MAX_FILENAME_LEN];
    char backup_path[MAX_FILENAME_LEN];
    char line[MAX_LINE_LEN];
    int backup_num = get_backup_num(backup_dir);
    
    // Open input file
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open input file.\n");
        return;
    }
    
    // Construct backup filename
    sprintf(backup_filename, "%s.bak%d", filename, backup_num);
    
    // Construct backup path
    sprintf(backup_path, "%s/%s", backup_dir, backup_filename);
    
    // Create and open output file
    FILE* backup_file = fopen(backup_path, "w");
    if (backup_file == NULL) {
        printf("Error: could not create backup file.\n");
        fclose(file);
        return;
    }
    
    // Copy contents of input file to output file
    while (fgets(line, MAX_LINE_LEN, file) != NULL) {
        fputs(line, backup_file);
    }
    
    // Close files
    fclose(file);
    fclose(backup_file);
    
    printf("Backup created successfully: %s\n", backup_filename);
}

void list_backups(char* backup_dir) {
    int i;
    char filename[MAX_FILENAME_LEN];
    FILE* backup_file;
    printf("Listing backups in directory: %s\n", backup_dir);
    printf("====================================\n");
    for (i = 0; i < MAX_BACKUP_NUM; i++) {
        sprintf(filename, "%s.bak%d", "example.txt", i);
        backup_file = fopen(filename, "r");
        if (backup_file != NULL) {
            printf("%s\n", filename);
            fclose(backup_file);
        }
    }
    printf("====================================\n");
}

int get_backup_num(char* backup_dir) {
    int i;
    char filename[MAX_FILENAME_LEN];
    FILE* backup_file;
    for (i = 0; i < MAX_BACKUP_NUM; i++) {
        sprintf(filename, "%s/%s.bak%d", backup_dir, "example.txt", i);
        backup_file = fopen(filename, "r");
        if (backup_file == NULL) {
            return i;
        }
        fclose(backup_file);
    }
    return -1; // Error: exceeded maximum number of backups
}