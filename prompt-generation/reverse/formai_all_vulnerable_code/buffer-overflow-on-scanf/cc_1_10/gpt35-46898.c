//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024

// Function to generate a unique digital watermark using a given secret key
void generate_digital_watermark(char *key, char *watermark)
{
    // Declare variables
    int i, j, len_key, len_watermark;
    char temp[MAX_FILE_SIZE];

    // Get the lengths of key and watermark
    len_key = strlen(key);
    len_watermark = strlen(watermark);

    // Generate digital watermark
    for(i = 0; i < len_watermark; i++)
    {
        for(j = 0; j < len_key; j++)
        {
            sprintf(temp, "%d", (int)watermark[i] ^ (int)key[j]);
            strcat(watermark, temp);
            memset(temp, 0, sizeof(temp));
        }
    }
}

// Function to verify the authenticity of a file using a given digital watermark and secret key
void verify_file_authenticity(char *filename, char *key, char *watermark)
{
    // Declare variables
    FILE *fp;
    int i, j, k, len_key, len_watermark, len_file;
    char file_data[MAX_FILE_SIZE], temp[MAX_FILE_SIZE];

    // Open file for reading
    fp = fopen(filename, "r");

    // Check if file exists
    if(fp == NULL)
    {
        printf("Error: File not found!\n");
        exit(1);
    }

    // Read file data
    len_file = fread(file_data, 1, MAX_FILE_SIZE, fp);
    file_data[len_file] = '\0';

    // Get the lengths of key, watermark and file data
    len_key = strlen(key);
    len_watermark = strlen(watermark);

    // Generate digital watermark from file data
    generate_digital_watermark(key, temp);

    // Compare generated digital watermark with given digital watermark
    if(strcmp(temp, watermark) == 0)
    {
        // Print message indicating file authenticity
        printf("File is authentic!\n");
    }
    else
    {
        // Print message indicating file tampering
        printf("File has been tampered with!\n");
    }

    // Close file
    fclose(fp);
}

int main()
{
    // Declare variables
    char filename[50], key[50], watermark[MAX_FILE_SIZE];

    // Get filename from user
    printf("Enter filename: ");
    scanf("%s", filename);

    // Get secret key from user
    printf("Enter secret key: ");
    scanf("%s", key);

    // Get digital watermark from user
    printf("Enter digital watermark: ");
    scanf("%s", watermark);

    // Verify authenticity of file
    verify_file_authenticity(filename, key, watermark);

    return 0;
}