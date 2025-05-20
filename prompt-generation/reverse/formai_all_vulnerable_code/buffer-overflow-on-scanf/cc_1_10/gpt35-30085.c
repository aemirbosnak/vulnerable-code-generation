//FormAI DATASET v1.0 Category: File handling ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024

int main() {
    char filename[50];
    char data[MAX_FILE_SIZE];

    printf("Enter filename: ");
    scanf("%s", filename);

    FILE *fp;
    fp = fopen(filename, "w+");

    if (fp == NULL) {
        printf("Unable to create file.\n");
        return 0;
    }

    printf("Enter data to write to file: ");
    scanf("%s", data);

    fprintf(fp, "%s", data);

    printf("Data written to file.\n");

    fclose(fp);

    printf("File closed.\n");

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Unable to open file for reading.\n");
        return 0;
    }

    char readData[MAX_FILE_SIZE];

    fscanf(fp, "%s", readData);

    printf("Data read from file: %s\n", readData);

    fclose(fp);

    printf("File closed.\n");

    return 0;
}