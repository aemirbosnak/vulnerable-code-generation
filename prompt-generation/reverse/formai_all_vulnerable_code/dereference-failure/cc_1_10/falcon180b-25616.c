//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE 1000000
#define VIRUS_SIGNATURE "Virus"

int is_virus(char* file_content);

int main(int argc, char* argv[])
{
    if(argc!= 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE* file = fopen(argv[1], "rb");
    if(file == NULL)
    {
        printf("Error opening file %s\n", argv[1]);
        exit(1);
    }

    char* file_content = malloc(MAX_FILE_SIZE);
    size_t file_size = fread(file_content, 1, MAX_FILE_SIZE, file);

    if(ferror(file))
    {
        printf("Error reading file %s\n", argv[1]);
        exit(1);
    }

    fclose(file);

    if(is_virus(file_content))
    {
        printf("Virus found in file %s\n", argv[1]);
    }
    else
    {
        printf("No virus found in file %s\n", argv[1]);
    }

    free(file_content);
    return 0;
}

int is_virus(char* file_content)
{
    char* token = strtok(file_content, " \n\t\r");
    while(token!= NULL)
    {
        if(strcasecmp(token, VIRUS_SIGNATURE) == 0)
        {
            return 1;
        }
        token = strtok(NULL, " \n\t\r");
    }
    return 0;
}