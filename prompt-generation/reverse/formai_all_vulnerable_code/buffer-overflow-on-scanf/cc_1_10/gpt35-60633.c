//FormAI DATASET v1.0 Category: File Backup System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_FILENAME_LENGTH 64
#define MAX_FILE_SIZE 1000

int main(){
    //get filename and data from user
    char filename[MAX_FILENAME_LENGTH];
    char data[MAX_FILE_SIZE];
    printf("Enter filename: ");
    scanf("%s", filename);
    printf("Enter data to be written to file:\n");
    scanf("%s", data);
    
    //backup original file
    char backup_filename[MAX_FILENAME_LENGTH+5];
    strcpy(backup_filename, filename);
    strcat(backup_filename, ".bak");
    FILE *backup = fopen(backup_filename, "w");
    if(backup == NULL){
        printf("Error creating backup file.");
        return 1;
    }
    FILE *original = fopen(filename, "r");
    if(original == NULL){
        //if original file does not exist, create it
        original = fopen(filename, "w");
        if(original == NULL){
            printf("Error creating new file.");
            return 1;
        }
    }else{
        //if original file exists, copy its contents to backup file
        char c = fgetc(original);
        while(c != EOF){
            fputc(c, backup);
            c = fgetc(original);
        }
        fclose(original);
    }
    fclose(backup);
    
    //write data to original file
    FILE *write_file = fopen(filename, "w");
    if(write_file == NULL){
        printf("Error writing to file.");
        return 1;
    }
    fprintf(write_file, "%s", data);
    fclose(write_file);
    
    printf("File successfully backed up and updated.");
    return 0;
}