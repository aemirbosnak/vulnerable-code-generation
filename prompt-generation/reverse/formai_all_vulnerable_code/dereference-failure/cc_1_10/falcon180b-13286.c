//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_FILE_NAME 255
#define MAX_VIRUS_NAME 50
#define MAX_VIRUSES 100
#define MAX_VIRUS_SIZE 1000

typedef struct
{
    char name[MAX_VIRUS_NAME];
    char signature[MAX_VIRUS_SIZE];
} virus;

virus viruses[MAX_VIRUSES];
int num_viruses;

void load_viruses()
{
    FILE *fp;
    char line[MAX_FILE_NAME];
    char *token;

    fp = fopen("viruses.txt", "r");
    if (fp == NULL)
    {
        printf("Error loading virus database.\n");
        exit(1);
    }

    num_viruses = 0;
    while (fgets(line, MAX_FILE_NAME, fp)!= NULL)
    {
        if (num_viruses >= MAX_VIRUSES)
        {
            printf("Error: too many viruses in database.\n");
            exit(1);
        }

        token = strtok(line, ",");
        strcpy(viruses[num_viruses].name, token);

        token = strtok(NULL, ",");
        strcpy(viruses[num_viruses].signature, token);

        num_viruses++;
    }

    fclose(fp);
}

void scan_file(char *filename)
{
    FILE *fp;
    char buffer[MAX_FILE_NAME];
    int filesize;
    int i;

    fp = fopen(filename, "rb");
    if (fp == NULL)
    {
        printf("Error opening file '%s'.\n", filename);
        return;
    }

    fseek(fp, 0, SEEK_END);
    filesize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    while (fread(buffer, 1, filesize, fp) > 0)
    {
        for (i = 0; i < num_viruses; i++)
        {
            if (strstr(buffer, viruses[i].signature)!= NULL)
            {
                printf("Virus found in file '%s': %s\n", filename, viruses[i].name);
                return;
            }
        }
    }

    printf("File '%s' is clean.\n", filename);
}

int main(int argc, char *argv[])
{
    load_viruses();

    if (argc < 2)
    {
        printf("Usage: %s <file>\n", argv[0]);
        exit(1);
    }

    scan_file(argv[1]);

    return 0;
}