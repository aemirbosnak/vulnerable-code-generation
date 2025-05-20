//FormAI DATASET v1.0 Category: File system simulation ; Style: cheerful
/* Welcome to File System Simulation! Yay! */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Global Constants
#define MAX_FILENAME_SIZE 15
#define MAX_FILE_SIZE 1024
#define MAX_NUM_FILES 32

// Global Variables
int num_files = 0; 
char filenames[MAX_NUM_FILES][MAX_FILENAME_SIZE+1];
char files[MAX_NUM_FILES][MAX_FILE_SIZE+1];

// Helper Functions
int get_file_index(char* filename) {
    for (int i = 0; i < num_files; i++) {
        if(strcmp(filenames[i], filename) == 0) {
            return i;
        }
    }
    return -1;
}

void list_files() {
    printf("====List of Files:====\n");
    for (int i = 0; i < num_files; i++) {
        printf("%d. %s\n", i+1, filenames[i]);
    }
    printf("======================\n");
}

// Main Function
int main() {
    printf("Welcome to File System!\n");

    // Main Loop
    while(1) {
        printf("\nEnter command: ");
        char command[10];
        scanf("%s", command);
        if (strcmp(command, "create") == 0) {
            char filename[MAX_FILENAME_SIZE+1];
            scanf("%s", filename);
            if(get_file_index(filename) != -1) {
                printf("File already exists!\n");
            }
            else if(num_files == MAX_NUM_FILES) {
                printf("File system full!\n");
            }
            else {
                strcpy(filenames[num_files], filename);
                files[num_files][0] = '\0';
                num_files++;
                printf("File created!\n");
            }
        }
        else if (strcmp(command, "delete") == 0) {
            char filename[MAX_FILENAME_SIZE+1];
            scanf("%s", filename);
            int file_index = get_file_index(filename);
            if(file_index == -1) {
                printf("File does not exist!\n");
            }
            else {
                for (int i = file_index; i < num_files-1; i++) {
                    strcpy(filenames[i], filenames[i+1]);
                    strcpy(files[i], files[i+1]);
                }
                num_files--;
                printf("File deleted!\n");
            }
        }
        else if (strcmp(command, "write") == 0) {
            char filename[MAX_FILENAME_SIZE+1];
            scanf("%s", filename);
            int file_index = get_file_index(filename);
            if(file_index == -1) {
                printf("File does not exist!\n");
            }
            else {
                char input[MAX_FILENAME_SIZE];
                while(getchar() != '\n');
                fgets(input, MAX_FILE_SIZE, stdin);
                strcpy(files[file_index], input);
                printf("Data written to file!\n");
            }
        }
        else if (strcmp(command, "read") == 0) {
            char filename[MAX_FILENAME_SIZE+1];
            scanf("%s", filename);
            int file_index = get_file_index(filename);
            if(file_index == -1) {
                printf("File does not exist!\n");
            }
            else {
                printf("File content: %s\n", files[file_index]);
            }
        }
        else if (strcmp(command, "list") == 0) {
            list_files();
        }
        else if (strcmp(command, "quit") == 0) {
            printf("Goodbye!\n");
            break;
        }
        else {
            printf("Invalid command, please try again!\n");
        }
    }
    return 0;
}