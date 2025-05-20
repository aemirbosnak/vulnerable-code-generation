//FormAI DATASET v1.0 Category: File Backup System ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define FILENAME_LENGTH 256
// function declarations
void backupFile(char *filename);
void printMenu();
int main()
{   
    char filename[FILENAME_LENGTH];
    int option;
    printf("Welcome to the Unique C File Backup System!");
    while(1){
        printMenu();
        printf("Enter your choice: ");
        scanf("%d",&option);
        switch(option){
            case 1:
                printf("Enter filename to backup: ");
                scanf("%s",filename);
                backupFile(filename);
                break;
            case 2:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid option. Try again.\n");
        }
    }
    return 0;
}

void backupFile(char *filename){
    char backupname[FILENAME_LENGTH];
    FILE *fp, *fp2;
    strcpy(backupname,filename);
    strcat(backupname,".bak"); // create backup file name
    fp = fopen(filename,"r");
    if(fp == NULL){
        printf("Error opening file. File does not exist.\n");
        return;
    }
    fp2 = fopen(backupname,"w");
    char ch;
    while((ch = fgetc(fp)) != EOF){
        fputc(ch, fp2);
        printf("%c",ch);
    }
    printf("\nFile backed up successfully!\n");
    fclose(fp);
    fclose(fp2);
}

void printMenu(){
    printf("\nMenu:\n");
    printf("1. Backup a File\n");
    printf("2. Exit\n");
}