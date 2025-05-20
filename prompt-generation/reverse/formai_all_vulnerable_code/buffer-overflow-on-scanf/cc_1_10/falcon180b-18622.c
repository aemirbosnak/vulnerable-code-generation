//Falcon-180B DATASET v1.0 Category: File handling ; Style: secure
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_LINE_LENGTH 1024

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    FILE* fp;
} FILE_HANDLE;

int main() {
    FILE_HANDLE file_handle;
    char file_name[MAX_FILE_NAME_LENGTH];
    char line[MAX_LINE_LENGTH];
    int line_count = 0;
    int character_count = 0;

    // Prompt user for file name
    printf("Enter the file name: ");
    scanf("%s", file_name);

    // Open the file in read mode
    file_handle.fp = fopen(file_name, "r");
    if (file_handle.fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Read the file line by line
    while (fgets(line, MAX_LINE_LENGTH, file_handle.fp)!= NULL) {
        line_count++;

        // Count the number of characters in the line
        int i = 0;
        while (line[i]!= '\0') {
            character_count++;
            i++;
        }

        // Print the line number and character count
        printf("Line %d has %d characters.\n", line_count, character_count);

        // Reset character count for the next line
        character_count = 0;
    }

    // Close the file
    fclose(file_handle.fp);

    return 0;
}