//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void scan(char *filename);
void removeVirus(char *filename, char *virus);

int main()
{
    char filename[100];
    printf("Enter the name of the file to scan: ");
    scanf("%s", filename);

    printf("\nScanning %s....\n", filename);
    scan(filename);

    return 0;
}

void scan(char *filename)
{
    FILE *fp;
    char buffer[10000];
    fp = fopen(filename, "rb");
    if(fp == NULL)
    {
        printf("Could not open file!\n");
        exit(1);
    }

    fread(buffer, sizeof(buffer), 1, fp);
    fclose(fp);

    char *virus = "malware";
    if(strstr(buffer, virus))
    {
        printf("Malware detected!\nWould you like to remove it? (y/n) ");
        char response;
        scanf("%s", &response);
        if(response == 'y')
        {
            removeVirus(filename, virus);
        }
        else
        {
            printf("File not cleaned!\n");
        }
        
    }
    else
    {
        printf("File is clean!\n");
    }
}

void removeVirus(char *filename, char *virus)
{
    FILE *fp;
    char buffer[10000];
    fp = fopen(filename, "rb");
    if(fp == NULL)
    {
        printf("Could not open file!\n");
        exit(1);
    }

    fread(buffer, sizeof(buffer), 1, fp);
    fclose(fp);

    int virusLength = strlen(virus);
    char *pos = strstr(buffer, virus);
    int index = pos - buffer;

    memmove(pos, pos+virusLength, strlen(pos+virusLength)+1);

    fp = fopen(filename, "wb");
    if(fp == NULL)
    {
        printf("Could not open file!\n");
        exit(1);
    }

    fwrite(buffer, sizeof(buffer), 1, fp);
    fclose(fp);

    printf("Malware was successfully removed!\n");
}