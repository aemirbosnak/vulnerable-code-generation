//FormAI DATASET v1.0 Category: File Backup System ; Style: accurate
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_BUFFER_SIZE 1024

// function to check if file exists
int file_exists(char *file_name){
    FILE *file = fopen(file_name, "r");
    if(file){
        fclose(file);
        return 1;
    }
    return 0;
}

int main() {
    char file_name[MAX_FILE_NAME_LENGTH];
    char buffer[MAX_BUFFER_SIZE];

    printf("Enter file name to backup: ");
    scanf("%s", file_name);

    // check if file exists
    if(!file_exists(file_name)){
        printf("Error: File does not exist\n");
        return 1;
    }

    // get backup file name
    char backup_file_name[MAX_FILE_NAME_LENGTH];
    strcpy(backup_file_name, "backup_");
    strcat(backup_file_name, file_name);

    // check if backup file already exists
    if(file_exists(backup_file_name)){
        printf("Backup file already exists. Overwrite? (y/n): ");
        char option;
        scanf(" %c", &option);  // space before %c to consume newline character left in buffer
        if(option == 'n'){
            return 0;
        }
    }

    // open file for reading
    FILE *file = fopen(file_name, "r");
    if(!file){
        printf("Error opening file\n");
        return 1;
    }

    // open backup file for writing
    FILE *backup_file = fopen(backup_file_name, "w");
    if(!backup_file){
        printf("Error creating backup file\n");
        return 1;
    }

    // read from file and write to backup file
    while(fgets(buffer, MAX_BUFFER_SIZE, file)){
        fputs(buffer, backup_file);
    }

    printf("Backup created successfully\n");

    // close files
    fclose(file);
    fclose(backup_file);

    return 0;
}