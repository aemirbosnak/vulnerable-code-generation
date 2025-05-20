//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to extract metadata from file
void extract_metadata(char* file_name)
{
    FILE *file = fopen(file_name, "r"); // open file in read mode

    if(file == NULL) // check if file exists
    {
        printf("File not found!");
        return;
    }

    char line[256]; // array to hold each line of the file
    char metadata[256]; // array to hold extracted metadata
    int found_metadata = 0; // flag to indicate if metadata has been found
    int line_num = 0; // counter for line number

    while(fgets(line, sizeof(line), file)) // loop through each line of the file
    {
        line_num++; // increment line number

        if(line[0] == '#' && !found_metadata) // check if line starts with #
        {
            found_metadata = 1; // set metadata flag to true
            strcpy(metadata, line); // copy metadata to metadata array
        }
        else if(line[0] == '#' && found_metadata) // check if line starts with # after metadata has been found
        {
            printf("Multiple metadata found on line %d!", line_num); // print error message
            return;
        }
    }
    fclose(file); // close file

    if(found_metadata) // check if metadata was found
    {
        printf("Metadata found: %s", metadata); // print metadata
    }
    else
    {
        printf("Metadata not found!"); // print error message
    }
}

int main()
{
    char file_name[256]; // array to hold file name

    printf("Enter file name: ");
    scanf("%s", file_name); // get file name from user

    extract_metadata(file_name); // call function to extract metadata

    return 0;
}