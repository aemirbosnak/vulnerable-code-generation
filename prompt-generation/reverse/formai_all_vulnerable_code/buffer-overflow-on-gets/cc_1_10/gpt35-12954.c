//FormAI DATASET v1.0 Category: Data recovery tool ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100 // maximum size of data to be recovered

// function to check if file exists
bool doesFileExist(char* fileName) {
    FILE *file;
    file = fopen(fileName, "r");
    
    if (file != NULL) {
        fclose(file);
        return true;
    } else {
        return false;
    }
}

// function to recover data
void recoverData(char* fileName) {
    FILE* file;
    char data[MAX_SIZE];
    
    // check if file exists
    if (!doesFileExist(fileName)) {
        printf("File does not exist!\n");
        return;
    }
    
    // open file in read mode
    file = fopen(fileName, "r");
    
    // read data from file
    fgets(data, MAX_SIZE, file);
    
    // close file
    fclose(file);
    
    // print recovered data
    printf("Recovered Data: %s\n", data);
}

// main function
int main() {
    char fileName[50];
    
    // get file name from user
    printf("Enter file name: ");
    gets(fileName);
    
    // recover data
    recoverData(fileName);
    
    return 0;
}