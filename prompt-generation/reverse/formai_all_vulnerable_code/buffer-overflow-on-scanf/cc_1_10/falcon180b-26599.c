//Falcon-180B DATASET v1.0 Category: File handling ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_FILE_NAME_LENGTH 50

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    FILE* file_ptr;
} File;

int main() {
    int num_files = 0;
    char file_name[MAX_FILE_NAME_LENGTH];
    int file_name_length;
    int line_length;
    char line[MAX_LINE_LENGTH];
    File files[10];

    // Prompt the user for the number of files they want to open
    printf("Enter the number of files you want to open: ");
    scanf("%d", &num_files);

    // Loop through each file and prompt the user for the file name and open the file
    for (int i = 0; i < num_files; i++) {
        printf("Enter the name of file %d: ", i+1);
        scanf("%s", file_name);
        file_name_length = strlen(file_name);

        // Check if the file name is too long
        if (file_name_length > MAX_FILE_NAME_LENGTH) {
            printf("Error: File name is too long.\n");
            exit(1);
        }

        // Open the file
        files[i].file_ptr = fopen(file_name, "r");

        // Check if the file was successfully opened
        if (files[i].file_ptr == NULL) {
            printf("Error: File could not be opened.\n");
            exit(1);
        }
    }

    // Loop through each file and read lines from the file
    for (int i = 0; i < num_files; i++) {
        while (fgets(line, MAX_LINE_LENGTH, files[i].file_ptr)!= NULL) {
            // Print the line to the console
            printf("%s", line);
        }
    }

    // Close each file
    for (int i = 0; i < num_files; i++) {
        fclose(files[i].file_ptr);
    }

    return 0;
}