//Falcon-180B DATASET v1.0 Category: File handling ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_LINE_LENGTH 1000

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    FILE* file_pointer;
} File;

int main() {
    int num_files;
    char file_name[MAX_FILE_NAME_LENGTH];
    File files[100];
    char line[MAX_LINE_LENGTH];

    // Prompt the user for the number of files to open
    printf("Enter the number of files to open: ");
    scanf("%d", &num_files);

    // Prompt the user for the file names and open each file
    for (int i = 0; i < num_files; i++) {
        printf("Enter file name %d: ", i+1);
        scanf("%s", file_name);
        files[i].file_name[0] = '\0';
        strcat(files[i].file_name, file_name);
        files[i].file_pointer = fopen(files[i].file_name, "r");
        if (files[i].file_pointer == NULL) {
            printf("Error opening file %s\n", file_name);
            exit(1);
        }
    }

    // Read each file and print its contents
    for (int i = 0; i < num_files; i++) {
        printf("File %s:\n", files[i].file_name);
        while (fgets(line, MAX_LINE_LENGTH, files[i].file_pointer)!= NULL) {
            printf("%s", line);
        }
    }

    // Close each file
    for (int i = 0; i < num_files; i++) {
        fclose(files[i].file_pointer);
    }

    return 0;
}