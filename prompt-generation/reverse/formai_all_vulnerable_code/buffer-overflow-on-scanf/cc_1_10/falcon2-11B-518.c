//Falcon2-11B DATASET v1.0 Category: File handling ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

int main() {
    char file_name[50];
    FILE *fp;
    char line[MAX_LINE_LENGTH];

    // Prompt user for file name
    printf("Enter file name: ");
    scanf("%s", file_name);

    // Open file for writing
    fp = fopen(file_name, "w");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // Write some data to the file
    printf("Enter a line of text (or \"quit\" to finish): ");
    fgets(line, MAX_LINE_LENGTH, stdin);
    while (strcmp(line, "quit")!= 0) {
        if (fputs(line, fp) == EOF) {
            printf("Error writing to file\n");
            return 1;
        }
        printf("Enter a line of text (or \"quit\" to finish): ");
        fgets(line, MAX_LINE_LENGTH, stdin);
    }

    // Close file
    fclose(fp);

    // Prompt user for file name
    printf("Enter file name to read from: ");
    scanf("%s", file_name);

    // Open file for reading
    fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // Read data from the file
    printf("Data from file:\n");
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        printf("%s\n", line);
    }

    // Close file
    fclose(fp);

    return 0;
}