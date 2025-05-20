//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: excited
#include <stdio.h>
#include <string.h>

void scan_file(char *file_name)
{
    FILE *file = fopen(file_name, "r");
    
    if (!file)
    {
        printf("%s not found\n", file_name);
        return;
    }
    
    char virus_signature[] = "malware";
    int virus_signature_length = strlen(virus_signature);
    char buffer[virus_signature_length];
    
    int position = 0;
    int character;
    while ((character = fgetc(file)) != EOF)
    {
        if (character == virus_signature[position])
        {
            buffer[position] = character;
            position++;
            
            if (position == virus_signature_length)
            {
                printf("Found malware in %s\n", file_name);
                fclose(file);
                return;
            }
        }
        else
        {
            position = 0;
        }
    }
    
    fclose(file);
    printf("No malware found in %s\n", file_name);
}

int main()
{
    printf("Welcome to C Antivirus Scanner\n");
    printf("Please enter file name to scan:");
    
    char file_name[100];
    scanf("%s", file_name);
    
    scan_file(file_name);
    
    return 0;
}