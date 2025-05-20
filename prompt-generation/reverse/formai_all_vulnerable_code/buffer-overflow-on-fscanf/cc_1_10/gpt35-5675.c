//FormAI DATASET v1.0 Category: File Backup System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LEN 50  // maximum length of file name
#define MAX_FILES_NUM 100      // maximum number of files that can be stored in the backup system
#define BACKUP_FILE_NAME "backup.txt"  // backup file name

// Structure for storing each file in the system
struct backup_file{
    char filename[MAX_FILE_NAME_LEN];
    char data[1000];
};

// Function declarations
void print_menu();
int get_file_index(struct backup_file files[], char filename[]);
void backup_files(struct backup_file files[], int num_files);
void restore_files(struct backup_file files[], int num_files);

// Main function
int main(){
    struct backup_file files[MAX_FILES_NUM];  // array for storing backup files
    int num_files = 0;  // number of backup files currently stored in the system
    char user_input[10];  // user input for menu
    int exit_program = 0;  // flag for exiting program
    
    // Load backup data from file if it exists
    FILE *fptr = fopen(BACKUP_FILE_NAME, "r");
    if(fptr != NULL){
        while(!feof(fptr) && num_files < MAX_FILES_NUM){
            fscanf(fptr, "%s %[^\n]", files[num_files].filename, files[num_files].data);
            num_files++;
        }
        fclose(fptr);
        printf("Backup data loaded from file.\n");
    }
    
    // Main program loop
    while(!exit_program){
        print_menu();
        fgets(user_input, sizeof(user_input), stdin);
        user_input[strcspn(user_input, "\n")] = 0;  // remove newline character
        
        // Handle user choice
        switch(atoi(user_input)){
            case 1:
                backup_files(files, num_files);
                num_files++;
                break;
            case 2:
                restore_files(files, num_files);
                break;
            case 3:
                exit_program = 1;
                break;
            default:
                printf("Invalid input. Try again.\n");
                break;
        }
    }
    
    // Save backup data to file
    fptr = fopen(BACKUP_FILE_NAME, "w");
    for(int i=0; i<num_files; i++){
        fprintf(fptr, "%s\n%s\n", files[i].filename, files[i].data);
    }
    fclose(fptr);
    printf("Backup data saved to file.\n");
    printf("Exiting program...\n");
    return 0;
}

// Function to print the menu for the backup system
void print_menu(){
    printf("\nWelcome to the C File Backup System.\n");
    printf("===================================\n");
    printf("1. Backup a file\n");
    printf("2. Restore a file\n");
    printf("3. Exit program\n");
    printf("Enter your choice: ");
}

// Function to get the index of a file in the backup system
int get_file_index(struct backup_file files[], char filename[]){
    for(int i=0; i<MAX_FILES_NUM; i++){
        if(strcmp(files[i].filename, filename) == 0){
            return i;
        }
    }
    return -1;
}

// Function to backup files
void backup_files(struct backup_file files[], int num_files){
    char filename[MAX_FILE_NAME_LEN];
    FILE *fptr;
    printf("Enter the filename to backup: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = 0;  // remove newline character
    
    // Check if file already exists in backup system
    if(get_file_index(files, filename) != -1){
        printf("File already exists in backup system.\n");
        return;
    }
    
    // Open file for reading
    fptr = fopen(filename, "r");
    if(fptr == NULL){
        printf("Error: file not found.\n");
        return;
    }
    
    // Read data and store in backup system
    strcpy(files[num_files].filename, filename);
    fgets(files[num_files].data, sizeof(files[num_files].data), fptr);
    fclose(fptr);
    
    // Confirmation message
    printf("File backed up successfully.\n");
}

// Function to restore files
void restore_files(struct backup_file files[], int num_files){
    char filename[MAX_FILE_NAME_LEN];
    int file_index;
    FILE *fptr;
    printf("Enter the filename to restore: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = 0;  // remove newline character
    
    // Check if file exists in backup system
    file_index = get_file_index(files, filename);
    if(file_index == -1){
        printf("File not found in backup system.\n");
        return;
    }
    
    // Open file for writing
    fptr = fopen(filename, "w");
    if(fptr == NULL){
        printf("Error: could not create file.\n");
        return;
    }
    
    // Write data to file
    fprintf(fptr, "%s", files[file_index].data);
    fclose(fptr);
    
    // Confirmation message
    printf("File restored successfully.\n");
}