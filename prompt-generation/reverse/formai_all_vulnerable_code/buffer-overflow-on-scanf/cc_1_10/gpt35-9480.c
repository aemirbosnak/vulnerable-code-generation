//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char name[100];
    char date_created[15];
    char author[50];
    char language[20];
    int num_of_lines;
} Metadata;

// function to extract metadata from a C file
Metadata extract_metadata(char* filename){
    Metadata data;
    FILE* fp = NULL;
    char line[200];
    int count = 0;
    fp = fopen(filename, "r");
    if(fp == NULL){
        printf("Could not open file.\n");
        exit(0);
    }
    while(fgets(line, 200, fp)){
        count++;
        if(count == 1){
            strcpy(data.name, strtok(line, "\n"));
        }
        if(strstr(line, "// Date Created:") != NULL){
            strcpy(data.date_created, strtok(line, "// Date Created:"));
        }
        if(strstr(line, "// Author:") != NULL){
            strcpy(data.author, strtok(line, "// Author:"));
        }
        if(strstr(line, "// Language:") != NULL){
            strcpy(data.language, strtok(line, "// Language:"));
        }
    }
    data.num_of_lines = count;
    fclose(fp);
    return data;
}

// sample usage
int main(){
    char filename[100];
    printf("Enter the filename: ");
    scanf("%s", filename);
    Metadata data = extract_metadata(filename);
    printf("Name: %s", data.name);
    printf("Date created: %s", data.date_created);
    printf("Author: %s", data.author);
    printf("Language: %s", data.language);
    printf("Number of lines: %d", data.num_of_lines);
    return 0;
}