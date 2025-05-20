//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of characters allowed in a single field
#define MAX_FIELD_LENGTH 50

// Define the maximum number of fields allowed in a single row
#define MAX_FIELDS 10

/**
 * The main function that reads a CSV file and prints its contents to the console
 */
int main()
{
    printf("Welcome to the CSV Reader program!\n\n");

    // First, prompt the user to enter the name of the CSV file they want to read
    printf("Please enter the name of the CSV file: ");
    char filename[100];
    scanf("%s", filename);

    // Open the file using the filename provided by the user
    FILE* file = fopen(filename, "r");

    // If the file cannot be opened, print an error message and terminate the program
    if (file == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        return 1;
    }

    printf("\nFile opened successfully!\n");

    // We will use the getline function to read each line of the file
    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    // Initialize an array to store the fields in each row
    char fields[MAX_FIELDS][MAX_FIELD_LENGTH];

    // Loop through each line of the file
    while ((read = getline(&line, &len, file)) != -1) {

        // Initialize a counter to keep track of the current field in the row
        int field_index = 0;

        // Split the line into fields using strtok
        char* token = strtok(line, ",");

        // Loop through each field in the row
        while (token != NULL && field_index < MAX_FIELDS) {
            // Copy the field into the fields array
            strncpy(fields[field_index], token, MAX_FIELD_LENGTH);
            // Replace the newline character at the end with a null terminator
            int field_length = strlen(fields[field_index]);
            if (fields[field_index][field_length - 1] == '\n') {
                fields[field_index][field_length - 1] = '\0';
            }
            // Get the next field in the row
            token = strtok(NULL, ",");
            // Increment the field index
            field_index++;
        }

        // Print the fields in the current row
        for (int i = 0; i < field_index; i++) {
            printf("%s", fields[i]);
            if (i < field_index - 1) {
                printf(",");
            }
        }
        printf("\n");
    }

    // Close the file and free the memory used by the getline function
    fclose(file);
    if (line) {
        free(line);
    }

    printf("\nFile read successfully!\n");

    // Exit the program with a success status code
    return 0;
}