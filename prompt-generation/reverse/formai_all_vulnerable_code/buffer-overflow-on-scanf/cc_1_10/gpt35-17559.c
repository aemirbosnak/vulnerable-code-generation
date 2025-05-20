//FormAI DATASET v1.0 Category: File handling ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LENGTH 100

int main()
{
    printf("This program will perform a cryptic operation on a text file!");
    char filename[MAX_LENGTH];
    printf("\nPlease enter the file name (with .txt extension): ");
    scanf("%s",filename);
    
    // try to open the file
    FILE *fptr;
    fptr = fopen(filename, "r");
    if (fptr == NULL)
    {
        printf("Error: Failed to open the file...");
        exit(1);
    }

    // count the number of characters in the file
    int char_count = 0;
    char c;
    while ((c = fgetc(fptr)) != EOF) 
    {
        char_count++;
    }

    // close the file
    fclose(fptr);

    // re-open the file in read-write mode
    fptr = fopen(filename, "r+");
    if (fptr == NULL)
    {
        printf("Error: Failed to open the file...");
        exit(1);
    }

    // perform the cryptic operation on the file data
    char encrypted_data[char_count];
    int i = 0;
    while ((c = fgetc(fptr)) != EOF)
    {
        encrypted_data[i] = c + 10;
        i++;
    }

    // go back to the beginning of the file
    rewind(fptr);

    // overwrite the original data with the encrypted data
    fwrite(encrypted_data, sizeof(char), char_count, fptr);

    // close the file
    fclose(fptr);

    printf("\nThe file has been successfully encrypted!");
    return 0;
}