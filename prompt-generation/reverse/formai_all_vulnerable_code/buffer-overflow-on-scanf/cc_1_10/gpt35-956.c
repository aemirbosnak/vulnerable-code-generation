//FormAI DATASET v1.0 Category: File handling ; Style: modular
#include<stdio.h>
#include<stdlib.h>

//function prototype declarations
void writeToFile(char*, char*);
void readFromFile(char*);

int main(){
    char fileName[20];
    printf("Enter file name to create: ");
    scanf("%s", fileName);

    char message[100];
    printf("Enter message to write to the file: ");
    scanf("%s", message);

    writeToFile(fileName, message);

    readFromFile(fileName);

    return 0;
}

void writeToFile(char* fileName, char* message){
    //open a file in write mode
    FILE *fp = NULL;
    fp = fopen(fileName, "w");

    //check if file opened successfully or not
    if(fp == NULL){
        printf("Error opening file!");
        exit(1);
    }

    //write to file
    fputs(message, fp);

    //close the file
    fclose(fp);
}

void readFromFile(char* fileName){
    //open a file in read mode
    FILE *fp = NULL;
    fp = fopen(fileName, "r");

    //check if file opened successfully or not
    if(fp == NULL){
        printf("Error opening file!");
        exit(1);
    }

    //read from file and print
    char buff[255];
    while(fgets(buff, 255, (FILE*)fp)){
        printf("%s", buff);
    }

    //close the file
    fclose(fp);
}