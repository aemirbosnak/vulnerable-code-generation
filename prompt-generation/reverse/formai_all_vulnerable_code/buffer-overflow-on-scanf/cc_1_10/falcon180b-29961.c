//Falcon-180B DATASET v1.0 Category: File handling ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

// Function prototypes
void read_file(FILE *file, char *buffer);
void write_file(FILE *file);
int count_words(char *buffer);
void reverse_string(char *buffer);

int main()
{
    FILE *input_file;
    FILE *output_file;
    char input_filename[MAX_LINE_LENGTH];
    char output_filename[MAX_LINE_LENGTH];
    char buffer[MAX_LINE_LENGTH];

    // Get input filename from user
    printf("Enter input filename: ");
    scanf("%s", input_filename);

    // Open input file for reading
    input_file = fopen(input_filename, "r");
    if (input_file == NULL)
    {
        printf("Error opening input file.\n");
        exit(1);
    }

    // Get output filename from user
    printf("Enter output filename: ");
    scanf("%s", output_filename);

    // Open output file for writing
    output_file = fopen(output_filename, "w");
    if (output_file == NULL)
    {
        printf("Error opening output file.\n");
        exit(1);
    }

    // Read input file and write to output file
    while (fgets(buffer, MAX_LINE_LENGTH, input_file)!= NULL)
    {
        // Reverse the string
        reverse_string(buffer);

        // Count the number of words in the string
        int num_words = count_words(buffer);

        // Write the string and number of words to the output file
        fprintf(output_file, "%s (%d words)\n", buffer, num_words);
    }

    // Close input and output files
    fclose(input_file);
    fclose(output_file);

    return 0;
}

// Function to read a line from a file
void read_file(FILE *file, char *buffer)
{
    if (fgets(buffer, MAX_LINE_LENGTH, file) == NULL)
    {
        printf("Error reading file.\n");
        exit(1);
    }
}

// Function to write a line to a file
void write_file(FILE *file)
{
    if (fputs("", file) == EOF)
    {
        printf("Error writing file.\n");
        exit(1);
    }
}

// Function to count the number of words in a string
int count_words(char *buffer)
{
    int num_words = 0;
    char *word;

    // Loop through the string, counting words
    word = strtok(buffer, " ");
    while (word!= NULL)
    {
        num_words++;
        word = strtok(NULL, " ");
    }

    return num_words;
}

// Function to reverse a string
void reverse_string(char *buffer)
{
    char *start = buffer;
    char *end = buffer + strlen(buffer) - 1;

    // Reverse the string
    while (start < end)
    {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}