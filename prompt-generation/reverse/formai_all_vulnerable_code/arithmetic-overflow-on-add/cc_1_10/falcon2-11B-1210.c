//Falcon2-11B DATASET v1.0 Category: Data mining ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to get user input for file name
void getFileName() {
    char fileName[256];
    printf("Enter file name: ");
    scanf("%s", fileName);
    return;
}

// Function to read the file and store the data in an array
void readFile(char *fileName, char **data) {
    FILE *fp;
    fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    int fileSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    char *buffer = (char *)malloc(fileSize + 1);
    fread(buffer, fileSize, 1, fp);
    fclose(fp);
    *data = (char *)malloc(fileSize + 1);
    strcpy(*data, buffer);
    return;
}

// Function to extract data from the file
void extractData(char *data) {
    char *token = strtok(data, "\n");
    int count = 0;
    while (token!= NULL) {
        if (isdigit(token[0])) {
            count++;
        }
        token = strtok(NULL, "\n");
    }
    printf("Number of lines: %d\n", count);
    return;
}

int main() {
    char *fileName = "data.txt";
    char *data;
    getFileName();
    readFile(fileName, &data);
    extractData(data);
    return 0;
}