//FormAI DATASET v1.0 Category: File handling ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char filename[100];
    FILE *fp;

    // get filename from user
    printf("Enter the filename to create: ");
    scanf("%s", filename);

    // create/open file for writing
    fp = fopen(filename, "w");
    if(fp == NULL)
    {
        printf("Error creating file!");
        exit(1);
    }

    // get user input for file content
    char content[500];
    printf("Enter the content to write in the file: ");
    fflush(stdin);
    fgets(content, 500, stdin);

    // write content to file
    fputs(content, fp);

    // close file
    fclose(fp);

    // open file for reading
    fp = fopen(filename, "r");
    if(fp == NULL)
    {
        printf("Error opening file!");
        exit(1);
    }

    // read content from file
    char buffer[500];
    fgets(buffer, 500, fp);

    printf("File content:\n%s", buffer);

    // close file
    fclose(fp);

    return 0;
}