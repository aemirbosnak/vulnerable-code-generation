//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024
#define MAX_FILENAME_SIZE 255

int scan_file(char *filename);

int main()
{
    char filename[MAX_FILENAME_SIZE];
    int result;

    printf("RETRO Antivirus Scanner\n");
    printf("-----------------------\n");

    printf("Enter file name: ");
    scanf("%s", filename);

    result = scan_file(filename);

    switch(result)
    {
        case -1:
            printf("ERROR: Cannot open file '%s'\n", filename);
            break;
        case 0:
            printf("No virus found.\n");
            break;
        case 1:
            printf("Virus found!\n");
            break;
    }

    return 0;
}

int scan_file(char *filename)
{
    FILE *file;
    char buffer[MAX_FILE_SIZE];
    int i, len;

    file = fopen(filename, "r");
    if(!file) return -1;

    len = fread(buffer, 1, MAX_FILE_SIZE, file);
    fclose(file);

    for(i = 0; i < len; i++)
    {
        if(buffer[i] == 'R' && buffer[i+1] == 'E' && buffer[i+2] == 'T' && buffer[i+3] == 'R' && buffer[i+4] == 'O')
        {
            return 1;
        }
    }

    return 0;
}