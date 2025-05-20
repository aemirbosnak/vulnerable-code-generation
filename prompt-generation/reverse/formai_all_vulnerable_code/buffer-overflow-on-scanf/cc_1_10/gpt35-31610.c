//FormAI DATASET v1.0 Category: File Backup System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global configuration parameters
#define MAX_NAME_LENGTH 50 // maximum characters allowed in filename
#define MAX_BACKUPS 10 // maximum number of backup files

/* Structure Definition */

struct file {
    char name[MAX_NAME_LENGTH];
    int size;
    char content[1000];
};

/* Function Declarations */
int backup_exist(struct file backups[], int num_backups, char* target_file_name);
int is_file_valid(char* file_name);
void backup_file(struct file backups[], char* source_file_name, int* num_backups);
void restore_file(struct file backups[], int num_backups, char* target_file_name);

int main(){

    // Initialize the backup array
    struct file backups[MAX_BACKUPS];
    int num_backups = 0;

    int user_choice = -1;

    do{
        // Display menu
        printf("\n=================== C File Backup System ===================\n");
        printf("1. Backup a file\n");
        printf("2. Restore a file\n");
        printf("3. Exit Program\n");
        printf("Enter Choice: ");

        // Take user input
        scanf("%d", &user_choice);

        // Process user input
        switch(user_choice){
            case 1:{
                char source_file_name[MAX_NAME_LENGTH] = {"\0"};

                do{
                    printf("Enter full path of file to backup: ");
                    scanf("%s", source_file_name);
                }while(!is_file_valid(source_file_name));

                backup_file(backups, source_file_name, &num_backups);
                printf("\nFile Backup Successful!\n");

                break;
            }

            case 2:{
                char target_file_name[MAX_NAME_LENGTH] = {"\0"};

                do{
                    printf("Enter filename to restore: ");
                    scanf("%s", target_file_name);
                }while(!is_file_valid(target_file_name));

                if(!backup_exist(backups, num_backups, target_file_name)){
                    printf("\nFile Backup Not Found!\n");
                } else {
                    restore_file(backups, num_backups, target_file_name);
                    printf("\nFile Restore Successful!\n");
                }

                break;
            }

            case 3:{
                printf("\nExiting program...\n");
                break;
            }

            default:{
                printf("\nInvalid Choice. Try Again!\n");
                break;
            }
        }

    }while(user_choice!=3);

    return 0;
}

/* Function Definitions */

// Function to check whether a backup file exists
int backup_exist(struct file backups[], int num_backups, char* target_file_name){
    int i;
    for(i=0;i<num_backups;i++){
        if(strcmp(backups[i].name, target_file_name)==0){
            return 1;
        }
    }
    return 0;
}

// Function to validate whether a file exists
int is_file_valid(char* file_name){
    FILE* fp;
    fp = fopen(file_name, "rb");
    if(fp==NULL){
        printf("File \"%s\" does not exist! Try Again...\n", file_name);
        return 0;
    }
    fclose(fp);
    return 1;
}

// Function to backup a file
void backup_file(struct file backups[], char* source_file_name, int* num_backups){
    FILE* fp;
    struct file temp;

    fp = fopen(source_file_name, "rb");

    // Save file information into temporary structure
    strcpy(temp.name, source_file_name);
    fseek(fp, 0, SEEK_END);
    temp.size = ftell(fp);
    rewind(fp);
    fread(temp.content, temp.size, 1, fp);

    // Close file pointer
    fclose(fp);

    // Add temporary structure to backups array
    backups[*num_backups] = temp;
    *num_backups = *num_backups + 1;

}

// Function to restore a file
void restore_file(struct file backups[], int num_backups, char* target_file_name){
    FILE* fp;
    int i;

    // Search through backups array for target backup file
    for(i=0;i<num_backups;i++){
        if(strcmp(backups[i].name, target_file_name)==0){
            fp = fopen(target_file_name, "wb");
            fwrite(backups[i].content, backups[i].size, 1, fp);
            fclose(fp);
            break;
        }
    }
}