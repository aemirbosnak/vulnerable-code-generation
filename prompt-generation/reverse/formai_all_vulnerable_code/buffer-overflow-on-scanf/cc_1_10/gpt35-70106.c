//FormAI DATASET v1.0 Category: File handling ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file_pointer; // Create a file pointer to handle file operations
    char filename[50], text[1000]; // Declare variables to store filename and text
    int option;

    printf("Welcome to the file handling program!\n");

    do
    {
        printf("Please select an option:\n");
        printf("1. Create a new file\n");
        printf("2. Write to an existing file\n");
        printf("3. Read from an existing file\n");
        printf("4. Exit the program\n");
        scanf("%d", &option);

        switch(option)
        {
            case 1: // Create a new file
                printf("Please enter the filename: ");
                scanf("%s", filename);
                file_pointer = fopen(filename, "w"); // Open the file for writing
                if(file_pointer == NULL)
                {
                    printf("Error! Unable to create file.\n");
                    exit(1);
                }
                else
                {
                    printf("File created successfully!\n");
                    fclose(file_pointer); // Close the file
                }
                break;

            case 2: // Write to an existing file
                printf("Please enter the filename: ");
                scanf("%s", filename);
                file_pointer = fopen(filename, "a"); // Open the file for appending
                if(file_pointer == NULL)
                {
                    printf("Error! Unable to open file.\n");
                    exit(1);
                }
                else
                {
                    printf("Please enter the text to be written to the file:\n");
                    getchar(); // Clear the input buffer
                    fgets(text, 1000, stdin); // Read the input text
                    fprintf(file_pointer, "%s", text); // Write the text to the file
                    printf("Text written to file successfully!\n");
                    fclose(file_pointer); // Close the file
                }
                break;

            case 3: // Read from an existing file
                printf("Please enter the filename: ");
                scanf("%s", filename);
                file_pointer = fopen(filename, "r"); // Open the file for reading
                if(file_pointer == NULL)
                {
                    printf("Error! Unable to open file.\n");
                    exit(1);
                }
                else
                {
                    printf("The contents of the file are:\n");
                    while(fgets(text, 1000, file_pointer) != NULL) // Read the contents of the file line by line
                    {
                        printf("%s", text); // Print the contents of the file
                    }
                    fclose(file_pointer); // Close the file
                }
                break;

            case 4: // Exit the program
                printf("Exiting the program...\n");
                break;

            default: // Invalid input
                printf("Invalid input! Please try again.\n");
                break;
        }
    }while(option != 4);

    return 0;
}