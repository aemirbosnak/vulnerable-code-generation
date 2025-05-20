//FormAI DATASET v1.0 Category: Error handling ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

// Our custom error handling function that prints an error message
void handle_error(const char* err_message) {
    printf("Error: %s\n", err_message);
    exit(1);
}

int main() {

    // Initialize our counter to 0
    int counter = 0;

    // Attempt to open a file
    FILE* file = fopen("nonexistent_file.txt", "r");
    
    // Check if the file opened successfully
    if (file == NULL) {
        
        // If not, call our error handling function
        handle_error("Could not open file");
    }

    // Read in the first value from the file and increment our counter
    int value;
    if (fscanf(file, "%d", &value) != 1) {
        // If we couldn't read the value, call our error handling function
        handle_error("Could not read from file");
    }
    counter++;

    // Read in the second value from the file and increment our counter
    if (fscanf(file, "%d", &value) != 1) {
        // If we couldn't read the value, call our error handling function
        handle_error("Could not read from file");
    }
    counter++;

    // Close the file
    if (fclose(file) != 0) {
        // If we couldn't close the file, call our error handling function
        handle_error("Could not close file");
    }

    // If the counter is not 2, something went wrong. Call the error handling function.
    if (counter != 2) {
        handle_error("Unexpected error occurred");
    }

    // If we made it this far, everything worked correctly!
    printf("Successfully read 2 integers from file\n");
    return 0;
}