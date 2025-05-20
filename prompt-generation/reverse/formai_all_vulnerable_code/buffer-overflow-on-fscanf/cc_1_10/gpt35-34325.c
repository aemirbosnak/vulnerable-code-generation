//FormAI DATASET v1.0 Category: File handling ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LEN 100

int main(){

    char filename[MAX_LEN], str[MAX_LEN];
    FILE *fp;
    int choice;

    printf("Enter Filename: ");
    scanf("%s", filename);

    // File reading
    fp = fopen(filename, "r");
    if(fp == NULL){
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }else{
        printf("Successfully opened file %s.\n\n", filename);
    }

    printf("\nContents of %s:\n", filename);
    while(fscanf(fp, "%s", str) != EOF){
        printf("%s ", str);
    }

    // Close the file
    fclose(fp);

    // File writing
    printf("\n\n------------------------\n");

    printf("\n1. Append to file\n2. Overwrite file\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    fp = fopen(filename, choice == 1 ? "a" : "w");
    if(fp == NULL){
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    printf("Enter string to write to file:\n");
    fflush(stdin);
    fgets(str, sizeof(str), stdin);

    fprintf(fp, "%s", str);

    printf("\nSuccessfully wrote to file %s.\n", filename);

    // Close the file
    fclose(fp);

    // File reading
    fp = fopen(filename, "r");
    if(fp == NULL){
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }else{
        printf("\nNew contents of file %s:\n", filename);
    }

    while(fscanf(fp, "%s", str) != EOF){
        printf("%s ", str);
    }

    // Close the file
    fclose(fp);

    return 0;
}