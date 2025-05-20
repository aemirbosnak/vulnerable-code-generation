//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME 50
#define MAX_SCAN_LENGTH 100

typedef enum {false, true} bool;

void scan_file(char *filename);
bool is_safe(char *string);

int main()
{
    char filename[MAX_FILE_NAME];

    printf("Enter the name of the file to scan: ");
    scanf("%s", filename);

    scan_file(filename);

    return 0;
}

void scan_file(char *filename)
{
    char string[MAX_SCAN_LENGTH];
    FILE *file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("Unable to open file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    printf("Scanning file: %s\n", filename);

    while (fgets(string, MAX_SCAN_LENGTH, file) != NULL)
    {
        if (is_safe(string))
        {
            printf("SAFE: %s\n", string);
        }
        else
        {
            printf("UNSAFE: %s\n", string);
        }
    }

    fclose(file);
}

bool is_safe(char *string)
{
    char *virus_1 = "rm -rf /";
    char *virus_2 = "sudo rm -rf /";
    char *virus_3 = "format C:";

    if (strstr(string, virus_1) != NULL ||
        strstr(string, virus_2) != NULL ||
        strstr(string, virus_3) != NULL)
    {
        return false;
    }

    return true;
}