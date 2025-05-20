//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: invasive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void backup_system(char *filename)
{
    FILE *fp;
    char *buffer;
    int size = 0, i = 0;

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Error opening file: %s\n", filename);
        return;
    }

    // Calculate file size
    while (fscanf(fp, "%c", buffer) != EOF)
    {
        size++;
    }

    // Allocate memory for buffer
    buffer = (char *)malloc(size);

    // Read file contents into buffer
    fp = fopen(filename, "r");
    while (fscanf(fp, "%c", buffer) != EOF)
    {
        i++;
    }

    // Write buffer to a new file
    FILE *fp2 = fopen("backup.txt", "w");
    fprintf(fp2, "%s", buffer);
    fclose(fp2);

    // Free memory
    free(buffer);
    fclose(fp);

    printf("File %s successfully backed up to backup.txt\n", filename);
}

int main()
{
    char filename[256];

    printf("Enter the filename: ");
    scanf("%s", filename);

    backup_system(filename);

    return 0;
}