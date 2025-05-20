//FormAI DATASET v1.0 Category: File system simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_SIZE 20
#define MAX_FILE_CONTENT_SIZE 100

typedef struct file {
    char name[MAX_FILE_NAME_SIZE];
    char content[MAX_FILE_CONTENT_SIZE];
} File;

int main() {
    // Define the files array
    File files[10];
    
    // Keep track of the number of files in the array
    int num_files = 0;
    
    // Variable to store the user's choice in the main menu
    int choice;
    
    do {
        // Print the main menu options
        printf("\nFile System Simulation:\n");
        printf("1. Create new file\n");
        printf("2. Read file\n");
        printf("3. Update file\n");
        printf("4. Delete file\n");
        printf("5. List all files\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        
        // Read the user's choice
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                // Create new file
                if (num_files >= 10) {
                    printf("Error: Cannot create new file. File system is full.\n");
                    break;
                }
                
                printf("Enter file name: ");
                scanf("%s", files[num_files].name);
                
                printf("Enter file content: ");
                scanf("%s", files[num_files].content);
                
                printf("File created successfully.\n");
                num_files++;
                break;
            
            case 2:
                // Read file
                printf("Enter file name: ");
                char read_file_name[MAX_FILE_NAME_SIZE];
                scanf("%s", read_file_name);
                
                int read_file_index = -1;
                for (int i = 0; i < num_files; i++) {
                    if (strcmp(files[i].name, read_file_name) == 0) {
                        read_file_index = i;
                    }
                }
                
                if (read_file_index == -1) {
                    printf("Error: Could not find file.\n");
                    break;
                }
                
                printf("\nContent of file %s:\n%s\n", files[read_file_index].name, files[read_file_index].content);
                break;
            
            case 3:
                // Update file
                printf("Enter file name: ");
                char update_file_name[MAX_FILE_NAME_SIZE];
                scanf("%s", update_file_name);
                
                int update_file_index = -1;
                for (int i = 0; i < num_files; i++) {
                    if (strcmp(files[i].name, update_file_name) == 0) {
                        update_file_index = i;
                    }
                }
                
                if (update_file_index == -1) {
                    printf("Error: Could not find file.\n");
                    break;
                }
                
                printf("Enter new content: ");
                scanf("%s", files[update_file_index].content);
                
                printf("File updated successfully.\n");
                break;
            
            case 4:
                // Delete file
                printf("Enter file name: ");
                char delete_file_name[MAX_FILE_NAME_SIZE];
                scanf("%s", delete_file_name);
                
                int delete_file_index = -1;
                for (int i = 0; i < num_files; i++) {
                    if (strcmp(files[i].name, delete_file_name) == 0) {
                        delete_file_index = i;
                    }
                }
                
                if (delete_file_index == -1) {
                    printf("Error: Could not find file.\n");
                    break;
                }
                
                for (int i = delete_file_index; i < num_files - 1; i++) {
                    strcpy(files[i].name, files[i+1].name);
                    strcpy(files[i].content, files[i+1].content);
                }
                
                strcpy(files[num_files-1].name, "");
                strcpy(files[num_files-1].content, "");
                num_files--;
                printf("File deleted successfully.\n");
                break;
            
            case 5:
                // List all files
                printf("\nList of files:\n");
                for (int i = 0; i < num_files; i++) {
                    printf("%s\n", files[i].name);
                }
                break;
                
            case 6:
                // Exit
                printf("Goodbye!\n");
                exit(0);
            
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 6);
    
    return 0;
}