//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Surprise! Welcome to the C Antivirus Scanner Program!\n");
    printf("Please input the directory path you want to scan: ");
    char path[100];
    scanf("%s", path);
    printf("\nScanning...\n");
    printf("==================================================\n");

    // Scan each file in the directory
    char command[100]; // For executing system command
    sprintf(command, "ls -p %s | grep -v /", path);
    FILE* fp = popen(command, "r");
    if (fp == NULL)
    {
        printf("Error: failed to execute system command. Program terminated.\n");
        exit(1);
    }
    char filename[100];
    while (fgets(filename, 100, fp) != NULL)
    {
        // Remove newline character and check if file is executable
        filename[strcspn(filename, "\n")] = 0;
        sprintf(command, "file %s%s | grep -o executable", path, filename);
        FILE* fp2 = popen(command, "r");

        // If file is executable, scan for virus
        if (fp2 != NULL && fgets(command, 100, fp2) != NULL)
        {
            printf("Found executable file: %s%s\n", path, filename);
            printf("Scanning for viruses...\n");

            // Open file and read its contents
            FILE* fp3 = fopen(filename, "r");
            if (fp3 == NULL)
            {
                printf("Error: failed to open file %s%s\n", path, filename);
                exit(1);
            }
            char* buffer = (char*) malloc(1001);
            memset(buffer, 0, 1001);
            fread(buffer, sizeof(char), 1000, fp3);

            // Check for known virus signatures in file
            if (strstr(buffer, "trojan.horse") != NULL)
                printf("Virus found in %s%s: trojan.horse\n", path, filename);
            else if (strstr(buffer, "worm.w32") != NULL)
                printf("Virus found in %s%s: worm.w32\n", path, filename);
            else if (strstr(buffer, "rootkit.0day") != NULL)
                printf("Virus found in %s%s: rootkit.0day\n", path, filename);
            else
                printf("No virus found in %s%s\n", path, filename);

            free(buffer);
            fclose(fp3);
        }
        else
            printf("File %s%s is not executable or does not exist.\n", path, filename);
    }

    pclose(fp);
    printf("==================================================\n");
    printf("Done scanning. Thank you for using this program!\n");
    return 0;
}