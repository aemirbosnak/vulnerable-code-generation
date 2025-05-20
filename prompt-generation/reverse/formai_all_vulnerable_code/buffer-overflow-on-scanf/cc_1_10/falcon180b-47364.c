//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_FILE_NAME 256

// Function to read data from file
void read_data(FILE *fp, char *buffer)
{
    int count = 0;
    while ((count = fread(buffer, 1, MAX_FILE_NAME, fp)) > 0)
    {
        buffer[count] = '\0';
        printf("%s", buffer);
    }
}

// Function to write data to file
void write_data(FILE *fp, char *buffer)
{
    fwrite(buffer, strlen(buffer), 1, fp);
}

// Function to recover data from corrupted file
void recover_data(char *file_name)
{
    FILE *fp;
    char buffer[MAX_FILE_NAME];

    // Open the file in read mode
    fp = fopen(file_name, "rb");
    if (fp == NULL)
    {
        printf("Error opening file %s\n", file_name);
        exit(1);
    }

    // Read data from file
    read_data(fp, buffer);

    // Close the file
    fclose(fp);

    // Open the file in write mode
    fp = fopen(file_name, "wb");
    if (fp == NULL)
    {
        printf("Error opening file %s\n", file_name);
        exit(1);
    }

    // Write data to file
    write_data(fp, buffer);

    // Close the file
    fclose(fp);
}

// Function to check if file is corrupted
int is_corrupted(char *file_name)
{
    FILE *fp;
    char buffer[MAX_FILE_NAME];

    // Open the file in read mode
    fp = fopen(file_name, "rb");
    if (fp == NULL)
    {
        return 1;
    }

    // Read data from file
    read_data(fp, buffer);

    // Close the file
    fclose(fp);

    // Check if data is readable
    if (buffer[0] == '\0')
    {
        return 1;
    }

    return 0;
}

int main()
{
    char file_name[MAX_FILE_NAME];

    // Get file name from user
    printf("Enter the name of the file to be recovered: ");
    scanf("%s", file_name);

    // Check if file is corrupted
    if (is_corrupted(file_name))
    {
        printf("File is corrupted!\n");
        recover_data(file_name);
    }
    else
    {
        printf("File is not corrupted!\n");
    }

    return 0;
}