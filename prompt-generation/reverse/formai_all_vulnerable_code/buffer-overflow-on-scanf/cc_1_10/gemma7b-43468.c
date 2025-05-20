//Gemma-7B DATASET v1.0 Category: Intrusion detection system ; Style: portable
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

#define LOG_FILE "intrusion_log.txt"

int main()
{
    char filename[256];
    FILE *fp;

    // Log file initialization
    fp = fopen(LOG_FILE, "a");
    if (fp == NULL)
    {
        perror("Error opening log file");
        return 1;
    }

    // Monitoring loop
    while (1)
    {
        // Get the filename
        printf("Enter the filename: ");
        scanf("%s", filename);

        // Check if the file exists
        if (stat(filename, NULL) == -1)
        {
            fprintf(fp, "Error: File does not exist.\n");
            continue;
        }

        // Check if the file is executable
        if (!access(filename, X_OK))
        {
            fprintf(fp, "Error: File is executable.\n");
            continue;
        }

        // Check if the file is a script
        if (string_contains(filename, ".sh"))
        {
            fprintf(fp, "Error: File is a script.\n");
            continue;
        }

        // File is safe, log it
        fprintf(fp, "File: %s is safe.\n", filename);
    }

    fclose(fp);
    return 0;
}

int string_contains(const char *str, const char *substr)
{
    return strstr(str, substr) != NULL;
}