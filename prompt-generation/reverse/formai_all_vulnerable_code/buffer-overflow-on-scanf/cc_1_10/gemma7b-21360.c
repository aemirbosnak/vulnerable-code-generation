//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_SIZE 1024

typedef struct FileEntry
{
    char filename[256];
    int size;
    time_t timestamp;
} FileEntry;

int main()
{
    FILE *fp;
    FileEntry fileEntries[100];
    int numEntries = 0;
    char backupDir[256];

    printf("Welcome to the C File Backup System!\n");

    // Get the current directory and set the backup directory
    getcwd(backupDir, sizeof(backupDir));
    backupDir[strlen(backupDir)] = '\0';
    strcat(backupDir, "/backup");

    // Create a new file entry
    FileEntry newEntry;
    newEntry.size = MAX_FILE_SIZE;
    newEntry.timestamp = time(NULL);

    // Loop to get the file name and size
    printf("Enter file name: ");
    scanf("%s", newEntry.filename);

    printf("Enter file size (in KB): ");
    scanf("%d", &newEntry.size);

    // Add the file entry to the array
    fileEntries[numEntries++] = newEntry;

    // Save the file entries to a file
    fp = fopen("fileEntries.dat", "w");
    fwrite(fileEntries, sizeof(FileEntry) * numEntries, 1, fp);
    fclose(fp);

    // Print a confirmation message
    printf("File entry saved successfully!\n");

    return 0;
}