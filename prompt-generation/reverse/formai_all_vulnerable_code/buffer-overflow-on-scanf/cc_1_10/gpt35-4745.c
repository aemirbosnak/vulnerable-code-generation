//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* A program to extract metadata from a C program */

typedef struct Metadata{
    char author[50];
    char date[20];
    char version[10];
}Metadata;

int main(){
    printf("Welcome to the C Metadata Extractor!\n");
    printf("Please enter the file name to extract metadata from: ");

    char filename[50];
    scanf("%s", filename);
    printf("\n");

    FILE* file = fopen(filename, "r");

    if(file == NULL){
        printf("Error: File not found!\n");
        exit(1);
    }

    char line[200];
    Metadata metadata;
    memset(&metadata, 0, sizeof(metadata));

    while(fgets(line, 200, file)){

        if(strstr(line, "Author:")){
            strcpy(metadata.author, strchr(line, ':') + 2);
            metadata.author[strlen(metadata.author)-1] = '\0';
        }
        else if(strstr(line, "Date:")){
            strcpy(metadata.date, strchr(line, ':') + 2);
            metadata.date[strlen(metadata.date)-1] = '\0';
        }
        else if(strstr(line, "Version:")){
            strcpy(metadata.version, strchr(line, ':') + 2);
            metadata.version[strlen(metadata.version)-1] = '\0';
        }
    }

    printf("Metadata extracted successfully!\n");
    printf("Author: %s\n", metadata.author);
    printf("Date: %s\n", metadata.date);
    printf("Version: %s\n", metadata.version);

    fclose(file);

    return 0;
}