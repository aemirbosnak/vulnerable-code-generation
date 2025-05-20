//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: protected
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1000
#define MAX_FILE_NAME_SIZE 100

// Function to calculate the checksum of a given string
unsigned int calculate_checksum(char* input_string)
{
    unsigned int checksum = 0;
    int i;

    // Loop through each character in the input string
    for (i = 0; i < strlen(input_string); i++)
    {
        // Convert character to uppercase
        input_string[i] = toupper(input_string[i]);

        // Add the ASCII value of the character to the checksum
        checksum += (unsigned int)input_string[i];
    }

    // Return the checksum
    return checksum;
}

int main()
{
    FILE* input_file;
    char filename[MAX_FILE_NAME_SIZE];
    char input_string[MAX_LINE_SIZE];
    unsigned int checksum;

    // Prompt user to enter the name of the input file
    printf("Enter the name of the input file: ");
    scanf("%s", filename);

    // Open the input file for reading
    input_file = fopen(filename, "r");

    // Check if input file is valid
    if (input_file == NULL)
    {
        printf("Error: Input file not found.\n");
        return 1;
    }

    // Read input file line by line
    while (fgets(input_string, MAX_LINE_SIZE, input_file)!= NULL)
    {
        // Calculate the checksum of the input string
        checksum = calculate_checksum(input_string);

        // Print the input string and its corresponding checksum
        printf("Input string: %s\nChecksum: %u\n\n", input_string, checksum);
    }

    // Close the input file
    fclose(input_file);

    return 0;
}