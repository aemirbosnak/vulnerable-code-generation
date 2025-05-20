//FormAI DATASET v1.0 Category: Data recovery tool ; Style: real-life
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void printMenu(); // function to print menu options
void recoverData(char *filename); // function to recover data from file
void writeFile(char *filename, char *content); // function to write data to file

int main(){
    char filename[50];
    int choice;

    printMenu(); // print menu options

    printf("Enter your choice: ");
    scanf("%d", &choice); // get user input

    switch(choice){
        case 1:
            printf("Enter the name of the file to recover: ");
            scanf("%s", filename); // get the filename to recover
            recoverData(filename); // call function to recover data
            break;
        case 2:
            printf("Enter the name of the file to write: ");
            scanf("%s", filename); // get the filename to write
            printf("Enter the content to write to file: ");
            char content[1000];
            scanf(" %[^\n]s", content); // get the content to write
            writeFile(filename, content); // call function to write data to file
            break;
        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}

void printMenu(){
    printf("***Data Recovery Tool***\n");
    printf("1. Recover data from file\n");
    printf("2. Write data to file\n");
}

void recoverData(char *filename){
    FILE *fp;
    char ch;

    fp = fopen(filename, "r"); // open file in read mode

    if(fp == NULL){
        printf("File not found\n");
        return;
    }

    printf("***Data Recovered from %s***\n\n", filename);

    while((ch = fgetc(fp)) != EOF){ // read data from file
        printf("%c", ch); // print data to console
    }

    fclose(fp); // close file
}

void writeFile(char *filename, char *content){
    FILE *fp;

    fp = fopen(filename, "w"); // open file in write mode

    if(fp == NULL){
        printf("Error creating file\n");
        return;
    }

    fputs(content, fp); // write data to file

    printf("Data written to file successfully\n");

    fclose(fp); // close file
}