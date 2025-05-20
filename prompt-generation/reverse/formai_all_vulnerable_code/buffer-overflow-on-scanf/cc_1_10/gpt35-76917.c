//FormAI DATASET v1.0 Category: Data recovery tool ; Style: introspective
#include<stdio.h>
#include<stdlib.h>

//Structure to hold data of the file
typedef struct {
    char filename[50];
    char data[500];
} FileData;

//Function to recover data from file
FileData *dataRecovery(char *filename) {
    FILE *fp = fopen(filename, "r"); //Opening the file in read mode
    if(fp == NULL) {
        printf("Error: Could not open file '%s' for reading.\n", filename);
        return NULL;
    }
    else {
        FileData *filedata = (FileData*) malloc(sizeof(FileData)); //Allocating memory for data recovery
        int i = 0;
        char c = fgetc(fp);
        while(c != EOF) { //Recovering data from file character by character
            filedata->data[i] = c;
            i++;
            c = fgetc(fp);
        }
        fclose(fp); //Closing the file
        printf("Data recovered from file '%s'.\n", filename);
        return filedata;
    }
}

//Function to create a new file with the recovered data
void createFile(FileData *filedata) {
    if(filedata == NULL) {
        printf("Error: Cannot create file as no data has been recovered.\n");
    }
    else {
        FILE *fp = fopen(filedata->filename, "w"); //Opening the file in write mode
        fprintf(fp, "%s", filedata->data); //Writing the recovered data to the file
        fclose(fp); //Closing the file
        printf("File '%s' created successfully with the recovered data.\n", filedata->filename);
    }
}

int main() {
    char filename[50];
    printf("Enter the name of the file you want to recover: ");
    scanf("%s", filename);
    FileData *filedata = dataRecovery(filename); //Recovering data from file
    createFile(filedata); //Creating a new file with the recovered data
    return 0;
}