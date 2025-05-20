//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to extract metadata from C source code
void c_metadata_extractor(char *filename) {
    FILE *file = fopen(filename, "r");  // Open the file in read mode
    char line[1000];  // To store each line while reading the file
    int num_lines = 0;  // To count the total number of lines in the file
    int num_comments = 0;  // To count the total number of comments in the file
    int num_vars = 0;  // To count the total number of variables in the file
    int num_functions = 0;  // To count the total number of functions in the file

    if (file == NULL) {  // If file is empty
        printf("Error: File %s does not exist or could not be opened.\n", filename);
        exit(1);
    }

    while (fgets(line, sizeof(line), file)) {  // Read each line of the file
        num_lines++;  // Increment the number of lines counter

        if (strstr(line, "/*") != NULL) {  // If the line contains a comment block
            num_comments++;  // Increment the number of comments counter
        }

        if (strstr(line, "//") != NULL) {  // If the line contains a comment
            num_comments++;  // Increment the number of comments counter
        }

        if (strstr(line, "int ") != NULL) {  // If the line contains an integer variable declaration
            num_vars++;  // Increment the number of variables counter
        }

        if (strstr(line, "float ") != NULL) {  // If the line contains a float variable declaration
            num_vars++;  // Increment the number of variables counter
        }

        if (strstr(line, "double ") != NULL) {  // If the line contains a double variable declaration
            num_vars++;  // Increment the number of variables counter
        }

        if (strstr(line, "char ") != NULL) {  // If the line contains a character variable declaration
            num_vars++;  // Increment the number of variables counter
        }

        if (strstr(line, "(") != NULL && strstr(line, ")") != NULL) {  // If the line contains parentheses
            if (strstr(line, "int ") != NULL ||
                strstr(line, "float ") != NULL ||
                strstr(line, "double ") != NULL ||
                strstr(line, "char ") != NULL) {  // If the line contains variable declaration inside parentheses
                continue; // Do nothing and move on to the next line
            }
            num_functions++;  // Increment the number of functions counter
        }
    }

    fclose(file);  // Close the file after reading

    printf("Total number of lines in file: %d\n", num_lines);
    printf("Total number of comments in file: %d\n", num_comments);
    printf("Total number of variables in file: %d\n", num_vars);
    printf("Total number of functions in file: %d\n", num_functions);
}

int main() {
    char filename[100];

    printf("Enter the name of the C source code file: ");
    scanf("%s", filename);

    c_metadata_extractor(filename);  // Call the metadata extraction function

    return 0;
}