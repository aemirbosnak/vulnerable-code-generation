//FormAI DATASET v1.0 Category: File Backup System ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct file{
    char name[50];
    double size;
    int no_of_copies;
    char* last_backup_date;
};

void delete_file(struct file *backup_list, int num_of_files, char *name_to_delete);
void update_backup_date(struct file *file_to_update, char *backup_date);
void add_new_file(struct file *backup_list, int num_of_files);
void display_backup_list(struct file *backup_list, int num_of_files);
void save_backup_list(struct file *backup_list, int num_of_files);

int main(){
    int choice = 1;
    int num_of_files = 0;
    struct file backup_list[50];

    while(choice != 0){
        printf("\n\n ------FILE BACKUP SYSTEM------\n");
        printf("\nSelect an option:\n");
        printf("1. Add a file to the backup list.\n");
        printf("2. Delete a file from the backup list.\n");
        printf("3. Update last backup date for a file.\n");
        printf("4. Display list of files.\n");
        printf("0. Exit.\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                add_new_file(backup_list, num_of_files);
                num_of_files++;
                break;
            case 2:
                {
                    char name_to_delete[50];
                    printf("\nEnter the name of the file to delete: ");
                    scanf("%s", name_to_delete);
                    delete_file(backup_list, num_of_files, name_to_delete);
                    num_of_files--;
                }
                break;
            case 3:
                {
                    char name_to_update[50];
                    char backup_date[50];
                    printf("\nEnter the name of the file to update backup date: ");
                    scanf("%s", name_to_update);
                    printf("Enter the new backup date (yyyy-mm-dd): ");
                    scanf("%s", backup_date);
                    for(int i=0; i<num_of_files; i++){
                        if(strcmp(backup_list[i].name, name_to_update) == 0){
                            update_backup_date(&backup_list[i], backup_date);
                            break;
                        }
                    }
                }
                break;
            case 4:
                display_backup_list(backup_list, num_of_files);
                break;
            case 0:
                save_backup_list(backup_list, num_of_files);
                printf("\nThank you for using the File Backup System.\n");
                break;
            default:
                printf("\nINVALID CHOICE!\n");
                break;
        }
    }

    return 0;
}

void add_new_file(struct file *backup_list, int num_of_files){
    printf("\n");
    printf("Enter the name of the file: ");
    scanf("%s", backup_list[num_of_files].name);
    printf("Enter the size of the file (in MB): ");
    scanf("%lf", &backup_list[num_of_files].size);
    printf("Enter the number of copies: ");
    scanf("%d", &backup_list[num_of_files].no_of_copies);
    char backup_date[50];
    printf("Enter the last backup date (yyyy-mm-dd): ");
    scanf("%s", backup_date);
    backup_list[num_of_files].last_backup_date = (char*) malloc(sizeof(char)*(strlen(backup_date)+1));
    strcpy(backup_list[num_of_files].last_backup_date, backup_date);
    printf("The file has been added to the backup list.\n");
}

void delete_file(struct file *backup_list, int num_of_files, char *name_to_delete){
    int file_index = -1;
    for(int i=0; i<num_of_files; i++){
        if(strcmp(backup_list[i].name, name_to_delete) == 0){
            file_index = i;
            break;
        }
    }
    if(file_index == -1){
        printf("\nThe file %s is not present in the backup list.\n", name_to_delete);
        return;
    }
    else{
        for(int i=file_index; i<num_of_files-1; i++){
            backup_list[i] = backup_list[i+1];
        }
        printf("\nThe file %s has been deleted from the backup list.\n", name_to_delete);
    }
}

void update_backup_date(struct file *file_to_update, char *backup_date){
    free(file_to_update->last_backup_date);
    file_to_update -> last_backup_date = (char*) malloc(sizeof(char)*(strlen(backup_date)+1));
    strcpy(file_to_update -> last_backup_date, backup_date);
    printf("\nThe last backup date for file %s has been updated to %s.\n", file_to_update->name, file_to_update->last_backup_date);
}

void display_backup_list(struct file *backup_list, int num_of_files){
    printf("\n\n  ----- Backup List -----\n\n");
    printf("SL.No\tFilename\tSize\tCopies\tLastBackupDate\n");
    for(int i=0; i<num_of_files; i++){
        printf("%d.\t%s\t%.2lfMB\t%d\t%s\n", i+1, backup_list[i].name, backup_list[i].size, backup_list[i].no_of_copies, backup_list[i].last_backup_date);
    }
}

void save_backup_list(struct file *backup_list, int num_of_files){
    FILE* fptr = fopen("backup_list.txt", "w");
    if(fptr == NULL){
        printf("ERROR: Could not create backup_list.txt.\n");
        return;
    }
    fprintf(fptr, "SL.No\tFilename\tSize\tCopies\tLastBackupDate\n");
    for(int i=0; i<num_of_files; i++){
        fprintf(fptr, "%d.\t%s\t%.2lfMB\t%d\t%s\n", i+1, backup_list[i].name, backup_list[i].size, backup_list[i].no_of_copies, backup_list[i].last_backup_date);
    }
    fclose(fptr);
    printf("\nThe backup list has been saved to backup_list.txt.\n");
}