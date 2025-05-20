//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: lively
#include <stdio.h>  // Importing standard input and output library
#include <string.h> // Importing string library

int main()
{
    char filename[50], signature[50];
    int virusflag = 0;

    // Get the name of the file to be scanned from the user
    printf("Enter the name of the file to be scanned: ");
    scanf("%s", filename);

    // Get the signature of the virus from the user
    printf("Enter the virus signature: ");
    scanf("%s", signature);

    // Open the file for scanning
    FILE *fp;
    fp = fopen(filename, "r");

    // Check if the file is opened successfully
    if (fp == NULL)
    {
        printf("Error: Could not open the file\n");
        return 1;
    }

    // Read the contents of the file
    char filecontent[1000];
    fgets(filecontent, 1000, fp);

    // Check if the virus signature is present in the file
    if (strstr(filecontent, signature) != NULL)
    {
        printf("Virus Found!\n");
        virusflag = 1;
    }
    else
    {
        printf("File is clean\n");
    }

    // Close the file
    fclose(fp);

    // Display the result of the scan
    if (virusflag == 1)
    {
        printf("Your system has been infected by the virus.\n");
        printf("Action recommended: Take immediate action to remove the virus.\n");
    }
    else
    {
        printf("No virus was found in the file.\n");
        printf("Your system is safe.\n");
    }

    return 0;
}