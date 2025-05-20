//FormAI DATASET v1.0 Category: File Backup System ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define FILE_NAME_SIZE 100
#define BUFFER_SIZE 1024

void encrypt(char data[BUFFER_SIZE]){
    for(int i=0;i<strlen(data);i++){
        data[i] = data[i] + 5;
    }
}

void decrypt(char data[BUFFER_SIZE]){
    for(int i=0;i<strlen(data);i++){
        data[i] = data[i] - 5;
    }
}

int main(){
    char file_name[FILE_NAME_SIZE];
    char buffer[BUFFER_SIZE];
    FILE *source_file, *target_file;
    int choice, i;

    printf("Welcome to the Cryptic C File Backup System\n");

    while(1){
        printf("\nWhat do you want to do?\n");
        printf("1. Backup a file\n");
        printf("2. Restore a file\n");
        printf("3. Exit\n");

        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nEnter the name of the file to backup: ");
                scanf("%s", file_name);

                source_file = fopen(file_name, "r");
                if(source_file == NULL){
                    printf("\nError opening source file. Please check if the file exists or its name is correct.\n");
                    continue;
                }

                strcat(file_name, ".backup");
                target_file = fopen(file_name, "w");

                while((i = fread(buffer, sizeof(char), BUFFER_SIZE, source_file)) > 0){
                    encrypt(buffer);
                    fwrite(buffer, sizeof(char), i, target_file);
                }

                printf("\nFile backed up successfully as %s\n", file_name);

                fclose(source_file);
                fclose(target_file);

                break;

            case 2:
                printf("\nEnter the name of the file to restore: ");
                scanf("%s", file_name);

                source_file = fopen(file_name, "r");
                if(source_file == NULL){
                    printf("\nError opening source file. Please check if the file exists or its name is correct.\n");
                    continue;
                }

                i = strlen(file_name);
                if(i<7 || strcmp(file_name + i - 7, ".backup")){
                    printf("\nInvalid file selected. Please select a valid backup file.\n");
                    continue;
                }

                file_name[i-7] = '\0';
                target_file = fopen(file_name, "w");

                while((i = fread(buffer, sizeof(char), BUFFER_SIZE, source_file)) > 0){
                    decrypt(buffer);
                    fwrite(buffer, sizeof(char), i, target_file);
                }

                printf("\nFile restored successfully as %s\n", file_name);

                fclose(source_file);
                fclose(target_file);

                break;

            case 3:
                printf("\nThank you for using Cryptic C File Backup System\n");
                return 0;

            default:
                printf("\nInvalid choice. Please select a valid option.\n");
                break;
        }
    }
    
    return 0;
}