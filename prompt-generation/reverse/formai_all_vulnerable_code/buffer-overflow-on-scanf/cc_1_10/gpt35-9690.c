//FormAI DATASET v1.0 Category: Text processing ; Style: complex
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp; // file pointer to the input file
    char filename[20], searchword[20]; // inputs for filename and searchword
    char line[100]; // buffer to store text from file
    int lineno = 1, count = 0, wordfound = 0; // variables to keep track of line number, number of searchword occurrences and whether the word has been found on any line
    printf("Enter the filename: ");
    scanf("%s",filename);
    printf("Enter the search word: ");
    scanf("%s",searchword);
    fp = fopen(filename,"r"); // open the file in read mode
    if(fp == NULL) // check if file exists
    {
        printf("%s file does not exist.",filename);
        exit(0);
    }

    while(fgets(line,100,fp)) // loop through each line of the file
    {
        int i = 0, j = 0; // variables to keep track of position in the line and searchword respectively
        while(line[i] != '\0') // loop through each character in the line
        {
            if(line[i] == searchword[j]) // if the character in the line matches the searchword character
            {
                j++; // move to the next character in the searchword
                if(searchword[j] == '\0') // if all characters in the searchword have been matched
                {
                    count++; // increment number of searchword occurrences
                    wordfound = 1; // mark the word as found
                }
            }
            else
            {
                j = 0; // reset searchword position
            }
            i++; // move to the next character in the line
        }

        if(wordfound) // if the searchword was found on the line
        {
            printf("Line %d : %s",lineno,line);
            wordfound = 0; // reset flag for next line
        }

        lineno++; // move to the next line
    }

    printf("\n\n%d occurrences found.",count); // display number of occurrences found
    fclose(fp); // close the file
    return 0;
}