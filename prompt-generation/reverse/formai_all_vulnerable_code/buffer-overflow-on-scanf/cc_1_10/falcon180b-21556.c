//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Function to extract metadata from a C program
void extract_metadata(char *file_name) {
    FILE *file;
    char line[1000];
    char *token;
    bool in_comment = false;
    int num_functions = 0;
    int num_structs = 0;
    int num_variables = 0;

    // Open the file for reading
    file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Error: Unable to open file '%s'\n", file_name);
        exit(1);
    }

    // Loop through each line in the file
    while (fgets(line, sizeof(line), file)!= NULL) {
        // Check if the line is a comment
        if (line[0] == '/' && line[1] == '/') {
            in_comment = true;
        } else if (line[0] == '*' && line[1] == '/') {
            in_comment = false;
        }

        // If the line is not a comment, extract metadata
        if (!in_comment) {
            // Extract function definitions
            if (strstr(line, "int main()")!= NULL) {
                num_functions++;
            } else if (strstr(line, "int")!= NULL && strstr(line, "(")!= NULL) {
                num_functions++;
            }

            // Extract struct definitions
            if (strstr(line, "struct")!= NULL) {
                num_structs++;
            }

            // Extract variable definitions
            if (strstr(line, "int")!= NULL &&!strstr(line, "=")) {
                num_variables++;
            }
        }
    }

    // Print the metadata
    printf("Number of functions: %d\n", num_functions);
    printf("Number of structs: %d\n", num_structs);
    printf("Number of variables: %d\n", num_variables);

    // Close the file
    fclose(file);
}

int main() {
    char file_name[100];

    // Prompt the user for the name of the C program to extract metadata from
    printf("Enter the name of the C program: ");
    scanf("%s", file_name);

    // Extract metadata from the C program
    extract_metadata(file_name);

    return 0;
}