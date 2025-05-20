//Gemma-7B DATASET v1.0 Category: File handling ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void file_operations(char *filename)
{
    FILE *fp = NULL;
    char data[1024];

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        perror("Error opening file");
        exit(1);
    }

    printf("File contents:");
    while (fgets(data, 1024, fp) != NULL)
    {
        printf("%s", data);
    }

    fclose(fp);

    printf("\n");
    printf("Enter data to write:");
    fgets(data, 1024, stdin);

    fp = fopen(filename, "w");
    if (fp == NULL)
    {
        perror("Error writing to file");
        exit(1);
    }

    fprintf(fp, "%s", data);

    fclose(fp);

    printf("Data written successfully!\n");
}

int main()
{
    char filename[256];

    printf("Enter file name:");
    scanf("%s", filename);

    file_operations(filename);

    return 0;
}