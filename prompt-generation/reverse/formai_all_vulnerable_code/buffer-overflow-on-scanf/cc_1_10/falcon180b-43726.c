//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to split a string into tokens based on a delimiter
void split(char *str, char delimiter, char ***tokens) {
    char *token;
    int count = 0;

    // Count the number of tokens in the string
    while (*str) {
        if (*str == delimiter) {
            count++;
        }
        str++;
    }

    // Allocate memory for the tokens array and set initial values
    *tokens = (char **)malloc(count * sizeof(char *));
    for (int i = 0; i < count; i++) {
        (*tokens)[i] = NULL;
    }

    // Split the string into tokens and store them in the array
    token = strtok(str, delimiter);
    while (token!= NULL) {
        (*tokens)[count - 1] = token;
        token = strtok(NULL, delimiter);
        count--;
    }
}

// Function to read a CSV file and print its contents
void read_csv_file(FILE *file, int num_columns) {
    char line[1024];
    char **tokens;

    // Read each line of the file and split it into tokens
    while (fgets(line, sizeof(line), file)!= NULL) {
        split(line, ',', &tokens);

        // Print the tokens in a formatted manner
        for (int i = 0; i < num_columns; i++) {
            if (tokens[i]!= NULL) {
                printf("%s ", tokens[i]);
            } else {
                printf("NULL ");
            }
        }
        printf("\n");

        // Free the memory allocated for the tokens array
        for (int i = 0; i < num_columns; i++) {
            free(tokens[i]);
        }
        free(tokens);
    }
}

int main() {
    FILE *file;
    char filename[100];

    // Prompt the user to enter the name of the CSV file
    printf("Enter the name of the CSV file: ");
    scanf("%s", filename);

    // Open the CSV file for reading
    file = fopen(filename, "r");

    // Check if the file was opened successfully
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Read the first line of the file to determine the number of columns
    char first_line[1024];
    if (fgets(first_line, sizeof(first_line), file) == NULL) {
        printf("Error reading first line of file.\n");
        return 1;
    }
    int num_columns = 0;
    for (int i = 0; i < strlen(first_line); i++) {
        if (first_line[i] == ',') {
            num_columns++;
        }
    }

    // Read the contents of the CSV file and print them
    read_csv_file(file, num_columns);

    // Close the CSV file
    fclose(file);

    return 0;
}