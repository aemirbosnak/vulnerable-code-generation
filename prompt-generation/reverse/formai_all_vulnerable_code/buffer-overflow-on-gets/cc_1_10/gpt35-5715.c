//FormAI DATASET v1.0 Category: File handling ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

int main() {
    FILE *fp; //defining a file pointer
    char buffer[BUFFER_SIZE]; //declaring a buffer to store data
    char filename[100], full_filename[100];

    printf("Enter the filename to create: ");
    gets(filename); //getting input from user

    //adding file extension to filename
    strcpy(full_filename, filename);
    strcat(full_filename, ".txt");

    fp = fopen(full_filename, "w"); //opening file in write mode
    if(fp == NULL) {
        printf("Error: Unable to create file '%s'", full_filename);
        exit(1); //exiting the program if unable to create file
    }

    printf("Enter the text to write to the file (Enter 'exit' to stop writing):\n");
    while(1) {
        gets(buffer); //getting input from user
        if(strcmp(buffer, "exit") == 0) {
            break; //if user enters 'exit', break the loop
        }
        fputs(buffer, fp); //writing data to the file
        fputc('\n', fp); //writing newline character after each line
    }

    fclose(fp); //closing the file

    fp = fopen(full_filename, "r"); //opening file in read mode
    if(fp == NULL) {
        printf("Error: Unable to open file '%s'", full_filename);
        exit(1); //exiting the program if unable to open file
    }

    printf("Contents of the file '%s':\n", full_filename);
    int count = 0;
    while(fgets(buffer, BUFFER_SIZE, fp) != NULL) { //reading file data line by line
        printf("%d: %s", count++, buffer); //printing the data
    }

    fclose(fp); //closing the file

    return 0;
}