//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char file_name[100];
    printf("Enter the file name: ");
    scanf("%s", file_name);

    FILE *fp = fopen(file_name, "rb");

    if(fp == NULL)
    {
        printf("Error: Unable to open file!\n");
        return 1;
    }

    printf("Extracting metadata from %s...\n", file_name);

    char metadata[50];
    fseek(fp, 0, SEEK_END);
    long int file_size = ftell(fp);
    fseek(fp, -50, SEEK_END);
    fread(metadata, sizeof(char), 50, fp);

    printf("Metadata found: %s\n", metadata);

    printf("Analyzing metadata...\n");

    int num_bytes = 0;

    for(int i = 0; i < 50; i++)
    {
        if(metadata[i] == '0' || metadata[i] == '1')
        {
            num_bytes++;
        }
        else if(metadata[i] == 'X')
        {
            printf("WARNING: Corrupted metadata detected!\n");
            break;
        }
    }

    printf("%d bytes of metadata contains binary data.\n", num_bytes);
    printf("%d bytes of metadata is unused.\n", 50 - num_bytes);

    fclose(fp);
    return 0;
}