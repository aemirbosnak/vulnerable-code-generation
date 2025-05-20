//FormAI DATASET v1.0 Category: File handling ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file_ptr;
    char filename[50], text[100];

    // Get the file name from the user
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Open the file
    file_ptr = fopen(filename, "w");

    // Check if the file was opened successfully
    if (file_ptr == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    // Get text input from the user
    printf("Enter some text: ");
    scanf("%s", text);

    // Write the text to the file
    fprintf(file_ptr, "%s", text);

    // Close the file
    fclose(file_ptr);

    // Re-open the file to read the contents
    file_ptr = fopen(filename, "r");

    // Check if the file was opened successfully
    if (file_ptr == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    // Read the contents of the file and print it to the screen
    printf("Contents of file %s:\n", filename);
    while (fgets(text, sizeof(text), file_ptr)) {
        printf("%s", text);
    }

    // Close the file
    fclose(file_ptr);

    return 0;
}