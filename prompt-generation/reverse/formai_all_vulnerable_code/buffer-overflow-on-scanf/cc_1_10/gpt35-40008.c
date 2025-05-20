//FormAI DATASET v1.0 Category: File handling ; Style: lively
#include <stdio.h> // standard input/output library
#include <stdlib.h> // standard library for memory allocation
#include <string.h> // string handling library

#define MAX_SIZE 100 // maximum size for file content

int main()
{
    char filename[50]; // variable for file name
    char content[MAX_SIZE]; // variable for file content
    FILE *fp; // file pointer

    printf("Welcome to My File Handling Program!\n");
    printf("Please enter the file name (including extension): ");
    scanf("%s", filename); // get file name from user input

    // open file with write permission
    fp = fopen(filename, "w");

    if(fp == NULL) // check if file was opened successfully
    {
        printf("Error opening file!\n"); // error message
        exit(1); // terminate program
    }

    printf("File created successfully!\n");
    printf("Please enter the content you want to write to the file (max %d characters): ", MAX_SIZE);

    scanf(" %[^\n]", content); // get file content
    fputs(content, fp); // write content to file
    printf("Content written to file successfully!\n");
    fclose(fp); // close file

    // open file with read permission
    fp = fopen(filename, "r");

    if(fp == NULL) // check if file was opened successfully
    {
        printf("Error opening file!\n"); // error message
        exit(1); // terminate program
    }

    printf("File content:\n");
    printf("----------------\n");

    while(fgets(content, MAX_SIZE, fp) != NULL) // read content from file line by line
    {
        printf("%s", content); // print file content
    }

    printf("----------------\n");
    fclose(fp); // close file

    printf("Thank you for using My File Handling Program!\n");

    return 0; // return success signal
}