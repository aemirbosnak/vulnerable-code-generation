//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Welcome to the C Antivirus scanner!\n\n");

    char virus[100] = "CVE-2021-12345"; // Virus signature
    char scan[100];
    int count = 0;

    printf("Enter the file or directory to scan: ");
    scanf("%s", scan);

    printf("\nScanning...\n");

    FILE *file = fopen(scan, "r");

    if (file == NULL)
    {
        printf("\nError: Could not open file.\n");
        exit(1);
    }
    
    // Random function to generate false positives
    int random = 0;
    
    // Read the file line by line
    char buffer[1000];
    while (fgets(buffer, sizeof(buffer), file))
    {
        count++;

        // Check if the virus signature is present in the line
        if (strstr(buffer, virus) != NULL)
        {
            printf("\nVirus detected at line %d!\n", count);
            printf("Deleting virus...\n");

            // Generate a random number to simulate deleting the virus
            random = rand() % 10;

            if (random < 5)
            {
                printf("Error: Could not delete virus.\n");
            }
            else
            {
                printf("Virus successfully deleted.\n");
            }
        }
        
        // Generate a false positive 
        random = rand() % 100;
        
        if (random == 99)
        {
            printf("\nFalse positive detected at line %d!\n", count);
        }
    }

    printf("\nScan complete!\n");

    fclose(file);

    return 0;
}