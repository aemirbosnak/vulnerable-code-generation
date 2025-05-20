//FormAI DATASET v1.0 Category: File Backup System ; Style: Romeo and Juliet
//VeronaFileBackupSystem.c
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    char veronaFolder[] = "VeronaFolder";
    char backupFolder[] = "BackupFolder";
    char fileName[50];
    FILE *veronaFile, *backupFile;
    int fileLength;

    printf("Welcome to Verona File Backup System\n");
    printf("We shall protect your data, just like Romeo protected Juliet\n\n");

    //creating Verona Folder, if not exists
    system("mkdir VeronaFolder");
    //creating Backup Folder, if not exists
    system("mkdir BackupFolder");

    printf("Enter your file name :");
    gets(fileName);

    //Opening file from Verona folder
    veronaFile = fopen(strcat(veronaFolder, fileName), "r");

    //Checking if file exists
    if(veronaFile==NULL){
        printf("Oops! Looks like Romeo didn't leave this file for us\n");
        return 0;
    }

    //getting file length
    fseek(veronaFile, 0 , SEEK_END);
    fileLength = ftell(veronaFile);
    fseek(veronaFile, 0 , SEEK_SET);

    //Opening file in Backup folder to write
    backupFile = fopen(strcat(backupFolder, fileName), "w");

    //Copying File from Verona Folder to Backup Folder
    int i;
    for(i=0; i<fileLength; i++) {
       fputc(fgetc(veronaFile), backupFile);
    }

    //Closing all files
    fclose(veronaFile);
    fclose(backupFile);

    //Output Success
    printf("Your file has been saved with Romeo's blessings in Backup Folder, may it be protected forever.\n");

    return 0;
}