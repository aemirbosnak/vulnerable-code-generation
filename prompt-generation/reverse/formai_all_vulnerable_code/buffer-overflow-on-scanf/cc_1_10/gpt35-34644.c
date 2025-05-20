//FormAI DATASET v1.0 Category: Data recovery tool ; Style: Sherlock Holmes
// Sherlock Holmes style C Data Recovery Tool Example Program
// By the famous detective coder, Sherlock Code
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 100000 // Maximum file size we can recover

// Function to recover data from a given file
int recover_file_data(char *filename, char *data)
{
    FILE *fp;
    fp = fopen(filename, "rb"); // Open file in binary mode

    if (fp == NULL) // File not found or unable to open
    {
        printf("ERROR: File not found or unable to open.\n");
        return -1;
    }

    fseek(fp, 0, SEEK_END);
    int file_size = ftell(fp); // Get file size
    rewind(fp);

    if (file_size > MAX_FILE_SIZE) // If file size is too large
    {
        fclose(fp); // Close file
        printf("ERROR: File size is too large.\n");
        return -1;
    }

    fread(data, file_size, 1, fp); // Read file data into buffer
    fclose(fp); // Close file
    printf("Data has been recovered successfully!\n");
    return 0;
}

// Main function to recover data from a lost file
int main()
{
    char filename[100]; // To store lost file name
    char recovered_data[MAX_FILE_SIZE]; // To store recovered data
    int i;

    printf("Detective Coder, Sherlock Code here to help you recover lost data!\n");
    printf("Please enter the name of your lost file: ");
    scanf("%s", filename);

    if (recover_file_data(filename, recovered_data) == -1) // Unable to recover data
    {
        printf("Unable to recover data. Sorry, could not help you this time!\n");
        return 0;
    }

    // Display recovered data
    printf("Recovered data: \n");
    for (i = 0; i < strlen(recovered_data); i++)
    {
        printf("%c", recovered_data[i]);
    }
    printf("\n");
    return 0;
}