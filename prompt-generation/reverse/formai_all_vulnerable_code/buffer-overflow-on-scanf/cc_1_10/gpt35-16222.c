//FormAI DATASET v1.0 Category: File Backup System ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 1000   //maximum number of files to be backed up

int main(){

    char filenames[MAX_SIZE][100];  //array to store file names
    int num_files;      //variable to store the number of files
    char backup_destination[100];  //variable to store backup destination

    printf("Welcome to the File Backup System.\n\n");

    //getting user input for backup destination
    printf("Please enter the backup destination: ");
    fgets(backup_destination, 100, stdin);
    backup_destination[strlen(backup_destination)-1] = '\0';  //removing newline character

    //getting user input for number of files
    printf("\nPlease enter the number of files to be backed up: ");
    scanf("%d", &num_files);
    getchar();  //removing newline character from input buffer

    //getting user input for file names
    printf("\nPlease enter the file names: \n");
    for(int i=0; i<num_files; i++){
        printf("%d. ", i+1);
        fgets(filenames[i], 100, stdin);
        filenames[i][strlen(filenames[i])-1] = '\0';   //removing newline character
    }

    //creating backup directory
    char command[150];
    sprintf(command, "mkdir -p %s", backup_destination); 
    system(command);

    //backing up files one by one
    for(int i=0; i<num_files; i++){

        //creating backup filename
        char backup_filename[150];
        sprintf(backup_filename, "%s/%s.bak", backup_destination, filenames[i]);

        //copying file to backup directory
        sprintf(command, "cp %s %s", filenames[i], backup_filename);
        system(command);

        printf("\n%s backed up successfully as %s.\n", filenames[i], backup_filename);
    }

    printf("\nAll files backed up successfully to %s.\n", backup_destination);

    return 0;
}