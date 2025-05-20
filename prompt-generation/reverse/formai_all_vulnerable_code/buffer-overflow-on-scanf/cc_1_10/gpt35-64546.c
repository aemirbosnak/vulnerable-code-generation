//FormAI DATASET v1.0 Category: File handling ; Style: curious
#include <stdio.h>

int main(){
    printf("Welcome to the File Handling Program\n");
    char file_name[20];
    printf("Enter the file name: ");
    scanf("%s", file_name);

    // Open the file in write mode
    FILE *fptr;
    fptr = fopen(file_name, "w");

    if (fptr == NULL){
        printf("Error opening file!");
        return 1;
    }

    printf("File opened successfully!\n\n");

    // Ask for user input
    char input[50];
    printf("Enter some text to write to the file: ");
    scanf(" %[^\n]", input);

    // Write to file
    fputs(input, fptr);
    printf("Successfully wrote to file: %s\n", file_name);
    
    // Close the file
    fclose(fptr);

    // Open the file in read mode
    fptr = fopen(file_name, "r");

    if (fptr == NULL){
        printf("Error opening file!");
        return 1;
    }

    // Read from file
    printf("\nPrinting contents of file:\n");
    char read_char = fgetc(fptr);
    while (read_char != EOF){
        printf("%c", read_char);
        read_char = fgetc(fptr);
    }

    // Close the file
    fclose(fptr);

    printf("\n\nEnd of Program");

    return 0;
}