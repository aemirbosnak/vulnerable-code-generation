//FormAI DATASET v1.0 Category: File handling ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Initialize the file pointer
    FILE *file_pointer;
    char filename[20];
    
    // Ask the user for the name of the file they want to read from or write to 
    printf("Enter the name of the file you want to process: ");
    scanf("%s", filename);
    
    // Open the file in read or write mode 
    file_pointer = fopen(filename, "w"); // File is opened in write mode
    
    // Check if the file was opened successfully
    if (file_pointer == NULL) {
        printf("Error: Cannot open file for writing\n");
        exit(1);
    }
    
    // Get input from the user and write it to the file
    printf("Enter the text to be written to the file: ");
    char input[100];
    scanf("%s", input);
    fprintf(file_pointer, input);
    
    // Close the file after writing is done
    fclose(file_pointer);

    // Open the file again, this time to read from it
    file_pointer = fopen(filename, "r"); // File is opened in read mode
    
    // Check if the file was opened successfully
    if (file_pointer == NULL) {
        printf("Error: Cannot open file for reading\n");
        exit(1);
    }
    
    // Read the contents of the file and display it on the console
    printf("The contents of the file are: ");
    char c;
    while ((c = fgetc(file_pointer)) != EOF) {
        printf("%c", c);
    }
    
    // Close the file after reading is done
    fclose(file_pointer);

    return 0;
}