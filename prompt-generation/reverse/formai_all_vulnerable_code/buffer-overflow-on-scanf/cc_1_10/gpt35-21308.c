//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: detailed
#include <stdio.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 50
#define MAX_SIGNATURE_LENGTH 20

#define SIGNATURE_COUNT 3

char signatures[][MAX_SIGNATURE_LENGTH] = {"VIOLATION", "TROJAN", "BACKDOOR"};

int main()
{
    char file_name[MAX_FILE_NAME_LENGTH];
    int signature_match_count = 0;

    printf("Enter the file name: ");
    scanf("%s", file_name);

    FILE *file_pointer = fopen(file_name, "rb");

    if (file_pointer == NULL)
    {
        printf("Unable to open file.\n");
        return 1;
    }

    char buffer[MAX_SIGNATURE_LENGTH];

    for (int i = 0; i < SIGNATURE_COUNT; i++)
    {
        fseek(file_pointer, 0, SEEK_SET);

        if (fread(buffer, sizeof(char), strlen(signatures[i]), file_pointer) != strlen(signatures[i]))
        {
            continue;
        }

        if (strncmp(signatures[i], buffer, strlen(signatures[i])) == 0)
        {
            signature_match_count++;
        }
    }

    fclose(file_pointer);

    if (signature_match_count > 0)
    {
        printf("Antivirus: Virus detected!\n");
    }
    else
    {
        printf("Antivirus: File is safe.\n");
    }

    return 0;
}