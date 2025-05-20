//FormAI DATASET v1.0 Category: QR code reader ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STR_LEN 256

// Function to detect if the input string is a valid QR code
bool isQRCode(char* input)
{
    // QR codes always start with "QR:"
    if (strncmp(input, "QR:", 3) != 0)
        return false;
  
    // QR codes always end with a newline character
    int len = strlen(input);
    if (input[len-1] != '\n')
        return false;
    
    // QR codes should contain only alphanumeric characters and ':'
    for (int i = 3; i < len-1; i++)
    {
        if (!isalnum(input[i]) && input[i] != ':')
            return false;
    }
  
    return true;
}

// Function to read QR codes from file and print the contents
void readQRCodeFromFile(char* filename)
{
    FILE* fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Failed to open file: %s\n", filename);
        return;
    }

    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    while ((read = getline(&line, &len, fp)) != -1)
    {
        // Discard empty lines
        if (read <= 1)
            continue;

        // Discard non-QR code lines
        if (!isQRCode(line))
        {
            printf("Invalid QR code: %s", line);
            continue;
        }

        // Parse the QR code
        char* token = strtok(line, ":");
        token = strtok(NULL, ":");
        printf("QR code data: %s\n", token);
    }

    fclose(fp);
    if (line)
        free(line);
}

int main()
{
    char filename[MAX_STR_LEN];
    printf("Please enter the path to the QR code file: ");
    fgets(filename, MAX_STR_LEN, stdin);

    // Strip the newline character
    int len = strlen(filename);
    if (filename[len-1] == '\n')
        filename[len-1] = '\0';

    readQRCodeFromFile(filename);

    return 0;
}