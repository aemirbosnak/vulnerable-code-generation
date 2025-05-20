//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: curious
#include<stdio.h>
#include<string.h>

int main()
{
    char fileName[20];
    int i, j, k, count = 0;

    printf("Enter file name: ");
    scanf("%s", fileName);

    printf("\nScanning %s for viruses...\n", fileName);

    // Checking for file extension
    char *extension = strrchr(fileName, '.');
    if (extension == NULL)
    {
        printf("File extension missing. Aborting scan...\n");
        return 0;
    }

    // Checking for valid file extension
    char *validExtensions[5] = {".exe", ".dll", ".bat", ".com", ".vbs"};
    for (i = 0; i < 5; i++)
    {
        if (strcmp(extension, validExtensions[i]) == 0)
        {
            printf("Valid file extension. Scanning file...\n");
            count++;
            break;
        }
    }

    if (count == 0)
    {
        printf("Invalid file extension. Aborting scan...\n");
        return 0;
    }

    // Opening file in read-mode
    FILE *fptr = fopen(fileName, "r");
    if (fptr == NULL)
    {
        printf("Error opening file. Aborting scan...\n");
        return 0;
    }

    // Checking for virus signatures
    char *virusSignatures[5] = {"trojan", "worm", "spyware", "adware", "virus"};
    char ch;
    char word[20];
    i = 0;
    j = 0;
    while ((ch = fgetc(fptr)) != EOF)
    {
        if (ch != ' ' && ch != '\n' && ch != '\r' && ch != '\t' && ch != '.' && ch != ',' && ch != ':' && ch != ';')
        {
            word[i] = ch;
            i++;
        }
        else
        {
            word[i] = '\0';

            for (k = 0; k < 5; k++)
            {
                if (strcmp(virusSignatures[k], word) == 0)
                {
                    printf("Virus signature detected: %s\n", word);
                    printf("File contains virus. Aborting scan...\n");
                    fclose(fptr);
                    return 0;
                }
            }

            i = 0;
        }
    }

    printf("File scanned successfully. No viruses detected.\n");
    fclose(fptr);

    return 0;
}