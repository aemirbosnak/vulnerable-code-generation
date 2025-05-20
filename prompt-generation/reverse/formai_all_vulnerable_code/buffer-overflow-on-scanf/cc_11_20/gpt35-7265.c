//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i, j, k, counter = 0;
    char filename[50];
    printf("Enter file name to scan: ");
    scanf("%s", filename);

    FILE *fp;
    fp = fopen(filename, "rb");
    if(fp == NULL)
    {
        printf("Error: Could not open file %s\n", filename);
        return 1;
    }
    
    fseek(fp, 0L, SEEK_END);
    int filesize = ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    char *buffer = (char*)malloc(filesize);
    memset(buffer, 0, filesize);
    fread(buffer, 1, filesize, fp);

    for(i=0; i<(filesize-3); i++)
    {
        if(buffer[i]=='+' && buffer[i+1]=='+' && buffer[i+2]=='+' && buffer[i+3]=='+')
        {
            counter++;
            printf("Found '++++' at position %d\n", i);
        }

        if(buffer[i]=='-' && buffer[i+1]=='-' && buffer[i+2]=='-' && buffer[i+3]=='-')
        {
           counter++;
           printf("Found '----' at position %d\n", i);
        }

        if(counter >= 3)
        {
            printf("\nFile %s is infected!\n", filename);
            fclose(fp);
            free(buffer);
            return 1;
        }
    }

    printf("\nFile %s is clean!\n", filename);
    fclose(fp);
    free(buffer);

    return 0; 
}