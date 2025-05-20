//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_VIRUSES 100
#define MAX_VIRUS_NAME 32
#define MAX_VIRUS_SIGNATURE 64
#define MAX_FILE_SIZE 1024 * 1024

typedef struct
{
    char name[MAX_VIRUS_NAME];
    char signature[MAX_VIRUS_SIGNATURE];
} Virus;

Virus viruses[MAX_VIRUSES];
int num_viruses = 0;

bool load_viruses(const char *filename)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        return false;
    }

    while (fscanf(fp, "%s %s", viruses[num_viruses].name, viruses[num_viruses].signature) != EOF)
    {
        num_viruses++;
    }

    fclose(fp);

    return true;
}

bool scan_file(const char *filename, unsigned char *buf, size_t size)
{
    for (int i = 0; i < num_viruses; i++)
    {
        const char *signature = viruses[i].signature;
        for (size_t j = 0; j < size; j++)
        {
            if (buf[j] == signature[0] && memcmp(buf + j, signature, strlen(signature)) == 0)
            {
                return true;
            }
        }
    }

    return false;
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("Usage: %s <virus_file> <file_to_scan>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (!load_viruses(argv[1]))
    {
        printf("Error loading virus database\n");
        return EXIT_FAILURE;
    }

    FILE *fp = fopen(argv[2], "rb");
    if (fp == NULL)
    {
        printf("Error opening file to scan\n");
        return EXIT_FAILURE;
    }

    unsigned char buf[MAX_FILE_SIZE];
    size_t size = fread(buf, 1, sizeof(buf), fp);
    if (size == 0)
    {
        printf("Error reading file to scan\n");
        fclose(fp);
        return EXIT_FAILURE;
    }

    fclose(fp);

    bool infected = scan_file(argv[2], buf, size);
    if (infected)
    {
        printf("File is infected\n");
    }
    else
    {
        printf("File is clean\n");
    }

    return EXIT_SUCCESS;
}