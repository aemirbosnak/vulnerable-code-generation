//FormAI DATASET v1.0 Category: Text processing ; Style: Ada Lovelace
/* 
This program reads a text file, processes the data and stores the results in a new file. 
The user can choose to either count the number of words in the text or replace a specific word with another one.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp, *output; // file pointers
    char filename[100], new_filename[100]; // input and output file names
    int choice; // user choice
    
    // Ask user for input file name
    printf("Enter the name of the file you want to process:\n");
    scanf("%s", filename);

    // Open the input file
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Error opening file '%s'\n", filename);
        exit(1);
    }

    // Ask user for output file name
    printf("Enter the name of the output file:\n");
    scanf("%s", new_filename);

    // Open the output file
    output = fopen(new_filename, "w");
    if (output == NULL)
    {
        printf("Error creating output file '%s'\n", new_filename);
        fclose(fp);
        exit(1);
    }

    // Ask user for operation choice
    printf("What do you want to do?\n");
    printf("1 - Count the number of words in the text\n");
    printf("2 - Replace a specific word with another one\n");
    scanf("%d", &choice);

    // Count number of words in the text
    if (choice == 1)
    {
        char c;
        int count = 1; // initialize to 1 because the last word may not end with a space

        while ((c = fgetc(fp)) != EOF) // loop through each character in the file
        {
            if (c == ' ' || c == '\n') // if the character is a space or newline, increase word count
                count++;
        }

        fprintf(output, "The number of words in the text is %d\n", count); // write results to output file
    }
    // Replace a specific word with another one
    else if (choice == 2)
    {
        char search_word[100], replacement_word[100], line[500], *token;

        // Ask user for word to replace and its replacement
        printf("Enter the word you want to replace:\n");
        scanf("%s", search_word);
        printf("Enter the replacement word:\n");
        scanf("%s", replacement_word);

        // Loop through each line in the input file
        while (fgets(line, 500, fp))
        {
            // Loop through each word in the line
            token = strtok(line, " \n");
            while (token != NULL)
            {
                // If the word matches the user input, replace it
                if (strcmp(token, search_word) == 0)
                    fprintf(output, "%s ", replacement_word);
                else
                    fprintf(output, "%s ", token);

                token = strtok(NULL, " \n");
            }
            fprintf(output, "\n");
        }

        fprintf(output, "The word '%s' has been replaced with '%s'\n", search_word, replacement_word); // write results to output file
    }
    // Invalid choice
    else
    {
        printf("Invalid choice\n");
    }

    // Close the files
    fclose(fp);
    fclose(output);

    return 0;
}