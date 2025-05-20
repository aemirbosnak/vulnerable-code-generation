//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    system("clear");

    // Define a directory for backups
    char backupDir[256] = "/home/backup";

    // Create a timestamp for the backup file
    time_t t = time(NULL);
    char timestamp[26] = "";
    strftime(timestamp, 26, "%Y-%m-%d_%H-%M-%S", localtime(&t));

    // Get the file name from the user
    char filename[256] = "";
    printf("Enter the file name: ");
    scanf("%s", filename);

    // Create a full path for the backup file
    char backupPath[512] = "";
    snprintf(backupPath, 512, "%s/%s_%s.bak", backupDir, filename, timestamp);

    // Open the file in read mode
    FILE *fp = fopen(filename, "r");

    // If the file is opened successfully, copy it to the backup file
    if (fp)
    {
        // Create a buffer for data transfer
        char buffer[4096] = "";

        // Read data from the file in chunks
        int readBytes = 0;
        while ((readBytes = fread(buffer, 1, 4096, fp)) > 0)
        {
            // Write the data to the backup file
            fwrite(buffer, 1, readBytes, fopen(backupPath, "ab"));
        }

        // Close the file
        fclose(fp);

        // Print a confirmation message
        printf("File successfully backed up to %s\n", backupPath);
    }
    else
    {
        // Print an error message
        printf("Error backing up file: %s\n", filename);
    }

    return 0;
}