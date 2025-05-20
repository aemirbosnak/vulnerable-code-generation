//FormAI DATASET v1.0 Category: File handling ; Style: bold
#include <stdio.h>
#include <stdlib.h>

int main() 
{
    // Declare variables
    FILE *fp;
    char filename[50], sentence[1000];
    int num_lines = 0;
 
    // Get filename from user input
    printf("Enter filename: ");
    scanf("%s", filename);
 
    // Open file for reading
    fp = fopen(filename, "r");
 
    // If file cannot be opened, display error message and exit program
    if (fp == NULL) 
    {
        printf("Error opening file.\n");
        exit(EXIT_FAILURE);
    }
 
    // Read each line of the file and count number of lines
    while (fgets(sentence, sizeof(sentence), fp) != NULL) 
    {
        printf("%s", sentence);
        num_lines++;
    }
 
    // Close file and print number of lines
    fclose(fp);
    printf("\nNumber of lines in file: %d\n", num_lines);
 
    // Open file for writing
    fp = fopen(filename, "a");
 
    // If file cannot be opened, display error message and exit program
    if (fp == NULL) 
    {
        printf("Error opening file.\n");
        exit(EXIT_FAILURE);
    }
 
    // Add new sentence to file
    printf("Enter new sentence: ");
    scanf(" %[^\n]s", sentence);
    fprintf(fp, "\n%s", sentence);
 
    // Close file
    fclose(fp);
 
    return 0;
}