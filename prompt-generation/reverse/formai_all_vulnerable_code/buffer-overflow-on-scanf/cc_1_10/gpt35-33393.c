//FormAI DATASET v1.0 Category: Error handling ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

void error_handler(int status) {
    if(status == 0) {
        printf("No error occurred.\n");
    }
    else if(status == 1) {
        printf("Error occurred. Cleaning up...\n");
    }
    else if(status == 2) {
        printf("Critical error occurred. Exiting...\n");
        exit(1);
    }
    else {
        printf("Unknown error occurred. Terminating...\n");
        exit(1);
    }
}

int main() {
    char file_name[100]; // buffer to store the file name
    FILE *fp; // file pointer
    int status = 0; // variable to keep track of status

    printf("Enter the file name: ");
    scanf("%s", file_name); // read the file name from user input

    fp = fopen(file_name, "r"); // try to open the file in read mode

    if(fp == NULL) { // if file could not be opened
        printf("Error opening file \"%s\".\n", file_name);
        error_handler(2); // exit the program with critical error
    }
    else {
        printf("File \"%s\" opened successfully.\n", file_name);
        // file processing code...
        status = fclose(fp); // close the file and store the status
        if(status == EOF) { // if error occurred while closing the file
            printf("Error closing file \"%s\".\n", file_name);
            error_handler(1); // cleanup and continue running the program
        }
        else {
            printf("File \"%s\" closed successfully.\n", file_name);
        }
    }

    printf("Program terminated peacefully.\n");
    error_handler(0); // no error occurred
    return 0;
}